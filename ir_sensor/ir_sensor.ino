// Code by Abhishek M

// define the two IR sensor inputs pins
const int Front_IR = 3;   // IR pin 1
const int Side_IR = 4;  // IR pin 2

//using the L298N, define the MOTOR in1 and in2 of the board
int in1 = 8;
int in2 = 9;

// IR sensor responds to digital HIGH and LOW (i.e 1/0) 
//start the values at 0
int Front_IR_digitalvalue = 0;
int Side_IR_digitalvalue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // define the L298N pins as an OUTPUT
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // define the IR pins as an INPUT 
  pinMode(Front_IR, INPUT);
  pinMode(Side_IR, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  int a = front();  //  Calling the "front" function: read the IR sensor positioned in the front of the robot
  if (a == 0){
    forward_motor(); // if there is no object in front of the IR sensor, a 0 value is sent to the robot and we can move forward
  }
  else if (a == 1){ // if an object is in front of the IR sensor, a 1 value is sent to the robot which signals it to move
  }
    rotate_motor();
  }
 Serial.print("\n");
  delay(100);
}


int front(){ //read the IR sensor positioned in the front of the robot
  Serial.print("FRONT Reading = "); 
  Serial.println(Front_IR_digitalvalue);
  Front_IR_digitalvalue = digitalRead(Front_IR);
  return Front_IR_digitalvalue;
}

void side(){//read the IR sensor positioned on the side of the robot
  Serial.print("SIDE Reading = ");
  Serial.println(Side_IR_digitalvalue);
  Side_IR_digitalvalue = digitalRead(Side_IR);
  rotate_motor();   
}


void forward_motor(){ //Motor would turn clokcwise
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  Serial.print("front");
}

void rotate_motor(){ ////Motor would turn anti-clokcwise
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
    Serial.print("back");
}
