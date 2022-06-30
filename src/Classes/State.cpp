#include "./../Headers/Classes/State.h"

template <typename Prop>
StateProp<Prop>::StateProp(Prop _value)
{
    this->value = _value;
}

template <typename Prop>
void StateProp<Prop>::update(Prop _value)
{
    this->value = _value;
}

template <typename Prop>
Prop StateProp<Prop>::get()
{
    return this->value;
}