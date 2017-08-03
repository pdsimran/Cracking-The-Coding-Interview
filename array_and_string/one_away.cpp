#include <iostream>
#include <cstdio>

using namespace std;

bool one_away(string line1, string line2){
  
}

int main(){
  string line1, line2;
  cout << "Enter the first string : ";
  getline(cin, line1);
  cout << "Enter the second string : ";
  getline(cin, line2);

  bool answer = one_away(line1, line2);
  if(answer){
    cout << "Yes! (" << line1 << ") and (" << line2 <<") are one_away." << endl;
  } else{
    cout << "No! (" << line1 << ") and (" << line2 <<") are not one_away." << endl;
  }
}