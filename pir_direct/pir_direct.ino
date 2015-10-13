/***********************************************************************************
 *        ___                                            ___
 *      _/ ..\          RobotGeek Halloween             /.. \_
 *     ( \  0/__        Floor Mat Scare System        __\0  / )
 *      \    \__)                                    (__/    /   
 *      /     \                                        /     \
 *     /      _\                                      /_      \
 *     `"""""``                                        `"""""``
 *
 *  This sketch will read from a PIR sensor and then
 *  activate a digital output(like a relay) for a certain number of seconds. 
 *
 *
 *    Project Guide
 *      http://learn.robotgeek.com/projects/211-robotgeek-halloween-how-to.html 
 
 *  WIRING
 *    Servos
 *      Digital I/O 2 - Signal and Ground will be connected to the 2 leads on the floor mat
 *      Digital I/O 4 - Powerswitch tail or RobotGeek Relay
 *      Digital I/O 7 - RobotGeek Relay if you are connecting multiple devices
 *      Digital I/O 8 - RobotGeek Relay if you are connecting multiple devices
 *
 *
 *
 *  NOTES
 *    The PIR sensor when activated will stay high for several seconds - the relay will stay HIGH for as long as the sensor stays HIGH
 *
 *    
 *    This code will activate 3 digitial pins (4/7/8). If you are not using the second and third pins, you can still
 *    use this code without modification, just don't hook up anything. If you need those 2 pins for other purposes
 *    remove the applicable code in the setup and loop functions (see comments)
 *
 *  This code is a Work In Progress and is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
 *   
 *  ASCII Art From http://www.chris.com/ascii/joan/www.geocities.com/SoHo/7373/haloween.html
 ***********************************************************************************/
 
 
//Pin numbers for Digital I/O 
#define PIR_PIN 2
#define RELAY_PIN1 4
#define RELAY_PIN2 7
#define RELAY_PIN3 8

int PIRState = LOW;            //whtether the pir sensor is active (HIGH) or inactive(LOW)

void setup() 
{
  pinMode(RELAY_PIN1, OUTPUT);  //set the pin to output for the relay
  pinMode(RELAY_PIN2, OUTPUT);  //set the pin to output for the relay. You can remove this line if you are only using  one relay
  pinMode(RELAY_PIN3, OUTPUT);  //set the pin to output for the relay . You can remove this line if you are only using one or two relays 
  pinMode(PIR_PIN, INPUT);  //set the pin to input for PIR
}
void loop() 
{
  PIRState = digitalRead(PIR_PIN);      //read the current state of the PIR sensor 
  digitalWrite(RELAY_PIN1, PIRState);  ///write the state to the Relays
  digitalWrite(RELAY_PIN2, floorMatState);     //write the PIR state to the relay.  remove this line if you are only using 1 relay
  digitalWrite(RELAY_PIN3, floorMatState);     //write the PIR state to the relay.  remove this line if you are only using 1 or 2 relays

}  
