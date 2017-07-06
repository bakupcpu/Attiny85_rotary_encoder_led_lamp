/*
** Rotary Encoder Example
** Use the Sparkfun Rotary Encoder to vary brightness of LED
**
** Sample the encoder at 200Hz using the millis() function
*/

int brightness = 0;    // how bright the LED is, start at half brightness
int fadeAmount = 1;
int Light = 120;
int Fad = 0;
unsigned long currentTime;
unsigned long loopTime;
const int pin_A = 3;
const int pin_B = 4;
const int pin_C = 2;
int C;
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev=0;

void setup()  {
  // declare pin 9 to be an output:
  pinMode(1, OUTPUT);
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);
  pinMode(pin_C, INPUT);
//  currentTime = millis();
//  loopTime = currentTime; 
} 

void loop()  {
  
  // get the current elapsed time
 // currentTime = millis();
  //if(currentTime >= (loopTime + 1)){
    // 5ms since last check of encoder = 200Hz  
    encoder_A = digitalRead(pin_A);    // Read encoder pins
    encoder_B = digitalRead(pin_B);   
    if((!encoder_A) && (encoder_A_prev)){
      // A has gone from high to low 
      if(encoder_B) {
        // B is high so clockwise
        // increase the brightness, dont go over 255
        if(brightness + fadeAmount <= 255) brightness += fadeAmount;               
      }   
      else {
        // B is low so counter-clockwise      
        // decrease the brightness, dont go below 0
        if(brightness - fadeAmount >= 0) brightness -= fadeAmount;               
      }   

    }   
    encoder_A_prev = encoder_A;     // Store value of A for next time    
    
    // set the brightness of pin 9:
    analogWrite(1, brightness);   
   
    loopTime = currentTime;  // Updates loopTime

  C = digitalRead(pin_C); 
  if(C == 0 && brightness == 0){ Fad = 2; delay(200); }
  if(Fad == 2 && brightness < Light){ brightness+= fadeAmount; delay(5);}
  if(Fad == 2 && brightness == Light){ Fad = 0;}
  if(C == 0 && brightness > 1){ Light = brightness; Fad = 1; delay(50); }
  if(Fad == 1 && brightness > 0){ brightness--; delay(5);}
  if(Fad == 1 && brightness == 0){ Fad = 0;}
  
}

