#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <unordered_set>
#include <sstream>
#include <vector>

#include "word.h"
#include "dictionary.h"


/*
using std::ifstream;
using std::stringstream;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::min;
using std::pair;
using std::make_pair;
*/

using namespace std;


Dictionary::Dictionary() {

	ifstream in("words.txt");

	if(!in) {
		cout << "file could not be opened \n";
		return;
	}

	vector<string> trigrams;

	string word;

	/*	Word deklareras som såhär: Word(const string& w, const vector<string>& t)
									ORDET		 	 EN VEKTOR TRIGRAMS

		För varje word som läggs in i dict vill vi även lägga in motsvarande
		i en Word-vector. För respektive word behöver vi alltså, i enighet med
		ovan, en vector trigrams: word[i].push_back(Word(word, trigrams));
	*/

	while(in >> word) { //för varje ord hämtar vi även dess trigrams och lägger in i vår trigram-vector
		int nbrTrigrams;
		in >> nbrTrigrams;

		vector<string> trigrams;

		for(int i = 0; i < nbrTrigrams; i++) {
			std::string trigram;
			in >> trigram;
			trigrams.push_back(trigram);
		}
		dictionary->insert(word); //not sure why only arrow works, ask on lab
		Word w(word, trigrams);
		words[word.length()-1].push_back(w);
	}
	in.close();
}

bool Dictionary::contains(const string& word) const {
	return dictionary->count(word); //only arrow
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_trigram_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string> &suggestions, const string &word) const {
	if(word.length() < 3) {
		return;
	}
	int wLength = word.length();
	unsigned int nbrTrigrams = wLength - 2; 
	vector<string> trigrams(nbrTrigrams);
	
	for(int i = 0; i < wLength-2; i++) {
		trigrams.push_back(word.substr(i, 3));
	}

	sort(trigrams.begin(), trigrams.end());

	unsigned int start = wLength -1;
	unsigned int end = wLength + 1;

	for(unsigned int i = start; i <= end && i <= MAX_LENGTH; i++) {
		//Of these candidates, the words which contain at least
		//half of the “trigrams” of the misspelled word should be kept
		for(Word w: words[i]) {
			if(w.get_matches(trigrams) >= nbrTrigrams / 2) {	//fullfills above condition: if matches for word w => ..., then...
				suggestions.push_back(w.get_word());
			}
		}
	}

}
	/*	har en unordered_set dictionary
	  	har en inparameter suggestions-vector
		har ett word som är felstavat (?)
		vi ska kolla i dictionary med start på ord som är en bokstav kortare-längre
		alla dessa ska läggas in i vår vector suggestions
	*/ 

void Dictionary::rank_trigram_suggestions(vector<string>& suggestions, const string word) const {
	if(word.length() < 3) {
		return;
	}
	vector<pair<int, string>> levenDistances;
	for(const auto& s: suggestions) {
		unsigned int cost = levenshteinOf(word, s);
		levenDistances.push_back(make_pair(cost, s));
	}
	sort(levenDistances.begin(), levenDistances.end());
	suggestions.clear();
	for(auto s : levenDistances) {
		suggestions.push_back(s.second); //s.first is cost, s.second the word
	}
}	

int Dictionary::levenshteinOf(const string word, const string s) const {
	string::size_type string_length = s.length();
	string::size_type word_length = word.length();

	int d[26][26];
	d[0][0] = 0;
	
	//fill matrix
	for(unsigned int i = 1; i <= word_length; i++) {
		d[i][0] = i;		
	}
	for(unsigned int i = 1; i <= string_length; i++) {
		d[0][i] = i;
	}
	for(unsigned int i = 1; i<string_length+1; i++) {
		for(unsigned int j = 1; j<word_length+1; j++) {
			unsigned int a, b, c;
			if(word[i-1] == s[i-1]) {
				a = d[i-1][j-1];
			} else {
				a = d[i-1][j-1] + 1; 
			} 
			b = d[i-1][j] + 1;
			c = d[i][j-1] + 1;
			d[i][j] = std::min({a, b, c});
		}
	}
	return d[string_length][word_length];
}

//keep 5 best
void Dictionary::trim_suggestions(vector<string>& suggestions) const {
	//vector<string>& trimmedSuggestions; ...better way - RESIZE instead
	int newSize;
	if(suggestions.size() >= 5) {
		newSize = 5;
	} else {
		newSize = suggestions.size();
	}
	suggestions.resize(newSize);
}