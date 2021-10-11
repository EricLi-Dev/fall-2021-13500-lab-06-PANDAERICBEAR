#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

// add your tests here
TEST_CASE("encryptCaesar"){
  CHECK(encryptCaesar("Pandas", 0) == "Pandas");
  CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
  CHECK(encryptCaesar("Hi, My Name is Eric Li", 10) == "Rs, Wi Xkwo sc Obsm Vs");
  CHECK(encryptCaesar("zyxwvutsrqponmlkjihgfecba", 26) == "zyxwvutsrqponmlkjihgfecba");

  CHECK(encryptCaesar("FatPandas", 2) != "IdwSdqgdv");
  CHECK(encryptCaesar("!!!,,,a...1234", 2) != "!!!,,,b...1234");
}

TEST_CASE("encryptVigenere"){
  CHECK(encryptVigenere("Pandas", "a") == "Pandas");
  CHECK(encryptVigenere("Pandas", "ab") == "Pbneat");
  CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
  CHECK(encryptVigenere("Pandas Are Cool", "panda") == "Eaagah Aeh Cdoy");

  CHECK(encryptVigenere("FatPandas", "FatPandas") == "KamEaagak");
  CHECK(encryptVigenere("Fat", "FatPandas") == "Kam");

}

TEST_CASE("decryption"){
  SUBCASE("Caesar"){
    CHECK(decryptCaesar("Pandas", 0) == "Pandas");
    CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
    CHECK(decryptCaesar("Rs, Wi Xkwo sc Obsm Vs", 10) == "Hi, My Name is Eric Li");

    CHECK(decryptCaesar("HcvRcpfcz", 2) != "FatPandas");
    CHECK(decryptCaesar("!!!,,,c...1234", 2) == "!!!,,,a...1234");
  }

  SUBCASE("Vigenere"){
    CHECK(decryptVigenere("Pandas", "a") == "Pandas");
    CHECK(decryptVigenere("Pbneat", "ab") == "Pandas");
    CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
    CHECK(decryptVigenere("Eaagah Aeh Cdoy", "panda") == "Pandas Are Cool");

    CHECK(decryptVigenere("KamEaagak", "FatPandas") == "FatPandas");
  }
}
