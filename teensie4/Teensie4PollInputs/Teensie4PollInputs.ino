#include <MIDI.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
const int channel = 1;

// Skip A11 because I only need 13 and I burnt the pad off Pin 11...
int pinsToPoll[13] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A12, A13};
int pinToPollMax = 13;

int led = 13 ; // LED on arduino
int analogVal; // analog readings


// Triggering variables & consts
int lowWaterMark[13] = {512,512,512,512,512, 512,512,512,512,512, 512,512,512};
int highWaterMark[13] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0};
int triggerWaterMark[13] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0};
bool triggerCalibrated[13] = {false,false,false,false,false, false,false,false,false,false, false,false,false};
constexpr int triggerCalibrationThreshold = 40;

// Average variables & consts
int_fast16_t headings[13] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0};
constexpr int_fast16_t fractional_bits = 1;

// Veclocity variables & consts


// Note variables
int keyVelocity[13] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0} ;


int_fast16_t average_heading(int i, int_fast16_t sample)
{
    int_fast16_t average;
    headings[i] += sample;
    average = (headings[i] - (headings[i] < 0) + (1 << (fractional_bits - 1))) >> fractional_bits;
    headings[i] -= average;
    return average;
}

void setup() {
  
  pinMode (led, OUTPUT); 

  for (int i=0; i < pinToPollMax; i++)
  {
    pinMode(pinsToPoll[i], INPUT);   
  }
  
  Serial.begin(9600);
  MIDI.begin();
}

void loop() {
  
  /*int note;
  for (note=10; note <= 127; note++) {
    MIDI.sendNoteOn(note, 100, channel);
    delay(200);
    MIDI.sendNoteOff(note, 100, channel);
  }
  delay(2000);*/

   // Read the analog interface
  
  for (int i=0; i < pinToPollMax; i++)
  {
    analogVal = analogRead(pinsToPoll[i]);
      if (analogVal < lowWaterMark[i])
      {
        lowWaterMark[i] = analogVal;
      }
      if (analogVal > highWaterMark[i])
      {
        highWaterMark[i] = analogVal;
      }

    int differenceBetweenHighAndLowWaterMark = (highWaterMark[i] - lowWaterMark[i]);
    if (differenceBetweenHighAndLowWaterMark > triggerCalibrationThreshold)
    {
      triggerCalibrated[i] = true;
    }
    triggerWaterMark[i] = lowWaterMark[i] + (0.1 * differenceBetweenHighAndLowWaterMark);
    
    //Serial.print(analogVal); // print analog value
    if (i==0)
    {

      Serial.print(lowWaterMark[i]); // print analog value
      Serial.print(",");              //seperator
      Serial.print(highWaterMark[i]); // print analog value
      Serial.print(",");              //seperator
      Serial.print(triggerWaterMark[i]); // print analog value
      Serial.print(",");              //seperator
      int_fast16_t avg = average_heading(i,analogVal);
      Serial.print(avg); // print analog value
      Serial.print(",");              //seperator
      //Serial.print(analogVal); // print analog value
      Serial.print(headings[i]); // print analog value
      
      Serial.print('\n');
    
      if ( avg < triggerWaterMark[i] && triggerCalibrated[i])
      {
        if ( keyVelocity[i] == 0 )
        {
          keyVelocity[i] = 100;  
          MIDI.sendNoteOn(80, keyVelocity[i], channel);
          digitalWrite (led, HIGH);
        }
      } else {
        if ( keyVelocity[i] > 0 )
        {
          keyVelocity[i] = 0;
          MIDI.sendNoteOff(80, keyVelocity[i], channel);
          digitalWrite (led, LOW);
        }
      }
              
    }
    //Serial.print(",");              //seperator
  }
  //Serial.print('\n');        
  delay(50);
}
