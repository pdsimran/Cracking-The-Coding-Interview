#include <iostream>
#include <cstdio>

#include <string>
#include <unordered_map>

using namespace std;

void print_hash(unordered_map<string, string> hash, string name){
  cout << "---------------------" << endl;
  cout << name << " contains : " << endl;
  unordered_map<string, string> :: iterator it;
  for(it = hash.begin(); it != hash.end(); it++ ){
    cout << it->first << ":" << it->second << endl;
  }
  cout << "+++++++++++++++++++++" << endl;
}

int main(){

  // 1. Making a unordered set.
  unordered_map<string, string> string_hash;
  // This is not working right now.
  // unordered_map< string, string > string_hash2 ( {{"apple", "red"}, {"lemon", "yellow"}} );
  
  pair<string, string> first("apple", "red");
  string_hash.insert(first);
  string_hash.insert(pair<string, string>("lemon", "yellow"));
  string_hash.insert(pair<string, string>("lemon", "dup_yellow")); // will ignore the duplicate key.

  print_hash(string_hash, "string_hash");

  // 2. Capacity functions
  unordered_map<string, string> new_string_map;
  if(new_string_map.empty()){
    cout << "Yes, new_string_map is empty" << endl;
  }
  cout << "Size of string_hash = " << string_hash.size() << endl;

  // 3. Iterators
  // .begin() & .end() works in usual way.

  // 4. Element Access
  new_string_map["name"] = "Imran";   // set function
  new_string_map["company"] = "Housing"; // set function
  string name = new_string_map["name"]; // get function
  string unknown_key_value = new_string_map["department"]; // non-existing element : new key "department" is inserted.
  if(unknown_key_value == ""){
    cout << "non-existing key returns value empty string" << endl;
  }
  print_hash(new_string_map, "new_string_map");
  unordered_map<string, int > int_hash;
  int check = int_hash["id"]; // unknown key
  cout << "check = " << check << endl; // int initilize with 0 and string initiliza with empty string.

  // 5. Element Lookup
  string search_key = "name";
  unordered_map<string, string> :: iterator found = new_string_map.find(search_key);
  if(found == new_string_map.end()){
    cout << search_key << " not found!" << endl;
  } else {
    cout << search_key << " found! value = " << found->second << endl;
  }
  cout << string_hash.count("lemon") << endl; // Duplicate key lemon

  // 6. Modifiers
  unordered_map<string, string> again_new;
  again_new.insert(string_hash.begin(), string_hash.end()); // range insertion
  again_new.insert(new_string_map.begin(), new_string_map.end()); // range insertion
  again_new.insert(pair<string, string>("just_a_key", "just_a_value"));
  print_hash(again_new, "again_new");

  again_new.erase("just_a_key"); // erasing by key-name
  again_new.erase(again_new.begin()); // erasing by iterator
  // unordered_map containers do not follow any particular order to organize its elements,
  // therefore the effect of range deletions may not be easily predictable.
  again_new.erase(again_new.find("department"), again_new.end());
  print_hash(again_new, "again_new");
  string_hash.clear();
  new_string_map.clear();
  again_new.clear();
  print_hash(string_hash, "string_hash");
}