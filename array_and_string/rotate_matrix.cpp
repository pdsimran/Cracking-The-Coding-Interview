#include <iostream>
#include <cstdio>

#include "../maker/matrix.h"

using namespace std;

void rotate_matrix(int ** matrix, int size){
  for(int layer = 0; layer < size/2; layer++){
    for(int j = layer; j < size-1-layer; j++){

      int temp = matrix[layer][j];
      matrix[layer][j] = matrix[j][size-1-layer];
      matrix[j][size-1-layer] = matrix[size-1-layer][size-1-j];
      matrix[size-1-layer][size-1-j] = matrix[size-1-j][layer];
      matrix[size-1-j][layer] = temp;

    }
  }
  print_matrix(matrix, size, size, "Rotated Matrix");
}

int main(){
  int row_size = 4;
  int column_size = 4;
  int ** matrix = make_matrix(row_size, column_size, 10, 99);
  print_matrix(matrix, row_size, column_size, "Input Matrix");
  rotate_matrix(matrix, row_size);
}

