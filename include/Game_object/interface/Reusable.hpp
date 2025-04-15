#pragma once

#include <utility>

namespace Interface{
//Reusable effect interface.
//the derived class should implement the Initial() method,
//with same parameters as its constructor for reinitialization.
template<typename T>
class Reusable{
public:
    //CRTP
    template<typename...Args>
    void CallInitial(Args&&...args){
        static_cast<T*>(this)->Initial(std::forward<Args>(args)...);
    }
};
} // namespace 
