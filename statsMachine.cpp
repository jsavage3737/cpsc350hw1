#include "statsMachine.h"
#include <math.h>
#include <fstream>
#include <iostream>

using namespace hw1;

double statsMachine::calcVariance(string filepath, float mean, int numLines){

  // variable declaration
  int lineLength;
  float difference;
  float totalSquares = 0;
  string line;
  ifstream varianceReader(filepath);

  // calculating (x-mean)^2 for each term, adding to total to divide at end
  while(getline(varianceReader, line)){
    lineLength = line.length();
    difference = mean-lineLength;
    difference = pow(difference,2);
    totalSquares += difference;
  }
  cout << "Total Squares:" << totalSquares << endl;
  cout << "Num lines: " << numLines << endl;
  return totalSquares/float(numLines-1);
}

double statsMachine::getNormalRandom(float mean, float std){
   double a = double(rand())/RAND_MAX, b = double(rand())/RAND_MAX;
   double c = sqrt(-2*log(a))*cos(2*M_PI*b);
   return std*c + mean;
}
