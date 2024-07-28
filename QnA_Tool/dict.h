
#include <iostream>
#include<fstream>
#include <vector>
#include <string>
using namespace std;

//helper class ChotaHash
class ChotaHash{
    public:
    std::vector<string> table;
    ChotaHash(){
        table.resize(501);
        table.assign(table.size(),"");
    }

    unsigned long hash(string& word) {
        unsigned long hashValue = 5;
        for (char c : word) {
            hashValue = ((hashValue << 5) + hashValue) + c;
        }
        return hashValue % table.size();
    }

    void insert(string word, float value){
        int index = hash(word);
        while(table[index] != ""){
            index = (index+1)%table.size();
        }
        table[index] = word;
    }

    int getval(string word){
        int index = hash(word);
        if(word == table[index]){
            return index;
        }
    }
};


class dicNode {
public:
    string word;
    long long count;

    dicNode() : word(""), count(-1) {}

    dicNode(string w, long long val) : word(w), count(val) {}
};

class Hash {
public:
int collisions = 0;
    vector<dicNode> table;
    size_t size;

    Hash() : size(5000001) {
        table = vector<dicNode>(size);
    }
    size_t hash(const std::string& str, size_t vectorSize) {            
        size_t hashValue = 5381;                                         
        for (char c : str) {
            // We are mixing bits using addition and XOR
            hashValue = ((hashValue << 5) + hashValue) ^ (hashValue >> 27) ^ static_cast<size_t>(c);
        }
        // Mix in the word length
        hashValue = ((hashValue << 5) + hashValue) ^ (hashValue >> 27) ^ str.length();
        return hashValue % vectorSize;
}

    size_t get_hash(const string& word) {
        size_t val = hash(word,size);
        int idx = 1;
        if (table[val].word == "") {
            return val;
        }
        size_t probe = val;
        while (table[probe].word != word && table[probe].word != "") {
            probe = (val + idx * idx) % size;  // Quadratic probing
            idx++;
            collisions++;
        }
        val = probe;
        return val;
    }

    bool does_exist(const string& word) {
        size_t idx = get_hash(word);
        return table[idx].word == word;
    }

    void insert(const string& word) {
        size_t idx = get_hash(word);
        if (!does_exist(word)) {
            table[idx].word = word;
            table[idx].count = 1;
        } else {
            table[idx].count += 1;
        }
    }

    void setval(const string& word, long long count) {
        size_t idx = get_hash(word);
        table[idx].word = word;
        table[idx].count = count;
    }

    long long getval(const string& word) {
        if (!does_exist(word)) {
            return 0;
        }
        size_t idx = get_hash(word);
        return table[idx].count;
    }
};
class dumyHash {
public:
int collisions = 0;
    vector<dicNode> table;
    size_t size;
    dumyHash() : size(151) {
        table = vector<dicNode>(size);
    }
    size_t hash(const std::string& str, size_t vectorSize) {            
        size_t hashValue = 37;                                         
        for (char c : str) {
            // We are mixing bits using addition and XOR
            hashValue = ((hashValue << 5) + hashValue) ^ (hashValue >> 7) ^ static_cast<size_t>(c);
        }
        // Mix in the word length
        hashValue = ((hashValue << 5) + hashValue) ^ (hashValue >> 7) ^ str.length();
        return hashValue % vectorSize;
}
    size_t get_hash(const string& word) {
        size_t val = hash(word,size);
        int idx = 1;
        if (table[val].word == "") {
            return val;
        }
        size_t probe = val;
        while (table[probe].word != word && table[probe].word != "") {
            probe = (val + idx * idx) % size;
            idx++;
            collisions++;
        }
        val = probe;
        return val;
    }
    bool does_exist(const string& word) {
        size_t idx = get_hash(word);
        return table[idx].word == word;
    }
    void insert(const string& word) {
        size_t idx = get_hash(word);
        if (!does_exist(word)) {
            table[idx].word = word;
            table[idx].count = 1;
        } else {
            table[idx].count += 1;
        }
    }
    void setval(const string& word, long long count) {
        size_t idx = get_hash(word);
        table[idx].word = word;
        table[idx].count = count;
    }
    long long getval(const string& word) {
        if (!does_exist(word)) {
            return 0;
        }
        size_t idx = get_hash(word);
        return table[idx].count;
    }
};
class Dict {
private:
    // You can add attributes/helper functions here
    Hash*ht; 
public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    long long get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
    int getcollisions(){
        return ht->collisions;
    }
    void insert_tokenised_sentences(const vector<string> &sentence);
};