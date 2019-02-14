#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_set>

#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;
using namespace std;

Dictionary::Dictionary() {
	
	const bool contains(const string& word);
	const vector<string> get_suggestions(const string& word);

	vector<Word> words[25]; // words[i] = the words with i letters,
							// ignore words longer than 25 letters
	
	std::unordered_set<std::string> words;
	
	std::ifstream in("words");

	std::string str;

	while(std::getline(in, str)) {
		if(str.size() > 0) {
			words.insert(str);
		}
	}

	words << in;


	// ofstream outfile;
}

bool Dictionary::contains(const string& word) const {

	std::unordered_set<std::string>::const_iterator find = words.find(word);

	if (find == words.end()) {
		return false;
	} else {
		return true;
	}
	
	return false;
}


vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return const suggestions;
}
