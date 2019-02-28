#include <string>       
#include <iostream>     
#include <sstream>  
#include <stdexcept>    
#include "date.cc"

using namespace std;


//https://stackoverflow.com/questions/3512685/a-template-class-in-c/3512819#3512819
template<typename T>
    string toString(T a) {
        ostringstream myStream;
        myStream << a;
        return myStream.str();
    }

template<typename T>
    T string_cast(string s) {
        istringstream stringStream(s);
        T t;
        stringStream >> t;
        if(!stringStream) {
        //if(stringStream.fail()){
            throw invalid_argument("Invalid input.");    
        }
        return t;
    }

int main() {
    double d = 1.234;
    Date today;
    Date wrong(111111, 111111, 111111);
    cout << toString(wrong) << endl;
    std::string sd = toString(d);
    std::string st = toString(today);
    cout << sd << endl;
    cout << st << endl;

    try {
        int i = string_cast<int>("123");
        double d = string_cast<double>("12.34");
        cout << i << endl;
        cout << d << endl;
        Date date = string_cast<Date>("2015 01 10");
        cout << toString(date);
    } catch (std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

}
