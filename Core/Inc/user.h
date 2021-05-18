#ifndef __USER_H__
#define __USER_H__

#define BUFSIZE 200

#include "main.h"

typedef struct {
	int latitude1;
	int latitude2;
	char lat;
	int longitude1;
	int longitude2;
	char lon;
}location;

char strletter(char *str);

void cleanBuffer(char *buffer);

void print2string (char *str, char c);

void processMessage(char *str);

void sendCommand (char *str);

void checkSMS(void);

location parseLocation (int cnt,char *string,location location);

void setLocationFlag(int *locationFlag);

location checkLocation(int *locationFlag,char *str);

void PowerOnKey (void);

int SMS;

extern int SMS;


#endif
