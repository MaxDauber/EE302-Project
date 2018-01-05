//Motor A
const int motorPin1  = 9;  // Pin 14 of L293
const int motorPin2  = 10;  // Pin 10 of L293
//Motor B
const int motorPin4  = 5; // Pin  7 of L293
const int motorPin3  = 6;  // Pin  2 of L293  
const int ldrRightblack=0;
//const int ldrRightred=350;
const int ldrLeftblack=0;
//const int ldrLeftred=350;
const int ldrPinRight=0;
const int ldrPinLeft=1;
const int irFront=2;
const int irRight=3;
const int irLeft=4;

void setup() {
   //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
}

void loop() {
  int ldrRight=analogRead(ldrPinRight);
  int ldrLeft=analogRead(ldrPinLeft);
  float vFront=analogRead(irFront)*0.004882815;
  int dFront=13*pow(vFront, -1);
  int i=0;
    if (dFront<=6)
    {
      stopper();
    }
  // if((ldrRight<=ldrRightred && !(ldrRight>=ldrRightblack)) || (ldrLeft<=ldrLeftred && !(ldrLeft>=ldrLeftblack)))
   {
       stopper(); 
   }
    if(ldrRight<ldrRightblack && !(ldrLeft<ldrLeftblack))
    {
      right();
    }
    else if(ldrLeft<ldrLeftblack && !(ldrRight<ldrRightblack))
    {
      left();
    }
    else 
    {
      forward();
    }
}
void forward()
{
  digitalWrite(motorPin1, HIGH); //forwardright
  digitalWrite(motorPin2, LOW); //backright
  digitalWrite(motorPin3, HIGH); //forwardleft
  digitalWrite(motorPin4, LOW); //backleft
}
void left()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(220);
}
void right()
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(80);
}
void stopper()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(100);
}
