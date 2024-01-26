// motor one
int enA = 6; // 6
int in1 = 2; // 2
int in2 = 3; // 3

// motor two
int enB = 9; // 9
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

void moveClockwise()
{
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);

}

void moveCounterClockwise()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 125);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 125);

}

void loop()
{
  moveClockwise();
  delay(2000);
  moveCounterClockwise();
  delay(2000);
}