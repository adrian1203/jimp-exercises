//
// Created by Adrian on 2017-05-25.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <string>
#include <iostream>
#include <memory>
namespace tree{
    template<class T>
    class Tree;
    template<class T>
    class Node{
        T value;
        std::unique_ptr<Node<T>> left;
        std::unique_ptr<Node<T>> right;

    };
    template<class T>
    class Tree{
    public:
        Tree();

    private:
        std::unique_ptr<Node<T>> root;
    };
}
#endif //JIMP_EXERCISES_TREE_H
