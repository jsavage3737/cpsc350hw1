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
