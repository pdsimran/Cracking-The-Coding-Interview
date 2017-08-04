#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "../maker/matrix.h"

using namespace std;

int ** zero_matrix(int ** matrix, int row_size, int column_size){
  vector<int> zero_row;
  vector<int> zero_column;
  zero_row.resize(row_size, 0);
  zero_column.resize(column_size, 0);

  for(int i = 0; i < row_size; i++){
    for(int j = 0; j < column_size; j++){
      if(matrix[i][j] == 0){
        zero_row[i] = 1;
        zero_column[j] = 1;
      }
    }
  }

  for(int i = 0; i < zero_row.size(); i++ ){
    if(zero_row[i] == 1){
      for(int j = 0; j < column_size; j++ ){
        matrix[i][j] = 0;
      }
    }
  }

  for(int i = 0; i < zero_column.size(); i++ ){
    if(zero_column[i] == 1){
      for(int j = 0; j < row_size; j++){
        matrix[j][i] = 0;
      }
    }
  }

  return matrix;
}

int main(){
  int row_size, column_size;
  cout << "Enter the value of row_size and column_size : ";
  cin >> row_size >> column_size;
  int ** matrix = make_matrix(row_size, column_size, 0, 9);
  print_matrix(matrix, row_size, column_size, "Input Matrix");
  matrix = zero_matrix(matrix, row_size, column_size);
  print_matrix(matrix, row_size, column_size, "Zero Matrix");
}