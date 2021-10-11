#include <iostream>
#include "vigenere.h"

std::string encryptVigenere(std::string plaintext, std::string key){
  std::string encrypted = "";
  //looping through the plaintext --> to encrypt word
  int j = 0;
  for (int i = 0; i < plaintext.length(); i++){

    if ((j != 0) && (j % key.length() == 0)){
      j = 0;
    }

    if (isalpha(char(plaintext[i]))){
      int shift = getShiftAmountVigenere(char(key[j]));
      encrypted += shiftCharVigenere(char(plaintext[i]), shift);
      j++;
    } else {
      encrypted += plaintext[i];
    }

  }
  return encrypted;
}

char shiftCharVigenere(char c, int rshift){
  //Notes:
  //(a)97 - (z)122
  //(A)65 - (Z)90
  char temp;

  /*--------Encryption Method----------*/
  //if letter is capital and added shift extends beyond 'Z' unicode --> loop back to beginning ('A')
  if(isupper(c) && (int(c + rshift) > 90)){
    //it is greater by: int(c + rshift) - 91
    temp = 65 + (int(c + rshift) - 91);
    return temp;
  }
  //if adding shift extends beyond 'z' unicode --> loop back to beginning ('a')
  else if (int(c + rshift) > 122){
    //it is greater by: int(c + rshift) - 123
    temp = 97 + (int(c + rshift) - 123);
    return temp;
  } else {
    return c + rshift;
  }
}

int getShiftAmountVigenere(char c){
  //Notes:
  //(a)97 - (z)122
  //(A)65 - (Z)90

  int num = 0;

  //Uppercase characters
  if (isupper(c)){
    num = int(c) - 65;
  }
  //Lowrcase characters
  else {
    num = int(c) - 97;
  }
  return num;
}
