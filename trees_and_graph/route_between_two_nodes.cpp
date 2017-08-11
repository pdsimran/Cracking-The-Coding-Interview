#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <climits>

#include "../maker/graph.h"

vector<int> BFS(vector< vector<int> > graph, int source){
  queue<int> q;
  vector<int> visited;  visited.resize(graph.size(), 0);
  vector<int> parent;   parent.resize(graph.size(), -1);
  vector<int> distance; distance.resize(graph.size(), INT_MAX);

  q.push(source);
  visited[source] = 1;
  distance[source] = 0;

  while(!q.empty()){
    int front = q.front();
    for(int i = 0; i < graph[front].size(); i++){
      if(visited[graph[front][i]] == 0){
        q.push(graph[front][i]);
        visited[graph[front][i]] = 1;
        parent[graph[front][i]] = front;
        distance[graph[front][i]] = distance[front]+1;
      }
    }
    q.pop();
  }
  return visited;
}

bool route_two_nodes(vector< vector<int> > graph, int node1, int node2){
  vector<int> visited = BFS(graph, node1);
  return (visited[node2] == 1) ? true : false;
}

int main(){
  int no_of_nodes, no_of_edges;
  cin >> no_of_nodes >> no_of_edges;
  int (*edge_list)[2];
  edge_list = (int (*)[2])malloc(no_of_edges*sizeof(int[2]));
  for(int i = 0; i < no_of_edges; i++){
    cin >> edge_list[i][0] >> edge_list[i][1];
  }
  vector< vector<int> > graph = make_graph_custom(no_of_nodes, no_of_edges, edge_list, 1);
  print_graph(graph, "Input Graph", "direcrted graph");

  for(int i = 0; i < no_of_nodes; i++ ){
    for(int j = 0; j < no_of_nodes; j++ ){
      if(i == j) continue;
      bool is_routing_possible = route_two_nodes(graph, i, j);
      if(is_routing_possible){
        cout << "Routing possible between Node " << i << " and Node " << j << endl;
      } else {
        //cout << "Routing Not possible between Node " << i << " and Node " << j << endl;
      }
    }
  }

}