/*  Analog mesure for Serial Plotter
 *  Giovanni Gentile
 *  giovanni@0lab.it
 *  for Earth Cloud
 *  27 Marzo 2017
 *  
 *  INSTRUCTIONS:
 *  You must set the pins in "pin probe" and
 *  set the number of sensors in "num sensors".
 *  Also you can set the number of mesure: "numbers of detections".
 */

// SETTINGS
int Sensors[] = {A0, A1, A2}; // pin probe
int numSens = 3;              // number of sensors
int numR = 100;               // numbers of detections

/*****************************************/

int Values[] = {0,0,0};
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < numSens; i++){
    pinMode(Sensors[i], INPUT);  
  }
}

void loop() {
  for (int i = 0; i < numSens; i++) {
    for (int z = 0; z < numR; z++) {
      int value = analogRead(Sensors[i]);
      Values[i] = Values[i] + value;
      delay(10);
    }
    Values[i] = Values[i]/100;
  }
  for (int i = 0; i < numSens; i++) {
    Serial.print(Values[i]);
    Serial.print(" ");
  }
  Serial.println(" ");
  delay(50);
}
