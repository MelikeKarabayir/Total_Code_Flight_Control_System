//SENSOR SABITLERI
static const uint32_t GPSBaud = 9600;
double boylam,enlem;
uint16_t gps_yil;
uint8_t gps_ay, gps_gun, gps_saat, gps_dakika, gps_saniye;
//ADRES TANIMLAMA

//KÜTÜPHANENİN KULLANILACAĞI DEĞİŞKEN TANIMLAMA
TinyGPSPlus gps;
//Hardware için portlar
static const int RXPin = 16, TXPin = 17;
void BFC_Init_GPS()
{
	Serial2.begin(GPSBaud);
}
void BFC_GPS_Loop(void)
{   

	while (Serial2.available() > 0)

	if (gps.encode(Serial2.read()))
	{
			
		if (gps.location.isValid())
			{
			Serial.print(F("KONUM:   "));
        	boylam =34.345642; //gps.location.lat();
       		enlem= 36.234597; //gps.location.lng();
    		//LoRa ile aktarılan kısımlar
			//data.gps_lat = boylam;
			//data.gps_lng = enlem;
			Serial.print("P5,");//gorev yuku payload5
			Serial.print(enlem, 6);
			Serial.print(F(","));
			Serial.println(boylam, 6);
			}
			else
			{
			boylam =34.345642; //gps.location.lat();
       		enlem= 36.234597; //gps.location.lng();
    		//LoRa ile aktarılan kısımlar
			//data.gps_lat = boylam;
			//data.gps_lng = enlem;
			Serial.print("P5,");//gorev yuku payload5
			Serial.print(enlem, 6);
			Serial.print(F(","));
			Serial.println(boylam, 6);;
			}
				
		/*if (gps.date.isValid())
			{
			Serial.print(F("TARIH / ZAMAN : "));
			gps_yil = gps.date.year();
			gps_ay = gps.date.month();
			gps_gun = gps.date.day();				
			gps_saat = gps.time.hour();
			gps_dakika = gps.time.minute();
			gps_saniye = gps.time.second();

			//LoRa ile gönderilecek veriler
			//data.gps_date_year = gps_yil;
			//data.gps_date_month = gps_ay;
			//data.gps_date_day = gps_gun;
			//data.gps_date_hour = gps_saat;				
			//data.gps_date_minute = gps_dakika;
			//data.gps_date_second = gps_saniye;

			//TARİH
			Serial.print(gps_gun);
			Serial.print(F("/"));
			Serial.print(gps_ay);
			Serial.print(F("/"));				
			Serial.print(gps_yil);
			//SAAT
			Serial.print("  &  ");
			Serial.print(gps_saat);
			Serial.print(":");
			Serial.print(gps_dakika);				
			Serial.print(":");
			Serial.println(gps_saniye);
			}
			else
			{
			Serial.println(F("Tarih - Zaman BULUNAMADI!"));
			}*/
	}
	
}
