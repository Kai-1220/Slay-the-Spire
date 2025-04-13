#pragma once

namespace Template{
template<typename box_type>
class Group_template
{
public:
    Group_template()=default;
    virtual ~Group_template()=default;
    using T=typename box_type::value_type;
    void AddTop(T&&item){box.emplace_back(std::move(item));}
    void AddBot(T&&item){box.emplace_front(std::move(item));}
    void AddTop(const T&item){box.emplace_back(item);}
    void AddBot(const T&item){box.emplace_front(item);}
    T PopTop(){auto temp=std::move(box.back());box.pop_back();return temp;}
    void Clear(){box.clear();}
    auto begin()const{return box.begin();}
    auto end()const{return box.end();}
    bool empty()const{return box.empty();}
    const auto&Top()const{return box.back();}
    const auto&Bot()const{return box.front();}
    int Size()const{return static_cast<int>(box.size());}
protected:
    box_type box;
};
}
