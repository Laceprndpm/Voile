
#include "contact.h"
#include <stdlib.h>
void Menu()
{
    printf("***************************************\n");
    printf("***************************************\n");
    printf("***************************************\n");
    printf("***************************************\n");
    printf("***************************************\n");
    printf("***************************************\n");
}
int main(int argc, char *argv[])
{
    int input = 0;
    struct Contact con;
    int tag = 0;
    Contact_Init(&con);
    if (argc > 1)
    {
        if (strcmp(argv[1], "A") == 0)
        {
            input = 1;
        }
        else if (strcmp(argv[1], "S") == 0)
        {
            input = 2;
        }
        else if (strcmp(argv[1], "Multiply") == 0)
        {
            input = 3;
        }
        else if (strcmp(argv[1], "Divide") == 0)
        {
            input = 4;
        }
        else
        {
            input = 0; // 默认值或错误代码
        }
    }
    else
    {
        Menu();
        scanf("%d", &input);
    }
    do
    {
        switch (input)
        {
        case 0:

            break;
        case 1:
            Contact_Add(&con);
            break;
        case 2:
            Contact_Show(&con);
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        default:
            break;
        }
        Menu();
        scanf("%d", &input);
    } while (input);
}