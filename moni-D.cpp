#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string str;
    cin>>str;
    int sum=0,longer=str.size();
    bool flag1=false,flag2=false;
    for(int i=0;i<str.size();i++){
        if (i==0) {
            if(int(str[i])==45){
                longer--;
                flag1 = true;
                continue;
            }
        }
        if(int(str[i])-48==2){
            sum++;
        }
        if((int(str[str.size()-1])-48)%2==0||int(str[str.size()-1])-48==0){
            flag2 = true;
        }
    }
    if(flag1&&flag2){
        cout<<setiosflags(ios::fixed)<<setprecision(2);
        cout<<1.0*sum/longer*1.5*2*100<<"%";
    }
    if(flag1&&flag2==false){
        cout<<setiosflags(ios::fixed)<<setprecision(2);

        cout<<1.0*sum/longer*1.5*100<<"%";
    }
    if(flag2&&flag1==false){
        cout<<setiosflags(ios::fixed)<<setprecision(2);
        cout<<1.0*sum/longer*2*100<<"%";
    }
    
    return 0;
}
