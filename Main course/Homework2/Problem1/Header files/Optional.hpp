#pragma once

template <typename T>
class Optional {
public:
    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;

private:
    bool isEmpty;
    T content;
};

template<typename T>
Optional<T>::Optional()
{
    this->isEmpty = true;
}

template<typename T>
Optional<T>::Optional(const T& value)
{
    this->isEmpty = false;
    this->content = value;
}

template<typename T>
bool Optional<T>::is_none() const
{
    return this->isEmpty;
}

template<typename T>
T Optional<T>::get_value() const
{
    if (this->isEmpty)
    {
        return T();
    }

    return this->content;
}
