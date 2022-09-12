#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <random>
using namespace std;

// utilising Mersenne Twister engine
int rng(int num)
{
  random_device rd;
  mt19937 gen(rd());

  uniform_int_distribution<> dis(1,num);

      int result = dis(gen);
  return result;
}
