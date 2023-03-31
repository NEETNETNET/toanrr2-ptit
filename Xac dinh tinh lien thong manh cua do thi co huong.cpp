#include<iostream>
#include<stack>
using namespace std;
int a[1000][1000],check[1000],n;
int dfs(int u){
    stack<int> st;
    int cnt=1;
    st.push(u);
    check[u]=1;
    while(!st.empty()){
        int s=st.top();
        st.pop();
        for(int v=1;v<=n;++v){
          if(a[s][v]&&!check[v]){
            ++cnt;
            st.push(s);
            st.push(v);
            check[v]=1;
            break;
            }
        }  
    }
    return cnt;
}
void re_init(){
    for(int i=1;i<=n;++i) check[i]=0;
}
bool ltm(){
    for(int i=1;i<=n;++i){
        if(dfs(i)!=n) return false;
        else re_init();
    }return true;
}
int main(){
    cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }if(ltm()) cout << "strongly connected"; 
    else cout << "not strongly connected";
}
