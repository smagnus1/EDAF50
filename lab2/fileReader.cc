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

int main() {  

 
    std::ifstream read_file("words");
    std::ofstream output("words.txt");

    std::string word;

    while(getline(read_file, word)) {

        std::cout << "Reading word " << word << '\n';

        int nbrTrigrams = word.length() - 2; 

        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        std::vector<std::string> trigrams;
        for(int i = 0; i<nbrTrigrams; i++) {
            trigrams.push_back(word.substr(i, 3));
        }

        std::sort(trigrams.begin(), trigrams.end());
    
        output << word << " " << nbrTrigrams << " ";
        
        std::string trigString;
        for (const auto &piece : trigrams) {
            trigString += piece + " ";
        }

        output << trigString << '\n';

    }

    //output << "";

    return 0;
}

