#include<iostream> 
#include<vector> 
#include<stack> 
#include<queue> 
using namespace std;
int check1[1000],check2[1000],n,u,a[1000][1000];
vector<pair<int,int>> vp1,vp2;
void dfs(int u){
    stack<int> st;
    st.push(u);
    check1[u]=1;
    while(!st.empty()){
        int s=st.top();
        st.pop();
        for(int i=1;i<=n;++i){
            if(a[s][i]&&!check1[i]){
                int x1=s;
                int x2=i;
                if(x1>x2) swap(x1,x2);
                vp1.push_back({x1,x2});
                check1[i]=1;
                st.push(s);
                st.push(i);
                break;
            }
        }
    }
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    check2[u]=1;
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(int i=1;i<=n;++i){
            if(a[s][i]&&!check2[i]){
                int x1=s,x2=i;
                if(x1>x2) swap(x1,x2);
                vp2.push_back({x1,x2});
                q.push(i);
                check2[i]=1;
            }
        }
    }
}
void tree_DFS(){
    dfs(u);
    if(vp1.size()<n-1) cout << "do thi khong lien thong" ;
    else {
        cout << "DFS tree" << endl;
        for(auto x : vp1 ) cout << x.first << " " << x.second << endl;
    }
}
void tree_BFS(){
    bfs(u);
    if(vp2.size()<n-1) cout << "do thi khong lien thong";
    else {
        cout << "BFS tree" << endl;
        for(auto x : vp2 ) cout << x.first << " " << x.second << endl;
    }
}
int main(){
    cin >> n >> u;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }tree_DFS();
    tree_BFS();
}
