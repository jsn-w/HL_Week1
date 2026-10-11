#include <Wire.h>

const uint8_t M_IN1[2] = {10, 6};
const uint8_t M_IN2[2] = {11, 5};
const uint8_t M_SLP[2] = {9, 15};
const uint8_t ENC_A[2] = {8, 14};
const uint8_t ENC_B[2] = {7, 13};
const uint8_t XSHUT[5] = {0, 4, 23, 21, 22};
const uint8_t LED_PIN  = 12;
const uint8_t NUM_LEDS = 3;



const uint8_t  TOF_BASE_ADDR = 0x30;
// logic to change address
bool writeReg8(uint8_t addr, uint16_t reg, uint8_t val) {
  Wire.beginTransmission(addr);
  Wire.write(reg >> 8);
  Wire.write(reg & 0xFF);
  Wire.write(val);
  return Wire.endTransmission() == 0;
}
// tof init and read




void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}


//motor
void motorSleep(uint8_t m) {
  analogWrite(M_IN1[m], 0);
  analogWrite(M_IN2[m], 0);
  digitalWrite(M_SLP[m], LOW);
  motorAwake[m] = false;
  motorPct[m] = 0;
}
void setMotor(uint8_t m, int pct) {
  pct = constrain(pct, -100, 100);
  if (pct == 0) {                   // coast
    analogWrite(M_IN1[m], 0);
    analogWrite(M_IN2[m], 0);
    motorPct[m] = 0;
    return;
  }
  motorWake(m);
  uint16_t duty = (uint32_t)abs(pct) * PWM_MAX / 100;
  if (pct > 0) { analogWrite(M_IN1[m], duty); analogWrite(M_IN2[m], 0); }
  else         { analogWrite(M_IN1[m], 0);    analogWrite(M_IN2[m], duty); }
  motorPct[m] = pct;
}

void brakeMotor(uint8_t m) {
  motorWake(m);
  analogWrite(M_IN1[m], PWM_MAX);
  analogWrite(M_IN2[m], PWM_MAX);
  motorPct[m] = 0;
}

void forward() {

}

void backward() {

}

void left() {

}

void right() {

}