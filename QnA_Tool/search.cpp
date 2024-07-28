#include "search.h"

SearchEngine::SearchEngine() {}

SearchEngine::~SearchEngine() 
{
    for (element* e : storage) {
        delete e;
    }
}
vector<int> solve(const string& pattern) 
{
    int pat = pattern.length();
    std::vector<int> p_idx(pat, 0);

    int rep = 0;
    for (int i = 1; i < pat; i++) {
        while (rep > 0 && pattern[rep] != pattern[i]) {
            rep = p_idx[rep - 1];
        }

        if (pattern[rep] == pattern[i]) {
            rep++;
        }

        p_idx[i] = rep;
    }

    return p_idx;
}
 void get_par(int book_code,int page,int paragraph,int sentence_no,string sentence,vector<element*>&pars,element*prev)
 {
    element*root=new element(book_code,page,paragraph,sentence_no,sentence);
    if(prev==nullptr)
    {
        pars.push_back(root);
        prev=root;
    }
    else if(prev->book_code!=book_code||prev->page!=page||prev->paragraph!=paragraph)
    {
        pars.push_back(root);
        prev=root;
    }
    else
    {
        prev->sentence+=sentence;
    }
 }
void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no,string sentence) 
{
   // get_par(book_code,page,paragraph,sentence_no,sentence,pars,prev); //it will contain vector of paragraphs
    element* temp = new element(book_code, page, paragraph, sentence_no, sentence);
    storage.push_back(temp);
}
string tolower(const string& input)
 {
    string result = input;
    int n=result.length();
    for (char&ch:result) 
    {
        ch =  static_cast<char>(tolower(ch));
    }
    return result;
}
// void pattern_find(element* state, DicNode*& tail, int& n_matches, const string& pattern) {
//     const std::string newPat = tolower(pattern);
//     const std::string newSen = tolower(state->sentence);
//     int pat = newPat.length();
//     int sen = newSen.length();

//     std::vector<int> prefixIndex = solve(newPat);
//     int p = 0;
//     int s = 0;
//     int hold = 0;

//     while (s < sen) {
//         while (p < pat && newPat[p] == newSen[s]) {
//             p++;
//             s++;
//         }
//         if (p == pat) {
//             hold = s - p;
//             if (p > 0) {
//                 p = prefixIndex[p - 1];
//             }
//             DicNode* temp = new DicNode(state->book_code, state->page, state->paragraph, state->sentence_no, hold);
//             n_matches++;
//             DicNode* back = tail->left;
//             back->right = temp;
//             temp->left = back;
//             temp->right = tail;
//             tail->left = temp;
//         } else if (p == 0) {
//             s++;
//         } else {
//             p = prefixIndex[p - 1];
//         }
//     }
// }
// DicNode* SearchEngine::search(std::string pattern, int& n_matches) {
//     DicNode* head = new DicNode();
//     DicNode* tail = new DicNode();
//     head->right = tail;
//     tail->left = head;
  
//     for (element* e : storage) {
//         if (e->sentence.length() < pattern.length()) {
//             continue;
//         }
//         int cnt=0;
//         pattern_find(e, tail, cnt, pattern);
//         n_matches+=cnt;
//     }

//     DicNode* back = tail->left;
//     back->right = nullptr;

//     if (head->right) {
//         return head->right;
//     }

//     return nullptr;
// }
