#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

bool pelindrome_permutation(string line){
  vector<int> anagram;
  anagram.resize(256, 0);
  for(int i = 0; i < line.length(); i++ ){
    anagram[(int)line[i]]++;
  }

  int count = 0;
  vector<char> remaining_char;
  for(int i = 0; i < anagram.size(); i++ ){
    if(anagram[i]%2 == 0){
      anagram[i] = 0;
    } else{
      count++;
      remaining_char.push_back((char)i);
    }
  }
  if(count > 2) return false;
  if(count < 2) return true;
  if(count == 2){
    for(int i = 0; i < remaining_char.size(); i++){
      if(remaining_char[i] == ' ') return true;
    }
  }
  return false;
}

int main(){
  string line;
  cout << "Enter your string : ";
  getline(cin, line);

  bool result = pelindrome_permutation(line);
  if(result){
    cout << "Yes! the string have pelindrome_permutation" << endl;
  } else {
    cout << "No! the string is not pelindrome_permutation" << endl;
  }
}