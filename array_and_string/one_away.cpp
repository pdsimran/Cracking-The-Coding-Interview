#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool find_one_away(string s1, string s2){
  int start = 0;
  int end = s1.length()-1;

  for(int i = 0; i < s1.length(); i++){
    if(s1[start] == s2[start]) start++;
    if(s1[end] == s2[end+1]) end--;
  }
  if(start-1 == end) return true;
  else return false;
}

bool one_away(string line1, string line2){
  int length_diff = line1.length()-line2.length();
  if( length_diff < -1 || length_diff > 1 ) return false;
  if( line1.length() == line2.length() ){
    int mistakes = 0;
    for(int i = 0; i < line1.length(); i++){
      if(line1[i] != line2[i]) mistakes++;
    }
    if(mistakes < 2) return true;
    else return false;
  }
  if(line1.length() < line2.length()){
    return find_one_away(line1, line2);
  } else {
    return find_one_away(line2, line1);
  }
}

int main(){
  string line1, line2;
  cout << "Enter the first string : ";
  getline(cin, line1);
  cout << "Enter the second string : ";
  getline(cin, line2);

  bool answer = one_away(line1, line2);
  if(answer){
    cout << "Yes! (" << line1 << ") and (" << line2 <<") are just one_away." << endl;
  } else{
    cout << "No! (" << line1 << ") and (" << line2 <<") are not one_away." << endl;
  }
}