#include <Bitcraze_PMW3901.h>
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X rangeSensor;

// Using digital pin 10 for chip select
Bitcraze_PMW3901 flow(10);

void setup() {
  Serial.begin(9600);

  // Initialize flow sensor
  if (!flow.begin()) {
    Serial.println("Initialization of the flow sensor failed");
    while(1) { }
  }

  // Initialize range sensor
  Wire.begin();
  rangeSensor.init();
  rangeSensor.setTimeout(500);
}

int16_t deltaX,deltaY;

void loop() {
  // Get motion count since last call
  flow.readMotionCount(&deltaX, &deltaY);

  // Get single range measurement
  float range = rangeSensor.readRangeSingleMillimeters();

  Serial.println(deltaX);
  Serial.println(deltaY);


  delay(300);
}
