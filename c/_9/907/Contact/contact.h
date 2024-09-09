#if !defined(__CONTACT_H__)
#define __CONTACT_H__

#define NAME_Length 20
#define SEX_Length 5
#define CONTACT_MAX 100

#include <stdio.h>
#include <string.h>

struct PeoInfo
{
    char name[NAME_Length];
    int age;
    char sex[SEX_Length];
    char tele[12];
    char address[30];
};

struct Contact
{
    struct PeoInfo data[CONTACT_MAX];
    int size;
};

void Contact_Init(struct Contact *ps);
void Contact_Add(struct Contact *ps);
void Contact_Show(const struct Contact *ps);

#endif // __CONTACT_H__
