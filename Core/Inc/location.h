#ifndef __LOCATION_H__
#define __LOCATION_H__
#include "main.h"



typedef struct {
	int latitude1;
	int latitude2;
	char lat;
	int longitude1;
	int longitude2;
	char lon;
}location;

location parseLocation (int cnt,char *string,location location);

void setLocationFlag(int *locationFlag);

location checkLocation(int *locationFlag,char *str);


#endif
