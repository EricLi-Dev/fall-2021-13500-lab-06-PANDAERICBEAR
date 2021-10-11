#include <iostream>
#include "caesar.h"

std::string encryptCaesar(std::string plaintext, int rshift){
  std::string encrypted;
  for (int i = 0; i < plaintext.length(); i++){
    if(isalpha(char(plaintext[i]))){
      char c = shiftCharCaesar(char(plaintext[i]), rshift);
      encrypted += c;
    } else {
      encrypted += plaintext[i]; //adds punctuation marks without char shift
    }

  }
  return encrypted;
}

char shiftCharCaesar(char c, int rshift){
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
