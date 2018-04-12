const int  pulseline = 2;    
const int cntrl = 13;      

// Variables will change:
int count = 0;   
int presState = 0;         
int preState = 0;     

void setup() {
  
  pinMode(pulseline, INPUT);
  pinMode(cntrl, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  presState = digitalRead(pulseline);
  if (presState != preState) {
    if (presState == HIGH) {
      count++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(count);
    } else {
      Serial.println("off");
    }
    delay(50);
  }
  preState = presState;

  if (count == 20) {
    digitalWrite(cntrl, LOW);
  } else {
    digitalWrite(cntrl, HIGH);
  }

}
