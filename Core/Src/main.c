
#include "main.h"





int main(void)
{

  char c=0,i=0;
  char buffer1[BUFSIZE]={'\0'};
  char buffer2[BUFSIZE]= {'\0'};

  init();

 // communication_test();



  while (1)
  {
	  if (USART2_Dequeue (&c) != 0) {
//		  if (c=='b'){
//			  strcpy(string,"AT\r\n\0");
//			  LPUART1_SendString(string);
//		  	  }
//		  else{
//		  	  LPUART1_SendChar(c);
		  	  USART2_SendChar(c);
//		  }

		  print2string(buffer1,c);

		  if (strstr(buffer1,"a1")) {strcpy(buffer1,"AT+CGPSSTATUS?\r\n");LPUART1_SendString(buffer1);}
		  if (strstr(buffer1,"s1")) {strcpy(buffer1,"AT+CGPSPWR?\r\n"); LPUART1_SendString(buffer1);}
		  if (strstr(buffer1,"d1")) {strcpy(buffer1,"AT+CGPSPWR=1\r\n"); LPUART1_SendString(buffer1);}
		  if (strstr(buffer1,"f1")) {strcpy(buffer1,"AT+CGPSRST=0\r\n"); LPUART1_SendString(buffer1);}
		  if (strstr(buffer1,"g1")) {strcpy(buffer1,"AT+CGPSSTATUS?\r\n"); LPUART1_SendString(buffer1);}
		  if (strstr(buffer1,"h1")) {strcpy(buffer1,"AT+CGPSINF=2\r\n"); LPUART1_SendString(buffer1);}

		  if (strchr(buffer1,'\r')) {LPUART1_SendString(buffer1);}


	  }

	  if (LPUART1_Dequeue (&c) != 0) {

		  print2string(buffer2,c);

		  if (strchr(buffer2,'\n')){

			  USART2_SendString(buffer2);
		  	  }
	  }
  }


}
