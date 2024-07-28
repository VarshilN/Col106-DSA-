#include <assert.h>
#include <sstream>
#include "qna_tool.h"
#include<cmath>
#include <iostream>
using namespace std;
#define FILENAME "text_combined.txt"

bool separator_(vector<char> s, char ch)
{
    for (int i=0;i<s.size();i++)
    {
       
        if (s[i]== ch)
        {
            return true;
        }
    }
    return false;
}
vector<string> tokanized(const string s)
{
    vector<string> ans;
    string curr = "";
    vector<char> symbols = {' ','.', ',', '-', ':', '!', '\"', '\'','(', ')','?', '[', ']', ';','@'};
    //pp 
    for (char i : s)
    {   //' '
         if (!separator_(symbols,i))
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
    return ans; // ye tokanization same hai as in dictionary
}

void QNA_tool::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    vector<string> tsentence = tokanized(sentence);
    dic->insert_tokenised_sentences(tsentence);
    telement* e = new telement(book_code, page, paragraph, sentence_no, tsentence);
    corpus.push_back(e);
}

QNA_tool::QNA_tool()
{
    // Implement your function here
    //  ofstream o1("p1");
    // ofstream o2("p2");
    //src = new SearchEngine();
    dumy = new dumyHash();
    wordpair = new Hash();

//     ////////////
//     std::ifstream inputFile(FILENAME);
//     cout<<"contruction done, entering while loop of corpus"<<endl;
//     if (!inputFile.is_open())
//     {
//         throw runtime_error("Error: Unable to open the input file.");
//     }
//     std::string tuple;
//     std::string sentence;
//     while (std::getline(inputFile, tuple, ')') && std::getline(inputFile, sentence))
//     {
//         // Get a line in the sentence
//         tuple += ')';

//         std::vector<int> metadata;
//         std::istringstream iss(tuple);

//         // Temporary variables for parsing
//         std::string token;

//         // Ignore the first character (the opening parenthesis)
//         iss.ignore(1);

//         // Parse and convert the elements to integers
//         while (std::getline(iss, token, ','))
//         {
//             // Trim leading and trailing white spaces
//             size_t start = token.find_first_not_of(" ");
//             size_t end = token.find_last_not_of(" ");
//             if (start != std::string::npos && end != std::string::npos)
//             {
//                 token = token.substr(start, end - start + 1);
//             }

//             // Check if the element is a number or a string
//             if (token[0] == '\'')
//             {
//                 // Remove the single quotes and convert to integer
//                 int num = std::stoi(token.substr(1, token.length() - 2));
//                 metadata.push_back(num);
//             }
//             else
//             {
//                 // Convert the element to integer
//                 int num = std::stoi(token);
//                 metadata.push_back(num);
//             }
//         }
//         // Now we have the string in sentence
//         // And the other info in metadata
//         // Add to the dictionary
//         // Insert in the dictionary
//         vector<string> tsentence = tokanized(sentence);
//         // cout<<sentence<<endl;
//         dic->insert_tokenised_sentences(tsentence);
//         telement* e = new telement(metadata[0], metadata[1], metadata[2], metadata[3], tsentence);
//         corpus.push_back(e);
//         // cout<<"hellow"<<endl;
//         //src->insert_sentence(metadata[0], metadata[1], metadata[2], metadata[3], sentence);
//     }
//    // cout<<"h"<<endl;
//     //   dic->dump_dictionary("p1");
//     inputFile.close();
//     // now to store the word - count pairs in a trie
    //cout<<"corpus done"<<endl;
    std::ifstream InputFile("unigram_freq.csv");
    
    if (!InputFile.is_open())
    {
        throw runtime_error("Error: Unable to open the CSV file.");
    }

    std::string headerLine;
    std::getline(InputFile, headerLine);
    std::string line;
    while (std::getline(InputFile, line))
    {
        std::istringstream lineStream(line);
        std::string word;
        std::string countStr;
        if (std::getline(lineStream, word, ',') && std::getline(lineStream, countStr, ','))
        {
            long long count = std::stoll(countStr);
          
           wordpair->setval(word,count);
             //** //ye wordpair woh sab muje nhi mila headr mein
            //  cout<<"h2"<<endl;
        }
    }
    //cout<<"wordpair done"<<endl;
    // cout<<"h1"<<endl;
    InputFile.close();
    std::vector<std::string> str = {
        "a",
        "an",
        "and",
        "the",
        "who",
        "what",
        "in",
        "on",
        "at",
        "is",
        "it",
        "that",
        "with",
        "to",
        "of",
        "for",
        "you",
        "I",
        "he",
        "she",
        "we",
        "they",
        "me",
        "him",
        "us",
        "them",
        "my",
        "your",
        "his",
        "her",
        "its",
        "our",
        "their",
        "mine",
        "yours",
        "hers",
        "ours",
        "theirs",
        "this",
        "these",
        "those",
        "by",
        "as",
        "from",
        "of",
        "on",
        "off",
        "over",
        "under",
        "before",
        "after",
        "between",
        "above",
        "below",
        "though",
        "although",
        "because",
        "however",
        "unless",
        "until",
        "while",
        "since",
        "unless",
        "whether",
        "if",
        "were",
        "explain",
        "describe",
        "elaborate",
        "clarify",
        "define",
        "illustrate",
        "justify",
        "analyze",
        "evaluate",
        "compare",
        "contrast",
        "summarize",
        "discuss",
        "explore",
        "assess",
        "interpret",
        "probe",
        "examine",
        "investigate",
        "enumerate",
        "s"}; // dumytrie for useless words optimized!!
    for (string s : str)
    {
        dumy->insert(s);
    }
    //cout << "hi" << endl;
}
QNA_tool::~QNA_tool()
{
    delete dic;
    delete dumy;
    delete wordpair;
    // Implement your function here
}
/*
void QNA_tool::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here
    dic->insert_sentence(book_code,page,paragraph,sentence_no,sentence);
    src->insert_sentence(book_code,page,paragraph,sentence_no,sentence);
    if(prev==-1)
    {
        par.push_back(paragraph);
        prev=paragraph;
    }
   else if(prev!=paragraph)
   {
    par.push_back(paragraph);
    prev=paragraph;
   }
    return;
}*/


