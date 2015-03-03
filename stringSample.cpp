/*
Alfred Shaker
2/26/2015
StringSample program that taken in strings from a file and does the following:
  a) Reverse the string if its length is a multiple of 4.
  b) Truncate the string to 5 characters if its length is a multiple of 5.
  c) Convert the string to all uppercase if it contains at least 3 uppercase characters in the first 5 characters.
  d) If the string ends with a hyphen, remove it, and append the next string in the list to the current one.
  e) Print the string out.

 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cctype>
#include <ctype.h>

using std::endl;
using std::string;
using std::cout;
using std::vector;
using std::ifstream;
using std::getline;

//our function prototypes
//for the four different conditions
//definitions of each after main
void resizeFour(string);
void truncateFive(string);
void upperFive(string);
bool dashEnd(string);

//the variables that will store
//string length data for us

double totalChars = 0;
double totalFinalChars = 0;
double stringCount = 0;
double medianLength = 0.0;


//main function

int main(int argc,  char* argv[]){

  //vector declaration and clearing
  
  vector<string> stringList;
  stringList.clear();

  //declaring the string variable and input file
  
  string inputString;
  ifstream inputFile("strings.txt");

  //loop in each line and put it as a string
  //in out vector of strings

  while(getline(inputFile, inputString))
  {
    stringList.push_back(inputString);
  }


  //loop through each string in the vector
  //performing the operations on it as we go
  
  for (int i = 0; i < stringList.size(); ++i)
    {
      cout << "string number " << i << " : " << stringList[i] << endl;
      cout << "string size: " << stringList[i].length() << endl;

      //add to the total characters and string count
      totalChars += stringList[i].length();
      stringCount += 1;

      //check condition a)
      if (stringList[i].length() % 4 == 0)
        {
	  resizeFour(stringList[i]);
	}

      //check condition b)
      if (stringList[i].length() % 5 == 0)
	{
	  truncateFive(stringList[i]);
	}

      //check condition c)
      upperFive(stringList[i]);

      //check condition d)
      if (dashEnd(stringList[i]))
	{
	  cout << "removing the - " << endl;
	  stringList[i].erase(stringList[i].length() - 1);
	  int j = i +1;
	  if (j < stringList.size())
	    {
	  stringList[i] = stringList[i] + stringList[i+1];
	  cout << "new combined string = " << stringList[i] << endl;
	    
	  totalFinalChars += stringList[i].length();
	  stringCount += 1;
	    }
	  else
	    {
	      cout << "no string after " << stringList[i] << " to append to " << endl;
	      cout << "result string: " << stringList[i] << endl;

	      totalFinalChars += stringList[i].length();
	      stringCount += 1;
	    }
	}
    }

  //get the median length of all the strings
  //output the data collected
  medianLength = (totalChars + totalFinalChars)/stringCount;
  cout << "total number of input characters: " << totalChars << endl;
  cout << "total number of output characters: " << totalFinalChars << endl;
  cout << "total number of string: " << stringCount << endl;
  cout << "median length of all strings: " << medianLength << endl;
  return 0;
}

//takes in string and checks for condition a)
//if length is a multiple of 4 reverse string
void resizeFour(string str)
{
   cout << "string " << str << " is a multiple of 4, therefore it will be reversed" << endl;
   for (string::reverse_iterator rit = str.rbegin(); rit != str.rend(); ++rit)
     {
       cout << *rit;
       totalFinalChars += 1;
     }
   cout << endl;
   stringCount += 1;
    
}

//takes in a string and checks for condition b)
//if length is a multiple of 5, truncate string to 5 chars
void truncateFive(string str)
{
  cout << "string " << str << " is a multiple of 5, therefore we will truncate it's length to five" << endl;
  string result = str.substr (0, 5);
  cout << result << endl;
  totalFinalChars += result.length();
  stringCount += 1;
  
}

//takes in a string and checks for condition c)
//if 3 uppercase chars found in first 5 chars,
//uppercase whole string
void upperFive(string str)
{
  int upperCount = 0;
  for (int i = 0; i < 5; ++i)
    {
      if(isupper(str[i]))
	{
	  upperCount += 1;
	}
    }

  if (upperCount >= 3)
    {
      cout << "at least three uppercase letters found in first 5 letters" << endl;
      for (int i = 0; i < str.length(); ++ i)
	{
	  str[i] = toupper(str[i]);
	}
      cout << "result string: " << str << endl;
      totalFinalChars += str.length();
      stringCount += 1;
    }
}

//boolean that takes in string to check for condition d)
//returns true is there is a "-" at the end of a string
bool dashEnd(string str)
{
  if (str.find_last_of("-") != string::npos)
    {
      cout << str << " ends with a - " << endl;
      return true; 
    }
  return false;
}

