
// #include <stdio.h>
// #include <stdlib.h>
// #include <windows.h>
// #include <string.h>
// #include <mmsystem.h>
// #pragma comment(lib, "WINMM.LIB")
// #include<time.h>
// #pragma warning(disable : 4996)
// static  void  SetPos(int  x, int  y)
// {
//     COORD  point = { x ,  y }; //���Ҫ���õ�λ��x,y
//     HANDLE  HOutput = GetStdHandle(STD_OUTPUT_HANDLE); //ʹ��GetStdHandle(STD_OUTPUT_HANDLE)����ȡ��׼����ľ��
//     SetConsoleCursorPosition(HOutput, point); //���ù��λ��
// }
// int main()
// {
//      FILE* fp;
//      char buf[150], add[60], ai[5];
//      int i=1,delay=33;
//      clock_t stime = 0, ftime = 0;
    

//     mciSendString(TEXT("open C:\\BadApple.wav alias bkmusic"), NULL, 0, NULL);//��������
//     mciSendString(TEXT("play bkmusic"), NULL, 0, NULL);
//    /* Sleep(200);*/
//     stime = clock();
//     while (i<=6573)
//     {
//         if (i % 30 == 0)
//         {
//             delay = 43;
//         }
//         else
//         {
//             delay = 33;
//         }

//         strcpy(add, "C:\\�ַ��ı�\\t (");
//         sprintf(ai, "%d", i);
//         strcat(add, ai);
//         strcat(add, ").txt");
//        // �����޸�
//         ftime = clock();
//         if (ftime - stime >= delay) 
//         {
//             fp = fopen(add, "r");//��ӡ�ı�

//             if (NULL == fp)
//                 printf("�򿪴���");
//             else
//             {
//                 while (fgets(buf, 150, fp))
//                 {
//                     printf("%s", buf);
//                 }
//                 fclose(fp);
//                 SetPos(0, 0);
//                 i++;
//                 stime += delay;

//             }      }               }
//     return 0;
// }

