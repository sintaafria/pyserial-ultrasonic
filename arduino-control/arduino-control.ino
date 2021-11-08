 #define relay1 2
 #define relay2 3
 #define relay3 4
 #define relay4 12
 #define echoPin1 7
 #define trigPin1 6
 #define echoPin2 4
 #define trigPin2 3

 long duration1;
 int distance1;
 long duration2;
 int distance2;
 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT);
//  pinMode(trigPin2, OUTPUT); 
//  pinMode(echoPin2, INPUT); 
}

// the loop function runs over and over again forever
void loop() {
    char key = Serial.read();
    digitalWrite(trigPin1, LOW);
//    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
//    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
//    digitalWrite(trigPin2, LOW);
    duration1 = pulseIn(echoPin1, HIGH);
//    duration2 = pulseIn(echoPin2, HIGH);
    distance1 = duration1 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
//    distance2 = duration2 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

    Serial.println(distance1);
//    Serial.print(",");
//    Serial.println(distance2);
    
    if (distance1 < 30 && distance1 > 5){
      Serial.println("y");
    }else{
      Serial.println("n");
    }
    
    if (key == '1') {
      relay(1, 0, 0);
      delay(500);
      relay(0, 0, 0);
    } 
    if (key == '2'){
      relay(0, 1, 0);
      delay(500);
      relay(0, 0, 0);
    }
    if (key == '3') {
      relay(0, 0, 1);
      delay(500);
      relay(0, 0, 0);
    }
    if (key == '4'){
      digitalWrite(relay4, HIGH);
    }
    if (key == '5'){
      digitalWrite(relay4, LOW);
    }
    delay(100);
    
}

void relay(int a, int b, int c){
  digitalWrite(relay1, a);
  digitalWrite(relay2, b);
  digitalWrite(relay3, c);
  
}
