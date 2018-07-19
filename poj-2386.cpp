#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
char field[101][101];

void dfs(int x,int y){
    field[x][y] = '.';
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(x+i>0 && y+j>0 && x+i<=n && y+j<=m && field[x+i][y+j]=='W'){
                dfs(x+i,y+j);
            }
        }
    }
    return;
}

int main()
{
    int sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
//            scanf("%c",&field[i][j]);
            cin>>field[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(field[i][j]=='W'){
                dfs(i,j);
                sum++;
            }
        }
    }
    cout<<sum<<endl;
//    cout<<field[1][1];
    return 0;
}