void insert_sorted(Node*& head, Node* n) {
    if (head == nullptr) {
        // If the list is empty, insert the node as the head.
        head = n;
        n->left = nullptr;
        n->right = nullptr;
        return;
    }

    if (n->offset > head->offset) {
        // Insert at the beginning of the list.
        n->left = nullptr;
        n->right = head;
        head->left = n;
        head = n;
        return;
    }

    Node* temp = head;

    while (temp->right != nullptr && temp->right->offset > n->offset) {
        temp = temp->right;
    }

    if (temp->right == nullptr) {
        // Insert at the end of the list.
        temp->right = n;
        n->left = temp;
        n->right = nullptr;
    } else {
        // Insert in the middle of the list.
        Node* nextNode = temp->right;
        temp->right = n;
        n->left = temp;
        n->right = nextNode;
        nextNode->left = n;
    }
}

void insert_node(Node *&head, Node *n)
{
    Node *temp = head;
    // cout << "enter" << endl;
    if (head->right == nullptr)
    {
        head->right = n;
        n->left = head;
        return;
    }
    bool b = 0;
    while (temp->right->offset >= n->offset)
    {
        temp = temp->right;
        if (temp->right == nullptr)
        {
            b = 1;
            temp->right = n;
            n->left = temp;
            n->right = nullptr;
            break;
        }
    }
    if (b == 0)
    {
        temp = temp->right;
        Node *x = temp->left;
        x->right = n;
        n->left = x;
        n->right = temp;
        temp->left = n;
    }
    // cout << "exit" << endl;
}

