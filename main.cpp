#include <iostream>
#include <fstream>
#include "statsMachine.h"
#include <math.h>

using namespace hw1;
using namespace std;

int main(int argc, char *argv[]){

  // ensuring user gave arguments
  if (argc == 1){
    cout << "No arguments given" << endl;
    cout << "Please add file to read as argument";
    return 0;
  }

  // ensuring user entered only one argument
  if (argc > 2) {
    cout << argc << " arguments given" << endl;
    cout << "Please only enter one argument";
    return 0;
  }

// variables declared after checking args to prevent
// needless memory use
statsMachine statsMachine;
string filepath = argv[1]; // saving filespath
ifstream inputStream(filepath); // creating filestream object reading from filepath
string line; // lines read from file are temporarily stored here
string slice; // slices from lines read temporarily stored here
int AA,AC,AG,AT,CA,CC,CG,CT,GA,GC,GG,GT,TA,TC,TG,TT = 0; // counts of bigrams
int A,C,T,G = 0;
int sliceStart = 0; // used for selecting bigrams from line
int totalLines = 0; // counts number of lines in file
int totalChars = 0; // total number of nucleotide chars in file
int numpairs = 0; // total number of pairs in file
double mean; // mean line length
double variance, deviation;

// read all lines in file
while(getline(inputStream, line)){
  sliceStart = 0; // reset slice starting index for each line

  // used to calculate mean length
  totalChars += line.length();

  // operations on bigrams
  while (sliceStart < line.length()-2){ // only read complete pairs

    if (line.length()<2) {break;}

    slice = line.substr(sliceStart,2); // read a pair

    // some really braindead if statements to calculate bigram relative probs
    if (slice == "AA" || slice == "Aa" || slice == "aA" || slice == "aa")
      AA++;
    if (slice == "AC" || slice == "Ac" || slice == "aC" || slice == "ac")
      AC++;
    if (slice == "AG" || slice == "Ag" || slice == "aG" || slice == "ag")
      AG++;
    if (slice == "AT" || slice == "At" || slice == "aT" || slice == "at")
      AT++;
    if (slice == "CA" || slice == "Ca" || slice == "cA" || slice == "ca")
      CA++;
    if (slice == "CC" || slice == "Cc" || slice == "cC" || slice == "cc")
      CC++;
    if (slice == "CG" || slice == "Cg" || slice == "cG" || slice == "cg")
      CG++;
    if (slice == "CT" || slice == "Ct" || slice == "cT" || slice == "ct")
      CT++;
    if (slice == "GA" || slice == "Ga" || slice == "gA" || slice == "ga")
      GA++;
    if (slice == "GC" || slice == "Gc" || slice == "gC" || slice == "gc")
      GC++;
    if (slice == "GG" || slice == "Gg" || slice == "gG" || slice == "gg")
      GG++;
    if (slice == "GT" || slice == "Gt" || slice == "gT" || slice == "gt")
      GT++;
    if (slice == "TA" || slice == "Ta" || slice == "tA" || slice == "ta")
      TA++;
    if (slice == "TC" || slice == "Tc" || slice == "tC" || slice == "tc")
      TC++;
    if (slice == "TG" || slice == "Tg" || slice == "tG" || slice == "tg")
      TG++;
    if (slice == "TT" || slice == "Tt" || slice == "tT" || slice == "tt")
      TT++;

    // some more if statements for individual nucleotides
    sliceStart += 2; // move onto next pair
    numpairs++; // keep track of number of pairs
  }
      totalLines++;
}
inputStream.close();

totalChars -= totalLines-1;  // line length for all lines up to n-1 is 1 higher than expected
mean = double(totalChars)/double(totalLines);
variance = statsMachine.calcVariance(filepath,mean,totalLines);
deviation = sqrt(variance);

cout << mean << endl;
cout << variance << endl;
cout << deviation << endl;
cout << numpairs << endl;
cout << AC << endl;
}
