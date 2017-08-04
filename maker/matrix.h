#include <iostream>
#include <cstdio>

using namespace std;

#ifndef MATRIX_H
#define MATRIX_H

int ** make_matrix(int row_size, int column_size, int min_value = INT_MIN/2, int max_value = INT_MAX){
  int ** matrix;
  srand(time(NULL));

  matrix = (int **)malloc(row_size*sizeof(int *));
  for(int i = 0; i < row_size; i++ ){
    matrix[i] = (int *)malloc(column_size*sizeof(int));
  }

  for(int i = 0; i < row_size; i++){
    for(int j = 0; j < column_size; j++){
      matrix[i][j] = min_value+rand()%(max_value-min_value+1);
    }
  }

  return matrix;
}

void print_matrix(int ** matrix, int row_size, int column_size, string name = "Matrix"){
  cout << name << " (" << row_size << ", " <<column_size << ") : " << endl;
  for(int i = 0; i < row_size; i++){
    for(int j = 0; j < column_size; j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

#endif