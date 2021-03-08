#include <AntoIO.h>
#define ledPin1 14
#define ledPin2 13
#define ledPin3 16
#define ledPin4 14
#define ledPin5 15
#define ledPin 12
#define ledPin6 5

const char *ssid = "your access point SSID";
const char *pass = "access point password";
const char *user = "your username";
const char *token = "your token";
const char *thing = "your thing";
AntoIO anto(user, token, thing);

int value = 0;

void setup() {
     // pinMode(D4,OUTPUT);

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
anto.sub("LED1");
anto.sub("LED2");
anto.sub("LED3");
anto.sub("mLED1");
anto.sub("water");
anto.sub("mwater");
anto.sub("fan");
pinMode(ledPin1,OUTPUT);
pinMode(ledPin2,OUTPUT);
pinMode(ledPin3,OUTPUT);
pinMode(ledPin4,OUTPUT);
pinMode(ledPin5,OUTPUT);
pinMode(ledPin6,OUTPUT);
pinMode(ledPin,OUTPUT);
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
else if(channel.equals("LED3"))
    {
    value = payload.toInt();
    if(value == 1)
    {
        digitalWrite(ledPin6,HIGH);
    }
    else{
        digitalWrite(ledPin6,LOW);
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
else if(channel.equals("mwater"))
    {
    value = payload.toInt();
    if(value == 1)
    {
        digitalWrite(ledPin,HIGH);
    }
    else{
        digitalWrite(ledPin,LOW);
    }        
}
}#include <AntoIO.h>
#define ledPin1 14
#define ledPin2 13
#define ledPin3 16
#define ledPin4 14
#define ledPin5 15
#define ledPin 12
#define ledPin6 5

const char *ssid = "your access point SSID";
const char *pass = "access point password";
const char *user = "your username";
const char *token = "your token";
const char *thing = "your thing";
AntoIO anto(user, token, thing);

int value = 0;

void setup() {
     // pinMode(D4,OUTPUT);

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
anto.sub("LED1");
anto.sub("LED2");
anto.sub("LED3");
anto.sub("mLED1");
anto.sub("water");
anto.sub("mwater");
anto.sub("fan");
pinMode(ledPin1,OUTPUT);
pinMode(ledPin2,OUTPUT);
pinMode(ledPin3,OUTPUT);
pinMode(ledPin4,OUTPUT);
pinMode(ledPin5,OUTPUT);
pinMode(ledPin6,OUTPUT);
pinMode(ledPin,OUTPUT);
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
else if(channel.equals("LED3"))
    {
    value = payload.toInt();
    if(value == 1)
    {
        digitalWrite(ledPin6,HIGH);
    }
    else{
        digitalWrite(ledPin6,LOW);
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
else if(channel.equals("mwater"))
    {
    value = payload.toInt();
    if(value == 1)
    {
        digitalWrite(ledPin,HIGH);
    }
    else{
        digitalWrite(ledPin,LOW);
    }        
}
}
