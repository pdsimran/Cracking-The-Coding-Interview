#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

#define LESS 25
#define MEDIUM 50
#define DENSE 75

void print_graph(vector< vector<int> > graph, string name = "Graph", string type = "undirected_graph"){
  int no_of_edges = 0;
  for(int i = 0; i < graph.size(); i++){
    no_of_edges += graph[i].size();
  }
  cout << "**************************" << endl;
  cout << name << "(" << graph.size() << "," << no_of_edges << "," << type<< ")" << endl;
  for(int i = 0; i < graph.size(); i++ ){
    cout << "Node " << i << ": ";
    for(int j = 0; j < graph[i].size(); j++ ){
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
}

/*
  type  => 0 - undirected_graph, 1 - directed_graph
*/
vector< vector<int> > make_graph_custom(int no_of_nodes, int no_of_edges, int (*edge_list)[2], int type){
  vector< vector<int> > graph;
  graph.resize(no_of_nodes);
  for(int i = 0; i < no_of_edges; i++){
    graph[edge_list[i][0]].push_back(edge_list[i][1]);
    if(type == 0) graph[edge_list[i][1]].push_back(edge_list[i][0]);
  }
  return graph;
}

int density_factor(int density){
  int result;
  switch(density){
    case 0:
      result = LESS;
      break;
    case 1:
      result = MEDIUM;
      break;
    case 2:
      result = DENSE;
      break;
  }
  return result;
}

void DFS(vector< vector<int> > graph, int source, vector<int> * visited){
  (*visited)[source] = 1;
  for(int i = 0; i < graph[source].size(); i++ ){
    if((*visited)[graph[source][i]] == 0){
      DFS(graph, graph[source][i], visited);
    }
  }
}

bool single_connected_component(vector< vector<int> > graph){
  vector<int> * visited = new vector<int>();
  (*visited).resize(graph.size(), 0);
  int no_of_connected_components = 0;
  for(int i = 0; i < graph.size(); i++){
    if((*visited)[i] == 0){
      DFS(graph, i, visited);
      no_of_connected_components++;
    }
  }
  return (no_of_connected_components == 1) ? true : false;
}

/*
  density =>  0 - less dense, 1 - average dense, 2 - dense
*/
vector< vector<int> > make_graph(int no_of_nodes, int density){
  srand(clock());
  vector< vector<int> > graph;
  int d_factor = density_factor(density);
  graph.resize(no_of_nodes);
  while(true){
    for(int i = 0; i < no_of_nodes; i++ ){
      for(int j = 0; j < i; j++){
        int temp = rand()%100;
        if(temp < d_factor){
          graph[i].push_back(j);
          graph[j].push_back(i);
        }
      }
    }
    bool is_connected = single_connected_component(graph);
    if(is_connected) break;
  }
  return graph;
}

#endif