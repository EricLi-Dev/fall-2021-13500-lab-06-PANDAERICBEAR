#include <iostream>
#include "caesar.h"

int main()
{
  std::cout << "First Test Case: Hello, World!" << std::endl;
  std::cout << encryptCaesar("Hello, World!", 10) << std::endl;
  std::cout << "Second Test Case: Bye, World!" << std::endl;
  std::cout << encryptCaesar("Bye, World!", 5) << std::endl;
  return 0;
}
