//Blake Gauna
//CMPS 4883 - Unlock the Lock
//This program is a solution to Unlock the Lock UVA problem.


#include <iostream>
#include <queue>

using namespace std;

int main() {

  //Create a "lock" with 4 digit code, then variables for
  //reading in and storing things.
  int lock[10000], L, U, R, button[10], currentNum = 0;
  int caseNum = 1;
  bool printed = false;
  queue<int> q;

  //While reading in from the file and the digits
  //dont equal 0.
  while (cin >> L >> U >> R && (L + U + R != 0)) {
    //Read in the lock codes
    for (int i = 0; i < R; i++) {
      cin >> button[i];
    }

    cout << "Case " << caseNum << ": ";
    caseNum++;
    printed = false;

    //If the code is initially equal to the unlock code
    if (L == U) {
      
      //Set the amount of times we had to click the
      //button to change the lock code.
      lock[L] = 0;
      cout << lock[L] << endl;
      printed = true;
      continue;
    } 
    else {
      //Set all the array values (lock numbers) to something
      //we know hasn't been visited.
      for (int i = 0; i < 10000; i++) {
        lock[i] = -1;
      }
      
      //Set current lock code array value to = 0. 
      //This will act as a starting counter for all
      //the times we have pressed the button on each
      //cycle that we go through.
      //Since all the locks are -1, we can keep track
      //of the amount of button presses by keeping
      //the count on each individual path we go on.
      //For example, if we are on code 1047, then
      //we can do lock[1047] = lock[previous code] + 1.
      //If we were to land on lock[1047] again, it would
      //not equal -1, so we skip it.
      lock[L] = 0;
      
      //Push the lock code onto the queue
      q.push(L);
      while (!q.empty()) {
        //Set the lock code to be equal to the front of the queue
        L = q.front();
        //Pop the value to be done with it.
        q.pop();
        
        //Loop through the lock codes and add the code to the 
        //current number.
        for (int i = 0; i < R; i++) {
          currentNum = L + button[i];

          //If the current number is over 9999, subtract 10,000
          //since the lock uses the least 4 significant digits.
          if (currentNum > 9999) {
            currentNum -= 10000;
          }
          //If the current lock number has not been entered yet
          //(not been visited in the array), then keep count of how
          //many cycles we have been going through by adding 1 to the 
          //value of the last lock array value.
          if (lock[currentNum] == -1) {
            lock[currentNum] = lock[L] + 1;

            //If the current number is equal to the unlock
            //code, then display the amount of times we have
            //pressed the button (current lock code array value)
            //and set printed to true.
            if (currentNum == U) {
              cout << lock[U] << endl;
              printed = true;
              break;
            }

            //If the current number is not equal to the unlock
            //code, push the current lock code number onto the
            //queue
            q.push(currentNum);
          }
        }
      }
      //If we go through all possible lock codes and the 
      //current number never equals the unlock code,
      //print "permanently locked"
      if (currentNum != U && printed == false){
        cout << "Permanently Locked" << endl;
      }
    }
    
  }
  return 0;
}