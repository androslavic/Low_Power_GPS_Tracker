#include "call.h"




void setCallFlag(int *callFlag){

	*callFlag=1;
}


void checkCall(int *callFlag, char *str){


	char * token;
	char * string;
	int cnt=0;
	static int ring=0;

	if (ring==0){
		ring=1;
		return;
	}

	strcpy(auxBuffer,str);

	if (*callFlag){

		token = strtok (auxBuffer,",+");
		  while (token != NULL)
		  {
		    string=token;
			cnt++;
			callStruct=parseCall(cnt,string,callStruct);

		    token = strtok (NULL, ",+");
		  }

		*callFlag=0;

		USART2_SendString("Caller ID: ");
		sprintf(callBuffer,"\r\n %s\r\n",
				  callStruct.phone);
		USART2_SendString(callBuffer);

		ring=0;

		//sendLocation(phoneNumber);
	}

}


call parseCall (int cnt,char *string,call call){


	switch (cnt) {

       case 1:
    	   USART2_Debug("1");
    	   strcpy(call.phone,string);
    	   USART2_SendString(call.phone);
	       break;
       case 2:
    	   USART2_Debug("2");
    	   strcpy(call.phone,string);
    	   USART2_SendString(call.phone);
	       break;
       case 3:
    	   USART2_Debug("3");
    	   strcpy(call.phone,string);
    	   USART2_SendString(call.phone);
	       break;
       case 4:
    	   USART2_Debug("4");
    	   strcpy(call.phone,string);
    	   USART2_SendString(call.phone);
	       break;
       case 5:
    	   USART2_Debug("5");
    	   strcpy(call.phone,string);
    	   USART2_SendString(call.phone);
	       break;
       case 6:
    	   USART2_Debug("6");
    	   strcpy(call.phone,string);
    	   USART2_SendString(call.phone);
	       break;

       default:
    	   break;

	}

	return call;
}
