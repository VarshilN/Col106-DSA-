#include "Node.h"

Node::Node() 
{
   left=nullptr;
  right=nullptr;
  book_code=0;
  paragraph=0;
  sentence_no=0;
  offset=0;
}
Node::Node(int b_code, int pg, int para, int s_no, float off){
    left=right=nullptr;
    book_code = b_code;
    page = pg;
    paragraph = para;
    sentence_no = s_no;
    offset = off;
}