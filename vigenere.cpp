#include <iostream>
#include "vigenere.h"
#include "funcs.h"

std::string encryptVigenere(std::string plaintext, std::string key){
  std::string encrypted = "";
  //looping through the plaintext --> to encrypt word
  int j = 0;
  for (int i = 0; i < plaintext.length(); i++){

    if ((j != 0) && (j % key.length() == 0)){
      j = 0;
    }

    if (isalpha(char(plaintext[i]))){
      int shift = getShiftAmount(char(key[j]));
      encrypted += shiftChar(char(plaintext[i]), shift);
      j++;
    } else {
      encrypted += plaintext[i];
    }

  }
  return encrypted;
}
