#include <LiquidCrystal.h>
#include<Wire.h>
int sensor= 6 ;   //sensor pin
float gasvalue;   //reading analog resistance values from the sensor
int em;   //digital output from sensor
int flag=0;   //emergency flag
LiquidCrystal lcd(12,11,5,4,3,2);   //setting up LCD
void setup() {
  Wire.begin(8);
  Wire.onRequest(requestEvent);
  lcd.begin(16,2);
  pinMode(sensor,INPUT);
  pinMode(A3,INPUT);
  Serial.begin(9600);

}
void requestEvent(){
  Wire.write(flag);   //sends flag data to NodeMCU
}
void loop() {
  gasvalue=analogRead(A0);
  em=digitalRead(sensor);
  Serial.println(em);
  if(em==1)   //if sensor output is TRUE
  {
    flag=0;
    lcd.clear();
    lcd.home();
  lcd.print("Gas levels are");
  lcd.setCursor(0,1);
  lcd.print("normal.");
  }
  else
  {
    if(em==0)   //if sensor output is FALSE
    {
      flag=1;
    lcd.clear();
    lcd.home();
    lcd.print(":::Emergency:::");
    lcd.setCursor(0,1);
    lcd.print("    Gas leak");
    delay(1000);
    lcd.noDisplay();
    delay(500);
    lcd.display();
    }}
  delay(200);
}
