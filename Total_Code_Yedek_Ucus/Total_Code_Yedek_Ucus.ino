//KÜTÜPHANELERİ TANIMLA
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <DFRobot_BMX160.h>
#include "BFC_SENO052.h"
#include "BFC_BME280.h"
#include <TinyGPS++.h>
#include "BFC_Ublox_8M_GPS.h"
//millis fonksiyon değişkenleri
unsigned long currentMillis_GPS;
unsigned long previousMillis_GPS; 
unsigned long GPS_Scan_Time = 1000; 

unsigned long currentMillis_BMX160;
unsigned long previousMillis_BMX160; 
unsigned long BMX160_Scan_Time = 1000; 

unsigned long currentMillis_BME280;
unsigned long previousMillis_BME280; 
unsigned long BME280_Scan_Time = 1000;



void setup()
{
    Serial.begin(9600);
    
    //Serial.println(("YGM Gazi Salgur Yedek Ucus Bilgisayari Basliyor.."));
    BFC_Sensor_Init_BME280();
    BFC_Init_GPS();
    BFC_Sensor_Init_BMX160();
}

void loop()
{
  currentMillis_BME280 = millis();
  if ((currentMillis_BME280 - previousMillis_BME280) >= BME280_Scan_Time)
  {
    BFC_Sensor_Read_BME280();
    BFC_Sensor_Print_BME280();
    previousMillis_BME280 = currentMillis_BME280;
  }
   currentMillis_BMX160 = millis();
  if ((currentMillis_BMX160 - previousMillis_BMX160 ) >= BMX160_Scan_Time)
  {
    BFC_Sensor_Read_BMX160();
    BFC_Sensor_Print_BMX160();
    previousMillis_BMX160 = currentMillis_BMX160; 
  }
  currentMillis_GPS = millis();
  if ((currentMillis_GPS - previousMillis_GPS) >= GPS_Scan_Time)
  {
    BFC_GPS_Loop();
    previousMillis_GPS = currentMillis_GPS;
  }
}
