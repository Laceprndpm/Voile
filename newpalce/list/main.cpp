#include "acctabc.h"
int main()
{
    Brass b1("Zhang", 20, 10);
    BrassPlus B1(b1, 1, 0.1);
    b1.Withdraw(100);
}