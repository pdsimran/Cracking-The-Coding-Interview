#include <iostream>
#include <cstdio>
#include <string>

#include "../maker/string.h"

using namespace std;

bool string_rotation(string source, string target){
  target = target + target;
  if(is_substring(target, source)){
    return true;
  } else {
    return false;
  }
}

int main(){
  string line1, line2;
  cout << "Enter your first string : ";
  getline(cin, line1);
  cout << "Enter your second string: ";
  getline(cin, line2);

  bool answer = string_rotation(line1, line2);
  if(answer){
    cout << "Yes!, (" << line1 << ") , (" << line2 << ") are string rotation" << endl;
  } else{
    cout << "No!, (" << line1 << ") , (" << line2 << ") are not string rotation" << endl;
  }
}