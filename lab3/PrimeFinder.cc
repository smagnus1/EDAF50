#include <vector>
#include <string>
#include <iostream>



using namespace std;

    int highest = 100000;
    int primeLimit = 200;

    int findLargestUnderX() {
        int start = highest;
        int current = highest;
        bool found = false;
        while(!found) {
            for(int i = start - 1; i >= 2; i--){
                if (start % i == 0) {
                    found = true;
                    break;
                }
            if(found) {
                return highest;
            }
            highest--;
        }
    };

/*  String returning function not working?

    string findPrimes() {
        string primeLetters(primeLimit, 'P');
        primeLetters[0] = 'C';
        primeLetters[1] = 'C';

        
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
        return primeLetters;
    }
*/

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