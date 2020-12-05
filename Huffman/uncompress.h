#ifndef FINAL_UNCOMPRESS_H
#define FINAL_UNCOMPRESS_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include <cstring>

using namespace std;

int UnCompress(TreeNode tree[], int numAllNode) {
    ifstream in_stream;
    ofstream out_stream;
    in_stream.open(R"(D:\code is here\Final\Only0And1.txt)");
    if (in_stream.fail()) {
        cout << "inserting to Only0And1 file is failing";
        exit(1);
    }
    out_stream.open(R"(D:\code is here\Final\afterUncompress.txt)");
    if (out_stream.fail()) {
        cout << "inserting to afterUncompress file is failing";
        exit(1);
    }
    char contents[102400];
    int i = 0;
    char c;
    while (in_stream.get(c)) {
        contents[i++] = c;
        cout.put(c);
    }
    i = 0;
    int rootIndex = numAllNode - 1;
    cout << endl << "rootIndex" << rootIndex << endl;
    int index = rootIndex;
    char temp;//目前没有 和\n了
    while (contents[i] != '\0') {
        if (contents[i] == '0') {
            index = tree[index].left;
            if (tree[index].left == -1 && tree[index].right == -1) {
                temp=tree[index].ch;
                if(temp!=32&&temp!=10){
                    cout << temp;
                    out_stream.put(temp);
                }else if(temp==32){
                    cout << ' ';
                    out_stream.put(' ');
                }else if(temp==10){
                    cout<<'\n';
                    out_stream.put('\n');
                }
                index = rootIndex;
            }
        } else if (contents[i] == '1') {
            index = tree[index].right;
            if (tree[index].left == -1 && tree[index].right == -1) {
                temp=tree[index].ch;
                if(temp!=32&&temp!=10){
                    cout << temp;
                    out_stream.put(temp);
                }else if(temp==32){
                    cout << ' ';
                    out_stream.put(' ');
                }else if(temp==10){
                    cout<<'\n';
                    out_stream.put('\n');
                }
                index = rootIndex;
            }
        }
        i++;
    }
    cout << "UnCompress ended" << endl;
    return 0;
}

#endif //FINAL_UNCOMPRESS_H
