#include <PS2X_lib.h>

// ----- front Motors ----- //
// motor one
int enA = 6;
int in1 = 2;
int in2 = 3;

// motor two
int enB = 7;
int in3 = 4;
int in4 = 5;

// ----- back motors ----- //
// motor three
int enC = 30;
int in5 = 22;
int in6 = 24;

// motor four
int enD = 32;
int in7 = 26;
int in8 = 28;

PS2X ps2x;
int error = 0;
byte type = 0;
byte vibrate = 0;

void setup() {
  // ----- ps2 ----- //
  Serial.begin(57600);
  error = ps2x.config_gamepad(13, 11, 10, 12, true, true);

  if (error == 0) {
    Serial.println("Found Controller, configured successful");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Go to www.billporter.info for updates and to report bugs.");
  }

  else if (error == 1) {
      Serial.println("ERROR: No controller found");
      Serial.println("you must always either restart your Arduino after you connect the controller, or call config_gamepad(pins) again after connecting the controller.");
  }

  else if (error == 2){
      Serial.println("ERROR: Controller found but not accepting commands.");
  }

  else if (error == 3){
    Serial.println("ERROR: Controller refusing to enter Pressures mode, may not support it. ");
  }

  type = ps2x.readType();
  switch (type) {
    case 0:
      Serial.println("Unknown Controller type");
      break;
    case 1:
      Serial.println("DualShock Controller Found");
      break;
    case 2:
      Serial.println("GuitarHero Controller Found");
      break;
  }


  // ----- motors ----- //
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

void moveForward() {
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

void moveBackward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);

  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enC, 255);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  analogWrite(enD, 255);
}

void moveStop(){

  analogWrite(enA, 0);
  analogWrite(enB, 0);
  analogWrite(enC, 0);
  analogWrite(enD, 0);
}

void turnLeft() {
  // Slow down or reverse left motors
  digitalWrite(in1, HIGH); // Reverse direction or LOW to slow down
  digitalWrite(in2, LOW);  // Reverse direction or HIGH to slow down
  analogWrite(enA, 128);   // Adjust speed as necessary

  digitalWrite(in5, HIGH); // Reverse direction or LOW to slow down
  digitalWrite(in6, LOW);  // Reverse direction or HIGH to slow down
  analogWrite(enC, 128);   // Adjust speed as necessary

  // Keep right motors moving forward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);

  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD, 255);
}


void turnRight() {
  // Slow down or reverse right motors
  digitalWrite(in3, HIGH); // Reverse direction or LOW to slow down
  digitalWrite(in4, LOW);  // Reverse direction or HIGH to slow down
  analogWrite(enB, 128);   // Adjust speed as necessary

  digitalWrite(in7, HIGH); // Reverse direction or LOW to slow down
  digitalWrite(in8, LOW);  // Reverse direction or HIGH to slow down
  analogWrite(enD, 128);   // Adjust speed as necessary

  // Keep left motors moving forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);

  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC, 255);
}


void ps2Controller(){
  if(error == 1){
    return; 
  }
  
 if(type == 2){
   
   ps2x.read_gamepad();          //read controller 
   
   if(ps2x.ButtonPressed(GREEN_FRET))
     Serial.println("Green Fret Pressed");
   if(ps2x.ButtonPressed(RED_FRET))
     Serial.println("Red Fret Pressed");
   if(ps2x.ButtonPressed(YELLOW_FRET))
     Serial.println("Yellow Fret Pressed");
   if(ps2x.ButtonPressed(BLUE_FRET))
     Serial.println("Blue Fret Pressed");
   if(ps2x.ButtonPressed(ORANGE_FRET))
     Serial.println("Orange Fret Pressed");
     

    if(ps2x.ButtonPressed(STAR_POWER))
     Serial.println("Star Power Command");
    
    if(ps2x.Button(UP_STRUM))          //will be TRUE as long as button is pressed
     Serial.println("Up Strum");
    if(ps2x.Button(DOWN_STRUM))
     Serial.println("DOWN Strum");
  
 
    if(ps2x.Button(PSB_START))                   //will be TRUE as long as button is pressed
         Serial.println("Start is being held");
    if(ps2x.Button(PSB_SELECT))
         Serial.println("Select is being held");
    
    if(ps2x.Button(ORANGE_FRET)) // print stick value IF TRUE
    {
        Serial.print("Wammy Bar Position:");
        Serial.println(ps2x.Analog(WHAMMY_BAR), DEC); 
    } 
 }

 else { //DualShock Controller
  
    ps2x.read_gamepad(false, vibrate);          //read controller and set large motor to spin at 'vibrate' speed

    if(ps2x.ButtonPressed(PSB_GREEN)){
      Serial.println("Triangle just pressed. MOVE FORWARD.");  
      moveForward();
    } else if(ps2x.ButtonPressed(PSB_BLUE)){
      Serial.println("X just pressed. MOVE BACKWARD.");   
      moveBackward();
    } else if(ps2x.ButtonPressed(PSB_PINK)){
      Serial.println("Square just pressed. MOVE LEFT.");   
      turnLeft();
    } else if(ps2x.ButtonPressed(PSB_RED)) {
      Serial.println("Circle just pressed. MOVE RIGHT.");
      turnRight();
    } else if (ps2x.ButtonPressed(PSB_START)){
      Serial.println("Circle just pressed. MOVE RIGHT.");
      moveStop();
    }

 }

}

void loop() {
  // Serial.print("test");

  ps2Controller();
  delay(50);
}