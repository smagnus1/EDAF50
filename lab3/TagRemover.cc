#include "TagRemover.h"
#include <regex>

#include <fstream>

using namespace std;

//IF o.find('a') == std::string::npos THEN o doesn't contain 'a'.
//IF o.find('a') != std::string::npos THEN o contains 'a' at least once.



//http://www.cplusplus.com/reference/regex/regex_replace/
//https://stackoverflow.com/questions/11229831/regular-expression-to-remove-html-tags-from-a-string
void TagRemover::remove(ifstream &file, string &input) {
    std::regex reg (" <[^>]*>");
    input = regex_replace(input, reg, "");
}


// &lt   &gt   &nbsp   &amp
void TagRemover::translateSpecials() {
    while(true) {
        while(output.find("&lt") != string::npos) {
            auto pos = output.find("&lt");
            output.replace(pos, 4, "<");
        }

         while(output.find("&gt") != string::npos) {
            auto pos = output.find("&gt");
            output.replace(pos, 4, ">");
        }

       while(output.find("&nbsp") != string::npos) {
            auto pos = output.find("&nbsp");
            output.replace(pos, 6, " ");
        } 
       
        while(output.find("&amp") != string::npos) {
            auto pos = output.find("&amp");
            output.replace(pos, 5, "&");
        }
        break;
    }
}


TagRemover::TagRemover(istream &in) {
	string input;

    cout << "enter filename";
    in >> input;

    ifstream file(input);

    if(!file) {
        cout << "File could not be opened/does not exist.";
        return;
    }

    while(getline(file, input)) {
        remove(file, input);

        output += input;
        output += '\n';
    }

    file.close();

    transform();
}






