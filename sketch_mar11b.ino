
#define echoPin1 23 
#define trigPin1 22 

#define echoPin2 36 
#define trigPin2 37

#define echoPin3 50 
#define trigPin3 51

// defines variables for ultrasonic sensor

//DRAIN-1 VARIABLES
long duration1; // variable for the duration of sound wave travel
int distance1; // variable for the distance measurement

//DRAIN-2 VARIABLES
long duration2; // variable for the duration of sound wave travel
int distance2; // variable for the distance measurement

//DRAIN-3 VARIABLES
long duration3; // variable for the duration of sound wave travel
int distance3; // variable for the distance measurement

int RED1 = 12;
int GREEN1 = 13;
int BLUE1 = 2;

int RED2 = 3;
int GREEN2 = 4;
int BLUE2 = 5;

int RED3 = 6;
int GREEN3 = 7;
int BLUE3 = 8;

// deine variables for water-level sensor
const int BUTTON1 = 9;
const int BUTTON2 = 10;
const int BUTTON3 = 11;

int BUTTONstate1 = 0;
int BUTTONstate2 = 0;
int BUTTONstate3 = 0;

void setup() {
  // for ultrasonic sensor
  pinMode(RED1, OUTPUT);
  pinMode(BLUE1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

  //for water-level sensor
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:

//  DRAIN-1
    // Clears the trigPin condition
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  //DRAIN-2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distance2 = duration2 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  //DRAIN-3
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration3 = pulseIn(echoPin3, HIGH);
  // Calculating the distance
  distance3 = duration3 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance3: ");
  Serial.print(distance3);
  Serial.println(" cm");

  
  BUTTONstate1 = digitalRead(BUTTON1);
  BUTTONstate2 = digitalRead(BUTTON2);
  BUTTONstate3 = digitalRead(BUTTON3);


 //DRAIN-1 LEVEL CHECKING
  if( (BUTTONstate1 == HIGH) || (distance1 <= 10)){
    digitalWrite(RED1, HIGH);
    delay(100);
    digitalWrite(BLUE1, LOW);
    digitalWrite(GREEN1, LOW);

  }
  else if(distance1 >10 && distance1 <= 20){
    if(BUTTONstate1 == HIGH ){
      digitalWrite(RED1, HIGH);
    delay(100);
    digitalWrite(BLUE1, LOW);
    digitalWrite(GREEN1, LOW);
    }
    digitalWrite(RED1, LOW);
    digitalWrite(BLUE1, HIGH);
    digitalWrite(GREEN1, LOW);

  }
  else if(distance1 >20 || distance1 < 28){
    if(BUTTONstate1 == HIGH ){
      digitalWrite(RED1, HIGH);
    delay(100);
    digitalWrite(BLUE1, LOW);
    digitalWrite(GREEN1, LOW);
    }
    
    digitalWrite(RED1, LOW);
    digitalWrite(BLUE1, LOW);    
    digitalWrite(GREEN1,HIGH);

  }

//  //DRAIN-2 LEVEL CHECKING
  if( (BUTTONstate1 == HIGH) || (distance1 <= 10)){
    digitalWrite(RED1, HIGH);
    delay(100);
    digitalWrite(BLUE1, LOW);
    digitalWrite(GREEN1, LOW);

  }
  else if(distance2 >10 && distance2 <= 20){
    if(BUTTONstate2 == HIGH ){
      digitalWrite(RED2, HIGH);
    delay(100);
    digitalWrite(BLUE2, LOW);
    digitalWrite(GREEN2, LOW);
    }
    digitalWrite(RED2, LOW);
    digitalWrite(BLUE2, HIGH);
    digitalWrite(GREEN2, LOW);

  }
  else if(distance2 >20 || distance2 < 28){
    if(BUTTONstate2 == HIGH ){
      digitalWrite(RED2, HIGH);
    delay(100);
    digitalWrite(BLUE2, LOW);
    digitalWrite(GREEN2, LOW);
    }
    
    digitalWrite(RED2, LOW);
    digitalWrite(BLUE2, LOW);    
    digitalWrite(GREEN2,HIGH);

  }
//
//  //DRAIN-3 LEVEL CHECKING
  if( (BUTTONstate3 == HIGH) || (distance3 <= 10)){
    digitalWrite(RED3, HIGH);
    delay(100);
    digitalWrite(BLUE3, LOW);
    digitalWrite(GREEN3, LOW);

  }
  else if(distance3 >10 && distance3 <= 20){
    if(BUTTONstate3 == HIGH ){
      digitalWrite(RED3, HIGH);
    delay(100);
    digitalWrite(BLUE3, LOW);
    digitalWrite(GREEN3, LOW);
    }
    digitalWrite(RED3, LOW);
    digitalWrite(BLUE3, HIGH);
    digitalWrite(GREEN3, LOW);

  }
  else if(distance3 >20 || distance3 < 28){
    if(BUTTONstate3 == HIGH ){
      digitalWrite(RED3, HIGH);
    delay(100);
    digitalWrite(BLUE3, LOW);
    digitalWrite(GREEN3, LOW);
    }
    
    digitalWrite(RED3, LOW);
    digitalWrite(BLUE3, LOW);    
    digitalWrite(GREEN3,HIGH);

  }
 
  delay(1000);
}
