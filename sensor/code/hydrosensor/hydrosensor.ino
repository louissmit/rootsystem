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
  int step = 10;
  if(runtimes){
    for(r = 0; r < step; r++){
        for(g = 0; g < step; g++){
            for(b = 0; b < step; b++){
                analogWrite(red_port, r*(255/step));
                analogWrite(green_port, g*(255/step));
                analogWrite(blue_port, b*(255/step));
                Serial.print(r*(255/step));
                Serial.print(' ');
                Serial.print(g*(255/step));
                Serial.print(' ');
                Serial.println(b*(255/step));
                delay(100);
                int val=analogRead(photodiode_port);  //variable to store values from the photodiode  
//                Serial.println("sensor output:");
                delay(10);
                Serial.println(val); 
                
            }
        }
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
