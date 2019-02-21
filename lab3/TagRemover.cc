#include "TagRemover.h"

#include <fstream>

using namespace std;



//IF o.find('a') == std::string::npos THEN o doesn't contain 'a'.
//IF o.find('a') != std::string::npos THEN o contains 'a' at least once.

void TagRemover::remove(ifstream &file, string &input) {
    while(true) {
        while(input.find('<') != string::npos) {
            int position = input.find('<');

            if(position != string::npos) {
                int end = input.find('>');

                if(end != string::npos) {
                    input.erase(position, end);
                } else {
                    input.erase(position, input.length()-position);

                    output += input;

                    string nextLine = input;

                    while(nextLine.find(">") == string::npos) {
                        output += "\n";

                        getline(file, nextLine);
                    }

                    nextLine.erase(0, nextLine.find(">"));
                    input = nextLine;

                    continue;
                }
            } 
        }
        break;
    }    
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






