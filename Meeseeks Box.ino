#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 8;
const int buttonPin = 2;

int buttonState = 0;

void setup ()
{
 pinMode(ledPin1, OUTPUT);
 pinMode(ledPin2, OUTPUT);
 pinMode(ledPin3, OUTPUT);

 pinMode(buttonPin, INPUT);
 
 Serial.begin (9600);
 
 mp3_set_serial (Serial); //set Serial for DFPlayer-mini mp3 module 
 mp3_set_volume (10);
}
 
void loop ()
{
  int Save;
          
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);

    mp3_play_file_in_folder (1, 1);
    Save ++;
    
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);

      if (delay(10000))
      {
        Save --;
      }
      }
      if (buttonState == HIGH && Save == 1)
      {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);

        mp3_random_play();
        Save ++;
        
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
          if (delay(10000))
          {
            Save --;
          }
          if (buttonState == HIGH && Save == 2)
          {
            digitalWrite(ledPin1, HIGH);
            digitalWrite(ledPin2, HIGH);
            digitalWrite(ledPin3, HIGH);

            mp3_play_file_in_folder (1, 1);
            Save --;
    
            digitalWrite(ledPin1, LOW);
            digitalWrite(ledPin2, LOW);
            digitalWrite(ledPin3, LOW);
          }
      }
}
