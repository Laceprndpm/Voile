#include "contact.h"

void Contact_Init(struct Contact *ps)
{
    memset(ps->data, 0, sizeof(ps->data));
    memset(&ps->size, 0, sizeof(ps->size));
}

void Contact_Add(struct Contact *ps)
{
    if (ps->size == CONTACT_MAX)
    {
        printf("Sorry,Its Full");
    }
    else
    {
        printf("Input Name:");
        scanf("%s", ps->data[ps->size].name);
        printf("Input Age:");
        scanf("%d", &(ps->data[ps->size].age));
        printf("Input Sex:");
        scanf("%s", ps->data[ps->size].sex);
        printf("Input Tele:");
        scanf("%s", ps->data[ps->size].tele);
        printf("Input Address:");
        scanf("%s", ps->data[ps->size].address);
        printf("ALL DONE\n");

        ps->size++;
    }
}

void Contact_Show(const struct Contact *ps)
{
    if (ps->size == 0)
    {
        printf("Null");
    }
    else
    {
        int i = 0;
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "Name", "Age", "Sex", "Tele", "Address");
        for (i = 0; i < ps->size; i++)
        {
            printf(
                "%-20s\t"
                "%-4d\t"
                "%-5s\t"
                "%-12s\t"
                "%-20s\n",
                ps->data[i].name,
                ps->data[i].age,
                ps->data[i].sex,
                ps->data[i].tele,
                ps->data[i].address);
        }
    }
}