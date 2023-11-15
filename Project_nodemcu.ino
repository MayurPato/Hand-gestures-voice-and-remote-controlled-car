#define BLYNK_TEMPLATE_ID "TMPL3v1nn-7GB"
#define BLYNK_DEVICE_NAME "Project"
#define BLYNK_AUTH_TOKEN "W_AEA0TggsKjcyOuQbOMLbD1_fsNMpvs"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int Speed, direc;
bool forward, backward, left, right, handmode;

char auth[] = BLYNK_AUTH_TOKEN ;
char ssid[] = "";
char pass[] = "";

BLYNK_WRITE(V0)
{
  direc = param.asInt();
  Serial.println(direc);
}

BLYNK_WRITE(V1)
{
  Speed = param.asInt();
  Serial.println(Speed);
}

BLYNK_WRITE(V2)
{
  forward = param.asInt(); 
}

BLYNK_WRITE(V3)
{
  backward = param.asInt(); 
}

BLYNK_WRITE(V4)
{
  left = param.asInt(); 
}

BLYNK_WRITE(V5)
{
  right = param.asInt(); 
}

BLYNK_WRITE(V6)
{
  handmode = param.asInt(); 
}

BLYNK_WRITE(V7)
{
  Serial.println("Forward_voice");
  analogWrite(D0, Speed);
  analogWrite(D5, Speed);
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
  delay(5000); 
}

BLYNK_WRITE(V8)
{
  Serial.println("Right_voice");
  analogWrite(D0, Speed);
  analogWrite(D5, Speed);
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  delay(5000);
}

void remotecarcontrol()
{
  if (forward == 1)
  {
    car_forward();
    Serial.println("forward");
  }
  else if (backward == 1)
  {
    car_backward();
    Serial.println("back");
  }
  else if (left == 1)
  {
    car_left();
    Serial.println("left");
  }
  else if (right == 1)
  {
    car_right();
    Serial.println("right");
  }
  else
  {
    car_stop();
    Serial.println("stop");
  }
  
}

void handcarcontrol()
{
  if (direc == 1)
  {
    car_forward();
    Serial.println("hand_forward");
  }
  else if (direc == 2)
  {
    car_backward();
    Serial.println("hand_back");
  }
  else if (direc == 4)
  {
    car_left();
    Serial.println("hand_left");
  }
  else if (direc == 3)
  {
    car_right();
    Serial.println("hand_right");
  }
  else
  {
    car_stop();
    Serial.println("hand_stop");
  }
  
}


void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D1, OUTPUT); // left in1
  pinMode(D2, OUTPUT); // left in2
  pinMode(D3, OUTPUT); // right in1
  pinMode(D4, OUTPUT); // right in2
  pinMode(D5, OUTPUT);
  pinMode(D0, OUTPUT);
 
}

void loop()
{
  Blynk.run();
  if (handmode == 1){
    handcarcontrol();
  }
  else{
    remotecarcontrol();
  }
}



void car_forward()
{
  analogWrite(D0, Speed);
  analogWrite(D5, Speed);
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
}

void car_backward()
{
  analogWrite(D0, Speed);
  analogWrite(D5, Speed);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
}

void car_left()
{
  analogWrite(D0, Speed);
  analogWrite(D5, Speed);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
}


void car_right()
{
  analogWrite(D0, Speed);
  analogWrite(D5, Speed);
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}


void car_stop()
{
  analogWrite(D0, Speed);
  analogWrite(D5, Speed);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}
