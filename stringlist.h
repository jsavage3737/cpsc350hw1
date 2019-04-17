#include "node.h"
#include <string>
using namespace std;

namespace hw1{
  class stringlist{
  public:
    int getSize();
    string getIndex(int index);
    void setIndex(int index, string newValue);
    void addMember(string newValue);

  private:
    int size = 0;
    node listHead;
  };
}
