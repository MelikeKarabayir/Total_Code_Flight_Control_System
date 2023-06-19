//SENSOR SABITLERI
#define SEALEVELPRESSURE_HPA (926.5) // Test videosu için değiştirildi.Yaklaşık 1023.4 olmalı.
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
//ADRES TANIMLAMA

//KÜTÜPHANENİN KULLANILACAĞI DEĞİŞKEN TANIMLAMA
Adafruit_BME280 bme280;
float sicaklik,basinc,nem,irtifa;
int BME280_I2C_ADDRESS = 0X77;
void BFC_Sensor_Init_BME280(void)
{

	if (bme280.begin(BME280_I2C_ADDRESS) != true) //Adres bulunamazsa;
	{
		Serial.println(("BME280 init false"));
	}
}


void BFC_Sensor_Read_BME280(void)
{
	sicaklik = bme280.readTemperature();
	nem = bme280.readHumidity();
	basinc =bme280.readPressure() / 100.0F;
	irtifa = bme280.readAltitude(SEALEVELPRESSURE_HPA);
	 //LoRa'nın ileteceği veriler, bunlar toplam kodun olduğu kısımda data yapısında tanıtılacak.
	/*data.temperature = sicaklik;
	data.humidity = nem;
	data.pressure = basinc;
	data.altitude = irtifa;*/
}

void BFC_Sensor_Print_BME280(void)
{
	Serial.print("P1,");
	Serial.print(sicaklik);
  	Serial.print(",");
	Serial.print(nem);
  	Serial.print(",");
	Serial.print(basinc);
  	Serial.print(",");
	Serial.println(irtifa);
	

}
