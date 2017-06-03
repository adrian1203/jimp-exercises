//
// Created by Adrian on 2017-05-25.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <memory>
#include <iostream>

using namespace std;
namespace tree {


    template<class Element>
    class Leaf {
    public:
        Leaf(const Element &element) : value_{element}, left_{nullptr}, right_{nullptr} {}
        Element value_;
        unique_ptr<Leaf<Element>> left_;
        unique_ptr<Leaf<Element>> right_;
    };


    template<class Element>
    class Tree {
    public:
        size_t size_;
        size_t depth_;
        unique_ptr<Leaf<Element>> root_;
        Tree(Element e) :size_{1}, depth_{1},root_{make_unique<Leaf<Element>>(e)}{};
        Tree() {};
        size_t Size() {
            return size_;
        };

        size_t Depth() {
            return depth_;
        };

        Element Value() {
            return root_->value_;
        };

        void Insert(const Element &e) {
            size_++;
            size_t tmpdepth = 2;
            Leaf<Element> *tmp_wsk = root_.get();
            while (1) {
                if (e < tmp_wsk->value_) {
                    if (tmp_wsk->left_ == nullptr) {
                        depth_ = max(tmpdepth, depth_);
                        tmp_wsk->left_ = make_unique<Leaf<Element>>(e);
                        break;
                    } else {
                        tmpdepth++;
                        tmp_wsk = tmp_wsk->left_.get();
                    }
                } else {
                    if (tmp_wsk->right_ == nullptr) {
                        tmp_wsk->right_ = make_unique<Leaf<Element>>(e);
                        depth_ = max(tmpdepth, depth_);
                        break;
                    } else {
                        tmpdepth++;
                        tmp_wsk = tmp_wsk->right_.get();
                    }
                }
            }
        };

    };
}
#endif //JIMP_EXERCISES_TREE_H

