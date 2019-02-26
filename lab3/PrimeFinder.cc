#include <vector>
#include <string>
#include <iostream>



using namespace std;

    int highest = 100000;
    int primeLimit = 200;

    int findLargestUnderX() {
        bool found = false;
        int current = highest;
        while(!found) {
            found = true;
            for(int i = current - 1; i >= 2; i--){
                if (current % i == 0) {
                    found = false;
                    break;
                }
            }
            if(found) {
                return current;
            }
            current--;
        }
        return 0;
    }

int main(){

    //default string
    string primeLetters(primeLimit, 'P');
    
    //by default
    primeLetters[0] = 'C';
    primeLetters[1] = 'C';

    //starting prime in algorithm
    int currentPrime = 2;
    

    while(currentPrime < primeLimit) {
        int currentMultiple = currentPrime * 2;
        while(currentMultiple < primeLimit) {
            primeLetters[currentMultiple] = 'C';
            currentMultiple = currentMultiple + currentPrime; 
        }

        currentPrime++;
        //currentPrime becomes index indirectly 
        while(primeLetters[currentPrime] != 'P' && currentPrime < primeLimit) {
            currentPrime++;
        }
    } 

    cout << primeLetters << '\n';
    cout << findLargestUnderX() << '\n';
    return 0;
}