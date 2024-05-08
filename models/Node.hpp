#include <string>
class Node
{
private:
    std::string v;
    std::string t;
    Node *l;
    Node *r;

public:
    void setValue(std::string v) { this->v = v; }
    void setType(std::string t) { this->t = t; }
    void setLeft(Node *l) { this->l = l; }
    void setRight(Node *r) { this->r = r; }

    std::string getV() { return this->v; }
    std::string getT() { return this->t; }
    Node *getL() { return this->l; }
    Node *getR() { return this->r; }

    Node()
    {
        v = "";
        t = "";
        l = nullptr;
        r = nullptr;
    };

    Node(std::string v, std::string t, Node *l, Node *r)
    {
        this->v = v;
        this->t = t;
        this->l = l;
        this->r = r;
    };
};