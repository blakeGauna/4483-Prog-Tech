#include <iostream>

using namespace std;

int main() {
  int testCases, firstNum, secondNum, sum = 0;
  bool triggered = false;
  cin >> testCases;
  for(int i = 0; i < testCases; i++){
      cin >> firstNum >> secondNum;
      while(firstNum <= secondNum){
        if(firstNum % 2 != 0 && triggered == false){
           sum += firstNum;
           firstNum += 2;
           triggered = true;
          }
        else if (firstNum % 2 == 0 && triggered == false){
          firstNum += 1;
          sum += firstNum;
          firstNum += 2;
          triggered = true;
        }
        else {
          sum += firstNum;
          firstNum += 2;
        }
      }
      cout << "Case " << i + 1 << ": " << sum << endl;
      triggered = false;
      sum = 0;
      firstNum = 0;
      secondNum = 0;
  }
  return 0;
}