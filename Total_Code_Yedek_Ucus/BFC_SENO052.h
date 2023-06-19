//SENSOR SABITLERI
//ADRES TANIMLAMA
int BMX160_I2C_ADDRESS = 0X68;

//KÜTÜPHANENİN KULLANILACAĞI DEĞİŞKEN TANIMLAMA
DFRobot_BMX160 bmx160;
float manyetizma_x, manyetizma_y, manyetizma_z, ivme_x, ivme_y, ivme_z, aci_x, aci_y, aci_z ;
void BFC_Sensor_Init_BMX160(void)
{
	  if (bmx160.begin() != true){
    Serial.println("init false");
    while(1);
  }
}


void BFC_Sensor_Read_BMX160(void)
  {
  	sBmx160SensorData_t Omagn, Ogyro, Oaccel;
    bmx160.getAllData(&Omagn, &Ogyro, &Oaccel);
    manyetizma_x = Omagn.x;
    manyetizma_y = Omagn.y;
    manyetizma_z = Omagn.z;
    ivme_x = Oaccel.x;
    ivme_y = Oaccel.y;
    ivme_z = Oaccel.z;
    aci_x = Ogyro.x;
    aci_y = Ogyro.y;
    aci_z = Ogyro.z;
    //LoRa ile aktarılacak veriler
    /*data.magnitude_x = manyetizma_x;
    data.magnitude_y = manyetizma_y;
    data.magnitude_z = manyetizma_z;
    data.accel_x = ivme_x;
    data.accel_y = ivme_y;
    data.accel_z = ivme_z;
    data.gyro_x = aci_x;
    data.gyro_y = aci_y;
    data.gyro_z = aci_z;*/
}
 
void BFC_Sensor_Print_BMX160(void)
{
    Serial.print("P3,");
    Serial.print(ivme_x);
    Serial.print(",");
    Serial.print(ivme_y);
    Serial.print(",");
    Serial.print(ivme_z);
    Serial.print(",");
    Serial.print(aci_x);
    Serial.print(",");
    Serial.print(aci_y);
    Serial.print(",");
    Serial.print(aci_z);
    Serial.print(",");
    Serial.print(manyetizma_x);
    Serial.print(",");
    Serial.print(manyetizma_y);
    Serial.print(",");
    Serial.println(manyetizma_z);

}
