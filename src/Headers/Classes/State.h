class State
{
};

template <typename Prop>
class StateProp : public State
{
private:
    Prop value;

public:
    StateProp(Prop);
    ~StateProp();
    void update(Prop);
    Prop get();
};