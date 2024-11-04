#include "vect.h"
int main()
{
    VECTOR::Vector vect = VECTOR::Vector(2, 45, (static_cast<VECTOR::Vector::Mode>(1)));
    vect.rect_mode();
    std::cout << vect;
}