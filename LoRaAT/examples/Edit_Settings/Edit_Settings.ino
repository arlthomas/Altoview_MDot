/*
 This is a test program writen for the Seeeduino Stalker v2.3 and 
 uses the Multitech mDOT LoRa module running the Australian compatable AT
 enabled firmware.
 
 This program,
  * Gets and sets settings on the mDot
*/

/*--------------------------------------------------------------------------------------
  Includes
  --------------------------------------------------------------------------------------*/
#include <LoRaAT.h>                     //Include LoRa AT libraray
#include <SoftwareSerial.h>

/*--------------------------------------------------------------------------------------
  Definitions
  --------------------------------------------------------------------------------------*/
SoftwareSerial debugSerial(10, 11);     //RX, TX
LoRaAT mdot(0, &debugSerial);           //Instantiate a LoRaAT object

/*--- setup() --------------------------------------------------------------------------
  Called by the Arduino framework once, before the main loop begins.

  In the setup() routine:
   - Opens serial communication with MDOT
   - Gets some settings from the mDOT
   - Sets some settings to random values
   - Gets the settings (just to check)
   - Sets to some default settings CSA like to use and recomend
   - Gets the settings again (to check)
  --------------------------------------------------------------------------------------*/
void setup() {
  int responseCode;
  
  debugSerial.begin(38400);             //Debug output. Listen on this ports for debugging info
  mdot.begin(38400);                    //Begin (possibly amongst other things) opens serial comms with MDOT
  
  debugSerial.println("\r\n\r\n++ START ++\r\n\r\n");

  //Get all the initial settings
  mdot.getFrequencySubBand();
  mdot.getPublicNetwork();
  mdot.getNetworkID();
  mdot.getNetworkKey();
  mdot.getDataRate();
  mdot.getRXOutput();

  //Set some settings
  mdot.setFrequencySubBand('2');
  mdot.setPublicNetwork('1');
  char id[] = "00:00:aa:00:00:00:00:01";
  mdot.setNetworkID(id);
  char key[] = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:01";
  mdot.setNetworkKey(key);
  
  //Get the settings

  //Set to defaults

  //Get the settings
}

/*--- loop() ---------------------------------------------------------------------------
  Main loop called by the Arduino framework
  --------------------------------------------------------------------------------------*/
void loop() {

}