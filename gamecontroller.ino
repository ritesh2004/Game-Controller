#include "MPU6050.h"
#include "Wire.h"

MPU6050 mpu;

int16_t ax,ay,az;
int16_t gx,gy,gz;

int vx,vy;
int send;

char fb,lr;

#define button D7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button,INPUT);
  Wire.begin();
  mpu.initialize();
  Serial.println((mpu.testConnection() ? "Connected" : "Something went wrong!"));
}

void loop() {
  // put your main code here, to run repeatedly:
  send = digitalRead(button);
  if (send == 1){
    mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
    vx = map(ax, -16000, 16000, 90, -90);
    vy = map(ay, -16000, 16000, 90, -90);
    fb = vx > -60 ? 'W' : 'S';
    lr = vy > 20 ? 'D' : (vy < -20) ? 'A' : 'o';
    Serial.print(fb);
    Serial.print(",");
    Serial.println(lr);
    delay(800);
  }
}
