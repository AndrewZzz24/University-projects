#include <iostream>
#include <string>

using namespace std;

struct tree1 {
    long long key = 0;
    tree1 *parent = nullptr;
    tree1 *left = nullptr;
    tree1 *right = nullptr;
};
tree1 *root;


tree1 *search(tree1 *ptr, const long long &key) {
    if (ptr == nullptr || ptr->key == key) {
        return ptr;
    }
    if (key < ptr->key) {
        return search(ptr->left, key);
    } else {
        return search(ptr->right, key);
    }
}

tree1 *find(const long long &key) {
    return search(root, key);
}

tree1 *next(long long key) {
    tree1 *current = root;
    tree1 *successor = nullptr;

    while (current != nullptr) {
        if (current->key > key) {
            successor = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return successor;
}

tree1 *prev(long long key) {
    tree1 *current = root;
    tree1 *predecessor = nullptr;

    while (current != nullptr) {
        if (current->key >= key) {
            current = current->left;
        } else {
            predecessor = current;
            current = current->right;
        }
    }

    return predecessor;
}

void insert(long long key) {
    auto z = new tree1;
    z->key = key;
    tree1 *ptr = root;

    while (ptr != nullptr) {
        if (key == ptr->key) {
            return;
        }
        if (key > ptr->key) {
            if (ptr->right != nullptr) {
                ptr = ptr->right;
            } else {
                z->parent = ptr;
                ptr->right = z;
                return;
            }
        } else if (key < ptr->key) {
            if (ptr->left != nullptr) {
                ptr = ptr->left;
            } else {
                z->parent = ptr;
                ptr->left = z;
                return;
            }
        }
    }

    root = z;
}

void remove(long long key) {
    tree1 *ptr = find(key);

    if (ptr == nullptr) {
        return;
    }

    if (ptr == root) {
        if (ptr->left == nullptr && ptr->right == nullptr) {
            root = nullptr;
            delete ptr;
            return;
        }

        if (ptr->left == nullptr || ptr->right == nullptr) {
            if (ptr->left == nullptr) {
                root = ptr->right;
            } else {
                root = ptr->left;
            }
            delete ptr;
            return;
        }
    }

    if (ptr->left == nullptr && ptr->right == nullptr) {
        if (ptr->parent->left == ptr) {
            ptr->parent->left = nullptr;
        }
        if (ptr->parent->right == ptr) {
            ptr->parent->right = nullptr;
        }
        delete ptr;
        return;
    }

    if (ptr->left == nullptr || ptr->right == nullptr) {
        if (ptr->left == nullptr) {
            if (ptr->parent->left == ptr) {
                ptr->parent->left = ptr->right;
            } else {
                ptr->parent->right = ptr->right;
            }
            ptr->right->parent = ptr->parent;
        } else {
            if (ptr->parent->left == ptr) {
                ptr->parent->left = ptr->left;
            } else {
                ptr->parent->right = ptr->left;
            }
            ptr->left->parent = ptr->parent;
        }
        delete ptr;
        return;
    }

    tree1 *successor = next(key);
    ptr->key = successor->key;
    if (successor->parent->left == successor) {
        successor->parent->left = successor->right;
        if (successor->right != nullptr) {
            successor->right->parent = successor->parent;
        }
    } else {
        successor->parent->right = successor->right;
        if (successor->right != nullptr) {
            successor->right->parent = successor->parent;
        }
    }
    delete successor;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
    string s;
    int x;

    while (cin >> s >> x) {
        if (s == "insert") insert(x);
        if (s == "delete")  remove(x);
        if (s == "exists") {
            auto result = find(x);
            if (result == nullptr) cout << "false"<<endl;
            else cout << "true"<<endl;
        }
        if (s == "next") {
            auto result = next(x);
            if (result == nullptr) cout << "none"<<endl;
            else cout << result->key<<endl;
        }
        if (s == "prev") {
            auto result = prev(x);
            if (result == nullptr) cout << "none"<<endl;
            else cout << result->key<<endl;
        }
    }
    return 0;
}