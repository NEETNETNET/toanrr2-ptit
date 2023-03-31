#include <iostream>
#include <stack> 
using namespace std ;
int n,u,a[1000][1000];
void euler(int u){
    stack<int> st,ce;
    st.push(u);
    while(!st.empty()){
        int s=st.top();
        int cnt=0;
        for(int i=1;i<=n;++i) {
            if(!a[s][i]) ++cnt;
        }if(cnt!=n){
            for(int t=1;t<=n;++t){
                if(a[s][t]==1) {
                    st.push(t);
                    a[s][t]=a[t][s]=0;
                    break;
                }
            }
        }else {
            st.pop();
            ce.push(s);
        }
    }while(!ce.empty()){
        cout << ce.top() << " ";
        ce.pop();
    }
    
}
int main (){
    cin >> n >> u;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }euler(u);
}
