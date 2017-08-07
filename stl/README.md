##### Unordered Map (C++ 11)
* unordered_map<string, string> hash
* hash.insert(pair<string, string>)
* hash.insert(another_hash.begin(), another_hash.end())
* hash.empty()
* hash.size()
* hash["key"] = value // set a value
* value = hash["key"] // get a value
* hash.find("key")
* hash.erase("key")
* hash.erase(it)

##### Unordered Set (C++ 11)
* unordered_set<string> uset;
* uset.insert(string)
* uset.empty()
* uset.size()
* uset.find(string)

##### String
* string str
* string str("some string") // initialization
* str(length, char) // make string with repeating 'char' of 'length'. 
* str.length()
* str.replace(pos, len, new_str)
* str.push_back(char)

##### Vector
* vector<int> vect
* vect.resize(size)
* vect.resize(size, value)

##### Stack
* stack<int> my_stack;
* my_stack.push(value);
* my_stack.pop();	// void return;
* my_stack.top();   // return a refrence to the top_element of the stack. Reference can be used to access or modify the top element. throws segmentation fault is stack is empty()
* my_stack.size();
* my_stack.empty();



##### include<cstdlib>
* abs(value)
