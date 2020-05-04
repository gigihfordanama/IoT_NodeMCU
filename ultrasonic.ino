
#define LED         D0        // Led pada NodeMCU  pin GPIO16 (D0).
#define triggerPin  D1        // TriggerPin pada NodeMCU  pin GPIO5 (D1).
#define echoPin     D2        // TriggerPin pada NodeMCU  pin GPIO4 (D2).

void setup() {
  
pinMode(triggerPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LED, OUTPUT);
Serial.begin(9600); 
}

void loop() {

long duration, jarak;
digitalWrite(triggerPin, LOW);
delayMicroseconds(2); 
digitalWrite(triggerPin, HIGH);
delayMicroseconds(10); 
digitalWrite(triggerPin, LOW);
duration = pulseIn(echoPin, HIGH);
jarak = (duration/2) / 29.1;
Serial.print("Jarak Sensor: ");
Serial.println(jarak);

if (jarak < 4 ){
    digitalWrite(LED, HIGH); 
    }
else {
    digitalWrite(LED, LOW); 
    }

delay(500);
}
