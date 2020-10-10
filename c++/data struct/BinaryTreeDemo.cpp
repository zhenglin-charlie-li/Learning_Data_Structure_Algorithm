//
// Created by Zhenglin Li on 2020/10/8.
//
#include "iostream"
#include "string"

using namespace std;

/*class person {
private:
    int number;
    string name;
    person *next;
public:
    person(int number, const string &name) : number(number), name(name) {}

    person() {}

    void show(){
        cout<<number<<"\t"<<name<<endl;
    }
};*/

class Node {
private:
    int no;
    string name;
    Node *left= NULL;
    Node *right= NULL;
public:
    Node() {}

    Node(int no, string name) : no(no), name(name) {}

    string show() {
        return name + "\t" + to_string(no);
    }

    void setLeft(Node *toAdd) {
        this->left = toAdd;
    }

    void setRight(Node *toAdd) {
        this->right = toAdd;
    }

    void preOrder() {
        cout << this->show() << endl;
        if (this->left != NULL) {
            this->left->preOrder();
        }
        if (this->right != NULL) {
            this->right->preOrder();
        }
    }
};

class BinaryTree {
private:
    Node *rootNode = NULL;
public:
    BinaryTree(Node *rootNode) : rootNode(rootNode) {}

    BinaryTree() {}

    void setRootNode(Node *rootNode) {
        this->rootNode = rootNode;
    }


    void preOrder() {
        if (this->rootNode != NULL) {
            this->rootNode->preOrder();
        } else {
            cout << "NULL rootNode!" << endl;
        }
    }
};

int main109() {
    /*person one(123,"asdasd");
    one.show();*/
//    BinaryTree *binaryTree = new BinaryTree(new Node(1, "asd"));

//    BinaryTree Tree(new Node(1, "asd"));

    Node node1(1, "a");
    Node node2(2, "as");
    Node node3(3, "asd");
    Node node4(4, "sd");
    Node node5(5, "d");

    BinaryTree bt;
    bt.setRootNode(&node1);
    node1.setLeft(&node2);
    node1.setRight(&node3);
    node2.setLeft(&node4);
    node2.setRight(&node5);
    bt.preOrder();
    return 0;
}
