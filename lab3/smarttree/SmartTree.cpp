//
// Created by adrian on 18.03.17.
//

#include "SmartTree.h"
#include <ostream>
#include <string>
#include <memory>
#include <sstream>
#include <iostream>

namespace datastructures {
    struct SmartTree;

    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        std::unique_ptr<SmartTree> ptr(new SmartTree);
        ptr->root = nullptr;
        ptr->left = nullptr;
        ptr->right = nullptr;
        ptr->value = value;
        return ptr;

    }

    std::unique_ptr<SmartTree>
    InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        if (tree != nullptr) {
            tree->left = move(left_subtree);
        }
        return tree;
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        if (tree != nullptr) {
            tree->right = move(right_subtree);
        }
        return tree;

    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        if (unique_ptr == nullptr) {
            return;
        }
        PrintTreeInOrder(unique_ptr->left, out);
        for (int i = 0; i < std::to_string(unique_ptr->value).size(); i++) {
            (*out).put(std::to_string(unique_ptr->value)[i]);
        }
        (*out).put(',');
        (*out).put(' ');
        PrintTreeInOrder(unique_ptr->right, out);
    }


    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        std::string str;
        str = str + "[" + std::to_string((tree->value)) + " ";
        if (tree->left != nullptr) {
            str = str + DumpTree(tree->left);
        } else {
            str = str + "[none]";
        }
        str = str + " ";
        if (tree->right != nullptr) {
            str = str + DumpTree(tree->right);
        } else {
            str = str + "[none]";
        }
        str = str + "]";
        return str;
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {
        int i = 0;
        return BuildTree(tree, &i);
    }

    std::unique_ptr<SmartTree> BuildTree(const std::string &str, int *i) {
        std::string tmpstr = "";
        (*i)++;
        while ((str[*i] != ' ') and (str[*i] != ']')) {
            tmpstr += str[*i];
            (*i)++;
        }

        if (tmpstr != "none") {
            int tmp = std::stoi(tmpstr);
            std::unique_ptr<SmartTree> ptr = CreateLeaf(tmp);
            (*i)++;
            ptr->left = BuildTree(str, i);
            while (str[*i] != '[') {
                (*i)++;
            }
            ptr->right = BuildTree(str, i);
            return ptr;
        } else {
            return nullptr;
        }
    }


}
