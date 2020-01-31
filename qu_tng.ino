 #include <EEPROM.h>
#include <Keypad.h>
#include <DS3231.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>
  
Servo servo1; 
int servoVal;
DS3231 clock;
RTCDateTime t;
#define buz 7
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)
int Hor, Min, Sec, tim, dat, h, m, s;
int ASCII = 48;
char key = 0;
char buffer[2];

const byte numRows= 4;
const byte numCols= 4;
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
byte rowPins[numRows] = {9, 8, 7, 6};
byte colPins[numCols]= {5, 4, 3, 2};
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
void setup() {
  Serial.begin(9600);
   servo1.attach(10);
   servoVal=15;
  servo1.write(servoVal);
Wire.begin();
clock.begin();
pinMode(buz, OUTPUT);
display.begin(SSD1306_SWITCHCAPVCC);
display.clearDisplay();
display.setTextColor(WHITE);
display.setTextSize(1);
welcome();
//uncomment these lines to set the date and time
//rtc.setDOW(SATURDAY); // Set Day-of-Week to SUNDAY
//rtc.setTime(10, 54, 0); // Set the time to 12:00:00 (24hr format)
//rtc.setDate(7, 1, 2017); // Day, Month, Year
}
void loop() {
t = clock.getDateTime();
Hor = t.hour;
Min = t.minute;
Sec = t.second;


//tim = clock.getTime();
//dat = clock.getDate();
char key = myKeypad.getKey();
if (key == 'C'){

EEPROM.write(2, ASCII+6);
EEPROM.write(3, ASCII);

servo1.write(15);
}

if(key == '#'){
  
display.clearDisplay();
display.setCursor(0,12);
display.print("Enter New Time");
display.setCursor(0,20);
display.display();

int j =0;
int i=0;
while( j<6)
{
  if(i==2 || i == 5){
  display.print(":");
  display.display();
  i++;
}
key=myKeypad.getKey();
if(key)
{
  display.print(key);
   display.display();
  EEPROM.write(j,key);
j++;
i++;
}
}
}
if(key=='*')
{
  display.clearDisplay();
display.setCursor(0,12);
display.print("Enter Feeding Time");
display.setCursor(0,20);
display.display();
int k=7;
int h=0;
while(k<9)
{
  if(h==2){
  display.print(";");
  display.display();
  h++;
}
key=myKeypad.getKey();
if(key)
{
  display.print(key);
   display.display();
  EEPROM.write(k,key);
k++;
h++;
buffer[0]=EEPROM.read(7);
buffer[1]=EEPROM.read(8);
tim = atoi(buffer);
delay(200);
} }}
changealarm();
checkalarm();
timedate();
Serial.println(tim);
}
void checkalarm(){
if( Hor == h && Min == m)
{
display.clearDisplay();
display.setCursor(0,11);
display.print("Hold C to stop feeding ");
display.display();
servo1.write(70);
delay(tim*100);
if (key == 'C'){

EEPROM.write(2, ASCII+6);
EEPROM.write(3, ASCII);

servo1.write(15);
}

}
else
servo1.write(15);

}
void changealarm(){
buffer[0]=EEPROM.read(0);
buffer[1]=EEPROM.read(1);
h = atoi(buffer);
Serial.println(h);
buffer[0]=EEPROM.read(2);
buffer[1]=EEPROM.read(3);
m = atoi(buffer);
buffer[0]=EEPROM.read(4);
buffer[1]=EEPROM.read(5);
s = atoi(buffer);
}
void timedate(){
display.clearDisplay();
display.setTextColor(WHITE);
display.setTextSize(1);
display.setCursor(11,11);
display.print("Time: ");
display.print(t.hour);
display.print(":");
display.print(t.minute);
display.print(":");
display.print(t.second);


//display.print();
display.setCursor(11,20);
display.print("Alarm: ");
display.print(h);
display.print(":");
display.print(m);
display.print(":");
display.print(s);
display.display();

}
void turn()
{
servo1.write(70);
delay(tim*100);

  }
void welcome(){


display.setCursor(15,11);
display.print(" Welcome To ");
display.display();
display.setCursor(15,21);
display.print("Cuongslab <3 ");
display.display();
delay(5000);
}
