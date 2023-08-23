#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define PCA9685_ADDR 0x40
#define NUM_CHANNELS 16
#define PWM_FREQ 50

#define LED_CASE_1 3
#define LED_CASE_2 5
#define LED_CASE_3 7
#define LED_CASE_4 9

uint8_t position_x = 0; // khai báo biến vị trí x
uint8_t position_y = 0; // khai báo biến vị trí y
uint8_t angle = 0; 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(PCA9685_ADDR);

void setup() {
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(PWM_FREQ);

}

void sendPWM(int channel, int on, int off) {
  pwm.setPWM(channel, on, off);
}
/*
void moveServos1() {


}
void moveServos2() {
  for (int angle = 0; angle <= 120; angle++) {
    int pwm2 = map(angle, 0, 180, 90, 575);
    pwm.setPWM(1, 0, pwm2); 
    pwm.setPWM(3, 0, pwm2);   
    delay(10);
  }

}
int angleToPusle (int ang){
int pulse = map (ang,0,180,90,575);
return pulse;
}


void moveServos4() {
  for (int angle = 0; angle <= 5; angle++) {
    int pwm1 = map(angle, 0, 180, 90, 575);
    int pwm2 = map(angle, 0, 180, 90, 575);
    int pwm3 = map(angle, 0, 180, 90, 575);
    pwm.setPWM(0, 0, pwm1);
    pwm.setPWM(1, 0, pwm1);
    pwm.setPWM(2, 0, pwm2);
    pwm.setPWM(3, 0, pwm2);
    pwm.setPWM(4, 0, pwm3);
    pwm.setPWM(5, 0, pwm3);
    delay(10);
  }
}
*/


void loop() {
  if (Serial.available() > 0) {
    int command = Serial.read();
    switch (command) {
      case '1':
        //moveServos1();
      while(1)
        {//--------------------------------------//
          Serial.read();
          for(int i=350;i>300;i--)
          
          {
            pwm.setPWM(0, 0, i );
            delay(50);

          }
          for(int i=475;i>425;i--)
          {
            pwm.setPWM(1, 0, i );
            delay(50);
          }          
          for(int i=280;i<350;i++)
          {
            //pwm.setPWM(2, 0, i );
            pwm.setPWM(3, 0, i );
            delay(50);
          }
          for(int i=230;i<232;i++)
          {
            pwm.setPWM(2, 0, i );
            //pwm.setPWM(3, 0, i );
            delay(100);
          }
          // IF uart read not 1 or 0 break
          if(Serial.peek() != '1')
          {
            break; 
          }

          //For stream uart
          //else if(Serial.peek() != '0')
          //{
          //  break;
          //}          
        }//--------------------------------------//
      break; 
      case '2':
          while(2)
        {//--------------------------------------//
          Serial.read();
            Serial.print("case2");

          for(int i=575;i>475;i--)
          {
            //pwm.setPWM(0, 0, i );
            //delay(10);
            pwm.setPWM(1, 0, i );
            delay(50);
          }
          for(int i=280;i<340;i++)
          {
            pwm.setPWM(0, 0, i );
            delay(50);


          }
          
          for(int i=280;i<340;i++)
          {
            pwm.setPWM(2, 0, i );
            pwm.setPWM(3, 0, i );            
            delay(50);

          }
                    if(Serial.peek() != '1')
          {
            break; 
          }
     

        
        }
break;        
      case '3':
          while(3)
        {//--------------------------------------//
          Serial.read();
          

          for(int i=350;i>300;i--)
          {
            pwm.setPWM(0, 0, i );
            delay(100);

          }
          for(int i=230;i>232;i--)
          {

            pwm.setPWM(1, 0, i );
            delay(100);
          }
          for(int i=280;i<360;i++)
          {
            pwm.setPWM(2, 0, i );          
            delay(100);

          }
          for(int i=260;i<280;i++)
          {
            pwm.setPWM(3, 0, i );            
            delay(100);

          }
                    if(Serial.peek() != '1')
          {
            break; 
          }

        
        }  
break;
      case '4':
          while(4)
        {//--------------------------------------//
          Serial.read();

          for(int i=500;i>470;i--)
          {
            pwm.setPWM(0, 0, i );
            delay(100);

          }
          for(int i=400;i<500;i++)
          {

            pwm.setPWM(1, 0, i );
            delay(100);
          }
          for(int i=220;i<280;i++)
          {
            pwm.setPWM(2, 0, i );          
            delay(50);

          }
          for(int i=260;i<280;i++)
          {
            pwm.setPWM(3, 0, i );            
            delay(100);

          }
                          if(Serial.peek() != '1')
          {
            break; 
          }

        
        }  
      default:
        break;
    }
  }
}

/*void loop() {
  if (Serial.available() > 0) {
    int data_rx = Serial.read();
    switch (data_rx) {
      case '0':
        position_x = position_x; // cập nhật vị trí hiện tại
        position_y = position_y; // cập nhật vị trí hiện tại
        break;
      case '1': // up left corner
        digitalWrite(LED_CASE_1, !digitalRead(LED_CASE_1)); // toggle trạng thái của LED_CASE_1
        if (position_x < 180) {position_x--;}
        if (position_y < 180) {position_y++;}
        Serial.print('case1');
        break;
      case '2': // up right corner
        digitalWrite(LED_CASE_2, !digitalRead(LED_CASE_2)); // toggle trạng thái của LED_CASE_2
        if (position_x > 0){position_x++;}
        if (position_y < 180) {position_y++;}
        Serial.print('case1');

        break;
      case '3': // down left corner
        digitalWrite(LED_CASE_3, !digitalRead(LED_CASE_3)); // toggle trạng thái của LED_CASE_3
        if (position_x < 180) {position_x--;}
        if (position_y > 0) {position_y--;}
        Serial.print('case1');

        break;
      case '4': // down right corner
        digitalWrite(LED_CASE_4, !digitalRead(LED_CASE_4)); // toggle trạng thái của LED_CASE_4
        if (position_x > 0) {position_x++;}
        if (position_y > 0) {position_y--;}
        Serial.print('case1');

        break;
    }
  }
// Dong co theo y    
Serial.print("position y: ");
Serial.println(position_y);
moveServos1(position_y);
// Dong co theo x
Serial.print("position x: ");
Serial.println(position_x);
}*/
  