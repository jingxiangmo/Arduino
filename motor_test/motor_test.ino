// motor one
int enA = 6; // 6
int in1 = 2; // 2
int in2 = 3; // 3

// motor two
int enB = 7; // 9
int in3 = 4; // 4
int in4 = 5; // 5


void setup () 
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void moveForward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);

}



void loop()
{
  moveForward();
  delay(2000);
}