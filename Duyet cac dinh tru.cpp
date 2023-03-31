#include<iostream>
#include<stack>
using namespace std;
int a[1000][1000],n,check[1000];
void dfs(int u){
    stack<int> st;
    st.push(u);
    check[u]=1;
    while(!st.empty()){
        int s=st.top();
        st.pop();
        for(int v=1;v<=n;++v){
            if(a[s][v]&&!check[v]){
                st.push(s);
                st.push(v);
                check[v]=1;
                break;
            }
        }
    }
}
void re_init(){
    for(int i=1;i<=n;++i) check[i]=0;
}
int dem(){
    int count =0;
    for(int i=1;i<=n;++i){
        if(!check[i]){
            ++count;
            dfs(i);
        }
    }return count;
}


void tru(){
    int tplt=dem();
    re_init();
    for(int u=1;u<=n;++u){
        check[u]=1;
        int ans = dem();
        if(ans > tplt ) cout << u << " ";
        re_init();
    }
}
int main(){
    cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }tru();
}
