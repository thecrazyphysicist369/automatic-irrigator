// Plug the relay into Digital Pin 13
// code to define the function for storing signal values in an array after calibrating

// the setup routine runs once when you press reset:
#include <LiquidCrystal.h>

// Setup the LiquidCrystal library with the pin numbers we have
// physically connected the module to.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int relay = 13; 


//string to display during the initialization phase
char* init_text[] = {
  "  Squirter_69  ",
  "initializing...",
  
};

char* change_text[] = {
  "  Squirter_69  ",
  "initializing...",
  
};

char* display_text[]{
  "K_1 K_2 TTO H20"
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    pinMode(relay, OUTPUT);
  
  // Setup the number of columns and rows that are available on the LCD.
  lcd.begin(16, 2);

  //printing init statements
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print(init_text[0]);
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print(init_text[1]);
  delay (3000);
}



void loop() {
  // put your main code here, to run repeatedly:
  long sensorValue1 = analogRead(A1);
  // read the input on analog pin 2:
  long sensorValue2 = analogRead(A2);

  //mapping the first knob value from 1 to 24, stating interval
  long mapped_1 = map(sensorValue1, 0, 1023, 1, 24);
  //mapping the second knob value from 10 to 60, stating watering time
  long mapped_2 = map(sensorValue2, 0, 1023, 10, 60);
  
  long dupe_mapped_1 = mapped_1;
  long dupe_mapped_2 = mapped_2;

  long k_1 = mapped_1*3600;
  long k_2 = mapped_2*1000;

  Serial.print("\n starting while loop \n");
  while (k_1>1)
  {
    //if kbob value is changed in the middle of the loop
    //then the program should break and run again
    //with the new value
    if (dupe_mapped_1 != mapped_1 || dupe_mapped_2 != mapped_2)
    {
      Serial.print("\nbreaking\n");
      break;
    }

    //
    lcd.clear();
    //printint the top row with static info
    lcd.setCursor(0,0);
    lcd.print(display_text[0]);
    
    //printing hours
    lcd.setCursor(0,1);
    lcd.print(mapped_1);
    lcd.setCursor(2,1);
    lcd.print("h");
    
    //printing seconds
    lcd.setCursor(4,1);
    lcd.print(mapped_2);
    lcd.setCursor(6,1);
    lcd.print("s");

    //printing time to open
    lcd.setCursor(8,1);
    lcd.print(k_1);
    Serial.println(k_1);
    lcd.setCursor(13,1);
    lcd.print("s");

    if (k_1==5) //water turns on!!!
    {
    //displaying in the display
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("WATERING PLANTS");
    lcd.setCursor(0,1);
    lcd.print("YUM! YUM! YUM!");

    digitalWrite(relay, HIGH); // Turn the relay on
    delay(k_2);
    digitalWrite(relay, LOW); // Turn the relay Off
    }

    //re-reading values to detect change in the middle of the loop
    sensorValue1 = analogRead(A1);
    // read the input on analog pin 2:
    sensorValue2 = analogRead(A2);

    //mapping the first knob value from 1 to 24, stating interval
    mapped_1 = map(sensorValue1, 0, 1023, 1, 24);
    //mapping the second knob value from 10 to 60, stating watering time
    mapped_2 = map(sensorValue2, 0, 1023, 10, 60);
  

    //printing sensor values
    Serial.print(k_1);
    Serial.print("\n");
    Serial.print("dupe 1: ");
    Serial.print(dupe_mapped_1);
    Serial.print("\n");
    Serial.print("interval: ");
    Serial.print(mapped_1);
    Serial.print("\n");
    Serial.print("dupe 2: ");
    Serial.print(dupe_mapped_2);
    Serial.print("\n");
    Serial.print("water_time: ");
    Serial.print(mapped_2);
    Serial.print("\n");
    Serial.print("\n");
    
    k_1--;
    delay(1000); //each iteration takes 1 second

}

}
