#pragma once
#include <string>
#include <queue>
#include <iostream>
#include "Node.hpp"
#include "Grammar.hpp"
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
    std::queue<Node *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        Node *temp = qu.front();
        qu.pop();
        std::cout << "(" << temp->getV() << ", " << temp->getT() << ") ";
        if (temp->getL() != nullptr)
        {
            qu.push(temp->getL());
        }
        if (temp->getR() != nullptr)
        {
            qu.push(temp->getR());
        }
    }
    std::cout << std::endl;
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
                current->setRight(new Node(".", "dot", "", nullptr, nullptr));
            }
            current = current->getR();
        }
        else if (v[i] == '/')
        {
            if (current->getR() == nullptr)
            {
                current->setRight(new Node("/", "slash", "", nullptr, nullptr));
            }
            current = current->getR();
        }
        else
        {
            URLGrammar grammar;
            std::string alphabet = grammar.getCharacterAlphabet(v[i]);
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