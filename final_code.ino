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

char* display_text[]{
  "K_1 K_2 TTO H20"
};


void setup() {
  // initialize serial communication at 9600 bits per second:
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

// the loop routine runs over and over again forever:
void loop() {

  //this section is to read the potentiometer values and convert them to hours and seconds
  // read the input on analog pin 0:
  int sensorValue0 = analogRead(A0);
  // read the input on analog pin 2:
  int sensorValue1 = analogRead(A2);

  //this is the interval where the valve will be off (hours)
  int normal0= (sensorValue0-100)/30;
  //limiting the value from 0 to 24
  if (normal0<0)
  {
    normal0=0;
  }
  if (normal0>24)
  {
    normal0=24;
  }

  //this is for the time the valve will be on (seconds)
  int normal1= sensorValue1/10;
  //limitint the value from 10 to 60
  if (normal1<10)
  {
    normal1=10;
  }
  if (normal1>60)
  {
    normal1=60;
  }

  //this section is to operate the relay
  unsigned long t1=normal0*3600; //converting the hours into seconds for better control
  
  unsigned long i = t1;
  //starting the control loop
  //for(i=t1; i>0; i--) //counting down hours by each seconds
  while (i > 0)
  {

    delay(1000); //waiting for one second for each iteration

    lcd.clear();
    //printint the top row with static info
    lcd.setCursor(0,0);
    lcd.print(display_text[0]);
    
    //printing hours
    lcd.setCursor(0,1);
    lcd.print(normal0);
    lcd.setCursor(2,1);
    lcd.print("h");
    Serial.print("interval: ");
    Serial.println(normal0);
    
    //printing seconds
    lcd.setCursor(4,1);
    lcd.print(normal1);
    lcd.setCursor(6,1);
    lcd.print("s");
    Serial.print("duration: ");
    Serial.println(normal1);

    
    

    //printing time to open
    lcd.setCursor(8,1);
    lcd.print(i);
    Serial.println(i);
    lcd.setCursor(13,1);
    lcd.print("s");

    //sensor value readjustment
    // read the input on analog pin 2:
    int sensorValue1 = analogRead(A2);
    //this is for the time the valve will be on (seconds)
    int normal1= sensorValue1/10;
    //limitint the value from 10 to 60
    if (normal1<10)
    {
      normal1=10;
    }
    if (normal1>60)
    {
      normal1=60;
    }
    int t2=normal1*1000; //converting the seconds to miliseconds for delay control
    //water turns on!!!
    if(i==10)
    {
    //displaying in the display
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("WATERING PLANTS");
    lcd.setCursor(0,1);
    lcd.print("YUM! YUM! YUM!");

    digitalWrite(relay, HIGH); // Turn the relay on
    delay(t2);
    digitalWrite(relay, LOW); // Turn the relay Off

    } //water turns off

    //sensor value readjustment
    int sensorValue0 = analogRead(A0);
    Serial.println(sensorValue0);
    //this is the interval where the valve will be off (hours)
    int normal0_a= (sensorValue0-100)/30;
    //limiting the value from 0 to 24
    if (normal0_a<0)
    {
      normal0_a=0;
    }
    if (normal0_a>24)
    {
      normal0_a=24;
    }

    if (normal0 != normal0_a)
    {
      break;
    }
    i--;
}


}