#include<iostream>
#include<stack>
using namespace std;

int n,a[1000][1000],check[1000];
void dfs(int u){
    stack<int> s;
    cout << u << " ";
    check[u]=1;
    s.push(u);
    while(!s.empty()){
        int v=s.top();
        s.pop();
        for(int i=1;i<=n;++i){
            if(!check[i]&&a[v][i]){
                cout << i << " ";
                s.push(v);
                s.push(i);
                check[i]=1;
                break;
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }dfs(1);
}
