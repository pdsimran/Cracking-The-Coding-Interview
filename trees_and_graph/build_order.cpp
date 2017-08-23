 #include <iostream>
#include <cstdio>
#include <cstdlib>

#include <map>
#include <vector>
#include <list>

using namespace std;

void dfs_visit(map<char, vector<char> > graph, char source, map<char, int> *visited, list<char> *order){
  (*visited)[source] = 1;
  for(int i = 0; i < graph[source].size(); i++){
    if( (*visited)[graph[source][i]] == 0){
      dfs_visit(graph, graph[source][i], visited, order);
    }
  }
  (*order).push_front(source);
}

void find_build_order(map<char, vector<char> > graph, map<char, int> *visited, list<char> *order){
  map<char, vector<char> > :: iterator graph_it;
  map<char, int> :: iterator visited_it;

  for(graph_it = graph.begin(); graph_it != graph.end(); graph_it++ ){
    visited_it = (*visited).find(graph_it->first);
    if(visited_it->second == 0){
      dfs_visit(graph, graph_it->first, visited, order);
    }
  }
}

int main(){
  map<char, vector<char> > graph;
  map<char, vector<char> > :: iterator it;
  int no_of_projects;
  cin >> no_of_projects;
  for(int i = 0; i < no_of_projects; i++){
    char temp;
    vector<char> list;
    cin >> temp;
    graph[temp] = list;
  }
  int no_of_dependencies;
  cin >> no_of_dependencies;
  for(int i = 0; i < no_of_dependencies; i++){
    char temp1, temp2; 
    cin >> temp1 >> temp2;
    it = graph.find(temp1);
    (it->second).push_back(temp2);
  }

  // printing the graph
  for(it = graph.begin(); it != graph.end(); it++){
    cout << "key " << it->first << " : ";
    for(int i = 0; i < (it->second).size(); i++ ){
      cout << (it->second)[i] << " ";
    }
    cout << endl;
  }

  list<char> order;
  map<char, int> visited;
  for(it = graph.begin(); it != graph.end(); it++ ){
    visited[it->first] = 0;
  }

  find_build_order(graph, &visited, &order);
  cout << "Ouput Order => ";
  while(!order.empty() ){
    cout << order.front() << " ";
    order.pop_front(); 
  }
  cout << endl;
}