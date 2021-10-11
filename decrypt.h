#pragma once
#include <iostream>

std::string decryptVigenere(std::string plaintext, std::string key);
std::string decryptCaesar(std::string plaintext, int rshift);
char decryptShiftChar(char c, int rshift);
