/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int red_port = 9;
int green_port = 10;
int blue_port = 11;
int photodiode_port = 0;
int runtimes = 5;



// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);  
  // initialize the digital pin as an output.
  pinMode(red_port, OUTPUT);     
  pinMode(green_port, OUTPUT);     
  pinMode(blue_port, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  int r, g, b;
  float w,step;
  w=380.;
  step = 1.;
  if(runtimes){
    while(w<=650){
      // color configuration
      if(w >= 380 && w < 440){
        r = -(w - 440.) / (440. - 380.)*255;
        g = 0.0;
        b = 255.0;
      }
      if(w >= 440 && w < 490){
        r = 0.0;
        g = (w - 440.) / (490. - 440.)*255.0;
        b = 255.0;
      }
      if(w >= 490 && w < 510){
        r = 0.0;
        g = 255.0;
        b = -(w - 510.) / (510. - 490.)*255.0;
      }
      if(w >= 510 && w < 580){
        r = (w - 510.) / (580. - 510.)*255.0;
        g = 1.0;
        b = 0.0;
      }
      if(w >= 580 && w < 645){
        r = 255.0;
        g = -(w - 645.) / (645. - 580.)*255.0;
        b = 0.0;
      }
      if(w >= 645 && w < 780){
        r = 255.0;
        g = 0.0;
        b = 0.0;
      }
      analogWrite(red_port, r);
      analogWrite(green_port, g);
      analogWrite(blue_port, b);
                Serial.print(r);
                Serial.print(' ');
                Serial.print(g);
                Serial.print(' ');
                Serial.println(b);
                delay(70);
                int val=analogRead(photodiode_port);  //variable to store values from the photodiode  
//                Serial.println("sensor output:");
                delay(10);
                Serial.println(val);
              
        w+=step;
    }

    runtimes--;
  } 
  else 
  {
        analogWrite(red_port, 0);
        analogWrite(green_port, 0);
        analogWrite(blue_port, 0);
    }
}
