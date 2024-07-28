
#include "dict.h"

Dict::Dict() : ht(new Hash()) {};

Dict::~Dict()
 {
    delete ht;
}
bool separator(vector<char>s,char ch)
{
    for(char i:s )
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
    vector<char> symbols = {' ','.', ',', '-', ':', '!', '\"', '\'','(', ')','?', '[', ']', ';','@'};
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
    for (const string& token: tokens)
     {    
        // if(ht->getval(token)==-1)
        // {
        //     ht->insert(token);
        // }
        ht->insert(token);
    }
}

void Dict::insert_tokenised_sentences(const vector<string> &sentence){
    for(const string &token : sentence){
        ht->insert(token);
    }
}

long long Dict::get_word_count( string word) 
{
    return ht->getval(word);
}
void Dict::dump_dictionary( string filename) {
}
/*
int main()
{
    Dict d ;
    d.insert_sentence(1,1,1,1,"i am re se seo seon rere re");
    d.insert_sentence(1,1,1,1,"ru");
    d.dump_dictionary("p1");
}*/