#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"

// add your tests here
TEST_CASE("Encrypt Caesar"){
  CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
}
