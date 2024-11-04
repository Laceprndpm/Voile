// #include <iostream>

// template <typename T>
// class MyClass
// {
// private:
//     T value;

// public:
//     MyClass(T v) : value(v) {}

//     // 非限制性模板友元函数
//     template <typename U>
//     friend void showValue(const MyClass<U>& obj);
// };

// // 对所有 MyClass<U> 友好的友元函数
// template <typename U>
// void showValue(const MyClass<U>& obj)
// {
//     std::cout << "Value: " << obj.value << std::endl;
// }

// int main()
// {
//     MyClass<int> obj1(42);
//     showValue(obj1); // 正确

//     MyClass<double> obj2(3.14);
//     showValue(obj2); // 正确

//     return 0;
// }
#include <iostream>
template <typename T>
void showValue(const T &obj);
template <typename TT>
class MyClass
{
private:
    TT value;

public:
    MyClass(TT v) : value(v) {}

    // 特殊友元声明，对所有 MyClass<T> 实例友好
    friend void showValue<>(const MyClass<TT> &);
};

// 对所有 MyClass<T> 实例友好的友元函数
template <typename T>
void showValue(const T &obj)
{
    std::cout << "Value: " << obj.value << std::endl;
}

int main()
{
    MyClass<int> obj1(42);
    showValue(obj1); // 正确

    MyClass<double> obj2(3.14);
    showValue(obj2); // 正确

    return 0;
}