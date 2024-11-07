
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
//     COORD  point = { x ,  y }; //光标要设置的位置x,y
//     HANDLE  HOutput = GetStdHandle(STD_OUTPUT_HANDLE); //使用GetStdHandle(STD_OUTPUT_HANDLE)来获取标准输出的句柄
//     SetConsoleCursorPosition(HOutput, point); //设置光标位置
// }
// int main()
// {
//      FILE* fp;
//      char buf[150], add[60], ai[5];
//      int i=1,delay=33;
//      clock_t stime = 0, ftime = 0;
    

//     mciSendString(TEXT("open C:\\BadApple.wav alias bkmusic"), NULL, 0, NULL);//播放音乐
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

//         strcpy(add, "C:\\字符文本\\t (");
//         sprintf(ai, "%d", i);
//         strcat(add, ai);
//         strcat(add, ").txt");
//        // 名字修改
//         ftime = clock();
//         if (ftime - stime >= delay) 
//         {
//             fp = fopen(add, "r");//打印文本

//             if (NULL == fp)
//                 printf("打开错误");
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

