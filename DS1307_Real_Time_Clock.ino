/*****************************************************************************
* Copyright (C) 2013 by Vasco Ferraz. All Rights Reserved.                   *
*                                                                            *
* This program is free software: you can redistribute it and/or modify       *
* it under the terms of the GNU General Public License as published by       *
* the Free Software Foundation, either version 3 of the License, or          *
* (at your option) any later version.                                        *
*                                                                            *
* This program is distributed in the hope that it will be useful,            *
* but WITHOUT ANY WARRANTY; without even the implied warranty of             *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the               *
* GNU General Public License for more details.                               *
*                                                                            *
* You should have received a copy of the GNU General Public License          *
* along with this program. If not, see <http://www.gnu.org/licenses/>.       *
*                                                                            *
*  Author:        Vasco Ferraz                                               *
*  Contact:       http://vascoferraz.com/contact/                            *
*  Description:   http://vascoferraz.com/tutorials/ds1307-real-time-clock/   *
*****************************************************************************/

#include <Wire.h>   // I2C and TWI library
#include <RTClib.h> // RTClib library
 
#define DS1307_I2C_ADDRESS 0x68 // Each I2C object has a unique bus address, the DS1307 (Real Time Clock) is 0x68
 
RTC_DS1307 RTC;
 
void setup ()
{
 Serial.begin(9600);
 Wire.begin();
 RTC.begin();
 
 // If the clock is not running, execute the following code
 if (! RTC.isrunning())
 {  
  Serial.println("Not Running! Restarting the clock");
  delay(5000);    
  // Starts ticking the clock
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write(0x00); // Move pointer to 0x00 byte address
  Wire.write(0x00); // Sends 0x00. The whole byte is set to zero (0x00). This also means seconds will reset!! Unless you use a mask -> homework :)
  Wire.endTransmission();
 
  // Following line sets the RTC to the date & time this sketch was compiled
  RTC.adjust(DateTime(__DATE__, __TIME__));
 
  // Following line sets the RTC to the date & time to: 2015 January 01 - 00:00:00
  //RTC.adjust(DateTime(2015,1,1, 0,0,0)); // Sequence: year, month, day,  hour, minute, second  
 }
}
 
void loop ()
{
 printTime();
 printDate();
}

// Print hour, minute and second
void printTime (void)
{
 DateTime now = RTC.now();
 
 // Print hour
 if (now.hour() <= 9)
 {
  Serial.print("0"); Serial.print(now.hour(), DEC); Serial.print(":");
 }
  else { Serial.print(now.hour(), DEC); Serial.print(":"); }
 
 // Print minute
 if (now.minute() <= 9)
 {
  Serial.print("0"); Serial.print(now.minute(), DEC); Serial.print(":");
 }
  else { Serial.print(now.minute(), DEC); Serial.print(":"); }
 
 // Print second
 if (now.second() <= 9)
 {
  Serial.print("0"); Serial.print(now.second(), DEC);
 }
  else { Serial.print(now.second(), DEC); }
}

//Print day, month, year and weekday
void printDate (void)
{
 DateTime now = RTC.now();

 Serial.print(" | ");

 // Print day
 if (now.day() <= 9)
 {
  Serial.print("0"); Serial.print(now.day(), DEC); Serial.print("/");
 }
  else { Serial.print(now.day(), DEC); Serial.print("/"); }
 
 // Print month
 switch(now.month())
 {
  case 1:  Serial.print("Jan/"); break;    
  case 2:  Serial.print("Feb/"); break;
  case 3:  Serial.print("Mar/"); break;
  case 4:  Serial.print("Apr/"); break;
  case 5:  Serial.print("May/"); break;
  case 6:  Serial.print("Jun/"); break;
  case 7:  Serial.print("Jul/"); break;
  case 8:  Serial.print("Aug/"); break;    
  case 9:  Serial.print("Sep/"); break;
  case 10: Serial.print("Oct/"); break;
  case 11: Serial.print("Nov/"); break;
  case 12: Serial.print("Dec/"); break;
  default: Serial.print("Err/");
 }
 
 // Print year
 Serial.print(now.year(), DEC);

 // Print weekday
 switch(now.dayOfWeek())
 {
  case 0:  Serial.println(" | Sunday");    break;
  case 1:  Serial.println(" | Monday");    break;
  case 2:  Serial.println(" | Tuesday");   break;
  case 3:  Serial.println(" | Wednesday"); break;
  case 4:  Serial.println(" | Thursday");  break;
  case 5:  Serial.println(" | Friday");    break;
  case 6:  Serial.println(" | Saturday");  break;
  default: Serial.println(" | Error");
 }
}
