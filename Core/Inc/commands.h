#ifndef __COMMANDS_H__
#define __COMMANDS_H__

// SIM and GSM related commands
extern const char sim808_AT[];
extern const char sim808_ISATECHO[];
extern const char sim808_ISOK[];
extern const char sim808_ISRING[];
extern const char sim808_ISRING2[];                  // if first character is missing - we also accept
extern const char sim808_ISREG1[];            // SIM registered in HPLMN
extern const char sim808_ISREG2[];            // SIM registered in ROAMING NETWORK
extern const char sim808_SHOW_REGISTRATION[];
extern const char sim808_DISREGREPORT[];  //  disable reporting URC of losing 2G coverage by +CREG=0
extern const char sim808_PIN_IS_READY[];
extern const char sim808_PIN_MUST_BE_ENTERED[];


extern const char sim808_SHOW_PIN[];
extern const char sim808_ECHO_OFF[];
extern const char sim808_ENTER_PIN[];
extern const char sim808_CFGRIPIN[];
extern const char sim808_HANGUP[];

extern const char sim808_SMS1[];
extern const char sim808_SMS2[];
extern const char sim808_DELSMS[];

extern const char sim808_CRLF[];
extern const char sim808_CLIP[];

// Flightmode ON OFF - for saving battery while in underground garage with no GSM signal
// tracker will check 2G network availability in 30 minutes intervals
// meanwhile radio will be switched off for power saving
extern const char sim808_FLIGHTON[];
extern const char sim808_FLIGHTOFF[];

// Sleepmode ON OFF - mode #1 requires DTR pin manipulation,
// to get out of SIM808 sleepmode DTR must be LOW for at least 50 miliseconds
extern const char sim808_SLEEPON[];
extern const char sim808_SLEEPOFF[];

// Fix UART speed to 9600 bps
extern const char sim808_SET9600[];

// Save settings to SIM808
extern const char sim808_SAVECNF[];

// Disable SIM808 LED for further reduction of power consumption
extern const char sim808_DISABLELED[];

// for sending SMS predefined text
extern const char sim808_GOOGLELOC1[];
extern const char sim808_GOOGLELOC2[];
extern const char sim808_GOOGLELOC3[];
extern const char sim808_LONG[];
extern const char sim808_LATT[];
extern const char sim808_BATT[];

// definition of APN used for GPRS communication
// please put correct APN, USERNAME and PASSWORD here appropriate
// for your Mobile Network provider
extern const char sim808_SAPBR1[];
extern const char sim808_SAPBR2[];    // Put your mobile operator APN name here
extern const char sim808_SAPBR3[];   // Put your mobile operator APN username here
extern const char sim808_SAPBR4[];    // Put your mobile operator APN password here
// PDP context commands
extern const char sim808_SAPBROPEN[];     // open IP bearer
extern const char sim808_SAPBRQUERY[];    // query IP bearer
extern const char sim808_SAPBRCLOSE[];    // close bearer
extern const char sim808_SAPBRSUCC[];          // bearer was succesfull we are not checking IP assigned

// check statuses & cells
extern const char sim808_CHECKGPS[];  // check AGPS position of nearest GSM CELL
extern const char sim808_CHECKBATT[];           // check battery voltage

// GPS SIM808 only related AT commands and responses
extern const char sim808_GPSPWRON[];                 // enable GPS inside SIM808
extern const char sim808_GPSSTAT[];                // check GPS fixation
extern const char sim808_GPSISFIXED1[];  // GPS in now fixed for 3D Response code
extern const char sim808_GPSISFIXED2[];  // GPS in now fixed for 2D Response code
extern const char sim808_GPSINFO[];                  // Read GPS LAT & LONG for SMS
extern const char sim808_GPSCLDSTART[];              // GPS cold restart
extern const char sim808_GPSHOTSTART[];              // GPS hot restart
extern const char sim808_GPSPWROFF[];                // disable GPS inside SIM808
extern const char sim808_GNSPWROFF[];                // shutoff GNSS section inside SIM808
extern const char sim808_GNSPWRON[];                 // switch on GNSS section inside SIM808

#endif

