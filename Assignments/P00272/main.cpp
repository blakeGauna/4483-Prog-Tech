// ./main < data

#include <iostream>

using namespace std;

int main() { 
  char ch;
  bool beginningQuote = true;

  //noskipws makes sure the spaces aren't skipped
  while(cin >> noskipws >> ch){
    //if the character is quotes in ascii and is the beginning quote
    if(ch == 34 && beginningQuote){
      cout << "``";
      beginningQuote = false;
    }
    //if the character is quotes in ascii and is the ending quote
    else if (ch == 34 && beginningQuote == false){
      cout << "''";
      beginningQuote = true;
    }
    //any other character
    else{
      cout << ch;
    }
  }
   
}