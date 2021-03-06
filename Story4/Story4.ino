int const reverse_left_motor = 12;
int const forward_left_motor = 11;
int const enable_left_motor = 10;
int const enable_right_motor = 9;
int const reverse_right_motor = 8;
int const forward_right_motor = 7;

const int LEFT_FEEDBACK = 3;
const int RIGHT_FEEDBACK = 2;
  
volatile int leftcounter = 0;
volatile int rightcounter = 0;


void LeftMotorISR(){
  
  leftcounter++;
}

void RightMotorISR(){
  rightcounter++;
}  


void setup()
{
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  pinMode(reverse_left_motor, OUTPUT); 
  pinMode(forward_left_motor, OUTPUT);
  pinMode(LEFT_FEEDBACK, INPUT);
  pinMode(RIGHT_FEEDBACK, INPUT);
  pinMode(enable_left_motor, OUTPUT);
  pinMode(enable_right_motor, OUTPUT);
  pinMode(reverse_right_motor, OUTPUT);
  pinMode(forward_right_motor, OUTPUT);
}

void loop()
{
  forwards_rover(0);
  Serial.print("Left Counter ");
  Serial.println(leftcounter);
  
  //Serial.print("Right Counter ");
  //Serial.println(rightcounter);
  
  if(leftcounter >=870){
    Serial.println("Stop called");
    stop_rover(100000000);
  }
}


void stop_rover(int length) {
  digitalWrite(enable_left_motor, LOW);
  digitalWrite(enable_right_motor, LOW);
  digitalWrite(forward_left_motor, LOW);
  digitalWrite(forward_right_motor, LOW);
  digitalWrite(reverse_left_motor, LOW);
  digitalWrite(reverse_right_motor, LOW);

  delay(length); 
}

void reverse_rover(int duration) {
  digitalWrite(enable_left_motor, HIGH);
  digitalWrite(enable_right_motor, HIGH);
  digitalWrite(reverse_left_motor, HIGH);
  digitalWrite(reverse_right_motor, HIGH);
  delay(duration);
}  
  
void forwards_rover(int timedelay){
  digitalWrite(enable_left_motor, HIGH);
  digitalWrite(enable_right_motor, HIGH);
  digitalWrite(forward_left_motor, HIGH);
  digitalWrite(forward_right_motor, HIGH);
  delay(timedelay);
}
