//Blake Gauna
//CMPS - 4883 - Programming Techniques
//10226 - Hardwood Species

#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main() {

  //Creating two strings, one to hold the line we
  //read and a temporary string to get the number
  //of test cases
  string str, str_testCase;
  //Map with string as the key and int as the value
  map<string, double> trees;
  double testCases, jobCycle, totalTrees = 0; 
  //Read test cases
  getline(cin, str_testCase);
  //Turn into an integer
  testCases = stoi(str_testCase);
  //Read empty line in input so it doesn't affect
  //future reads
  getline(cin, str_testCase);
  
  do{
    
    //Read from the file line by line
    getline(cin, str);
    
    //If the line is empty, then we know we've either
    //reached the end of a test case or the end of the
    //input
    //Otherwise if the line isn't empty, then we read
    //it as normal
    if (str == "" || !cin){
      
      //Increment jobCycle if we reach an empty line
       jobCycle++;
      
      //Iterate through the map and print the trees
      for (auto i : trees){
         cout << i.first << " " << setprecision(4) << fixed << ((i.second)/totalTrees) * 100 << endl;
  }
      
      //Clear map since we will use it again for multiple test cases
      trees.clear();
      
      //If we reached the final test case, then we don't need
      //to print the final line 
      if(jobCycle != testCases){
        cout << endl;
      }
      
      //Reset totalTrees counter
      totalTrees = 0;
  }
      
    //If the line isn't empty, then we read
    //it as normal
    else{
      //Increment the trees map at the key of whatever tree we
      //just read in and raise the totalTrees counter by 1.
      trees[str]++;
      totalTrees++;
      
    }
    //While the current jobCycle (test case) we are on is less than the 
    //total test cases, keep looping.
 } while (jobCycle < testCases);
  
  return 0;
}