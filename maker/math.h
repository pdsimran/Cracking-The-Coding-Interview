#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#ifndef MATH_H
#define MATH_H

int diff_abs(int a, int b){
  if(a > b) return (a-b);
  else return (b-a);
}

#endif