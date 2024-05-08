#include <Node.hpp>

class Tree{
    public:
        Tree();
        void print();
        void insert(std::string);
    private:
        Node *root;
};

Tree::Tree(){
    root = new Node("://", "protocol", nullptr, new Node(".", "dot", nullptr, new Node(".", "dot", nullptr, new Node("/", "slash", nullptr, nullptr))));
}

void Tree::print(){
    queue<Node*> qu;
    qu.push(root);
    while (!qu.empty()){
        Node* temp = qu.front();
        qu.pop();
        cout << "(" << temp->getV() << ", " << temp->getT() << ") ";
        if(temp->getL()!=nullptr){
            qu.push(temp->getL());
        }
        if(temp->getR()!=nullptr){
            qu.push(temp->getR());
        }
    }
    cout << endl;
}

void Tree::insert(std::string v){
    Node* current = root;
    int s = v.size();
    for(int i=0; i<s; i++){
        if(v[i] == '.'){
            if(current->getR() == nullptr){
                current->setRight(new Node(".", "dot", nullptr, nullptr));
            }
            current = current->getR();
        }
        else if(v[i] == '/'){
            if(current->getR() == nullptr){
                current->setRight(new Node("/", "slash", nullptr, nullptr));
            }
            current = current->getR();
        }
        else{
            if(current->getL() == nullptr){
                current->setLeft(new Node(std::string(1, v[i]), "char", nullptr, nullptr));
            }
            current = current->getL();
        }
    }
}