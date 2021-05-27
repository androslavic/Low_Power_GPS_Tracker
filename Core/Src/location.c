#include "location.h"



location parseLocation (int cnt,char *string,location location){



	switch (cnt) {

	case 5:
		location.latitude1=atoi(string);
		break;
	case 6:
		location.latitude2=atoi(string);
		break;
	case 7:
		location.lat=strletter(string);
		break;
	case 8:
		location.longitude1=atoi(string);
		break;
	case 9:
		location.longitude2=atoi(string);
		break;
	case 10:
		location.lon=strletter(string);
		break;
	default:
		break;

	}
	return location;
}


void setLocationFlag(int *locationFlag){

	*locationFlag=1;
}

void checkLocation(int *locationFlag, char *str){

	char * token;
	char * string;
	int cnt=0;

	strcpy(auxBuffer,str);

	if (*locationFlag){

		token = strtok (auxBuffer," ,.-");
		  while (token != NULL)
		  {
		    string=token;
			cnt++;
			locationStruct=parseLocation(cnt,string,locationStruct);

		    token = strtok (NULL, " ,.-");
		  }

		*locationFlag=0;

		  sprintf(locationBuffer,"\r\n%2d.%4d %c, %2d.%4d %c\r\n",
				  locationStruct.latitude1,locationStruct.latitude2,locationStruct.lat,
				  locationStruct.longitude1,locationStruct.longitude2,locationStruct.lon);
		  USART2_SendString(locationBuffer);

	}

}



void location_handler(void){

	static int i;

	if (findLocation){

		if (interruptTIM!=i){
		  // location status
			i++;
			USART2_SendString("Location tracing...\r\n");
			LPUART1_SendString("\r\nAT+CGPSSTATUS?\r\n");
			if (loc==3){
				findLocation=0;
				USART2_SendString("Location 3D Fix");
				sendLocation(phoneNumber);
			}
		}
		i=interruptTIM;

	}

}


