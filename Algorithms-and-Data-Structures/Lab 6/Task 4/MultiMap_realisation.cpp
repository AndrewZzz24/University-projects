#include <iostream>
#include <list>

using namespace std;

struct hash_set {
    string key;
    //string value;
    hash_set *next = nullptr;
    hash_set *prev = nullptr;
    list<string> map_set;
} hash_set1[1000000];

bool exists_value(string &key, string &value);

struct hash_set *get1(string &key);

long long hash_function(string &key);

void put1(string &key, string &value);

bool exists_key(string &key);

long long hash_function(string &key) {
    long long s = 0;
    for (long long i = 0; i < key.length(); ++i)
        s += (long long) key[i] * (i + 123);
    return s % 10000001;
}

void delete_key(string &key) {
    if (exists_key(key)) {
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

void delete_value(string &key, string &value) {
    if (exists_key(key)) {
        long long result = hash_function(key);
        hash_set *pointer = hash_set1[result].next;
        auto it = pointer->map_set.begin();
        while (pointer != nullptr) {
            if (pointer->key == key) {
                for (it = pointer->map_set.begin(); it != pointer->map_set.end(); ++it) {
                    if (*it == value) {
                        pointer->map_set.erase(it);
                        break;
                    }
                }
            }
            pointer = pointer->next;
        }
    }
}

void put1(string &key, string &value) {
    if (!exists_key(key)) {
        auto a = new hash_set;
        a->map_set.push_back(value);
        //a->value = value;
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
    } else if (exists_key(key) && !exists_value(key, value)) {
        get1(key)->map_set.push_back(value);
    }
}

bool exists_key(string &key) {
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

bool exists_value(string &key, string &value) {
    long long result = hash_function(key);
    hash_set *pointer = hash_set1[result].next;
    while (pointer != nullptr) {
        if (pointer->key == key) {
            for (auto &iter : pointer->map_set) {
                if (iter == value) return true;
            }
        }
        pointer = pointer->next;
    }
    return false;
}

struct hash_set *get1(string &key) {
    if (exists_key(key)) {
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
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);
    string command, key, value;
    while (cin >> command) {
        cin >> key;
        if (command == "put") {
            cin >> value;
            put1(key, value);
        } else if (command == "delete") {
            cin >> value;
            delete_value(key, value);
        } else if (command == "deleteall") delete_key(key);
        else if (command == "get") {
            hash_set *pointer = get1(key);
            int sum = 0;
            if (pointer != nullptr) {
                auto it1 = pointer->map_set.begin();
                for (it1 = pointer->map_set.begin(); it1 != pointer->map_set.end(); ++it1) sum++;
            }
            cout << sum << ' ';
            if (sum != 0) {
                auto it1 = pointer->map_set.begin();
                for (it1 = pointer->map_set.begin(); it1 != pointer->map_set.end(); ++it1) cout << *it1 << ' ';
            }
            cout << endl;
        }
    }
}