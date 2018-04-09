
#include<Servo.h>

Servo myservo3;   //gripper
Servo myservo5;   //shoulder
Servo myservo6;   //shoulder
Servo myservo9;   //wrist
Servo myservo10;   //elbow
Servo myservo11;   //base

char A;
char X;// variable to receive data from the serial port 
char E;


int val = 0;    //gripper
int val1=0;   //wrisht
int val2 = 0;   //elbow
int val3 = 0;   //shoulder
int val4 = 0;   //base

int temp = 0;    //gripper
int temp1=0;   //wrisht
int temp2 = 0;   //elbow
int temp3 = 0;   //shoulder
int temp4 = 0;   //base
int i=0;
int j=0;
int k=0;
int l=0;


void setup() 
{ 

myservo3.attach(3);
  myservo5.attach(5);
  myservo6.attach(6);
  myservo9.attach(9);
  myservo10.attach(10);
  myservo11.attach(11);
Serial.begin(9600); // start serial communication at 115200bps 

} 

void loop() 
{ 
  if( Serial.available() ) // if data is available to read 
  { 
  ; 
  } 
  A = Serial.read(); // read serial and store it in 'val' 
   

  switch ( A )
 {
  
 //gripper
  
    case 0x43:
 
         myservo3.write(120);
         Serial.print("GRAB: ");
            
         delay(15);  
         break;

    case 0x44:
  
          myservo3.write(0); 
          Serial.print("RELEASE: "); 
          delay(15);  
          break;
        
//wrist
  
 case 0x38:
    //up
    
            val1=val1+1;
            if( val1>=0 && val1<=30)
            {
            temp1=val1;
            temp1 = map(temp1, 0, 30, 0, 179);
         
           myservo9.write(temp1);
            Serial.print("u: ");
            Serial.println(val1);
            }
      break;
  

 case 0x32:
    //down
        
            val1=val1-1;
            if( val1>=0 && val1<=30)
            {
            temp1=val1;
            temp1 = map(temp1, 0, 30, 0, 179);
         
            myservo9.write(temp1);  
             Serial.print("d: ");
            Serial.println(val1);
            }
    break;

  //base
 
 case 0x34:
 //left
              val4=val4+1;
              if( val4>=0 && val4<=30)
              {
              temp4=val4;
              temp4 = map(temp4, 0, 30, 0, 179);
           
             myservo11.write(temp4);
              Serial.print("L: ");
              Serial.println(val4);
              }
      break;
case 0x36:
    //right
               val4=val4-1;
              if( val4>=0 && val4<=30)
              {
              temp4=val4;
              temp4 = map(temp4, 0, 30, 0, 179);
           
              myservo11.write(temp4);  
               Serial.print("R: ");
              Serial.println(val4);
              }  
      break;
  
  //elbow

  case 0x45:
      
        
            for(val2 = j; val2 <= 180; val2 += 1)
            {                                 
             if((X = Serial.read())==0x45 ) 
           { 
                Serial.print("------PRESS-------");
            
               break;
                
           } else{
              i=val2;
              temp2=val2;
              temp2 = map(temp2, 0, 180, 0, 180);
              Serial.print("elbow: ");
              Serial.println(val2);
           
              myservo10.write(temp2);
             delay(15);
             
              }
            }
            
           delay(2000);
                for(val2 = i ; val2>=0; val2-=1)     
                {                                
                 if( (X = Serial.read())==0x45 )
               { 
                
                Serial.print("------------- ");
                
                  
                     break;
                    
               } else{
                  j=val2;
                  temp2=val2;
                  temp2 = map(temp2, 0, 180, 0, 180);
                  Serial.print("elbow: ");
                  Serial.println(val2);
              
                  myservo10.write(temp2);
                 delay(15);
                 
                  } 
                } 
            
                  

    break;

 

  //shoulder
  case 0x46:
     
               for(val3 = k; val3 <= 180; val3 += 1)
            {                                 
             if((X = Serial.read())==0x46 ) 
           { 
                Serial.print("------PRESS-------");
            
               break;
                
           } else{
              l=val3;
              temp3=val3;
              temp3 = map(temp3, 0, 180, 0, 180);
              Serial.print("shoulder: ");
              Serial.println(val3);
               myservo5.write(temp3);
                  myservo6.write(temp3);
             delay(15);
             
              }
            }
            
           delay(2000);
                for(val3 = l ; val3>=0; val3-=1)     
                {                                
                 if( (X = Serial.read())==0x46 )
               { 
                
                Serial.print("------------- ");
                
                  
                     break;
                    
               } else{
                  k=val3;
                  temp3=val3;
                  temp3 = map(temp3, 0, 180, 0, 180);
                  Serial.print("shoulder: ");
                  Serial.println(val3);
                  myservo5.write(temp3);
                  myservo6.write(temp3);
                 delay(15);
                 
                  } 
                } 
            
                  
    break;

}
  }



