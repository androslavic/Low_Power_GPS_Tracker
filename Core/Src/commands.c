#include "commands.h"
/*
// SIM and GSM related commands
const char sim808_AT[]  = { "AT\n\r" };
const char sim808_ISATECHO[]  = { "AT" };
const char sim808_ISOK[]  = { "OK" };
const char sim808_ISRING[]  = { "RING" };
const char sim808_ISRING2[]  = { "ING" };                  // if first character is missing - we also accept
const char sim808_ISREG1[]  = { "+CREG: 0,1" };            // SIM registered in HPLMN
const char sim808_ISREG2[]  = { "+CREG: 0,5" };            // SIM registered in ROAMING NETWORK
const char sim808_SHOW_REGISTRATION[]  = {"AT+CREG?\n\r"};
const char sim808_DISREGREPORT[]  = {"AT+CREG=0\n\r"};  //  disable reporting URC of losing 2G coverage by +CREG=0
const char sim808_PIN_IS_READY[]  = {"+CPIN: READY"};
const char sim808_PIN_MUST_BE_ENTERED[]  = {"+CPIN: SIM PIN"};


const char sim808_SHOW_PIN[]  = {"AT+CPIN?\n\r"};
const char sim808_ECHO_OFF[]  = {"ATE0\n\r"};
const char sim808_ENTER_PIN[]  = {"AT+CPIN=\"1111\"\n\r"};
const char sim808_CFGRIPIN[]  = {"AT+CFGRI=1\n\r"};
const char sim808_HANGUP[]  = {"ATH\n\r"};

const char sim808_SMS1[]  = {"AT+CMGF=1\r\n"};
const char sim808_SMS2[]  = {"AT+CMGS=\""};
const char sim808_DELSMS[]  = {"AT+CMGDA=\"DEL ALL\"\r\n"};

const char sim808_CRLF[]  = {"\"\n\r"};
const char sim808_CLIP[]  = {"AT+CLIP=1\r\n"};

// Flightmode ON OFF - for saving battery while in underground garage with no GSM signal
// tracker will check 2G network availability in 30 minutes intervals
// meanwhile radio will be switched off for power saving
const char sim808_FLIGHTON[]  = { "AT+CFUN=4\r\n" };
const char sim808_FLIGHTOFF[]  = { "AT+CFUN=1\r\n" };

// Sleepmode ON OFF - mode #1 requires DTR pin manipulation,
// to get out of SIM808 sleepmode DTR must be LOW for at least 50 miliseconds
const char sim808_SLEEPON[]  = { "AT+CSCLK=1\r\n" };
const char sim808_SLEEPOFF[]  = { "AT+CSCLK=0\r\n" };

// Fix UART speed to 9600 bps
const char sim808_SET9600[]  = { "AT+IPR=9600\r\n" };

// Save settings to SIM808
const char sim808_SAVECNF[]  = { "AT&W\r\n" };

// Disable SIM808 LED for further reduction of power consumption
const char sim808_DISABLELED[]  = { "AT+CNETLIGHT=0\r\n" };

// for sending SMS predefined text
const char sim808_GOOGLELOC1[]  = {"\r\n http://maps.google.com/maps?q="};
const char sim808_GOOGLELOC2[]  = {","};
const char sim808_GOOGLELOC3[]  = {"\r\n"};
const char sim808_LONG[]  = {" LONGTITUDE="};
const char sim808_LATT[]  = {" LATTITUDE="};
const char sim808_BATT[]  = {"\nBATTERY[mV]="};

// definition of APN used for GPRS communication
// please put correct APN, USERNAME and PASSWORD here appropriate
// for your Mobile Network provider
const char sim808_SAPBR1[]  = {"AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"\r\n"};
const char sim808_SAPBR2[]  = {"AT+SAPBR=3,1,\"APN\",\"internet\"\r\n"};    // Put your mobile operator APN name here
const char sim808_SAPBR3[]  = {"AT+SAPBR=3,1,\"USER\",\"internet\"\r\n"};   // Put your mobile operator APN username here
const char sim808_SAPBR4[]  = {"AT+SAPBR=3,1,\"PWD\",\"internet\"\r\n"};    // Put your mobile operator APN password here
// PDP context commands
const char sim808_SAPBROPEN[]  = {"AT+SAPBR=1,1\r\n"};     // open IP bearer
const char sim808_SAPBRQUERY[]  = {"AT+SAPBR=2,1\r\n"};    // query IP bearer
const char sim808_SAPBRCLOSE[]  = {"AT+SAPBR=0,1\r\n"};    // close bearer
const char sim808_SAPBRSUCC[]  = {"+SAPBR: 1,1"};          // bearer was succesfull we are not checking IP assigned

// check statuses & cells
const char sim808_CHECKGPS[]  = {"AT+CIPGSMLOC=1,1\r\n"};  // check AGPS position of nearest GSM CELL
const char sim808_CHECKBATT[]  = {"AT+CBC\r\n"};           // check battery voltage

// GPS SIM808 only related AT commands and responses
const char sim808_GPSPWRON[]  = {"AT+CGPSPWR=1\r\n"};                 // enable GPS inside SIM808
const char sim808_GPSSTAT[]  = {"AT+CGPSSTATUS?\r\n"};                // check GPS fixation
const char sim808_GPSISFIXED1[]  = {"+CGPSSTATUS: Location 3D Fix"};  // GPS in now fixed for 3D Response code
const char sim808_GPSISFIXED2[]  = {"+CGPSSTATUS: Location 2D Fix"};  // GPS in now fixed for 2D Response code
const char sim808_GPSINFO[]  = {"AT+CGPSINF=0\r\n"};                  // Read GPS LAT & LONG for SMS
const char sim808_GPSCLDSTART[]  = {"AT+CGPSRST=0\r\n"};              // GPS cold restart
const char sim808_GPSHOTSTART[]  = {"AT+CGPSRST=1\r\n"};              // GPS hot restart
const char sim808_GPSPWROFF[]  = {"AT+CGPSPWR=0\r\n"};                // disable GPS inside SIM808
const char sim808_GNSPWROFF[]  = {"AT+CGNSPWR=0\r\n"};                // shutoff GNSS section inside SIM808
const char sim808_GNSPWRON[]  = {"AT+CGNSPWR=1\r\n"};                 // switch on GNSS section inside SIM808
*/
