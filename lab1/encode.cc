#include <iostream>
#include <string>
#include <fstream>
#include <fstream>
#include <array>

using namespace std;

int main() {

    string filename;
    cout << "Please enter filename." << '\n';
    getline (std::cin,filename);
    ifstream file(filename);


    //Tried file.tellg() for size but that seems to return 0, what is the correct way?
    char *data = new char[20];

    for(int i = 0; i<20; i++)
        file >> data[i];

    

    for(int i = 0; i < 20; ++i) {
        data[i] = data[i] + 1;
    }

    ofstream out(filename, ios::binary);
    out.write(data, 20); 
}


