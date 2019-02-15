// implementation file
#include "stringlist.h"
#include <iostream>
#include <string>

using namespace hw1;

int stringlist::getSize(){
  return size;
}

// returns value stored at index
string stringlist::getIndex(int index){

  // explicitly handles index = 0
  if (index == 0){
    return listHead.getValue();
  }

  node *targetNode = new node; // can't assign object directly to pointer
  targetNode = listHead.next; // sets first node to head
  cout << targetNode->getValue();
// iterate through nodes until desired index is reached
  for(int x = 0; x<index; x++){
    targetNode = targetNode->next;
    cout << targetNode->getValue();
  }
  return targetNode->getValue(); // return value of node at index
}

// adding new value to end of list
void stringlist::addMember(string newValue){
  if (size == 0){   // place value into head if list is empty
    listHead.setValue(newValue);
    //listHead.createNext();
    node *temp = new node;
    listHead.next = temp;
    size = 1; // adjust size
  }

  else {
    node nodeToCheck = listHead; // start with head

    while (true){
      if (nodeToCheck.getNext().getValue() ==""){ // if next node is empty
        cout << listHead.next->value << " should be here";
        //nodeToCheck.createNext(); // initialize next node
        node *temp = new node;
        nodeToCheck.next = temp;
        nodeToCheck.next->setValue(newValue); // place value in empty node
        cout << nodeToCheck.next->getValue() << endl;
        size++;
        return; // exit the method
      }

      else {
      nodeToCheck = nodeToCheck.getNext(); // move onto the next node
      }
    }
  }
}
