
#include "main.h"





int main(void)
{

  char c=0,i=0;
  char buffer1[BUFSIZE]={'\0'};
  char buffer2[BUFSIZE]= {'\0'};

  init();

 // communication_test();
  /* pri paljenju uređaja provjerimo da postoji komunikacija s sim808
   * nakon toga sleep
   * rutina se pali prilikom interrupta s sim808 (poruka/poziv)
   * pali se antena AT+CGPSPWR=1
   * cekamo status AT+CGPSSTATUS? svakih 30 sekundi
   * (proizvoljno,treba mu par min da se pronađe)
   * kad dobijemo odgovor 3D fix --> AT+CGPSINF=2
   * dobivamo koordinate --> šalje se SMS*/



  while (1)
  {
	  if (USART2_Dequeue (&c) != 0) {

 //	  	  LPUART1_SendChar(c);
		  USART2_SendChar(c);
		  print2string(buffer1,c);

		  if (strstr(buffer1,"a1")) {strcpy(buffer1,"\r\nAT+CGPSSTATUS?\r\n");LPUART1_SendString(buffer1);}
		  if (strstr(buffer1,"s1")) {strcpy(buffer1,"\r\nAT+CGPSPWR?\r\n"); LPUART1_SendString(buffer1);}
		  if (strstr(buffer1,"d1")) {strcpy(buffer1,"\r\nAT+CGPSPWR=1\r\n"); LPUART1_SendString(buffer1);}
		  if (strstr(buffer1,"f1")) {strcpy(buffer1,"\r\nAT+CGPSRST=0\r\n"); LPUART1_SendString(buffer1);}
	 	  if (strstr(buffer1,"g1")) {strcpy(buffer1,"\r\nAT+CGPSSTATUS?\r\n"); LPUART1_SendString(buffer1);}
		  if (strstr(buffer1,"h1")) {strcpy(buffer1,"\r\nAT+CGPSINF=2\r\n"); LPUART1_SendString(buffer1);}

		  if (strchr(buffer1,'\r')) {LPUART1_SendString(buffer1);}

	  }

	  if (LPUART1_Dequeue (&c) != 0) {

//	  	  USART2_SendChar(c);

		  print2string(buffer2,c);

		  if (strchr(buffer2,'\n')){

			  USART2_SendString(buffer2);
		  	  }
	  }
  }


}
