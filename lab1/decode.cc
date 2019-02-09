#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main() {

    std::string filename;
    cout << "Please enter filename.";
    std::getline (std::cin,filename);
    ifstream file("filename.txt");

    char txtFile [5] = {0};

    if(file.is_open()) {
        for(int i = 0; i < 4; ++i) {  //declared size instead of finding a "file.sizeof" due to time limits
            file >> txtFile[i];
        }
    }

    //char txtFile [] = infile >> data;;
   
    void encodeFile(txtFile) {
        for(int i = 0; i<sizeof(txtFile); i++) {
            int x = txtFile[i];
            x--;
            txtFile[i] = (char)x;
        }
    }
}