#include <iostream>
#include <queue>
using namespace std;

class Node{
    private:
        string v;
        Node *l;
        Node *r;
    public:
        void setValue(string v){this->v=v;}
        void setLeft(Node* l){this->l=l;}
        void setRight(Node* r){this->r=r;}

        string getV(){return this->v;}
        Node* getL(){return this->l;}
        Node* getR(){return this->r;}

        Node(){
            v="";
            l=nullptr;
            r=nullptr;
        };

        Node(string v, Node* l, Node* r){
            this->v=v;
            this->l=l;
            this->r=r;
        };
};

class Tree{
    public:
        Tree();
        void print();
        void insert(string);
    private:
        Node *root;
};

Tree::Tree(){
    root = new Node("://", nullptr, new Node(".", nullptr, new Node(".", nullptr, new Node("/", nullptr, nullptr))));
}

void Tree::print(){
    bool finish=false;
    queue<Node*> qu;
    qu.push(root);
    while (!qu.empty()){
        Node* temp = qu.front();
        qu.pop();
        cout<<temp->getV();
        if(temp->getL()!=nullptr){
            qu.push(temp->getL());
        }
        if(temp->getR()!=nullptr){
            qu.push(temp->getR());
        }
    }
}

void Tree::insert(string v){
    int s=v.size();
    for(int i=0; i<s; i++){
        
    }
}

int main(int argc, char *argv[]){
    if(argc>0){
        Tree* bin = new Tree();
        string url(argv[1]);
        bin->print();
    }
    return 0;
}