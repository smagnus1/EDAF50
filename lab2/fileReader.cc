#include <fstream>
#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>
#include <numeric>


/*
    http://www.cplusplus.com/forum/general/63211/               - 
    http://www.cplusplus.com/reference/string/string/substr/    - 
    http://www.cplusplus.com/reference/algorithm/transform/     - 
    http://www.cplusplus.com/reference/algorithm/sort/          - default sort is used (<)
*/


using namespace std;

int main() {  

 
    ifstream read_file("words");
    ofstream output("words.txt");

    string word;
    
    while(getline(read_file, word)) {

        cout << "Reading word " << word << '\n';

        int nbrTrigrams = word.length() - 2; 

        transform(word.begin(), word.end(), word.begin(), ::tolower);

        vector<string> trigrams;
        for(int i = 0; i<nbrTrigrams; i++) {
            trigrams.push_back(word.substr(i, 3));
        }

        sort(trigrams.begin(), trigrams.end());
    
        output << word << " " << nbrTrigrams << " ";
        
        std::string trigString;
        for (const auto &part : trigrams) {
            trigString += part + " ";
        }

        output << trigString << '\n';

    }

    //output << "";

    return 0;
}

