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
string user_input;
int AA=0, AC=0, AG=0, AT=0, CA=0, CC=0, CG=0, CT=0, GA=0, GC=0, GG=0, GT=0, TA=0, TC=0, TG=0, TT=0;
double AA_prob, AC_prob, AG_prob, AT_prob, CA_prob, CC_prob, CG_prob, CT_prob;
double GA_prob, GC_prob, GG_prob, GT_prob, TA_prob, TC_prob, TG_prob, TT_prob;
double A_prob, C_prob, G_prob, T_prob;
int x; // counts of bigrams
int A=0, C=0, T=0, G=0;
int sliceStart = 0; // used for selecting bigrams from line
int totalLines = 0; // counts number of lines in file
int totalChars = 0; // total number of nucleotide chars in file
int numpairs = 0; // total number of pairs in file
double mean = 0; // mean line length
double variance = 0, deviation = 0;
double probability;
bool running = true;

while(running){

  // read all lines in file
  while(getline(inputStream, line)){

    totalLines++;
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

      sliceStart += 2; // move onto next pair
      numpairs++; // keep track of number of pairs
    }

    // going through line again and counting individual nucleotides
    for (int x = 0; x < line.length(); x++){

        // more if statements
        if (line.at(x) == 'A' || line.at(x) =='a')
        A++;
        if (line.at(x) == 'C' || line.at(x) =='c')
        C++;
        if (line.at(x) == 'G' || line.at(x) =='g')
        G++;
        if (line.at(x) == 'T' || line.at(x) =='t')
        T++;
      }
  }
  inputStream.close();

  // summary calculations
  totalChars -= totalLines-1;  // line length for all lines up to n-1 is 1 higher than expected
  mean = double(totalChars)/double(totalLines);
  variance = statsMachine.calcVariance(filepath,mean,totalLines);
  deviation = sqrt(variance);

  // generating relative probabilities
  AA_prob = float(AA)/numpairs;
  AC_prob = float(AC)/numpairs;
  AG_prob = float(AG)/numpairs;
  AT_prob = float(AT)/numpairs;
  CA_prob = float(CA)/numpairs;
  CC_prob = float(CC)/numpairs;
  CG_prob = float(CG)/numpairs;
  CT_prob = float(CT)/numpairs;
  GA_prob = float(GA)/numpairs;
  GC_prob = float(GC)/numpairs;
  GG_prob = float(GG)/numpairs;
  GT_prob = float(GT)/numpairs;
  TA_prob = float(TA)/numpairs;
  TC_prob = float(TC)/numpairs;
  TG_prob = float(TG)/numpairs;
  TT_prob = float(TT)/numpairs;

  A_prob = float(A)/totalChars;
  C_prob = float(C)/totalChars;
  G_prob = float(G)/totalChars;
  T_prob = float(T)/totalChars;

  // outputting header to text file
  ofstream fileOutput("jacksavage.txt", ofstream::out | ofstream::app);

  if(fileOutput.is_open()){
    fileOutput << "\nName: Jack Savage \n";
    fileOutput << "Student ID: 2295072 \n";
    fileOutput << "Class: CPSC 350 \n \n";
    fileOutput << "Summary Statistics: \n";
    fileOutput << "Total number of nucleotides: " << totalChars;
    fileOutput << "\nTotal number of lines: " << totalLines;
    fileOutput << "\nMean line length: " << mean;
    fileOutput << "\nVariance of line length: " << variance;
    fileOutput << "\nStandard deviation of line length: " << deviation;
    fileOutput << "\n\nNucleotide Relative Probabilities: \n";
    fileOutput << "A: " << A_prob;
    fileOutput << "\nC: " << C_prob;
    fileOutput << "\nG: " << G_prob;
    fileOutput << "\nT: " << T_prob;
    fileOutput << "\n\nBigram Relative Probabilities: \n";
    fileOutput << "AA: " << AA_prob << "\nAC: " << AC_prob << "\nAG: " << AG_prob << "\nAT: " << AT_prob;
    fileOutput << "\nCA: " << CA_prob << "\nCC: " << CC_prob << "\nCG: " << CG_prob << "\nCT: " << C_prob;
    fileOutput << "\nGA: " << GA_prob << "\nGC: " << GC_prob << "\nGG: " << GG_prob << "\nGT: " << GT_prob;
    fileOutput << "\nTA: " << TA_prob << "\nTC: " << TC_prob << "\nTG: " << TG_prob << "\nTT: " << TT_prob;
  }

  fileOutput.close();

  // dividing range 0,1 into domains == bigram and nucleotide probs
  AC_prob = float(AC)/numpairs + AA_prob;
  AG_prob = float(AG)/numpairs + AC_prob;
  AT_prob = float(AT)/numpairs + AG_prob;
  CA_prob = float(CA)/numpairs + AT_prob;
  CC_prob = float(CC)/numpairs + CA_prob;
  CG_prob = float(CG)/numpairs + CC_prob;
  CT_prob = float(CT)/numpairs + CG_prob;
  GA_prob = float(GA)/numpairs + CT_prob;
  GC_prob = float(GC)/numpairs + GA_prob;
  GG_prob = float(GG)/numpairs + GC_prob;
  GT_prob = float(GT)/numpairs + GG_prob;
  TA_prob = float(TA)/numpairs + GT_prob;
  TC_prob = float(TC)/numpairs + TA_prob;
  TG_prob = float(TG)/numpairs + TC_prob;
  TT_prob = float(TT)/numpairs + TG_prob;

  // outputting new lines to text file
  fileOutput.open("jacksavage.txt", ofstream::app);
  if(fileOutput.is_open()){
    for(int x=0; x<1000; x++){ // write 1000 lines

      // generate line length from mean and deviation
      int outputLength = statsMachine.getNormalRandom(mean,deviation) ;

      if (outputLength<1) // handles case if output length is negative or 0
        outputLength = mean;

      string outputLine; // declare fresh string for each line

      while (outputLength>0){ // generates characters until line length is reached
        srand(time(NULL)+x+outputLength); // seed random number gen
        probability = double(rand())/RAND_MAX; // generate probability for nucleotide generation

        if(outputLength == 1){ // generate individual nucleotide if no room for bigram
          if (probability>=0 && probability<=A_prob)
            outputLine.append("A");
          else if (probability>A_prob && probability<=C_prob)
            outputLine.append("C");
          else if (probability>C_prob && probability<=G_prob)
            outputLine.append("G");
          else if (probability>G_prob && probability<=T_prob)
            outputLine.append("T");
          outputLength--;
        }

        else if(outputLength >1){ // generate bigram if there's space left in the line
        // bigram generation from relative probability
          if (probability>=0 && probability<=AA_prob)
            outputLine.append("AA");
          else if (probability>AA_prob && probability<=AC_prob)
            outputLine.append("AC");
          else if (probability>AC_prob && probability<=AG_prob)
            outputLine.append("AG");
          else if (probability>AG_prob && probability<=AT_prob)
            outputLine.append("AT");
          else if (probability>AT_prob && probability<=CA_prob)
            outputLine.append("CA");
          else if (probability>CA_prob && probability<=CC_prob)
            outputLine.append("CC");
          else if (probability>CC_prob && probability<=CG_prob)
            outputLine.append("CG");
          else if (probability>CG_prob && probability<=CT_prob)
            outputLine.append("CT");
          else if (probability>CT_prob && probability<=GA_prob)
            outputLine.append("GA");
          else if (probability>GA_prob && probability<=GC_prob)
            outputLine.append("GC");
          else if (probability>GC_prob && probability<=GG_prob)
            outputLine.append("GG");
          else if (probability>GG_prob && probability<=GT_prob)
            outputLine.append("GT");
          else if (probability>GT_prob && probability<=TA_prob)
            outputLine.append("TA");
          else if (probability>TA_prob && probability<=TC_prob)
            outputLine.append("TC");
          else if (probability>TC_prob && probability<=TG_prob)
            outputLine.append("TG");
          else if (probability>TG_prob && probability<=TT_prob)
            outputLine.append("TT");
          outputLength-=2;
        }
      }
      fileOutput << '\n' << outputLine; // outputting generated line to file
    }
  }

  fileOutput.close();
    cout << "Lines written to jacksavage.out" << endl;
    cout << "Would you like to quit(y/*)? ";
    cin >> user_input;
    cout << endl;
    if (user_input == "y" || user_input == "Y")
      running = false;
    }
}
