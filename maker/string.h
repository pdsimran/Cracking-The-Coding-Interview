#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#ifndef STRING_H
#define STRING_H

// Check wheather target is a substring of source.
bool is_substring(string source, string target){
  if(target.length() > source.length()) return false;
  for(int i = 0; i < (source.length()-target.length()); i++ ){
    int j = 0;
    for(j = 0; j < target.length(); j++){
      if(source[i+j] != target[j]) break; 
    }
    if(j == target.length()) return true;
  }
  return false;
}

#endif