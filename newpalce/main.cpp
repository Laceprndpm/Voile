#include <iostream>
#include "Box.h"

int main()
{
    // 创建一个存储整数的 Box 对象
    Box<int> intBox(123);
    std::cout << "Integer Box contains: " << intBox.getData() << std::endl;

    // 创建一个存储字符串的 Box 对象
    Box<std::string> strBox("Hello, World!");
    std::cout << "String Box contains: " << strBox.getData() << std::endl;

    // 修改 Box 对象中的数据
    intBox.setData(456);
    std::cout << "Integer Box now contains: " << intBox.getData() << std::endl;

    strBox.setData("Goodbye, World!");
    std::cout << "String Box now contains: " << strBox.getData() << std::endl;

    return 0;
}