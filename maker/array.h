#include <iostream>
#include <cstdio>
using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

int * make_array(int size, int min = INT_MIN/2, int max = INT_MAX/2){
	int * output;
	srand (time(NULL));

	output = (int *)malloc(size*sizeof(int));
	for(int i = 0; i < size; i++ ){
		output[i] = min + rand()%(max-min+1);
	}

	return output;
}

bool is_unique(int * output, int size, int value){
	for(int i = 0; i < size; i++ ){
		if (output[i] == value) return false;
	}
	return true;
}

int * make_array_unique(int size, int min = INT_MIN/2, int max = INT_MAX/2){
	int * output;
	srand (time(NULL));
	int value;

	output = (int *)malloc(size*sizeof(int));
	for(int i = 0; i < size; i++ ){
		value = min + rand()%(max-min+1);
		if (!is_unique(output, i, value)){
			i--;
			continue;
		}
		output[i] = value;
	}

	return output;
}

void print_array(int * input, int size, string name = "Array"){
	cout << name << " : ";
	for(int i = 0; i < size; i++ ){
		cout << input[i] << " ";
	}
	cout << endl;
}

#endif