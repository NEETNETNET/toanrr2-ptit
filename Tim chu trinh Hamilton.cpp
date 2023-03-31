#include<iostream>
using namespace std ;
int n,u,a[1000][1000],check[1000],X[1000];
void hmt(int k){
    for(int i=1;i<=n;++i){
        if(a[X[k-1]][i]){
            if(k==n+1&&i==u){
                for(int j=1;j<=n;++j) cout << X[j] << " ";
                cout << u << endl;
            } 
            else if(!check[i]){
                X[k]=i;
                check[i]=1;
                hmt(k+1);
                check[i]=0;
            }
        }
    }
}
int main(){
    cin >> n >> u;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }X[1]=u;
    check[u]=1;
    hmt(2);
}
