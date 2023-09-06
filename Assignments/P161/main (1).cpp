// Blake Gauna
// CMPS 4883 - Programming Techniques
// Traffic Lights - P161

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> times;
  int time = 0;
  int totalTime = 0;
  bool LightsGreen = false;

  // A file will never start with 0, so we start cin'ing 
  // the times into the empty times vector

  while (cin >> time && time != 0) {
    times.push_back(time);
    cin >> time;
    // Keep reading while the next time is a 0
    while (time != 0) {
      times.push_back(time);
      cin >> time;
    }
    
    // We start when the shortest cycle time traffic light becomes
    // green again.
    totalTime = *min_element(times.begin(), times.end()) * 2;

  
    do {
      LightsGreen = true;
      
      // Declare I, which is an interator through the vector, and
      // take each value, take the mod of the current cycle time * 2, and see
      // if the cycle time - 5 is bigger than the mod of the current cycle time * 2

      // The * is there for the vector <int> iterator.
      // totalTime % (*i * 2)
      
      // Example input: 19 20 0
      
      // totalTime would be 38 seconds since that is the min cycle count * 2

      // First cycle time (19)
      
      // 38 % (19 * 2) = 38 % 38 = 0 
      // (19 - 5) = 14
      // 0 < 14 == true

      // Second cycle time (20)
      
      // 38 % (20 * 2) = 38 % 40 = 0 (Remainder 38) = 38
      // We can see that we are 38 seconds in and the cycle time 
      // of the light
      // is 20. This means it is 18 seconds into the red light currently.
      // (20 - 5) = 15
      // 38 < 15 == false
      // When we hit a false, we increase the totalTime by 1 and set
      // LightsGreen to false

      // However when we hit 40 seconds.
      // 40 % (20 * 2) = 40 % 40 = 0
      // (20 - 5) = 15
      // 0 < 15.
      // When this is true for all cycle counts, then all the lights
      // are green

      
      //Go through the cycle times in the current vector
      for (int i = 0; i < times.size(); i++){
        
         // cout << "The iterator value is: " << *i << ". The total time is: " 
         // << totalTime << ". " <<  totalTime % (*i * 2) << "   " <<
         // (*i - 5) << endl;
        
        if ((totalTime % (times[i] * 2) < (times[i] - 5)) == false) {
          LightsGreen = false;
          break;
        }
      }
      
    } while (LightsGreen == false && totalTime++ <= 18000);

    // Print if all lights are green
    if (LightsGreen == true) {
      int hour = totalTime / 3600;
      int minute = (totalTime % 3600) / 60;
      int seconds = (totalTime % 3600) % 60;
      cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":"
           << setw(2) << seconds << endl;
    } else {
      cout << "Signals fail to synchronise in 5 hours\n";
    }
    // Since we are done working with this set of numbers, we clear the vector and 
    // continue to look for the next set of numbers and also looking for the delimiter 0.
    times.clear();
    LightsGreen = false;
  }

  return 0;
}