#include <iostream>
#include <vector>
using namespace std;

int value, n1, n2, n, a, b, x, y, z, w, c, num, num1;

vector<pair<int, pair <int, int>>> nodes;
vector<pair<int, pair <int, int>>> pr_nodes;
vector<int> ans, h;
int height(int k, int d) {
    if (nodes[k].second.first != -1) {
        if (nodes[k].second.second != - 1) {
            int l1 = height(nodes[k].second.second, d + 1);
            int r1 = height( nodes[k].second.first, d + 1);
            int ans1 = l1- r1;
            ans[k] = ans1;
            return max(r1, l1);
        } else {
            ans[k] = - height( nodes[k].second.first, d + 1) + d;
            return -ans[k] + d;
        }
    } else {
        if (nodes[k].second.second != -1) {
            ans[k] =  height(nodes[k].second.second, d + 1) - d;
            return ans[k] + d;
        } else {
            ans[k] = 0;
            return d;
        }
    }
}
int height(int s) {
    if (nodes[s].second.second != -1) {
        if (nodes[s].second.first != -1) {
            int k1 = height(nodes[s].second.first);
            int k2 = height(nodes[s].second.second);
            h[s] = max(k1, k2) + 1;
            return max(k1, k2) + 1;
        } else {
            int k1 = height(nodes[s].second.second);
            h[s] = k1 + 1;
            return k1 + 1;
        }
    } else {
        if (nodes[s].second.first != -1) {
            int k1 = height(nodes[s].second.first);
            h[s] = k1 + 1;
            return k1 + 1;
        }
    }
    h[s] = 1;
    return 1;
}

int real_height(int v) {
    if (v == -1) {
        return 0;
    } else {
        return h[v];
    }
}
int print_nodes(int s, int numbcout) {
    if (nodes[s].second.first != -1) {
        pr_nodes.push_back({nodes[s].first, {numbcout + 1, -1}});
        int next_line = print_nodes(nodes[s].second.first, numbcout + 1);
        if (nodes[s].second.second != -1) {
            pr_nodes[numbcout].second.second = next_line + 1;
            return print_nodes(nodes[s].second.second, next_line + 1);
        } else {
            return next_line;
        }
    } else {
        if (nodes[s].second.second != -1) {
            pr_nodes.push_back({nodes[s].first, {-1, numbcout + 1}});
            return print_nodes(nodes[s].second.second, numbcout + 1);
        } else {
            pr_nodes.push_back({nodes[s].first, {-1, -1}});
            return numbcout;
        }
    }

}

int big_left_rotation(int root) {
    a = root;
    b = nodes[root].second.second;
    w = nodes[root].second.first;
    c = nodes[b].second.first;
    z = nodes[b].second.second;
    x = nodes[c].second.first;
    y = nodes[c].second.second;
    pair<int, pair<int, int>> new_a = {nodes[a].first, {w, x}};
    pair<int, pair<int, int>> new_b = {nodes[b].first, {y, z}};
    pair<int, pair<int, int>> new_c = {nodes[c].first, {a, b}};
    nodes[a] = new_a;
    nodes[b] = new_b;
    nodes[c] = new_c;
    h[a] = max(real_height(w), real_height(x)) + 1;
    h[b] = max(real_height(y), real_height(z)) + 1;
    h[c] = max(real_height(a), real_height(b)) + 1;
    return c;
}
int big_right_rotation(int root) {
    a = root;
    b = nodes[root].second.first;
    w = nodes[root].second.second;
    c = nodes[b].second.second;
    z = nodes[b].second.first;
    x = nodes[c].second.first;
    y = nodes[c].second.second;
    pair<int, pair<int, int>> new_a = {nodes[a].first, {y, w}};
    pair<int, pair<int, int>> new_b = {nodes[b].first, {z, x}};
    pair<int, pair<int, int>> new_c = {nodes[c].first, {b, a}};
    nodes[a] = new_a;
    nodes[b] = new_b;
    nodes[c] = new_c;
    h[b] = max(real_height(z), real_height(x)) + 1;
    h[a] = max(real_height(y), real_height(w)) + 1;
    h[c] = max(real_height(a), real_height(b)) + 1;
    return c;
}

