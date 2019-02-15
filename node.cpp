// implementation file
#include "node.h"
#include <iostream>
#include <string>

using namespace hw1;

void node::createNext(){
  node *temp = new node;
  next = temp;
  //cout << next->getValue();
}

node node::getNext(){
  return *next;
}

string node::getValue(){
  return value;
}

void node::setValue(string newValue){
  value = newValue;
}
