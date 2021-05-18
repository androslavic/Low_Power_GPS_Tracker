#include "location.h"



location parseLocation (int cnt,char *string,location location){



	switch (cnt) {

	case 5:
		location.latitude1=atoi(string);
		USART2_Debug("location.latitude1: ");
		USART2_SendString(string);
		break;
	case 6:
		location.latitude2=atoi(string);
		USART2_Debug("location.latitude2: ");
		USART2_SendString(string);
		break;
	case 7:
		location.lat=strletter(string);
		USART2_Debug("location.lat: ");
		USART2_SendChar(location.lat);
		break;
	case 8:
		location.longitude1=atoi(string);
		USART2_Debug("location.longitude1: ");
		USART2_SendString(string);
		break;
	case 9:
		location.longitude2=atoi(string);
		USART2_Debug("location.longitude2: ");
		USART2_SendString(string);
		break;
	case 10:
		location.lon=strletter(string);
		USART2_Debug("location.lon: ");
		USART2_SendChar(location.lon);
		USART2_SendString("\r\n");
		break;
	default:
		break;

	}
	return location;
}


void setLocationFlag(int *locationFlag){

	*locationFlag=1;
}

location checkLocation(int *locationFlag, char *str){

	static location location;
	char * token;
	char * string;
	char str1[100]={0};
	int cnt=0;

	if (*locationFlag){

		token = strtok (str," ,.-");
		  while (token != NULL)
		  {
		    string=token;
			cnt++;
			location=parseLocation(cnt,string,location);

		    token = strtok (NULL, " ,.-");
		  }

		*locationFlag=0;
	}

	return location;

}
