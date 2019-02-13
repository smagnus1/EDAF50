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

    char *data = new char[20];

    for(int i = 0; i<20; i++)
        file >> data[i];

    //file.tellg() for size instead?

    

    for(int i = 0; i < 20; ++i) {
        data[i] = data[i] - 1;
    }

    ofstream out(filename, ios::binary);
    out.write(data, 20);
}


