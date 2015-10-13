/***********************************************************************************
 *        ___                                            ___
 *      _/ ..\          RobotGeek Halloween             /.. \_
 *     ( \  0/__        Floor Mat Scare System        __\0  / )
 *      \    \__)                                    (__/    /   
 *      /     \                                        /     \
 *     /      _\                                      /_      \
 *     `"""""``                                        `"""""``
 *
 *  This sketch will read from a momentary pushbutton (like a floor mat switch) and then
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
 *    This project will wire the floor mat directly to the geekduino without any resitors. This means that
 *    the mat must be read using the internal pullup resitor on the geekduino. When the floor mat is inactive,
 *    the geekduino will read a HIGH and when the mat is inactive, it will read a LOW. This is inverse from the normal
 *    HIGH(active)/LOW(inactive) convention
 *
 *    This code will activate the relay once it has detected the floor mat switch has gone from inactive
 *    to active. It will not activate again until the switch goes back to inactive - this means that 
 *    the relay will only turn on again after someone has stepped off the mat.
 *
 *    You can change the value after DELAY_AFTER_START to change the time that the relay will be held high, in milliseconds
 *    You can change the value after DELAY_BEFORE_START to change the time between stepping on the mat and setting the relays high
 *    - this is great for surprising people who know there is a system/mat
 *    
 *    This code will activate 3 digitial pins (4/7/8). If you are not using the second and third pins, you can still
 *    use this code without modification, just don't hook up anything. If you need those 2 pins for other purposes
 *    remove the applicable code in the setup and loop functions (see comments)
 *
 *  This code is a Work In Progress and is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
 *   
 * ASCII Art from http://www.chris.com/ascii/joan/www.geocities.com/SoHo/7373/haloween.html
 ***********************************************************************************/
 
//Pin numbers for Digital I/O 
#define FLOOR_MAT_PIN 2
#define RELAY_PIN1 4
#define RELAY_PIN2 7
#define RELAY_PIN3 8

//timing definitions
#define DELAY_BEFORE_START 0
#define DELAY_AFTER_START 5000

int floorMatState = HIGH;            //whether the floor mat is being read as inactive(high) or active (low)
int previousFloorMatState = HIGH;    //state of the mat on the previous loop

void setup() 
{
  pinMode(RELAY_PIN1, OUTPUT);  //set the pin to output for the relay
  pinMode(RELAY_PIN2, OUTPUT);  //set the pin to output for the relay. You can remove this line if you are only using  one relay
  pinMode(RELAY_PIN3, OUTPUT);  //set the pin to output for the relay . You can remove this line if you are only using one or two relays 
  pinMode(FLOOR_MAT_PIN, INPUT_PULLUP);  //the floor mat is connected directly to the arduino, so it needs to be setup as an input with a pullup resistor. This means that the mat will normally read as HIGH and only return a LOW when the mat is activated 
}

void loop() 
{
  floorMatState = digitalRead(FLOOR_MAT_PIN);  //read the current state of the floor mat 
  
  //only activate the relays if the floor mat is LOW(Active) and the last read was HIGH(inactive) This prevents the system going off repeatledy while someone stands on the mat
  if(floorMatState == LOW && previousFloorMatState == HIGH)
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


  previousFloorMatState = floorMatState;    //record the floor mat state for the next loop

}
