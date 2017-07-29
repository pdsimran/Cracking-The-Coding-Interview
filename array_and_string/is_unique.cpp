#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_set>

using namespace std;

bool is_unique1(string line){
  unordered_set<char> unique_set;
  unordered_set<char> :: iterator it;
  for(int i = 0; i < line.length(); i++){
    it = unique_set.find(line[i]);
    if(it == unique_set.end()){
      unique_set.insert(line[i]);
    } else{
      return false;
    }
  }
  return true;
}

bool is_unique2(string line){
  string bitmap(256, '0');
  for(int i = 0; i < line.length(); i++ ){
    if(bitmap[line[i]] == '0'){
      bitmap[line[i]] = '1';
    } else {
      return false;
    }
  }
  return true;
}

int main(){
  string line;
  cout << "Enter your string: ";
  getline(cin, line);
  bool is_unique = is_unique1(line);
  if(is_unique){
    cout << "Yes, (" << line << ") containes unique character." << endl;
  } else {
    cout << "No, (" << line << ") does not contains unique character" << endl;
  }
  cout << "************************" << endl;
  is_unique = is_unique2(line);
  if(is_unique){
    cout << "Yes, (" << line << ") containes unique character." << endl;
  } else {
    cout << "No, (" << line << ") does not contains unique character" << endl;
  }
}