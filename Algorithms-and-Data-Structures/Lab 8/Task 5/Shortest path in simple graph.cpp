#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> vertexes;
vector<short> used;
vector<int> components;
int m=0,n=0;

void input_data(){
    cin>>n>>m;
    vertexes.resize(n);
    used.resize(n);
    components.resize(n);
    for (int i=0; i<m; i++){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        vertexes[tmp1-1].push_back(tmp2-1);
        vertexes[tmp2-1].push_back(tmp1-1);
    }
}

void bfs_visitor(int curr_comp,int start) {
    queue<int> ochered;
    ochered.push(start);
    while (!ochered.empty()) {
        start=ochered.front();
        ochered.pop();
        for (int i = 0; i < vertexes[start].size(); i++) {
            if (used[vertexes[start][i]] == -1) {
                components[vertexes[start][i]] = components[start] + 1;
                used[vertexes[start][i]] = 0;
                ochered.push(vertexes[start][i]);
            }
        }
        used[start]=1;
    }
}
void bfs(){
    for (int i=0; i<n; i++)
        used[i]=-1;
    components={0};
    int num_of_component=0;
    for (int i=0; i<n; i++){
        if (used[i]==-1){
            used[i]= 1;
            components[i]=num_of_component;
            bfs_visitor(num_of_component+1,i);
            num_of_component++;
        }
    }
    for (int i=0; i<n;i++)
        cout<<components[i]<<' ';
    cout<<endl;
}

int main(){
    freopen("pathbge1.in","r",stdin);
    freopen("pathbge1.out","w",stdout);
    input_data();
    bfs();
    return 0;
}