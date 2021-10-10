#include <iostream>

void testAscii(std::string input);
using std::cout;
using std::endl;

int main(){
  std::string input = "Cat :3 Dog";
  testAscii(input);
  return 0;
}

void testAscii(std::string input){
  for (int i = 0; i < input.length(); i++){
    cout << input[i] << " " << int(char(input[i])) << endl;
  }
}
