#include<iostream>
#include "huffmancode.h"
#include "write_message.h"
#include "uncompress.h"

using namespace std;

int main() {
    int m;
    TreeNode p[10000];
    HuffCode HC;
    LinkNode* head = in_outstream();
    LinkNode* current = head;
    cout << "¹þ·òÂü±àÂë" << endl;
    m = Huffumancode(p, HC, current);
    write_message(m, p, head, HC);
    UnCompress(p, m);
    return 0;
}

