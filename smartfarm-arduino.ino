#include <LiquidCrystal.h> 
#include <Wire.h>
#include <SPI.h>
#include <RTClib.h>
RTC_DS3231 RTC;


const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
const int analogInPin = A0;
const int relaysm = 6; //ควบคุมอัตโนมัติ
const int relaytime =7; //เวลา //setRelaytime -------------------------
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);



//--------------------------------------
int sensorValue = 0;        // ตัวแปรค่า Analog
int outputValue = 0;        // ตัวแปรสำหรับ Map เพื่อคิด %


void setup()//ค่าเริ่มต้นอุปกรณ์
{
  Serial.begin(9600); //กำหนดการแสดงตัวอักษร
  
  pinMode(relaysm, OUTPUT); //active relay ให้รีเลย์ทำงาน
  pinMode(relaytime,OUTPUT); //active relay ให้รีเลย์ทำงาน
  
 // set timer ตัวบอกเวลา
  Wire.begin();
  RTC.begin(); 
  RTC.adjust(DateTime(__DATE__, __TIME__)); //บอกเวลาตอนนี้
  DateTime now = RTC.now();
  RTC.turnOnAlarm(1); //ให้เวลาทำงาน

  lcd.begin(20,4); //20คือจำนวนคอลัมล์ของLCD 4คือจำนวนแถว
  lcd.clear();// ให้เคลียร์หน้าจอ
}

void loop() {

  //รดน้ำอัตโนมัติ--------------------- 
lcd.setCursor(0,0);
lcd.print("SMARTFARM STP");
  
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue,0,1023,0,100);
 
  lcd.setCursor(0,1);
  Serial.print("SM = ");
  lcd.print("SM = "); //แสดงคำว่า SM ผ่านจอLCD
  lcd.setCursor(5,1); //กำหนดตำแหน่งที่ต้องการให้แสดง
  Serial.print(outputValue);
  lcd.print(outputValue); //แสดงอุณหภูมิผ่าน LCD
  lcd.setCursor(9,1);
  Serial.println("%  ");
  lcd.println("%  ");
  //delay(3000); // หน่วงเวลา 3 วินาที
  //lcd.clear();

  if (outputValue >60) {  //ตั้งค่า % ที่ต้องการจะรดน้ำต้นไม้
    digitalWrite(relaysm, HIGH);//ถ้าถึง%ที่ต้องรดน้ำก็จะให้มันทำงาน HIGHคือให้รีเลย์ทำงาน
  }
  else {
    digitalWrite(relaysm,LOW);//ถ้าถึง%ทีไม่ต้องงรดน้ำก็จะไม่ให้มันทำงาน LOWคือให้รีเลย์ไม่ทำงาน
  }
  delay(1000);


 //---รดน้ำตามเวลา----------------------------
  DateTime now = RTC.now(); //บอกเวลาตอนนี้
  lcd.setCursor (0,2);//ตำแหน่งที่ต้องการให้แสดง
  Serial.print("Time : ");
  lcd.print("Time : ");//แสดงtime ผ่านจอlcd
  lcd.setCursor (6,2);//ตำแหน่งที่ต้องการให้แสดง
  lcd.print(now.hour(), DEC);//แสดงhour ผ่านจอlcd
  Serial.print(now.hour(), DEC);
  lcd.setCursor (9,2);//ตำแหน่งที่ต้องการให้แสดง
  lcd.print(":");  //แสดง: ผ่านจอlcd
  //Serial.print(":");
  lcd.setCursor (10,2);//ตำแหน่งที่ต้องการให้แสดง
  lcd.print(now.minute(),DEC); //แสดงminute ผ่านจอlcd
  Serial.print(now.minute(),DEC);
  lcd.setCursor (13,2);
  lcd.print(":");
  //Serial.print(":");
  lcd.setCursor (14,2);//ตำแหน่งที่ต้องการให้แสดง
  lcd.print(now.second(),DEC ); //แสดงsecond ผ่านจอlcd
  Serial.print(now.second(),DEC);
  if(now.second()==00) //ถ้าถึงวินาทีที่00 ให้มันเคียร์หน้าจอ
  {
      lcd.clear ();  
  }
  
 if (now.hour()==20 && now.minute()==10 && now.second()==00) //ถ้าถึงชั่วโมง นาที วินาที ที่กำหนดไว้ ให้มันรดน้ำ
  {
    digitalWrite(relaytime,HIGH);
  }
 else if (now.hour()==20 && now.minute()==11 && now.second()==30) //ถ้าถึงชั่วโมง นาที วินาที ที่กำหนดไว้ ให้มันไม่รดน้ำ
  {
    digitalWrite(relaytime,LOW);
  }
  else if (now.hour()==17 && now.minute()==41 && now.second()==00) //ถ้าถึงชั่วโมง นาที วินาที ที่กำหนดไว้ ให้มันรดน้ำ
  {
    digitalWrite(relaytime,HIGH);
  }
  
}
