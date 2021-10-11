#pragma once
#include <iostream>

std::string encryptVigenere(std::string plaintext, std::string key);
char shiftCharVigenere(char c, int rshift);
int getShiftAmountVigenere(char c);
