#include<iostream>
using namespace std;

int n;
int a[1000][1000];
int check[1000];
void dfs(int u){
    cout << u << " " ;
    check[u]=1;
    for(int v=1;v<=n;++v){
        if(a[u][v]&&!check[v]) dfs(v);  
    }
}
int main(){
    cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }dfs(1);
}
