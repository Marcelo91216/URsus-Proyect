#include <iostream>
#include <string>
#include "Tree.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        Tree *bin = new Tree();
        string url(argv[1]);
        bin->insert(url);
        bin->print();

        URLGrammar grammar;
        if (grammar.isValidURL(url))
        {
            cout << "La URL es válida." << endl;
        }
        else
        {
            cout << "La URL es sus." << endl;
        }

        delete bin;
    }
    return 0;
}