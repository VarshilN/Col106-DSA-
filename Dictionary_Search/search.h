// Do NOT add any other includes
#include <string>
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;
class element
{
public:
    int book_code = 0;
    int page = 0;
    int paragraph = 0;
    int sentence_no = 0;
    std::string sentence = "";
    element()
    {
        this->sentence="";
    }
    element(int b, int p, int pa, int se, std::string s)
    {
        book_code = b;
        page = p;
        paragraph = pa;
        sentence_no = se;
        sentence = s;
    }
};


class SearchEngine
{
private:
   std:: vector<element*> storage;

public:
    /* Please do not touch the attributes and
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node *search(string pattern, int &n_matches);

    /* -----------------------------------------*/
};
