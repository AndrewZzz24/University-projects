#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> vertexes;
vector<bool> used;
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

void bfs_visitor(int curr_comp,int start){
    for (int i=0; i<vertexes[start].size();i++){
        if (!used[vertexes[start][i]]){
            used[vertexes[start][i]]=true;
            components[vertexes[start][i]]=curr_comp;
            bfs_visitor(curr_comp,vertexes[start][i]);
        }
    }
}

void bfs(){
    used={false};
    components={0};
    int num_of_component=1;
    for (int i=0; i<n; i++){
        if (!used[i]){
            used[i]= true;
            components[i]=num_of_component;
            bfs_visitor(num_of_component,i);
            num_of_component++;
        }
    }
    cout<<num_of_component-1<<endl;
    for (int i=0; i<n;i++)
        cout<<components[i]<<' ';
    cout<<endl;
}

int main(){
    //freopen("components.in","r",stdin);
    //freopen("components.out","w",stdout);
    input_data();
    bfs();
    return 0;
}