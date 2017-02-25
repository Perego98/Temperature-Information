#include <SimpleDHT.h>
String tp="";
// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11;

int vecTmp[10];
int vecUmi[10];
int cont=0;
int medTp=0;
int medUm=0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
    Serial.print("Read DHT11 failed.");
    return;
  }

if(cont<10){
  vecTmp[cont]=(int)temperature;
  vecUmi[cont]=(int)humidity;
  cont++;
}else{
 for(int i=0;i<10; i++){
  medTp+=vecTmp[i];
  }
  medTp=medTp/10;

 for(int i=0;i<10; i++){
  medUm+=vecUmi[i];
  }
medUm=medUm/10;
  
 tp+=(String)(medTp);
 tp+=";";
 tp+=(String)(medUm);
 tp+=";";
 tp+="1";
 Serial.println(tp); 
 tp="";
 medUm=0;
 medTp=0;
  // DHT11 sampling rate is 1HZ.
}
  


  delay(1000);
}
