#include<iostream>
#include<vector>
using namespace std ;
int u,check[1000],a[1000][1000],n;
vector<pair<int,int>> v;
void dfs(int u){
    check[u]=1;
    for(int i=1;i<=n;++i){
        if(!check[i]&&a[u][i]) {
            int x1=i;
            int x2=u;
            if(x1>x2) swap(x1,x2);
            v.push_back({x1,x2});
            dfs(i);
        }
        
    }
}
void tree_dfs(){
    dfs(u);
    if(v.size()<n-1) cout << "do thi khong lien thong";
    else {
        cout << "DFS tree" << endl;
        for(auto x : v) cout << x.first << " " << x.second << endl;
    }
}
int main(){
    cin >> n >> u;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }tree_dfs();
    
}
