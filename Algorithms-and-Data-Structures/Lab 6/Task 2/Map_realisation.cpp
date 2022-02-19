#include <iostream>

using namespace std;

struct hash_set {
    string key;
    string value;
    hash_set *next = nullptr;
    hash_set *prev = nullptr;
} hash_set1[1000000];

struct hash_set* get1(string &key);

long long hash_function(string &key);

void put1(string &key, string &value);

bool exists1(string &key);

long long hash_function(string &key) {
    long long s = 0;
    for (long long i = 0; i < key.length(); ++i)
        s += (long long) key[i] * (i + 123);
    return s % 10000001;
}

void delete1(string &key) {
    if (exists1(key)) {
        long long result = hash_function(key);
        hash_set *pointer = hash_set1[result].next;
        while (pointer != nullptr) {
            if (pointer->key == key) {
                pointer->prev->next = pointer->next;
                if (pointer->next != nullptr) pointer->next->prev = pointer->prev;
            }
            pointer = pointer->next;
        }
    }
}

void put1(string &key, string &value) {
    if (!exists1(key)) {
        auto a = new hash_set;
        a->value = value;
        a->key = key;
        long long result = hash_function(key);
        hash_set *pointer = hash_set1[result].next;
        if (pointer == nullptr) {
            hash_set1[result].next = a;
            a->prev = &hash_set1[result];
        } else {
            while (pointer->next != nullptr) pointer = pointer->next;
            pointer->next = a;
            a->prev = pointer;
        }
    }
    else get1(key)->value=value;
}

bool exists1(string &key) {
    long long result = hash_function(key);
    hash_set *pointer = hash_set1[result].next;
    while (pointer != nullptr) {
        if (pointer->key == key) {
            return true;
        }
        pointer = pointer->next;
    }
    return false;
}

struct hash_set* get1(string &key) {
    if (exists1(key)) {
        long long result = hash_function(key);
        hash_set *pointer = hash_set1[result].next;
        while (pointer != nullptr) {
            if (pointer->key == key) {
                return pointer;
            }
            pointer = pointer->next;
        }
    }
    return nullptr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    string command, key, value;
    while (cin >> command) {
        cin >> key;
        if (command == "put") {
            cin >> value;
            put1(key, value);
        } else if (command == "delete") delete1(key);
        else if (command == "get") {
            if (get1(key)!=nullptr) cout<<get1(key)->value<<endl;
            else cout<<"none"<<endl;
        }
    }
}