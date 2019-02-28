#ifndef TAGREMOVER_H
#define TAGREMOVER_H

#include <iostream>

class TagRemover {
public:
    TagRemover(std::istream &in);
    void print(std::ostream &out);
    std::string getText();
    void fixStuff();
private:
    void remove(std::string &input);
    void translateSpecials();

    std::string text;
};

#endif