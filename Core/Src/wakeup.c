#include "wakeup.h"

void wakeup_handler(int wakeUp){


	if (wakeUp){

		checkSMS();

		if (SMS==SMS_processed){
			wakeup=0;
			//todo: back to sleep!!
		}
	}


}

