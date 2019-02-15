#include <string>
using namespace std;

// beginning of header
namespace hw1 {
  class node {
  public:
    string getValue();
    void setValue(string newValue);
    node getNext();
    void createNext();
    node* next = NULL;
    string value;
  private:
  };
}
