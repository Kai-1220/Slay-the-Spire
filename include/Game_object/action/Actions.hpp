namespace Action{
class Actions
{
public:
    virtual ~Actions()=default;
    virtual void update()=0;
    bool IsDone()const{return is_done;}
protected:
    bool is_done;
};   
}