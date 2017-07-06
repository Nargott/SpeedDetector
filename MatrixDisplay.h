#include <binary.h>
#include <LedControl.h>

/*
 pin 12 is connected to the DataIn 
 pin 10 is connected to the CLK 
 pin 11 is connected to LOAD 
 */
LedControl lc=LedControl(12, 10, 11, 4);

int devices;

void initMatrix() {
  devices=lc.getDeviceCount();
  //we have to init all devices in a loop
  for(int address=0;address<devices;address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    lc.shutdown(address,false);
    /* Set the brightness to a medium values */
    lc.setIntensity(address,8);
    /* and clear the display */
    lc.clearDisplay(address);
  }
}

void clear() {
  for(int address=0;address<devices;address++) {
    lc.clearDisplay(address);
  }
}

void showDigit(int index, char num) {
  int ind = lc.getDeviceCount()-1 - index;
  switch(num) {
    case 1: {
      lc.setRow(ind, 0, B00000100);
      lc.setRow(ind, 1, B00000100);
      lc.setRow(ind, 2, B00000100);
      lc.setRow(ind, 3, B00000100);
      lc.setRow(ind, 4, B00000100);
      lc.setRow(ind, 5, B00000100);
      lc.setRow(ind, 6, B00000100);
      lc.setRow(ind, 7, B00000000);
    } break;
    case 2: {
      lc.setRow(ind, 0, B00111100);
      lc.setRow(ind, 1, B00000100);
      lc.setRow(ind, 2, B00000100);
      lc.setRow(ind, 3, B00111100);
      lc.setRow(ind, 4, B00100000);
      lc.setRow(ind, 5, B00100000);
      lc.setRow(ind, 6, B00111100);
      lc.setRow(ind, 7, B00000000);
    } break;
    case 3: {
      lc.setRow(ind, 0, B00111100);
      lc.setRow(ind, 1, B00000100);
      lc.setRow(ind, 2, B00000100);
      lc.setRow(ind, 3, B00111100);
      lc.setRow(ind, 4, B00000100);
      lc.setRow(ind, 5, B00000100);
      lc.setRow(ind, 6, B00111100);
      lc.setRow(ind, 7, B00000000);
    } break;
    case 4: {
      lc.setRow(ind, 0, B00100100);
      lc.setRow(ind, 1, B00100100);
      lc.setRow(ind, 2, B00100100);
      lc.setRow(ind, 3, B00111100);
      lc.setRow(ind, 4, B00000100);
      lc.setRow(ind, 5, B00000100);
      lc.setRow(ind, 6, B00000100);
      lc.setRow(ind, 7, B00000000);
    } break;
    case 5: {
      lc.setRow(ind, 0, B00111100);
      lc.setRow(ind, 1, B00100000);
      lc.setRow(ind, 2, B00100000);
      lc.setRow(ind, 3, B00111100);
      lc.setRow(ind, 4, B00000100);
      lc.setRow(ind, 5, B00000100);
      lc.setRow(ind, 6, B00111100);
      lc.setRow(ind, 7, B00000000);
    } break;
    case 6: {
      lc.setRow(ind, 0, B00111100);
      lc.setRow(ind, 1, B00100000);
      lc.setRow(ind, 2, B00100000);
      lc.setRow(ind, 3, B00111100);
      lc.setRow(ind, 4, B00100100);
      lc.setRow(ind, 5, B00100100);
      lc.setRow(ind, 6, B00111100);
      lc.setRow(ind, 7, B00000000);
    } break;
    case 7: {
      lc.setRow(ind, 0, B00111100);
      lc.setRow(ind, 1, B00000100);
      lc.setRow(ind, 2, B00000100);
      lc.setRow(ind, 3, B00000100);
      lc.setRow(ind, 4, B00000100);
      lc.setRow(ind, 5, B00000100);
      lc.setRow(ind, 6, B00000100);
      lc.setRow(ind, 7, B00000000);
    } break;
    case 8: {
      lc.setRow(ind, 0, B00111100);
      lc.setRow(ind, 1, B00100100);
      lc.setRow(ind, 2, B00100100);
      lc.setRow(ind, 3, B00111100);
      lc.setRow(ind, 4, B00100100);
      lc.setRow(ind, 5, B00100100);
      lc.setRow(ind, 6, B00111100);
      lc.setRow(ind, 7, B00000000);
    } break;
    case 9: {
      lc.setRow(ind, 0, B00111100);
      lc.setRow(ind, 1, B00100100);
      lc.setRow(ind, 2, B00100100);
      lc.setRow(ind, 3, B00111100);
      lc.setRow(ind, 4, B00000100);
      lc.setRow(ind, 5, B00000100);
      lc.setRow(ind, 6, B00111100);
      lc.setRow(ind, 7, B00000000);
    } break;
    case 0: {
      lc.setRow(ind, 0, B00111100);
      lc.setRow(ind, 1, B00100100);
      lc.setRow(ind, 2, B00100100);
      lc.setRow(ind, 3, B00100100);
      lc.setRow(ind, 4, B00100100);
      lc.setRow(ind, 5, B00100100);
      lc.setRow(ind, 6, B00111100);
      lc.setRow(ind, 7, B00000000);
    } break;
    
    //additional chars
    case 100: {
      lc.setRow(ind, 0, B00000000);
      lc.setRow(ind, 1, B00000000);
      lc.setRow(ind, 2, B00000000);
      lc.setRow(ind, 3, B01111110);
      lc.setRow(ind, 4, B00000000);
      lc.setRow(ind, 5, B00000000);
      lc.setRow(ind, 6, B00000000);
      lc.setRow(ind, 7, B00000000);
    } break;
    
    default: {
      lc.setRow(ind, 0, B00000000);
      lc.setRow(ind, 1, B00000000);
      lc.setRow(ind, 2, B00000000);
      lc.setRow(ind, 3, B00000000);
      lc.setRow(ind, 4, B00000000);
      lc.setRow(ind, 5, B00000000);
      lc.setRow(ind, 6, B00000000);
      lc.setRow(ind, 7, B00000000);
    }
  }
}

void showChar(char ch) {
  switch(ch) {
    case 45: { //-
      showDigit(0, 100);
      showDigit(1, 100);
      showDigit(2, 100);
      showDigit(3, 100);
    } break;
  }
}

void showNumber(int num) {
  int x = num / 1000;
  if ( (num < 1000) && (x == 0)) {showDigit(0, 255);} else {showDigit(0, x);}
    
  x = num / 100 % 10;
  if ( (num < 100) && (x == 0)) {showDigit(1, 255);} else {showDigit(1, x);}

  x = num / 10 % 10;
  if ( (num < 10) && (x == 0)) {showDigit(2, 255);} else {showDigit(2, x);}

  showDigit(3, num % 10);
}
