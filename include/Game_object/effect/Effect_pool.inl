#include <type_traits>
#include <algorithm>

#include "Game_object/effect/Effect_pool.hpp"
#include "Game_object/effect/Auto_release_pool_manager.hpp"

template <typename U,typename = void>
struct has_UseAutoRelease : std::false_type{};

template <typename U>
struct has_UseAutoRelease<U, std::void_t<decltype(U::UseAutoRelease())>> 
: std::conjunction<
    std::is_same<decltype(U::UseAutoRelease()),bool>,
    std::bool_constant<U::UseAutoRelease()>>{};

namespace Effect{
    template <typename T>
    template <typename...Args>
    T* Effect_pool<T>::GetEffect(Args&&...args){
        if constexpr (has_UseAutoRelease<T>::value){
            static bool once=false;
            if(!once){
                Auto_release_pool_manager::JoinToAutoCheck(Effect_pool<T>::CheckBoxRelease);
                once=true;
            }
            in_use=true;//if using auto release, mark as in use.
        }
        
        if(curr_n==n){//full the box
            if(box[curr_pos]->IsDone()){//can Initial
                box[curr_pos]->CallInitial(std::forward<Args>(args)...);
                const auto& ret=box[curr_pos++];
                if(n<=curr_pos)curr_pos=0;
                return &(*ret);
            }
            if(!box[curr_pos]->IsDone()&&n!=MAX){//n not enough
                if(MAX<(n<<1)) n=MAX;
                else n<<=1;
                box.reserve(n);
                std::rotate(box.begin(),box.begin()+curr_pos,box.end());//Ensure that effects with shortest remaining duration are moved to front of box.
                curr_pos=0;//fix curr_pos
            }
        }
        box.emplace_back(std::make_shared<T>(std::forward<Args>(args)...));
        curr_n++;
        return &(*box.back());
    }
    
    template <typename _T>
    static bool _check(const _T& _box){
        for(const auto &it:_box)
            if(!it->IsDone()) return false;
        return true;
    }

    template <typename T>
    void Effect_pool<T>::CheckBoxRelease(){
        if constexpr (has_UseAutoRelease<T>::value){
            if(!in_use&&_check(box)){
                if((n>>1)<MIN) n=MIN;
                else n>>=1;
                if(n<static_cast<int>(box.size()))//just in case
                    box.resize(n);//release memory.
                curr_pos=0;//fix pos.
                curr_n=n;//fix curr_n.
            }else{
                in_use=false;
            }
        }
    }

    template <typename T>
    std::vector<std::shared_ptr<T>> Effect_pool<T>::box;

    template <typename T>
    int Effect_pool<T>::n=Effect_pool<T>::MIN;

    template <typename T>
    bool Effect_pool<T>::in_use=false;

    template <typename T>
    int Effect_pool<T>::curr_pos;
    template <typename T>
    int Effect_pool<T>::curr_n;
}