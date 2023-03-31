#include<iostream> 
#include<queue>
using namespace std ;
int check1[1000],a[1000][1000],n,s,t,check2[1000],truoc1[1000],truoc2[1000],ok;
void dfs(int u){
    check1[u]=1;
    for(int v=1;v<=n;++v){
        if(a[u][v]&&!check1[v]) {
            truoc1[v]=u;
            dfs(v);
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
                truoc2[i]=s;
                q.push(i);
                check2[i]=1;
            } 
        }
    }
}
void trace1(int s,int t){
    if(!truoc1[t]) {
        ok=0;
        cout << "no path";
    }
    else {
        cout << "DFS path: ";
        cout << t << " ";
        int v=truoc1[t];
        while(v!=s){
            cout << v << " ";
            v=truoc1[v];
        }cout << s << endl;
    }
}
void trace2(int s,int t){
    if(truoc2[t]&&ok) {
        cout << "BFS path: ";
        cout << t << " ";
        int v=truoc2[t];
        while(v!=s){
            cout << v << " ";
            v=truoc2[v];
        }cout << s << endl;
    }
}
int main(){
    cin >> n >> s >> t;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }ok=1;
    dfs(s);
    bfs(s);
    trace1(s,t);
    trace2(s,t);
}
