//选择排序问题
#include<iostream>
using namespace std;
int main(){
    int n,t,sum1 = 0,sum2 = 0;
    cin>>n;
    int num[n+1];
    for (int i = 1; i<=n; i++) {
        cin>>num[i];
    }
    for (int i = 1; i<=n-1; i++) {
        for (int j = i+1; j<=n; j++) {
            if (num[i]<=num[j]) {
                t = num[i];
                num[i] = num[j];
                num[j] = t;
            }
        }
    }
    for (int i = 1; i<=n; i++) {
        if (i%2==0) {
            sum2 = sum2+num[i];
        }
        if (i%2!=0) {
            sum1 = sum1+num[i];
        }
    }
    cout<<sum1-sum2<<endl;
    return 0;
}
