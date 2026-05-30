// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return;
    }

    std::string str;
    while (!file.eof())
    {
        char ch = file.get();
        
        if (ch >= 'A' && ch <= 'Z') {
            ch += 32;
            str.push_back(ch);
        }
        else if (ch >= 'a' && ch <= 'z') {
            str.push_back(ch);
        } else {
            if (!str.empty()) {
                tree.insert(str);
                str.clear();
            }
        }
    }
    if (!str.empty()) {
        tree.insert(str);
    }

    file.close();
}
