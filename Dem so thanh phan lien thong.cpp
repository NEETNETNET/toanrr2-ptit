#include<iostream>
using namespace std ;
int n,a[1000][1000],check[1000];

void dfs(int u){
    check[u]=1;
    for(int v=1;v<=n;v++){
        if(!check[v]&&a[u][v]) dfs(v);
    }
}
int dem(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!check[i]) {
            ++cnt;
            dfs(i);
        }
    }return cnt;
}
int main() {
    cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }cout << dem() ;
}