Node *QNA_tool::get_top_k_para(string question, int k)
{

    vector<string> tokenized_q = tokanized(question);
    int len=tokenized_q.size();
    vector<vector<float>> Queryvec(len);
    for (int i = 0; i<len; i++){
            float sp=0.0;
            float w = wordpair->getval(tokenized_q[i])+1.0;
            float wp = dic->get_word_count(tokenized_q[i]) + 1.0;
            sp = (wp)/(w) ;
            Queryvec[i] = {};
            Queryvec[i].push_back(sp);
            Queryvec[i].push_back(0);
            //cout<<"score"<<Queryvec[i][0]<<endl;
        }
        //cout << corpus.size();
    long long i = 0;
   // int cnt = 0;
    Node *head = new Node();
    head->offset = INT32_MAX;
    MinHeap mn;
    // ofstream OutputFile("get_par");
    while (i < corpus.size())
    {
        // cout<<i<<endl;
        telement *e = corpus[i];
        
        int bc = e->book_code;
        int pg = e->page;
        int para = e->paragraph;
        Node* n = new Node(bc,pg,para,0,0);
        while((bc == e->book_code) && (pg == e->page) && (para == e->paragraph)){
            for(string word : e->sentence){
                for(int j = 0; j<len; j++){
                    if(word == tokenized_q[j]){
                        // cout<< word << " and " << tokenized_q[j]<<endl;
                        (Queryvec[j][1])++;
                    }
                }
            }
            
            //i'll be storing the score of each paragraph in the 'offset' attribute
            i++;
            if(i>= corpus.size()){
                break;
            }
            e = corpus[i];        
        }    
        float PARASCORE = 0;
        for (int k = 0; k<len; k++)
        {
            
            float sp=Queryvec[k][0];
            // cout << tokanized(question)[k] << ": "<< sp<<endl; 
            float fp =Queryvec[k][1];
            if(k == 0){
                //cout<<fp<<endl;
            }
            // cout << "fp : "<<fp<<endl;
            PARASCORE +=fp*sp;
            //cout<<"Parascore "<<word<<" :" << PARASCORE<<endl;
        }
        mn.push_heap((-1)*PARASCORE,n); 
        for(int z = 0; z<len; z++){
            Queryvec[z][1] = 0.0;
        }
    }

         Node *temp = head;

         int cnt=0;

    while(cnt<k)
    {
        cnt++;
        Node*curr=mn.get_min()->n;
        temp->right=curr;
        curr->left=temp;
        temp=temp->right;
        mn.pop();
    }
   // Node* n = head->right;
    temp = head;                        //just to be extra sure
       for (int i = 1; i <= k; i++)
    {
        temp = temp->right;
    }
    temp->right = nullptr;
    return  head->right;

}
void QNA_tool::query(string question, string filename)
{
        vector<string> tokenized_q = tokanized(question);
    int len=tokenized_q.size();
    vector<vector<float>> Queryvec(len);
     
    for (int i = 0; i<len; i++)
    {
        
            float sp=0.0;
            float w = wordpair->getval(tokenized_q[i])+1.0;
            float wp = dic->get_word_count(tokenized_q[i]) + 1.0;
            if(wp!=1)
            {
               sp=1/wp;
            }        
   //cout<<"score of "<< tokenized_q[i] << " is :" << sp<<endl;
            Queryvec[i] = {};
            Queryvec[i].push_back(sp);
            Queryvec[i].push_back(0);
            //cout<<"score"<<Queryvec[i][0]<<endl;
        }
        //cout << corpus.size();
    long long i = 0;
   // int cnt = 0;
    Node *head = new Node();
    head->offset = INT32_MAX;
    MinHeap mn;
    //head->sentence=question;
    // ofstream OutputFile("get_par");
    while (i < corpus.size())
    {
        // cout<<i<<endl;
        telement *e = corpus[i];
        
        int bc = e->book_code;
        int pg = e->page;
        int para = e->paragraph;
        // if(bc==BOOK){
        //     cout<<bc<<endl;
        //     BOOK++;
        // }
  
        Node* n = new Node(bc,pg,para,0,0);
        while((bc == e->book_code) && (pg == e->page) && (para == e->paragraph)){
            for(string word : e->sentence){
                for(int j = 0; j<len; j++){
                    if(word == tokenized_q[j]){
                        // cout<< word << " and " << tokenized_q[j]<<endl;
                       if(dumy->getval(word)!=0)
                        {
                            continue;
                        }
                        (Queryvec[j][1])++;
                    }
                }
            }
            //i'll be storing the score of each paragraph in the 'offset' attribute
            i++;
            if(i>= corpus.size()){
                break;
            }
            e = corpus[i];        
        }    
        // cout << "collisions for this para:" << dp.getcollisions()<<endl;
    //     cout << "start variables:" << endl;
    //     element *e = src->storage[i];
    //     int bc = e->book_code;
    //     int pg = e->page;
    //     int para = e->paragraph;
    //     Dict*dp=new Dict();
    //     Node *n = new Node(bc, pg, para, 0, 0);
    //     bool fl = 0;
    //     cout << "end variables:" << endl;
    //   //  string str = "";
    //     while ((bc == e->book_code) && (pg == e->page) && (para == e->paragraph))
    //     {
    //         cout << "start loop:" << endl;
    //         if (i >= len)
    //         {
    //             break;
    //         }
    //          dp->insert_sentence(bc,pg,para,e->sentence_no,e->sentence);// isme bad alloc error de rha hai
    //     //    str += e->sentence;
    //         // insert in linked_list
    //         // i'll be storing the score of each paragraph in the 'offset' attribute
    //         cout << "p" << endl;
    //         i++;
    //         if (i >= len)
    //         {
    //             break;
    //         }
    //         //  str+=e->sentence;
    //         cout << "end insert :" << endl;
    //         e = src->storage[i];
    //     }
    //     cout << "hellow " << endl;
    //     // vector<string>res=tokanized(str);
    //     // cnt++;
    //     cout << "finish loop:" << endl;
    //     // cout<<cnt<<endl;
        float PARASCORE = 0;
        float wrds_in_par=0.0;
        bool flag=0;
       // float constant=0.0;
        for(int r=0;r<len;r++)
        {
            if(dumy->getval(tokenized_q[r])!=0)
            {
                continue;
            }
            
            wrds_in_par+=Queryvec[r][1];
        }
        if(wrds_in_par!=0)
        {
        for (int k = 0; k<len; k++)
        {
            if(dumy->getval(tokenized_q[k])!=0)
            {
                continue;
            }
            float sp=Queryvec[k][0];
            // cout << tokanized(question)[k] << ": "<< sp<<endl; 
            float fp =Queryvec[k][1];
            // cout << "fp : "<<fp<<endl;
            PARASCORE+=(fp)*sp*sp;
                        //make a good parascore function  
            //cout<<"Parascore "<<word<<" :" << PARASCORE<<endl; 
        }
         mn.push_heap((-1)*PARASCORE,n);
        }
        for(int z = 0; z<len; z++){
            Queryvec[z][1] = 0.0;
        }
    }
    int k=4;
    string api_key="Enter Your CHAT GPT Api Key";    
    if(mn.heap.empty())
    {
         query_llm(filename,head,k,api_key,question);
         return;
    }
         Node *temp = head;
         int cnt=0;
         if(mn.heap.size()<k)
         {
            //cout<<"hi"<<endl;
            k=mn.heap.size();
         }
    // cnt=0;
    while(cnt<k)
    {
        cnt++;
        Node*curr=mn.get_min()->n;
        temp->right=curr;
        curr->left=temp;
        temp=temp->right;
        mn.pop();
    }
    //Node* n = head->right;
    temp = head;     
  
     for (int i = 1; i <= k; i++)
    {
        temp = temp->right;
    }
    temp->right = nullptr;
   // cout<<"***"<<endl;
    query_llm(filename,head,k,api_key,question);
    return;
}

