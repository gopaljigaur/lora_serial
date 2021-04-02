#include <SoftwareSerial.h>
String w1= "";
SoftwareSerial lora(8,9);
String band = "";
String edclass = "";
String deveui = "";
void setup() {
//set to true for initialization
bool init = true;
  Serial.begin(9600);
  Serial.println("\nInitializing. Please Wait..");
  lora.begin(115200);
  delay(2000);
  do{
    Serial.println("mac reset ind865");//Indian Band
  lora.println("mac reset ind865");
  } while(readLora()!=0);
  delay(2000); 
    if(init){
  do{
    Serial.println("mac set adr on");
  lora.println("mac set adr on\r\n");
  } while(readLora()!=0);
  delay(2000); do{
    Serial.println("mac set edclass a");
  lora.println("mac set edclass a\r\n");
  } while(readLora()!=0);
  delay(2000); do{
    Serial.println("mac set deveui 0000000000DEVEUI");
  lora.println("mac set deveui 0000000000DEVEUI\r\n");
  } while(readLora()!=0);
  delay(2000); do{
    Serial.println("mac set appeui 0000000000APPEUI");
  lora.println("mac set appeui 0000000000APPEUI\r\n");
  } while(readLora()!=0);
  delay(2000); do{
    Serial.println("mac set appkey 00000000000000000000000000APPKEY");
  lora.println("mac set appkey 00000000000000000000000000APPKEY\r\n");
  } while(readLora()!=0);
  delay(2000); do{
    Serial.println("mac set devaddr 0DEVADDR");
  lora.println("mac set devaddr 0DEVADDR\r\n");
  } while(readLora()!=0);
  delay(2000); do{
    Serial.println("mac set rx2 2 866550000");
  lora.println("mac set rx2 2 866550000\r\n");
  } while(readLora()!=0);
  delay(2000); do{
    Serial.println("mac set nwkskey 0000000000000000NETWORKSECRETKEY");
  lora.println("mac set nwkskey 0000000000000000NETWORKSECRETKEY\r\n");
  } while(readLora()!=0);
  delay(2000); do{
    Serial.println("mac set appskey 00000000000000000000APPSECRETKEY");
  lora.println("mac set appskey 00000000000000000000APPSECRETKEY\r\n");
  } while(readLora()!=0);
  delay(2000); do{
    Serial.println("mac save");
  lora.println("mac save\r\n");
  } while(readLora()!=0);
  delay(2000); 
    }
  do{
    Serial.println("mac join abp");
  lora.println("mac join abp\r\n");
  } while(readLora()!=0);
  readLora();
  Serial.println("Paused 10s while node connects to network");
  delay(10000);
  readLora();
  Serial.println("Testing...");
  do{
    Serial.println("mac tx cnf 1 1225");// '1225' are test bytes sent
  lora.println("mac tx cnf 1 1225\r\n");
  } while(readLora()!=0);
  Serial.println("Initialization Finished");
  Serial.println("Prgram paused for 20s for Test Packet");
  delay(20000);
  

}

void loop() {
  
  if (lora.available()) {
    Serial.write(lora.read());
  }
  
  if (Serial.available()) {
    lora.write(Serial.read());
  }


}

int readLora(){
  String w = "";
  while(lora.available()){
  char c = lora.read();
  if(c=='\n'){
if(w=="ok\r"||w=="accepted\r"||w=="no_ack\r")
    {
       Serial.println();
      return(0);
     
    }
    else if(w=="busy\r"){
      return(2);
    }
     else{
      Serial.println("\nRetrying..");
      delay(5000);
      return(1);
     }
     Serial.print(w);
  }
  else{
    w.concat(c);
    Serial.write(c);
  }
  }
}
