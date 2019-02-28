#include "TagRemover.h"
#include <regex>

#include <fstream>

using namespace std;


TagRemover::TagRemover(istream &in) {
	string input;

    cout << "enter filename" << endl;
    in >> input;

    ifstream file(input);

    if(!file) {
        cout << "File could not be opened/does not exist." << endl;
        return;
    }

    while(getline(file, input)) {
        remove(input);

        text += input;
        text += '\n';
    }

    file.close();

}

//http://www.cplusplus.com/reference/regex/regex_replace/
//https://stackoverflow.com/questions/11229831/regular-expression-to-remove-html-tags-from-a-string
//not sure what happens but it works
void TagRemover::remove(string &text) {
    std::regex reg (" <[^>]*>");
    text = regex_replace(text, reg, "");
}

// &lt   &gt   &nbsp   &amp
void TagRemover::translateSpecials() {
    bool run = true;
    while(run) {
        while(text.find("&lt") != string::npos) {
            auto pos = text.find("&lt");
            text.replace(pos, 4, "<");
        }

         while(text.find("&gt") != string::npos) {
            auto pos = text.find("&gt");
            text.replace(pos, 4, ">");
        }

       while(text.find("&nbsp") != string::npos) {
            auto pos = text.find("&nbsp");
            text.replace(pos, 6, " ");
        } 
       
        while(text.find("&amp") != string::npos) {
            auto pos = text.find("&amp");
            text.replace(pos, 5, "&");
        }
        run = false;
    }
}

void TagRemover::fixStuff() {
    remove(text);
    translateSpecials();
}

string TagRemover::getText() {
    return text;
}

void TagRemover::print(ostream &out) {
    out << text;
}






