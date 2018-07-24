#include <iostream>
#include <algorithm>
using namespace std;

int n,num[1001],maxx[1001];
void getmax(int x);

int main(){
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>num[i];
    }
    for(int i = 1;i<=n;i++){
        getmax(i);
    }
    int* max_num = max_element(&maxx[1],&maxx[n+1]);   //得到某数组的最大元素
    cout<<*max_num;
    return 0;
}

void getmax(int x){
    if(x==1){
        maxx[1] = 1;
    }
    else{
        maxx[x] = 1;       //当时这话没加，导致WA，因为数组默认为0而不是1,因为如果前面没有，也是1
        for(int i=1;i<x;i++){
            if(num[i]<num[x]){
                maxx[x] = max(maxx[i]+1,maxx[x]);
            }
        }
    }
}


/*
 * 这道题为"人人为我"型动态规划：
 * 时间复杂度：O(n^2)
 * "人人为我"即为：以"我"(num[x])为基准去更新其他成员的值。
 * 思路：将数组截获为一个一个元素，获得数组每个元素的最优解（最大长度），取最大值即可
 */

/*
 * 改写成"我为人人"型："我"(num[i+1]~num[n])
 * 即:
 * for(int i=1;i<=n;i++){
 *    maxx[i] = 1;
 *    for(int j=i+1;j<=n;j++){   //"我"与基准（num[i]）比较，看看能更新哪些状态的值
 *        if(num[j]>num[i]){
 *            maxx[j] = max(maxx[j]+1,maxx[i]);
 *        }
 *    }
 * }
 *
 */


