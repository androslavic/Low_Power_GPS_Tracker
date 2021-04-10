#include "user.h"


void cleanBuffer(char *buffer){

	int i;
    for(i=0;i<BUFSIZE;i++){
    	buffer[i]= 0;
    }

}

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
