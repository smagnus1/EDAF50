#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <unordered_set>
#include <vector>

#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;


Dictionary::Dictionary() {
	
		const contains(const string& word);
		const get_suggestions(const string& word);
		
		std::unordered_set<std::string> words;
		std::ofstream unprocessedWords("words.txt");
		
		words << ofstream;
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


// vector<string> Dictionary::get_suggestions(const string& word) const {
// 	vector<string> suggestions;
// 	return const suggestions;
// }
