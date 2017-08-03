#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string generate_compressed_string(string line){
  int char_start = 0;
  int char_current = 0;
  string answer("");

  while(char_current < line.length()){
    if(line[char_start] == line[char_current]){
      char_current++;
    } else{
      answer.push_back(line[char_start]);
      answer.push_back((char)((char_current-char_start)+48));
      char_start = char_current;
    }
  }
  answer.push_back(line[char_start]);
  answer.push_back((char)((char_current-char_start)+48));
  return answer;
}

string string_compression(string line){
  string compressed_string = generate_compressed_string(line);
  if(compressed_string.length() < line.length()){
    return compressed_string;
  } else {
    return line;
  }
}

int main(){
  string line;
  cout << "Enter your string : ";
  getline(cin, line);

  string answer = string_compression(line);
  cout << "Result after string compression : " << answer << endl;
}