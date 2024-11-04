#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <string>

template <typename T>
class Box
{
private:
    T data;

public:
    Box(T data);
    ~Box();
    T getData() const;
    void setData(T data);

    // 通用方法
    void printData() const;
};

// 通用模板类的实现
template <typename T>
Box<T>::Box(T data) : data(data) {}

template <typename T>
Box<T>::~Box() {}

template <typename T>
T Box<T>::getData() const
{
    return data;
}

template <typename T>
void Box<T>::setData(T data)
{
    this->data = data;
}

template <typename T>
void Box<T>::printData() const
{
    std::cout << "Data: " << data << std::endl;
}

// 特化方法：针对 std::string 类型的特化
template <>
void Box<std::string>::printData() const
{
    std::cout << "String Data: " << data << std::endl;
}

#endif // BOX_H