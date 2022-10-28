//Mack Foggia - CS 350 - April 2021
//Long Multiplication

//Program to perform long multiplication on two non-negative integers

#include <iostream>
#include <string.h>
using namespace std;


//Function to reverse the contents of a string
void reverse(string &);



//Main
int main(int argc, char * argv[]){
/*  Used to use command line args

  //Check for proper number of inputs
  if(argc < 3){
    cout << "Too few command line args." << endl;
    return 0;
  }
  
  //Read in numbers from command line and organize them
  string x = argv[1];
  string y = argv[2];
*/


  //Read in numbers from user and organize them
  string x, y;
  cout << "Enter first number: ";
  getline(cin, x);
  cout << "Enter second number: ";
  getline(cin, y);
  if (y.length() < x.length()) x.swap(y);
  reverse(x);
  reverse(y);
  
  //Create result array
  short resultSize = y.length() + x.length();
  //short result[resultSize]; //why did this work lol
  short * result = new short[resultSize];
  for(int i = 0; i < resultSize; ++i) result[i] = 0;

  //Loop through both strings performing the multiplication
  for(int b = 0; b < y.length(); ++b){
    short carry = 0;
    short finalIndex = 0;
    for(int a = 0; a < x.length(); ++a){
      short hold = (((int)y[b]-48) * ((int)x[a]-48) + carry);
      short rem = hold % 10;
      result[a+b] += rem;
      carry = (hold - rem) / 10;
      if(a + 1 == x.length()) finalIndex = a + b + 1;
    }
    result[finalIndex] += carry;
  }

  //The above doesn't account for carrying when adding,
  //so we must manually adjust for this
  for(int i = 0; i < resultSize; ++i){
    if(result[i] >= 10){
      short rem = result[i] % 10;
      result[i + 1] += (result[i] - rem) / 10;
      result[i] = rem;
    }
  }

  //Now print the thing
  cout << "Result: ";
  bool flag = false;
  for(int i = resultSize - 1; i >= 0; --i){
    if(!flag && result[i] != 0) flag = true;
    if(flag) cout << result[i];
  }
  cout << endl;

  delete [] result;

  return 0;
}


//Function to reverse the contents of a string
void reverse(string & rev){
  string copy(rev);
  int len = rev.length();
  for(int i = 0, j = len - 1; i < len; ++i, --j){
    copy[i] = rev[j];
  }
  rev = copy;
}
