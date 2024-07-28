#include "Node.h"

Node::Node()
 {
    this->left=nullptr;
    this->right=nullptr;
    this->book_code=-1;
    this->page=-1;
    this->paragraph=-1;
    this->sentence_no=-1;
    this->offset=-1;
}

Node::Node(int b_code, int pg, int para, int s_no, int off)
{
    this->book_code = b_code;
    this->page = pg;
    this->paragraph = para;
    this->sentence_no = s_no;
    this->offset = off;
    this->left=nullptr;
    this->right=nullptr;
}