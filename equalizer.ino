#include "LedControlMS.h"
#include "fix_fft.h"

char im[128];
char data[128];
int i = 0;
int j = 0;
int k = 0;
int l0;
int l1;
int l2;
int l3;
int l4;
int l5;
int l6;
int l7;
LedControl lc = LedControl(12, 11, 10, 1);
void setup() {
  ADCSRA = (1 << ADEN) | (1 << ADPS0) | (0 << ADPS1) | (1 << ADPS2); // sps=500k ~f=10k
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 1);
  /* and clear the display */
  lc.clearDisplay(0);
  pinMode(A0, INPUT);
}
void loop() {
  for (i = 0; i < 128; i++) {

    if (analogRead(A0) > 20) {
      data[i] = analogRead(A0) / 10;
    } else {
      data[i] = 0;
    }
    im[i] = 0;
  };
  fix_fft(data, im, 7, 0);

  for (i = 0; i < 64; i++) {
    data[i] = sqrt(data[i] * data[i] + im[i] * im[i]);
    data[i] = map(data[i], 0, 30, 0, 32);
  };
  l0 = (data[0] + data[1] + data[2] + data[3] + data[4] + data[5] + data[6] + data[7]) / 8;
  l1 = (data[8] + data[9] + data[10] + data[11] + data[12] + data[13] + data[14] + data[15]) / 3;
  l2 = (data[16] + data[17] + data[18] + data[19] + data[20] + data[21] + data[22] + data[23]) / 2;
  l3 = (data[24] + data[25] + data[26] + data[27] + data[28] + data[29] + data[30] + data[31]) / 2;
  l4 = (data[32] + data[33] + data[34] + data[35] + data[36] + data[37] + data[38] + data[39]) / 2;
  l5 = (data[40] + data[41] + data[42] + data[43] + data[44] + data[45] + data[46] + data[47]) / 2;
  l6 = (data[48] + data[49] + data[50] + data[51] + data[52] + data[53] + data[54] + data[55]) / 2;
  l7 = (data[56] + data[57] + data[58] + data[59] + data[60] + data[61] + data[62] + data[63]) / 2;
  i = 0;
  for (i = 0; i < l0; i++) {
    lc.setLed(0, 0, i, true);
  }
  i = 0;
  for (i = 0; i < l1; i++) {
    lc.setLed(0, 1, i, true);
  }
  i = 0;
  for (i = 0; i < l2; i++) {
    lc.setLed(0, 2, i, true);
  }
  i = 0;
  for (i = 0; i < l3; i++) {
    lc.setLed(0, 3, i, true);
  }
  i = 0;
  for (i = 0; i < l4; i++) {
    lc.setLed(0, 4, i, true);
  }
  i = 0;
  for (i = 0; i < l5; i++) {
    lc.setLed(0, 5, i, true);
  }
  i = 0;
  for (i = 0; i < l6; i++) {
    lc.setLed(0, 6, i, true);
  }
  i = 0;
  for (i = 0; i < l7; i++) {
    lc.setLed(0, 7, i, true);
  }
  i = 0;

  delay(50);
  lc.clearDisplay(0);
}
