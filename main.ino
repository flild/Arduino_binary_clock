#include <Wire.h>
#include "RTClib.h"


RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () 
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(A6, OUTPUT);
  Serial.begin(9600);
  delay(3000); // ждать открытия консоли

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
  
  // Закомментируйте ниже строки, как только вы установите дату и время
    // Следующая строка устанавливает RTC на дату и время компилирования этого скетча
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
    // Следующая строка устанавливает RTC с явной датой и временем
    // например, чтобы установить 27 января 2017 года в 12:56:
    // rtc.adjust(DateTime(2017, 1, 27, 12, 56, 0));
  }
}

void loop () 
{
    DateTime now = rtc.now();
    Serial.print(now.hour());
    Serial.print(":");
    Serial.print(now.minute());
    Serial.print(":");
    Serial.print(now.second());
    Serial.print(" ");
    int i = now.hour();
    
    int counth = 5;
    int hourmas[5];
    while (counth>= 0){
      hourmas[counth-1]=i%2;
      i=i/2;
      --counth;
      
    }
    int im = now.minute();
    int countm = 6;
    int minmas[6];
    while (countm>= 0){
      minmas[countm-1]=im%2;
      im=im/2;
      --countm;
    }

     int is = now.second();
     
    int counts = 0;
    int secmas[6];
    while (counts<= 5){
      secmas[counts]=is%2;
      is=is/2;
      ++counts;
      Serial.print("тут=");
      Serial.print(is);
      Serial.print(" остаток: ");
      Serial.println(is%2);
      
    }
    for (int i = 0;i<6;i++)
  {
    if(hourmas[i] == 1)
    digitalWrite(i+2, HIGH);
    else
    digitalWrite(i+2, LOW);
  }
  for (int im = 0;im<6;im++)
  {
    if(minmas[im] == 1)
    digitalWrite(im+7, HIGH);
    else
    digitalWrite(im+7, LOW);
  }

  for (int is = 0;is<4;is++)
  {
    if(secmas[is] == 1)
    digitalWrite(is+13, HIGH);
    else
    digitalWrite(is+13, LOW);
  }
    
    if(secmas[5] == 1)
      digitalWrite(A6, HIGH);
      else
      digitalWrite(A6, LOW);
   
  delay(800);
    
  
}
