
// ----- Back Motors ----- //
// motor one
int enA = 6;
int in1 = 2;
int in2 = 3;

// motor two
int enB = 7;
int in3 = 4;
int in4 = 5;

// ----- forward motors ----- //
// motor three
int enC = 12;
int in5 = 8;
int in6 = 9;

// motor four
int enD = 13;
int in7 = 10;
int in8 = 11;


void setup () 
{
  // back motors
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // front motors
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
}

void moveForward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);

  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC, 255);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD, 255);
}


void loop()
{
  // moveForward();
}