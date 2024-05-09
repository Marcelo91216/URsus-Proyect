#pragma once
#include <Node.hpp>
#include <string>
#include <Grammar.hpp>
class Tree
{
public:
    Tree();
    void print();
    void insert(std::string);
    bool isValidURL(const std::string &url);

private:
    Node *root;
};

Tree::Tree()
{
    root = new Node("://", "protocol", "", nullptr, new Node(".", "dot", "" ,nullptr, new Node(".", "dot", "", nullptr, new Node("/", "slash", "",nullptr, nullptr))));
}

void Tree::print()
{
    queue<Node *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        Node *temp = qu.front();
        qu.pop();
        cout << "(" << temp->getV() << ", " << temp->getT() << ") ";
        if (temp->getL() != nullptr)
        {
            qu.push(temp->getL());
        }
        if (temp->getR() != nullptr)
        {
            qu.push(temp->getR());
        }
    }
    cout << endl;
}

void Tree::insert(std::string v)
{
    Node *current = root;
    int s = v.size();
    for (int i = 0; i < s; i++)
    {
        if (v[i] == '.')
        {
            if (current->getR() == nullptr)
            {
                current->setRight(new Node(".", "dot", "latin", nullptr, nullptr));
            }
            current = current->getR();
        }
        else if (v[i] == '/')
        {
            if (current->getR() == nullptr)
            {
                current->setRight(new Node("/", "slash", "latin", nullptr, nullptr));
            }
            current = current->getR();
        }
        else
        {
            std::string alphabet = "latin";
            if (v[i] >= 0 && v[i] <= 127)
            {
                alphabet = "latin";
            }
            else if (v[i] >= 0x0400 && v[i] <= 0x04FF)
            {
                alphabet = "cyrillic";
            }
            else if (v[i] >= 0x0600 && v[i] <= 0x06FF)
            {
                alphabet = "arabic";
            }
            else

            if (current->getL() == nullptr)
            {
                current->setLeft(new Node(std::string(1, v[i]), "char", alphabet, nullptr, nullptr));
            }
            current = current->getL();
        }
    }
}
bool Tree::isValidURL(const std::string &url)
{
    URLGrammar grammar;
    return grammar.isValidURL(url);
}