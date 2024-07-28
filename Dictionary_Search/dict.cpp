
#include "dict.h"

Dict::Dict() : t(new Trie()) {}

Dict::~Dict() {
    delete t;
}


bool separator(vector<char>s,char ch)
{
    for(auto i:s )
    {
        if(i==ch)
        {
            return true;
        }
    }
    return false;
}
vector<string> tokanize(const string s)
{
    vector<string> ans;
    string curr = "";
    vector<char> symbols = {'.', ',', '-', ':', '!', '\"', '\'',' ','(', ')','?', '[', ']', ';','@'};
    //pp 
    for (char i : s)
    {   //' '
         if (!separator(symbols,i))
        {
            if (isupper(i))
            {
                i = tolower(i);
            }
            curr += i;
        }
        else
        {
            if (curr != "" && curr != " ")
            {
                ans.push_back(curr);
            }
            curr = "";
        }
    }
    if (curr != "" && curr != " ")
    {
        ans.push_back(curr);
    }
    return ans;
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, const string sentence) 
{
    vector<string> tokens = tokanize(sentence);
    for (const string& token : tokens) {
        t->insertTrie(token);
    }
}

int Dict::get_word_count( string word) {
    TrieNode* p = t->searchTrie(t->root, word, 0);
    if(p!=nullptr)
    {
        return p->count;
    }
    else
    {
        return -1;
    }
}

void printTrie(TrieNode* node, const string& currentWord, vector<string>& words) {
    if (node->isEnd)
     {
        string s="";
        s=currentWord+", "+std::to_string(node->count);
        words.push_back(s);
    }
    for (int i = 0; i < 95; i++) 
    {
        if (node->children[i] != nullptr) {
            printTrie(node->children[i], currentWord + char('!' + i), words);
        }
    }
}
vector<string> print(TrieNode* root) {
    vector<string> words;
    printTrie(root, "", words);
    return words;
}

void Dict::dump_dictionary( string filename) {
    ofstream outputFile(filename);
    vector<string> words = print(t->root);

    for (const string& word : words) {
        outputFile << word << '\n';
    }

    outputFile.close();
}
/*
int main()
{
    Dict d ;
    d.insert_sentence(1,1,1,1,"i am re se seo seon rere re");
    d.insert_sentence(1,1,1,1,"ru");
    d.dump_dictionary("p1");
}*/