#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> vertexes;
vector<short> used;
vector<int> components;
vector<vector<int>> way;
int m = 0, n = 0, sx, sy, fx, fy, start_point, finish_point, constanta;

void input_data() {
    cin >> m >> n;
    vector<vector<bool>> field(m, vector<bool>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            field[i][j] = false;
    constanta = m + 1;
    vertexes.resize(constanta * constanta + constanta);
    used.resize(constanta * constanta + constanta);
    components.resize(constanta * constanta + constanta);
    way.resize(constanta * constanta * constanta);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char tmp;
            cin >> tmp;
            if ((tmp == '.') or (tmp == 'S') or (tmp == 'T')) {
                field[i][j] = true;
            }
            if (tmp == 'S') {
                sx = i;
                sy = j;
            }
            if (tmp == 'T') {
                fx = i;
                fy = j;
            }
        }
    }
//    for (int i=0; i<m; i++) {
//        for (int j = 0; j < n; j++)
//            cout << field[i][j] << ' ';
//        cout<<endl;
//    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j]) {
                if (i > 0 && field[i - 1][j]) { //верхний сосед
                    vertexes[i * (constanta) + j].push_back((i - 1) * (constanta) + j);
                }
                if (j > 0 && field[i][j - 1]) { //левый сосед
                    vertexes[i * (constanta) + j].push_back(i * (constanta) + (j - 1));
                }
                if (i < (m - 1) && field[i + 1][j]) { //нижний сосед
                    vertexes[i * (constanta) + j].push_back((i + 1) * (constanta) + j);
                }
                if (j < (n - 1) && field[i][j + 1]) { //правый сосед
                    vertexes[i * (constanta) + j].push_back(i * (constanta) + (j + 1));
                }
            }
        }
    }
//    for (int i = 0; i < vertexes.size(); i++) {
//        cout << i << " is connected with:" << ' ';
//        for (int j = 0; j < vertexes[i].size(); j++) {
//            cout << vertexes[i][j] << ' ';
//        }
//        cout << endl;
//    }
    start_point = sx * constanta + sy;
    finish_point = fx * constanta + fy;
}

void bfs_visitor(int curr_comp, int start) {
    queue<int> ochered;
    ochered.push(start);
    while (!ochered.empty()) {
        start = ochered.front();
        ochered.pop();
        for (int i = 0; i < vertexes[start].size(); i++) {
            if (used[vertexes[start][i]] == -1) {
                components[vertexes[start][i]] = components[start] + 1;
                for (int index = 0; index < way[start].size(); index++)
                    way[vertexes[start][i]].push_back(way[start][index]);
                way[vertexes[start][i]].push_back(start);
                used[vertexes[start][i]] = 0;
                ochered.push(vertexes[start][i]);
            }
        }
        used[start] = 1;
    }
}

void bfs() {
    for (int i = 0; i < used.size(); i++) {
        used[i] = -1;
        components[i] = 0;
    }
    int num_of_component = 0;
    if (used[start_point] == -1) {
        used[start_point] = 1;
        components[start_point] = num_of_component;
        bfs_visitor(num_of_component + 1, start_point);
    }
//    for (int i=0; i<n; i++){
//        if (used[i]==-1){
//            used[i]= 1;
//            components[i]=num_of_component;
//            bfs_visitor(num_of_component+1,i);
//            num_of_component++;
//        }
//    }
    if (components[finish_point] == 0)
        cout << -1;
    else {
        cout << components[finish_point] << endl;
        way[finish_point].push_back(finish_point);
        for (int i = 0; i < way[finish_point].size() - 1; i++) {
            if (way[finish_point][i] - way[finish_point][i + 1] == -1)
                cout << "R";
            if (way[finish_point][i] - way[finish_point][i + 1] == 1)
                cout << "L";
            if (way[finish_point][i] - way[finish_point][i + 1] == (m + 1))
                cout << "U";
            if (way[finish_point][i] - way[finish_point][i + 1] == -(m + 1))
                cout << "D";
        }
        cout << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input_data();
    bfs();
    return 0;
}