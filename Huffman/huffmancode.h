#ifndef FINAL_HUFFMANCODE_H
#define FINAL_HUFFMANCODE_H

#include"in_outstream.h"
#include <iostream>
#include<fstream>
#include <vector>
#include <cstring>
using namespace std;

typedef char **HuffCode;

typedef struct TreeNode {
    int left = -1, right = -1;
    char ch = '0';
    int parent = -1;    // -1表示无父节点
    int weight = 0;
} TreeNode;
void initLeafs(TreeNode *p, int numLeafs,LinkNode* head) {
    // 对p指向的数组中前numLeafs个元素进行初始化
    LinkNode* current=head->next;
    for (int i = 0; i < numLeafs; i++) {
        p[i] = {-1,-1,current->key,-1,current->number};//初始化
        current = current->next;
    }
    cout << "---------------" << endl;
}
void searchMin(const TreeNode *p, int nums, int &min1, int &min2) {
    // 在p指向的nums个元素的数组中
    // 搜索权值最小的两个节点
    // 并保证其parent为空，即根节点

    // 首先找到数组中第一个根节点，即parent为空的节点
    // 将此根节点作为weight最小节点，即采用排序算法
    for (int i = 0; i < nums; i++) {
        if (p[i].parent == -1) {
            min1 = i;
            break;
        }
    }
    // 寻找数组中权值最小的根节点作为min1
    for (int i = 0; i < nums; i++) {
        if (p[i].parent == -1 && p[i].weight < p[min1].weight) {
            min1 = i;
        }
    }
    // 寻找到所有根节点中权值最小的weight1以后，继续寻找第二个
    // 找到数组中第一个根节点，作为初始权值最小的位置min2
    // 必须保证第min2不等于min1
    for (int i = 0; i < nums; i++) {
        if (p[i].parent == -1 && i != min1) {
            min2 = i;
            break;
        }
    }

    // 寻找数组中除去min1以外权值最小的根节点
    for (int i = 0; i < nums; i++) {
        if (p[i].parent == -1 && p[i].weight < p[min2].weight && i != min1) {
            min2 = i;
        }
    }
}
int createHuffman(TreeNode *p, int numLeafs,LinkNode* head) {
    // 1、初始化前numLeafs个根节点，指定其权值
    initLeafs(p, numLeafs,head);

    // 创建用于存储权值最小两个节点的位置
    int minPos1, minPos2;

    // 2、numLeafs个根节点需要进行numLeafs-1次合并
    for (int i = 0; i < numLeafs - 1; i++) {
        // 3、寻找权值最小的前两个节点
        // 寻找的范围是前numLeafs+i个节点
        // 即所有已经创建的节点
        searchMin(p, numLeafs + i, minPos1, minPos2);
        // 4、在numLeafs+1处创建新根节点
        p[numLeafs + i].weight = p[minPos1].weight + p[minPos2].weight;
        p[numLeafs + i].left = minPos1;
        p[numLeafs + i].right = minPos2;
        // 将当前权值最小的两个节点的parent指向新创建的根节点
        // 表示其不再是根节点，不再参与合并
        p[minPos1].parent = numLeafs + i;
        p[minPos2].parent = numLeafs + i;
    }
    return numLeafs;
}
void printHuffman(TreeNode *p, int numNodes) {
    // 输出所有的节点，及节点信息
    for (int i = 0; i < numNodes; i++) {
        cout << "下标：" << i <<"\t权值：" << p[i].weight
        << "\t字符：" << p[i].ch << "\t父节点：" <<
        p[i].parent << "\t左子节点：" << p[i].left <<
        "\t右子节点：" << p[i].right << endl;
    }
}

void printPreOrder(TreeNode *p, int index) {
    if (p == NULL)
        return;
    cout << index;
    if (p[index].left != -1 ) {
        printPreOrder(p, p[index].left);
    }
    if ( p[index].right != -1) {
        printPreOrder(p, p[index].right);
    }
}


int Huffumancode(TreeNode *p,HuffCode &HC,LinkNode* head) {
    int numberLeafs;
    LinkNode* current = head;//当前节点
    for(numberLeafs=-1;current!=NULL;current=current->next){
        numberLeafs++;
    }
    createHuffman(p, numberLeafs,head);
    printHuffman(p, numberLeafs * 2 - 1);
    HC = (char **) malloc((numberLeafs) * sizeof(char *));
    //暂存编码
    char *code;  //暂存编码的
    code = (char *) malloc(numberLeafs * sizeof(char));//使用了第0单元

    code[numberLeafs - 1] = '\0';
    int i;
    for (i = 0; i < numberLeafs; i++) {
        int start = numberLeafs - 1;
        for (int c = i, f = p[c].parent; f != -1; c = p[c].parent, f = p[c].parent) {//从叶子扫描到根
            if (p[f].left == c) {
                code[--start] = '0';
            } else if (p[f].right == c) {
                code[--start] = '1';
            } else {//否则什么也不做
                ;
            }
        }

        HC[i] = (char *) malloc(strlen(code) * sizeof(char));//动态地分配内存给存放哈夫曼编码的数组
        strcpy(HC[i], &code[start]);//暂时存放的code数组值复制给哈夫曼编码的数组
    }
    for (i = 0; i < numberLeafs; i++) {
        printf("%s\n", HC[i]);
    }
    return (numberLeafs * 2 - 1);
}

#endif //FINAL_HUFFMANCODE_H
