
// motor one
const int negR = 4;
const int posR = 5;

// motor two
const int negL = 6;
const int posL = 7;

const int pwmR=9;
const int pwmL=10;

const int irD1=A3;
const int irD2=A2;
const int irD3=A1;

const int Rspeed=200;
const int Lspeed=200;
byte IRstatus=0;


void setup() {
  // set all the motor control pins to outputs
  pinMode(pwmR, OUTPUT);
  pinMode(negR,OUTPUT);
  pinMode(posR,OUTPUT);
  
  pinMode(pwmL, OUTPUT);
  pinMode(negL,OUTPUT);
  pinMode(posL,OUTPUT);
  
  pinMode(irD1,INPUT_PULLUP);
  pinMode(irD2,INPUT_PULLUP);
  pinMode(irD3,INPUT_PULLUP);
  
  Serial.begin(9600);

}


void loop()
{
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;
 
  IRstatus=0;
  val1 = analogRead(irD1);
  if(val1 >= 150) {
    IRstatus=(IRstatus + 4);
  }
  val2 = analogRead(irD2);
  if(val2 >= 150) {
    IRstatus=(IRstatus + 2);
  }
  val3 = analogRead(irD3);
  if(val3 >= 150) {
    IRstatus=(IRstatus + 1);
  }

  
  Serial.print("val1 : ");
  Serial.println(val1);
  Serial.print("val2 : ");
  Serial.println(val2);
  Serial.print("val3 : ");
  Serial.println(val3);
  Serial.println(" ");
  delay(200);
}


void driveMotor(byte IRstatus) {
  switch(IRstatus)
  {
    case 0:
      forward(Rspeed, Lspeed);
      break;
    case 1:
      right(1, Rspeed, Lspeed);
      break;
    case 2:
      forward(Rspeed, Lspeed);
      break;
    case 3:
      right(0, Rspeed, Lspeed);
      break;
    case 4:
      left(1, Rspeed, Lspeed);
      break;
    case 5:
      pause(0, 0);
      break;
    case 6:
      left(0, Rspeed, Lspeed);
      break;
    case 7:
      pause(0, 0);
      break;
  }
}


void forward(byte RmotorSpeed, byte LmotorSpeed) {
  analogWrite(pwmR, RmotorSpeed);
  analogWrite(pwmL, LmotorSpeed);
  digitalWrite(posR, HIGH);
  digitalWrite(negR, LOW);
  digitalWrite(posL, LOW);
  digitalWrite(negL, HIGH);
}


void back(byte RmotorSpeed, byte LmotorSpeed) {
  analogWrite(pwmR, RmotorSpeed);
  analogWrite(pwmL, LmotorSpeed);
  digitalWrite(posR, LOW);
  digitalWrite(negR, HIGH);
  digitalWrite(posL, HIGH);
  digitalWrite(negL, LOW);
}



void pause(byte RmotorSpeed, byte LmotorSpeed) {
  analogWrite(pwmR, RmotorSpeed);
  analogWrite(pwmL, LmotorSpeed);
  digitalWrite(posR, LOW);
  digitalWrite(negR, LOW);
  digitalWrite(posL, LOW);
  digitalWrite(negL, LOW);
}


void right(byte flag, byte RmotorSpeed, byte LmotorSpeed) {
  analogWrite(pwmR, RmotorSpeed);
  analogWrite(pwmL, LmotorSpeed);
  if (1 == flag) {
    // right motor reverse, left motor reverse.
    digitalWrite(posR, LOW);
    digitalWrite(negR, HIGH);
    digitalWrite(posL, LOW);
    digitalWrite(negL, HIGH);
  } else {
    // right motor stop, left motor reverse.
    digitalWrite(posR, LOW);
    digitalWrite(negR, LOW);
    digitalWrite(posL, LOW);
    digitalWrite(negL, HIGH);
  }
}


void left(byte flag, byte RmotorSpeed, byte LmotorSpeed) {
  analogWrite(pwmR, RmotorSpeed);
  analogWrite(pwmL, LmotorSpeed);
  if (1 == flag) {
    // right motor reverse, left motor reverse.
    digitalWrite(posR, HIGH);
    digitalWrite(negR, LOW);
    digitalWrite(posL, HIGH);
    digitalWrite(negL, LOW);
  } else {
    // right motor stop, left motor reverse.
    digitalWrite(posR, HIGH);
    digitalWrite(negR, LOW);
    digitalWrite(posL, LOW);
    digitalWrite(negL, LOW);
  }
}



