#include <iostream>
#include <queue>
#include <Tree.hpp>

using namespace std;

int main(int argc, char *argv[]){
    if(argc > 1){
        Tree* bin = new Tree();
        string url(argv[1]);
        bin->insert(url);
        bin->print();
        delete bin;
    }
    return 0;
}