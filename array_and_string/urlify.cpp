#include <iostream>
#include <cstdio>

using namespace std;

string urilify(string line){
  string replace_str = "%20";
  for(int i = 0; i < line.length(); i++ ){
    if(line[i] == ' '){
      line.replace(i,1,replace_str);
    }
  }
  return line;
}

int main(){
  string line;
  cout << "Enter your string : ";
  getline(cin, line);
  string urlifies_str = urilify(line);
  cout << "Urilified string : " << urlifies_str << endl;
}