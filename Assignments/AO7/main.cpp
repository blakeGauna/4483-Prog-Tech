// Blake Gauna
// CMPS - 4883
// This program is a solution to "Rails"
// using a stack and a queue for the train
// order

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {

  int trainCount;
  int num;

  // Read the train count in
  while (cin >> trainCount && trainCount != 0) {

    // While there is a valid first number
    while (cin >> num && num != 0) {

      // We create a stack to represent the station

      // We also need a queue to keep track of the order
      // that is read in.
      stack<int> theStation;
      queue<int> trains;

      // Create a variable that starts at 1, since this is the
      // number of the first train coming in and push the cin we
      // just read into the first queue.
      int trainNum = 1;
      trains.push(num);

      // Loop through the rest of the trainCount - 1 since we
      // already have the first, and push them into the queue.
      for (int i = 0; i < trainCount - 1; i++) {
        cin >> num;
        trains.push(num);
      }

      // While we go through the original train order (1, 2, 3, 4, 5),
      // We see if the train number is equal to the first train number
      // requested. If it isn't equal, then we push the first train to the
      // stack.

      // Example:   The requested order is 3 5 4 2 1
      //
      //
      //            When train number 1 comes in, we see that it
      //            is not the requested train 3, so we send it to the
      //            stack.
      //            Then, number 2 comes in. We see that it is still
      //            not the requested train 3, so we send train 2 to
      //            the stack.
      //            Then, number 3 comes in. We see that it is the
      //            requested train, so we push it to the stack.
      //            Once on the stack, we have a check that sees
      //            if the top of the stack is equal to the front of
      //            the train order. It hits this check and removes the
      //            train number from both the stack and the queue, meaning
      //            the train has drove on through.

      while (trains.empty() == false) {
        // If the station is empty or the front train at the station is not
        // the next required train, then push the current train to the
        // station.
        if (theStation.empty() || theStation.top() != trains.front()) {

          // If we go through all trains and the top of the stack
          // doesn't equal the next in order train, then we break
          // from the while loop
          if (trainNum > trainCount) {
            break;
          }
          theStation.push(trainNum++);
        }
        // However, if the train at the top of the stack is equal to the
        // front of the requested train order, pop from both the stack and
        // queue. This is equivalent to the train stopping at the station
        // and immediately going on through
        else {
          theStation.pop();
          trains.pop();
        }
      }
      // If we hit our break statement
      if (trains.empty()) {
        cout << "Yes" << endl;
      } else
        cout << "No" << endl;
    }
    cout << endl;
  }
  return 0;
}
