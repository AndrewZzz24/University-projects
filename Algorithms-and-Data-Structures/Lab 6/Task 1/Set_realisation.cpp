#include <iostream>

using namespace std;

struct hash_set {
    int value = 0;
    hash_set *next = nullptr;
    hash_set *prev = nullptr;
} hash_set1[100000];

int hash_function(int num);

void insert1(int num);

bool exists1(int num);

int hash_function(int num) {
    return abs(num)%100000;
}

void delete1(int num) {
    if (exists1(num)) {
        int result = hash_function(num);
        hash_set *pointer = hash_set1[result].next;
        while (pointer!= nullptr){
            if (pointer->value==num){
                pointer->prev->next=pointer->next;
                if (pointer->next!=nullptr) pointer->next->prev=pointer->prev;
            }
            pointer=pointer->next;
        }
    }
}

void insert1(int num) {
    if (!exists1(num)) {
        auto a = new hash_set;
        a->value = num;
        int result = hash_function(num);
        hash_set *pointer = hash_set1[result].next;
        if (pointer == nullptr) {
            hash_set1[result].next = a;
            a->prev = &hash_set1[result];
        } else {
            while (pointer->next!=nullptr) pointer=pointer->next;
            pointer->next=a;
            a->prev = pointer;
        }
    }
}

bool exists1(int num) {
    int result = hash_function(num);
    hash_set *pointer = hash_set1[result].next;
    while (pointer != nullptr) {
        if (pointer->value == num) {
            return true;
        }
        //cout<<pointer->value<<endl;
        pointer = pointer->next;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    string command;
    int num;
    while (cin>>command) {
        cin >> num;
        if (command == "insert") insert1(num);
        else if (command == "delete") delete1(num);
        else if (command == "exists") {
            if (exists1(num)) cout << "true" << endl;
            else cout << "false" << endl;
        }
    }
}