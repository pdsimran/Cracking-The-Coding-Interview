#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

bool is_permutation(string line1, string line2){
  vector<int> anagram;
  anagram.resize(256, 0);
  if(line1.length() != line2.length() ) return false;
  for(int i = 0; i < line1.length(); i++ ){
    anagram[(int)line1[i]]++;
  }
  for(int i = 0; i < line2.length(); i++ ){
    anagram[(int)line2[i]]--;
  }
  for(int i = 0; i < anagram.size(); i++){
    if(anagram[i] != 0) return false;
  }
  return true;
}

int main(){
  string line1, line2;
  cout << "Enter first String : ";
  getline(cin, line1);
  cout << "Enter secong String: ";
  getline(cin, line2);
  bool answer = is_permutation(line1, line2);
  if(answer){
    cout << "Yes, (" << line1 << ") and (" << line2 << ") are permutation of each other." << endl;
  } else {
    cout << "No, (" << line1 << ") and (" << line2 << ") are not permutation of each other." << endl;
  }
}