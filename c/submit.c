// #include <stdio.h>
// #include <stdlib.h>

// typedef struct
// {
//     int place;
//     int l;
//     int r;
// } Person;

// int compare(const void *a, const void *b)
// {
//     if (((Person *)a)->l - ((Person *)b)->l != 0)
//         return ((Person *)a)->l - ((Person *)b)->l;
//     else
//         return ((Person *)a)->r - ((Person *)b)->r;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     Person *people = (Person *)malloc(n * sizeof(Person));

//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d %d", &people[i].l, &people[i].r);
//         people[i].place = i;
//     }

//     // 按 r 排序
//     qsort(people, n, sizeof(Person), compare);

//     int currentCount = 0;      // 当前加入人数
//     int totalParticipants = 0; // 总参与人数

//     for (int i = 0; i < n; i++)
//     {
//         // 检查当前人数是否在该人愿意加入的区间内
//         if (currentCount >= people[i].l && currentCount <= people[i].r)
//         {
//             totalParticipants++;
//             currentCount++;
//         }
//         else
//         {
//             people[i].place = -1;
//         }
//     }

//     printf("%d\n", totalParticipants);
//     for (int i = 0; i < n; i++)
//     {
//         if (people[i].place != -1)
//         {
//             printf("%d ", people[i].place + 1);
//         }
//     }

//     free(people);
//     return 0;
// }
