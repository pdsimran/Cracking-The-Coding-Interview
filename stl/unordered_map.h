#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>

using namespace std;

#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

void print_hash(unordered_map<int, int> hash, string name = "Hash"){
  unordered_map<int, int> :: iterator it;
  cout << name << " (" << hash.size() << ") : ";
  for(it = hash.begin(); it != hash.end(); it++ ){
    cout << it->first << ": " << it->second << " | ";
  }
  cout << endl;
}

#endif
