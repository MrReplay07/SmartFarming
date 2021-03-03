#include <AntoIO.h>
#define ledPin1 14
#define ledPin2 13
#define ledPin3 12
#define ledPin4 14

const char *ssid = "*******";  // Username wifi
const char *pass = "*******";  // Password wifi
const char *user = "*****";    // username anto
const char *token = "*******"; // token anto
const char *thing = "******";  // thing anto
AntoIO anto(user, token, thing);

int value = 0;

void setup() {
Serial.begin(115200);
delay(10);
Serial.println();
Serial.println();
Serial.print("Anto library version: ");
Serial.println(anto.getVersion());
Serial.print("\nTrying to connect ");
Serial.print(ssid);
Serial.println("...");

anto.begin(ssid, pass, messageReceived);
// Chanel anto--------
anto.sub("LED1");
anto.sub("LED2");
anto.sub("mLED1");
anto.sub("water");
anto.sub("fan");
//------------------
pinMode(ledPin1,OUTPUT);
pinMode(ledPin2,OUTPUT);
pinMode(ledPin3,OUTPUT);
pinMode(ledPin4,OUTPUT);
pinMode(ledPin5,OUTPUT);
}

void loop() {
  anto.mqtt.loop();

}

void messageReceived(String thing, String channel,String payload) 
{
  Serial.print("Recieved: ");
  Serial.print(thing);
  Serial.print("/");
  Serial.print(channel);
  Serial.print("-> ");
  Serial.println(payload);

if(channel.equals("LED1"))
    {
    value = payload.toInt();
    if(value == 1)
    {
        digitalWrite(ledPin1,HIGH);
    }
    else{
        digitalWrite(ledPin1,LOW);
    }        
}

else if(channel.equals("LED2"))
    {
    value = payload.toInt();
    if(value == 1)
    {
        digitalWrite(ledPin2,HIGH);
    }
    else{
        digitalWrite(ledPin2,LOW);
    }        
}
else if(channel.equals("mLED1"))
    {
    value = payload.toInt();
    if(value == 1)
    {
        digitalWrite(ledPin4,HIGH);
    }
    else{
        digitalWrite(ledPin4,LOW);
    }        
}

else if(channel.equals("water"))
    {
    value = payload.toInt();
    if(value == 1)
    {
        digitalWrite(ledPin3,HIGH);
    }
    else{
        digitalWrite(ledPin3,LOW);
    }        
}
else if(channel.equals("fan"))
    {
    value = payload.toInt();
    if(value == 1)
    {
        digitalWrite(ledPin5,HIGH);
    }
    else{
        digitalWrite(ledPin5,LOW);
    }        
}
}
