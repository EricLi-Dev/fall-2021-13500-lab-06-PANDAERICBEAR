#include <iostream>
#include <cctype>
#include "decrypt.h"

std::string decryptVigenere(std::string plaintext, std::string key){
  std::string decrypted = "";

  int j = 0;
  for (int i = 0; i < plaintext.length(); i++){
    if ((j != 0) && (j % key.length() == 0)){
      j = 0;
    }

    if (isalpha(char(plaintext[i]))){
      int shift = getShiftAmount(char(key[j]));
      decrypted += decryptShiftChar(char(plaintext[i]), shift);
      j++;
    } else {
      decrypted += plaintext[i];
    }
  }
  return decrypted;
}

std::string decryptCaesar(std::string plaintext, int rshift){
  std::string decrypted;
  for (int i = 0; i < plaintext.length(); i++){
    if(isalpha(char(plaintext[i]))){
      char c = decryptShiftChar(char(plaintext[i]), rshift);
      decrypted += c;
    } else {
      decrypted += plaintext[i]; //adds punctuation marks without char shift
    }
  }

  return decrypted;
}

char decryptShiftChar(char c, int rshift){
  //Notes:
  //(a)97 - (z)122
  //(A)65 - (Z)90
  char temp;

  /*--------Decryption Method----------*/
  //if letter is uppercase --> separated because of some weird subtraction edge bound case encountered
  if(isupper(c)){
    if ((int(c - rshift) < 65)){ //if shift extends below bound
      //it is smaller by: 65 - int(c - rshift)
      temp = 91 - (65 - int(c - rshift));
      return temp;
    } else { //if not, then shift normally
      return c - rshift;
    }
  } else if (int(c - rshift) < 97){ //if shift extends below bound (lowercase)
    //it is greater by: 97 - int(c + rshift)
    temp = 123 - (97 - int(c - rshift));
    return temp;
  }
  else {
    return c - rshift; //shift normally
  }
}

int getShiftAmount(char c){
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
