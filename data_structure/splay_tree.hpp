#pragma once

#include "../template.hpp"

template <typename T> struct splay_tree {
    struct node {
        node *left, *right, *par;
        int size;
        T val;
        node(T val) : left(nullptr), right(nullptr), par(nullptr), size(1), val(val) {}
        void rotate() {
            node *p, *pp, *c;
            p = par, pp = p->par;
            if (p->left == this) {
                c = right, right = p, p->left = c;
            } else {
                c = left, left = p, p->right = c;
            }
            if (pp) {
                if (pp->left == p) {
                    pp->left = this;
                } else {
                    pp->right = this;
                }
            }
            if (c) c->par = p;
            par = pp, p->par = this;
            p->update();
            update();
        }
        int state() {
            if (!par) { return 0; }
            if (par->left == this) {
                return 1;
            } else {
                return -1;
            }
        }
        void splay() {
            while (state() != 0) {
                if (par->state() == 0) {
                    rotate();
                } else if (state() == par->state()) {
                    par->rotate(), rotate();
                } else {
                    rotate(), rotate();
                }
            }
        }
        void update() {
            size = 1;
            if (left) size += left->size;
            if (right) size += right->size;
        }
    };
    node *root;
    splay_tree(node *root = nullptr) : root(root) {}
    int size() { return root ? root->size : 0; }
    node *get_node(int i) {
        node *cur = root;
        while (true) {
            int size_l = cur->left ? cur->left->size : 0;
            if (i < size_l) cur = cur->left;
            if (i == size_l) {
                cur->splay();
                return root = cur;
            }
            if (i > size_l) cur = cur->right, i -= size_l + 1;
        }
    }
    T &operator[](int i) { return get_node(i)->val; }
    template <typename F> int lower_bound(F f) {
        if (!root) return 0;
        node *cur = root;
        int ret = -1;
        while (true) {
            if (cur->state() < 1) {
                ret += cur->left ? cur->left->size + 1 : 1;
            } else {
                ret -= cur->right ? cur->right->size + 1 : 1;
            }
            if (f(cur->val)) {
                if (cur->left) {
                    cur = cur->left;
                } else {
                    cur->splay(), root = cur;
                    return ret;
                }
            } else {
                if (cur->right) {
                    cur = cur->right;
                } else {
                    cur->splay(), root = cur;
                    return ret + 1;
                }
            }
        }
    }
    splay_tree split(int size_left) {
        if (size_left == 0) {
            node *root_r = root;
            root = nullptr;
            return root_r;
        }
        if (size_left == root->size) return nullptr;
        node *root_r = get_node(size_left);
        root = root_r->left;
        root_r->left = nullptr, root->par = nullptr;
        root_r->update();
        return root_r;
    }
    void merge(splay_tree right) {
        if (!root) {
            root = right.root;
            return;
        }
        if (!right.root) return;
        get_node(root->size - 1);
        root->right = right.root, right.root->par = root;
        root->update();
    }
    void insert(int i, T val) {
        splay_tree vt = new node(val), right = split(i);
        merge(vt), merge(right);
    }
    void erase(int i) {
        splay_tree vt = split(i);
        splay_tree right = vt.split(1);
        delete vt.root;
        merge(right);
    }
};