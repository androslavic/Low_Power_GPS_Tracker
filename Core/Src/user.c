#include "user.h"



void print2string (char *str, char c){

	int i;

	for (i=0;i<(BUFSIZE-2);i++){

		if (str[i]=='\0')
		{
			str[i+1]=str[i];
			str[i]=c;
			return;
		}

	}

}



void PowerOnKey (void){

	//switch power on via Key pin on sim808
	  HAL_ResumeTick();
	   //USART2_Debug("Key set to 0 for 1 second");
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1,GPIO_PIN_RESET);
	  HAL_Delay(2000);
	  //USART2_Debug("Key set to 1");
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1,GPIO_PIN_SET);
	  USART2_SendString("\r\n");
}



char strletter(char *str){

	int i;

	for (i=0;i<strlen(str);i++){

        if (str[i]=='N' || str[i]=='W' || str[i]=='E' || str[i]=='S'){
        	return str[i];
        }
	}
	return 0;
}



void cleanBuffer(char *buffer){

	int i;
    for(i=0;i<BUFSIZE;i++){
    	buffer[i]= 0;
    }

}
