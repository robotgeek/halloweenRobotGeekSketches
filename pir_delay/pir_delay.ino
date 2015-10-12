/***********************************************************************************
 *        ___                                            ___
 *      _/ ..\          RobotGeek Halloween             /.. \_
 *     ( \  0/__        Floor Mat Scare System        __\0  / )
 *      \    \__)                                    (__/    /   
 *      /     \                                        /     \
 *     /      _\                                      /_      \
 *     `"""""``                                        `"""""``
 *
 *  This sketch will read from a PIR Sensor and then
 *  activate a digital output(like a relay) for a certain number of seconds. 
 *
 *
 *    Project Guide
 *      http://learn.robotgeek.com/projects/211-robotgeek-halloween-how-to.html 
 
 *  WIRING
 *    Servos
 *      Digital I/O 2 - PIR Sensor (black/red/white pins)
 *      Digital I/O 4 - Powerswitch tail or RobotGeek Relay
 *      Digital I/O 7 - RobotGeek Relay if you are connecting multiple devices
 *      Digital I/O 8 - RobotGeek Relay if you are connecting multiple devices
 *
 *
 *
 *  NOTES
 *    You can change the value after DELAY_AFTER_START to change the time that the relay will be held high, in milliseconds
 *    You can change the value after DELAY_BEFORE_START to change the time between stepping on the mat and setting the relays high
 *    - this is great for surprising people who know there is a system/mat
 *       
 *    This code will activate 3 digitial pins (4/7/8). If you are not using the second and third pins, you can still
 *    use this code without modification, just don't hook up anything. If you need those 2 pins for ther purposes
 *    remove the applicable code in the setup and loop functions (see comments)
 *
 *  This code is a Work In Progress and is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
 *   
 ***********************************************************************************/
 
//Pin numbers for Digital I/O 
#define PIR_PIN 2
#define RELAY_PIN1 4
#define RELAY_PIN2 7
#define RELAY_PIN3 8

//timing definitions
#define DELAY_BEFORE_START 0
#define DELAY_AFTER_START 5000

int PIRState = LOW;            //whtether the pir sensor is active (HIGH) or inactive(LOW)
int previousPIRState = LOW;    // state of the PIR sensor in the last loop

void setup() 
{
  pinMode(RELAY_PIN1, OUTPUT);  //set the pin to output for the relay
  pinMode(RELAY_PIN2, OUTPUT);  //set the pin to output for the relay. You can remove this line if you are only using  one relay
  pinMode(RELAY_PIN3, OUTPUT);  //set the pin to output for the relay . You can remove this line if you are only using one or two relays 
  pinMode(PIR_PIN, INPUT);  //set the pin to input for PIR
}
void loop() 
{
  PIRState = digitalRead(PIR_PIN);  //read the current state of the PIR sensor

   //only activate the relays if the PIR sensor is HIGH(Active) and the last read was LOW(inactive) This prevents the system going off repeatledy while the same person stands in front of it
  if(PIRState == HIGH && previousPIRState == LOW)
{
    delay(DELAY_BEFORE_START);
    digitalWrite(RELAY_PIN1, HIGH);          //write the relay to HIGH(active)
    digitalWrite(RELAY_PIN2, HIGH);          //write the state to HIGH(active)  remove this line if you are only using 1 relay
    digitalWrite(RELAY_PIN3, HIGH);          //write the state to HIGH(active)  remove this line if you are only using 1 or 2 relays
    delay(DELAY_AFTER_START);
    digitalWrite(RELAY_PIN1, LOW);          //write the state to LOW(inactive)
    digitalWrite(RELAY_PIN2, LOW);          //write the state to LOW(inactive)  remove this line if you are only using 1 relay
    digitalWrite(RELAY_PIN3, LOW);          //write the state to LOW(inactive)  remove this line if you are only using 1 or 2 relays
  }


  previousPIRState = PIRState;   //record the PIR state for the next loop

}
