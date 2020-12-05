//
// Created by Zhenglin Li on 2020/12/4.
//

#ifndef FINAL_IN_OUTSTREAM_H
#define FINAL_IN_OUTSTREAM_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include <cstring>


using namespace std;

//链表节点定义
typedef struct LNode {
    char key{};//字符
    int number{};//权值
    LNode *next = nullptr;
}LinkNode;

//创建一个新结点
LinkNode* CreateNode() {
    LinkNode* newNode = (LNode *) malloc(sizeof(LNode));
    if (newNode != nullptr) {
        newNode->key = '0';
        newNode->number = 0;
        newNode->next = nullptr;
    }
    return newNode;
}

//读取文件的信息，返回链表头指针
LinkNode* in_outstream() {
    char c;
    bool flag;
    LinkNode* head = nullptr;//头指针
    LinkNode* current = head;//当前结点
    ifstream in_stream;//源文件
    ofstream out_stream;//ofstream类构造函数，如果为0，打开失败
    in_stream.open(R"(D:\code is here\Final\compress.txt)");
    //打开源文件错误
    if (in_stream.fail()) {
        cout << "opening compress.txt failure";
        exit(1);
    }
    out_stream.open(R"(D:\code is here\Final\CharsAndNums.txt)");
    //打开输出文件错误
    if (out_stream.fail()) {
        cout << "opening CharsAndNums.txt failure";
        exit(1);
    }
    //遍历文件，依次读取每个字符
    while (in_stream.get(c)) {
        cout << c;
        flag = true;//标志c不存在于链表中
        //遍历链表，判断c是否已经存在于链表中
        for (current = head; current != nullptr; current = current->next) {
            //c已经存在，c对应的频数加1
            if (current->key == c) {
                current->number++;
                flag = false;//flag置为false
                break;//跳出for循环
            }
        }
        //遍历完链表，c不存在，则创建新节点
        if (flag) {
            LinkNode* newnode = CreateNode();
            newnode->key = c;
            newnode->number++;
            newnode->next = head;
            head = newnode;//这里头指针在往前移动，所以最后还需要一个头指针
        }
    }
    LinkNode* head1 = CreateNode();//最后加一个头指针在前面
    head1->next = head;
    cout << "The result:" << endl;//控制台输出
    //输出至输出文件
    out_stream << "字符" << "\t频数" << endl;
    //遍历链表，分别输出至控制台和文件中
    for (current = head; current != nullptr; current = current->next) {
        cout << current->key << ' ' << current->number << '\n';
        out_stream.put(current->key);
        out_stream << "\t" << current->number << endl;
    }

    //关闭流
    in_stream.close();
    out_stream.close();
    return head1;//返回存放了权值和字符的链表头指针
}

#endif //FINAL_IN_OUTSTREAM_H
