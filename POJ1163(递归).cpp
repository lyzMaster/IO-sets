#include <iostream>
#include <algorithm>
using namespace std;

int num[101][101];
int n;
int maxsum(int x,int y);
int visited[101][101];

int main(){
    cin>>n;
    for (int i = 1; i <= n; i++) {
        for(int j=1;j<=i;j++){
            cin>>num[i][j];
            visited[i][j] = -1;
        }
    }
    for(int i=1;i<=n;i++){
        visited[n][i] = num[n][i];
    }
    cout<<maxsum(1,1);
    return 0;
}

int maxsum(int x,int y){   //x:hang;y:lie
    if(x==n){
        return num[x][y];
    }
    if(visited[x][y]!=-1){
        return visited[x][y];
    }
    visited[x][y] = max(maxsum(x+1,y),maxsum(x+1,y+1))+num[x][y];
    return visited[x][y];
}

