#include <iostream>
#include <algorithm>
using namespace std;

int num[101][101],*maxsum;
int n;

int main(){
    cin>>n;
    for (int i = 1; i <= n; i++) {
        for(int j=1;j<=i;j++){
            cin>>num[i][j];
        }
    }
    maxsum = num[n];   //将num数组的第n行赋值给maxsum；
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            maxsum[j] = max(maxsum[j],maxsum[j+1])+num[i][j];
        }
    }
    cout<<maxsum[1];

    return 0;
}
