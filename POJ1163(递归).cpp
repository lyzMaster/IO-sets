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
    cout<<maxsum(1,1);
    return 0;
}

int maxsum(int x,int y){   //x:行;y:列
    if(visited[x][y]!=-1){
        return visited[x][y];
    }
    if(x==n){
        return num[x][y];
    }
    visited[x][y] = max(maxsum(x+1,y),maxsum(x+1,y+1))+num[x][y];
    return visited[x][y];
}

