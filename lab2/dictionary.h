#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "word.h"

#include <string>
#include <vector>
#include <unordered_set>


enum MAX_LENGTH {
	MAX_LENGTH = 25
};

class Dictionary {
public:
	Dictionary();

	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
	void add_trigram_suggestions(std::vector<std::string> &suggestions, const std::string &word) const;
	void rank_trigram_suggestions(vector<string>& suggestions, const string word) const;
	int levenshteinOf(const string word, const string s) const;
	std::unordered_set<std::string> dictionary[MAX_LENGTH];
	std::vector<Word> words[MAX_LENGTH];
};

#endif
