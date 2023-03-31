#include<iostream>
#include<queue>
using namespace std;

int n,a[1001][1001],check[1001];
void bfs(int u){
    cout << u << " ";
    check[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(int v=1;v<=n;++v){
            if(a[s][v]&&!check[v]){
                cout << v << " ";
                q.push(v);
                check[v]=1;
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }bfs(1);
}
