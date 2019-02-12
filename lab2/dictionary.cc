#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;

Dictionary::Dictionary() {
	public:
		const contains(const string& word);
		const get_suggestions(const sting& word);
	private:
		unordered_set<string> words;
		std::ofstream unprocessedWords("words.txt");

}

bool Dictionary::contains(const string& word) const {
	if() return true;
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