int small_left_rotation(int root) {
    a = root;
    b = nodes[root].second.second;
    x = nodes[root].second.first;
    y = nodes[b].second.first;
    z = nodes[b].second.second;
    pair<int, pair<int, int>> new_a = {nodes[a].first, {x, y}};
    pair<int, pair<int, int>> new_b = {nodes[b].first, {root, z}};
    nodes[a] = new_a;
    nodes[b] = new_b;

    h[a] = max(real_height(x), real_height(y)) + 1;
    h[b] = max(real_height(a), real_height(z)) + 1;
    return b;
}
int small_right_rotation(int root) {
    b = root;
    a = nodes[root].second.first;
    x = nodes[a].second.first;
    y = nodes[a].second.second;
    z = nodes[root].second.second;
    pair<int, pair<int, int>> new_b = {nodes[b].first, {y, z}};
    pair<int, pair<int, int>> new_a = {nodes[a].first, {x, b}};
    nodes[a] = new_a;
    nodes[b] = new_b;
    h[b] = max(real_height(y), real_height(z)) + 1;

    h[a] = max(real_height(x), real_height(b)) + 1;
    return a;
}

int insert(int root, int kek) {
    a = root;
    if (kek < nodes[a].first) {
        a = nodes[a].second.first;
        if (a != -1) {
            num1 = insert(a, kek);
            nodes[root].second.first = num1;
            h[root] = max(real_height(nodes[root].second.second), real_height(nodes[root].second.first)) + 1;
            ans[root] = real_height(nodes[root].second.second) - real_height(nodes[root].second.first);
            if (ans[root] == 2) {
                if (ans[nodes[root].second.second] == -1) {
                    return big_left_rotation(root);
                } else {
                    return small_left_rotation(root);
                }
            }
            if (ans[root] == -2) {
                if (ans[nodes[root].second.first] == 1) {
                    return big_right_rotation(root);
                } else {
                    return small_right_rotation(root);
                }
            }
            return root;
        } else {
            nodes.push_back({num, {-1, -1}});
            nodes[root].second.first = nodes.size() - 1;
            h[root] = max(real_height(nodes[root].second.second), real_height(nodes[root].second.first)) + 1;
            ans[root] = real_height(nodes[root].second.second) - real_height(nodes[root].second.first);
            return root;
        }
    } else {
        if (kek > nodes[a].first) {
            a = nodes[a].second.second;
            if (a != -1) {
                num1 = insert(a, kek);
                nodes[root].second.second = num1;
                h[root] = max(real_height(nodes[root].second.second), real_height(nodes[root].second.first)) + 1;
                ans[root] = real_height(nodes[root].second.second) - real_height(nodes[root].second.first);
                if (ans[root] == 2) {
                    if (ans[nodes[root].second.second] == -1) {
                        return big_left_rotation(root);
                    } else {
                        return small_left_rotation(root);
                    }
                }
                if (ans[root] == -2) {
                    if (ans[nodes[root].second.second] == 1) {
                        return big_right_rotation(root);
                    } else {
                        return small_right_rotation(root);
                    }
                }
                return root;
            } else {
                nodes.push_back({num, {-1, -1}});
                nodes[root].second.second = nodes.size() - 1;
                h[root] = max(real_height(nodes[root].second.second), real_height(nodes[root].second.first)) + 1;
                ans[root] = real_height(nodes[root].second.second) - real_height(nodes[root].second.first);
                return root;
            }
        }
    }
}
int main() {
    freopen("addition.in", "r", stdin);
    freopen("addition.out", "w", stdout);
    cin >> n;
    ans.resize(n);
    h.resize(n + 1);
    h[n] = 1;
    if (n == 0) {
        cout << 1 << endl;
    } else {
        cout << n + 1 << endl;
        for (int i = 0; i < n; ++i) {
            cin >> value;
            cin >> n1;
            cin >> n2;
            nodes.push_back({value, {n1 - 1, n2 - 1}});
        }
        height(0, 0);
        height(0);
    }
    cin >> num;
    if (n == 0) {
        cout << num << " " << 0 << " " << 0;
    } else {
        num1 = insert(0, num);
        print_nodes(num1, 0);
        for (auto & i : pr_nodes) {
            cout << i.first << " " << i.second.first + 1 << " "<< i.second.second + 1 << endl;
        }
    }

    return 0;
}