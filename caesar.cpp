#include <iostream>
#include "caesar.h"
#include "funcs.h"

std::string encryptCaesar(std::string plaintext, int rshift){
  std::string encrypted;
  for (int i = 0; i < plaintext.length(); i++){
    if(isalpha(char(plaintext[i]))){
      char c = shiftChar(char(plaintext[i]), rshift);
      encrypted += c;
    } else {
      encrypted += plaintext[i]; //adds punctuation marks without char shift
    }

  }
  return encrypted;
}
