#if !defined(__Uart__)
#define __Uart__

void UartInit(void); // 4800bps@11.0592MHz
void U_Send(unsigned char Byte);

#endif // __Uart__
