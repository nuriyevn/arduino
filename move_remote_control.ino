// moving forward backward stop via infra red remote control
// trying to turn left and right

#include <IRremote.h>

const int RECV_PIN = 7;

const char MOVE_FORWARD = '+';
const char STOP_MOVING = 0;
const char MOVE_BACKWARD = '-';
const char TURN_LEFT = '>';
const char TURN_RIGHT = '<';

#define IN1 3 // MOTOR A LEFT WHEELS
#define IN2 4 // MOTOR A LEFT WHEELS
#define IN3 5 // MOTOR B RIGHT WHEELS
#define IN4 6 // MOTOR B RIGHT WHEELS

IRrecv irrecv(RECV_PIN);
int  moveAll = STOP_MOVING;

void setup() {
 
  Serial.begin(9600);
  irrecv.enableIRIn();
  //irrecv.blink13(true);
  Serial.println("Crazy Bus is ready to start!");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.println("STOPPED");
}



void loop() {

  if (moveAll == STOP_MOVING)
  {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
  }
  else
  {
    if (moveAll == MOVE_FORWARD)
    { 
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
       
    }
    else if (moveAll == MOVE_BACKWARD)
    {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }
    else if (moveAll == TURN_RIGHT)
    {
        /*digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);*/
        
        
        digitalWrite(IN1, HIGH); // LEFT WHEELS FORWARD
        digitalWrite(IN2, LOW); // LEFT WHEELS FORWARD

        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        //delay(1000);
      
        //digitalWrite(IN3, LOW); // RIGHT WHEELS BACKWARD
        //digitalWrite(IN4, HIGH); // RIGHT WHEELS BACKWARD
        
        
    }
    else if (moveAll == TURN_LEFT)
    {
        /*digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        delay(1000);*/
      
        //digitalWrite(IN1, LOW);  // LEFT WHEELS BACKWARD
        //digitalWrite(IN2, HIGH);  // LEFT WHEELS BACKWARD

        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        
        digitalWrite(IN3, HIGH); // RIGHT WHEELS FORWARD
        digitalWrite(IN4, LOW); // RIGHT WHEELS FORWARD
        //delay(1000);
    }
  }  
  
  if (irrecv.decode()){

           switch (irrecv.results.value)
           {
              case 0xFF30CF:
                  Serial.println("1");
                  break;
              case 0xFF18E7:
                  Serial.println("2");
                  break;
              case 0xFF7A85:
                  Serial.println("3");
                  break;
              case 0xFF10EF:
                  Serial.println("4");
                  break;
              case 0xFF38C7:
                  Serial.println("5");
                  break;
              case 0xFF5AA5:
                  Serial.println("6");
                  break;
              case 0xFF42BD:
                  Serial.println("7");
                  break;
              case 0xFF4AB5:
                  Serial.println("8");
                  break;
              case 0xFF52AD:
                  Serial.println("9");
                  break;
              case 0xFFA25D:
                  Serial.println("CH-");
                  break;
              case 0xFF629D:
                  Serial.println("CH");
                  break;
              case 0xFFE21D:
                  Serial.println("CH+");
                  break;
              case 0xFF22DD:
                  Serial.println("|<<");
                  moveAll = TURN_LEFT;
                  Serial.println("TURN_LEFT");
                  break;
              case 0xFF02FD:
                  Serial.println(">>|");
                  moveAll = TURN_RIGHT;
                  Serial.println("TURN_RIGHT");
                  break;
              case 0xFFC23D:
                  Serial.println(">||");
                  break;
              case 0xFFE01F:
                  Serial.println("-");
                  moveAll = MOVE_BACKWARD;
                  Serial.println("MOVE_BACKWARD");
                  break;
              case 0xFFA857:
                  Serial.println("+");
                  moveAll = MOVE_FORWARD;
                  Serial.println("MOVE_FORWARD");
                  break;
              case 0xFF906F:
                  Serial.println("EQ");
                  break;
              case 0xFF6897:
                  Serial.println("0");
                  moveAll = STOP_MOVING;
                  Serial.println("STOPPED");
                  break;
              case 0xFF9867:
                  Serial.println("100+");
                  break;
              case 0xFFB04F:
                  Serial.println("200+");
                  break;
              default:
                  Serial.println( irrecv.results.value, HEX);
                  break;
           }
        irrecv.resume();
    }
}
