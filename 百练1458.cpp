#include <iostream>
#include <algorithm>
using namespace std;

string s1,s2;

int main(){
    while(cin>>s1>>s2){
        int s1_length = s1.length();
        int s2_length = s2.length();

        int max_len[s1.length()+1][s2_length+1];
        s1 = ' '+s1;
        s2 = ' '+s2;

        for(int i=0;i<=s1_length;i++){
            max_len[i][0] = 0;
        }
        for(int i=0;i<=s2_length;i++){
            max_len[0][i] = 0;
        }

        for(int i=1;i<=s1_length;i++){
            for(int j=1;j<=s2_length;j++){
                if(s1[i]==s2[j]){
                    max_len[i][j] = max_len[i-1][j-1]+1;
                }
                else{
                    max_len[i][j] = max(max_len[i-1][j],max_len[i][j-1]);
                }
            }
        }
        cout<<max_len[s1_length][s2_length]<<endl;
    }
    return 0;
}

