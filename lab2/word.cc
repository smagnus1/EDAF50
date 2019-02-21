#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;
using namespace std;

/* Creates a word w with the sorted trigrams t */
Word::Word(const string& w, const vector<string>& t) {
	word = w;
	trigrams = t;
}

	/* Returns the word */
string Word::get_word() const {
	return word;
}

/* Returns how many of the trigrams in t that are present
in this word's trigram vector */
unsigned int Word::get_matches(const vector<string>& t) const {
	int count = 0;
	for(string in_trigram : t) {
		for(string dict_trigram : trigrams) {
			//if(in_trigram == dict_trigram) { //doesn't work because it's string comparison
			if(in_trigram.compare(dict_trigram) == 0) {
				count++;

			//it's alphabetically sorted; if string comparison yields a nbr < 0
			//the future ones will not be interesting 
			} else if(in_trigram.compare(dict_trigram) < 0) { 
				break;
			}
		}
	}
	return count;
}