std::string QNA_tool::get_paragraph(int book_code, int page, int paragraph)
{   
    std::string filename = "mahatma-gandhi-collected-works-volume-";
    filename += to_string(book_code);
    filename += ".txt";
    std::ifstream inputFile(filename);
    std::string tuple;
    std::string sentence;

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the input file " << filename << "." << std::endl;
        exit(1);
    }
    std::string res = "";
    while (std::getline(inputFile, tuple, ')') && std::getline(inputFile, sentence)) {
        // Get a line in the sentence
        tuple += ')';

        int metadata[5];
        std::istringstream iss(tuple);
        std::string token;
        // Ignore the first character (the opening parenthesis)
        iss.ignore(1);

        // Parse and convert the elements to integers
        int idx = 0;
        while (std::getline(iss, token, ',')) {
            // Trim leading and trailing white spaces
            size_t start = token.find_first_not_of(" ");
            size_t end = token.find_last_not_of(" ");
            if (start != std::string::npos && end != std::string::npos) {
                token = token.substr(start, end - start + 1);
            }
            // Check if the element is a number or a string
            if (token[0] == '\'') {
                // Remove the single quotes and convert to integer
                int num = std::stoi(token.substr(1, token.length() - 2));
                metadata[idx] = num;
            } else {
                // Convert the element to integer
                int num = std::stoi(token);
                metadata[idx] = num;
            }
            idx++;
        }
        if(
            (metadata[0] == book_code) &&
            (metadata[1] == page) &&
            (metadata[2] == paragraph)
        ){
            res += sentence;
        }
    }
    inputFile.close();
    return res;
}
void QNA_tool::query_llm(string filename, Node *root, int k, string API_KEY,string question)
{
    // first write the 3 paragraphs into different files
    Node *traverse = root;
    //head of each answer linked list will be question
    traverse=traverse->right;
    int num_paragraph = 0;
    //k is 5
    int max_length=0;
    while (num_paragraph < k)
    {
        assert(traverse != nullptr);
        string p_file = "paragraph_";
        p_file += to_string(num_paragraph);
        p_file += ".txt";
        ofstream outfile(p_file);
        string paragraph;
      //  cout<<traverse->book_code<<" "<<traverse->page<<" "<<traverse->paragraph<<endl;
       paragraph= get_paragraph(traverse->book_code,traverse->page, traverse->paragraph);
        assert(paragraph != "$I$N$V$A$L$I$D$");
        outfile << paragraph;
        outfile.close();
        traverse = traverse->right;
        num_paragraph++;
    }
  //  cout<<"exit"<<endl;
    // write the query to query.txt;
    ofstream outfile("query.txt");
    string str="question:"+question;
    outfile<<str<<endl;
    // outfile<<"answer above question in this way:Provide a detailed overview of [Historical Figure]'s contributions to [specific field or cause]. Outline key aspects such as [list specific points]. Elaborate on each point, offering examples or anecdotes. Include relevant historical context and conclude with a summary of [Historical Figure]'s impact on [field or cause]. Please note that all this information should come only from the passage provided by me below and no other source. if corpus size is too small answer should be elaborated or if corpus is too large answer should be consiced answer  using provided data"<<endl;
    outfile<<"above given is a question. You have to answer it using ONLY the information in the passage below my me. The passage is from a corpus about mahatma gandhi. So make out how to contruct a fulfulling and logical answer from the limited information that you have"<<endl;
    // You can add anything here - show all your creativity and skills of using ChatGPT
    outfile.close();
    // python3 <filename> API_KEY paragraph_0.txt paragraph_1.txt paragraph_2.txt query.txt
    string command = "python3 ";
    command += filename;
    command += " ";
    command += API_KEY;
    command += " ";
    int cnt=0;
    while(cnt<k)
    {
        command+=("paragraph_"+std::to_string(cnt)+".txt");
        command+=" ";
        cnt++;
    }
    command += "query.txt";
    system(command.c_str());
    return;
}
// int main()
// {
//     QNA_tool x;
//     cout<<"Hi"<<endl;
//  //   cout<<"hi2"<<endl;
//    /*Node* n = x.get_top_k_para("", 4);
//      Node* temp = n;
//      while(temp){
//         cout << "("<<temp->book_code << " , "<<temp->page <<" , " << temp->paragraph<< ") score:"<< temp->offset<<endl;
//         temp = temp->right;
//      }  */ 
//     //  x.query("What were the views on England voyage", "p0");
//     Node* n = x.get_top_k_para("What is the purpose of life?", 8);
//     cout<<"gettopkcalled"<<endl;
//      Node* temp = n;
//      while(temp){
//         cout << "("<<temp->book_code << " , "<<temp->page <<" , " << temp->paragraph<< ") score:"<< temp->offset<<endl;
//         temp = temp->right;
//      }
//     return 0;
// }
