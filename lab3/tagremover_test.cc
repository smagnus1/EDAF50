#include "TagRemover.h"
#include <iostream>

using namespace std;

int main () {
    TagRemover tagRemover(cin);
    string pre = tagRemover.getText();
    tagRemover.fixStuff();
    string post = tagRemover.getText();
    if(pre == post) {
        cout << "Operation failed" << endl;
    } else {
        tagRemover.print(cout);
    }
}