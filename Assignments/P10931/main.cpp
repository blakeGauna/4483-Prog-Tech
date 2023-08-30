#include <iostream>
#include <bitset>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int n;
  std::string::difference_type i;
  size_t found;
  
  while(cin >> n){
    if(!n) break;
    //if we hit a 1, then we dont go into the if and do stuff
    string binary = bitset<128>(n).to_string();
    binary = binary.erase(0, binary.find_first_not_of('0'));
    cout << "The parity of " + binary + " is ";
    cout << count(binary.begin(), binary.end(), '1') << " (mod 2)." << endl;
  }
  
  return 0;
}