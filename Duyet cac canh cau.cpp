#include<iostream>
#include<stack>
using namespace std ;
int a[1000][1000],check[1000],n;
void dfs(int u){
    stack<int> st;
    st.push(u);
    check[u]=1;
    while(!st.empty()){
        int s=st.top();
        st.pop();
        for(int v=1;v<=n;++v){
            if(a[s][v]&&!check[v]){
                check[v]=1;
                st.push(s);
                st.push(v);
                break;
            }
        }
    }
}
void re_init(){
    for(int i=1;i<=n;++i) check[i]=0;
}
int dem(){
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(!check[i]){
            ++cnt;
            dfs(i);
        }
    }return cnt;
}
void cau(){
    int tplt = dem();
    re_init();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) {
            if(a[i][j]==1) {
                a[i][j]=a[j][i]=0;
                int ans=dem();
                re_init();
                if(ans > tplt && i < j) cout << i << " " << j << endl; 
                a[i][j]=a[j][i]=1;
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }cau();
}
