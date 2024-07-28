
#include <iostream>
#include<fstream>
#include <vector>
#include <string>
using namespace std;
class TrieNode {
public:
    std::vector<TrieNode*> children;
    int count;
    bool isEnd;

    TrieNode() : children(95, nullptr), count(0), isEnd(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() : root(new TrieNode()) {}

    void insertTrie(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = char(ch - 33);
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->count++;
        current->isEnd = true;
    }

    TrieNode* searchTrie(TrieNode* current, const std::string& word, size_t i) {
        if (current == nullptr) {
            return nullptr;
        }
        if (i == word.length()) {
            return (current->isEnd) ? current : nullptr;
        }
        int index = char(word[i] - 33);
        if (current->children[index]) {
            return searchTrie(current->children[index], word, i + 1);
        }
        return nullptr;
    }
};

class Dict {
private:
    // You can add attributes/helper functions here
    Trie*t;
    
public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};