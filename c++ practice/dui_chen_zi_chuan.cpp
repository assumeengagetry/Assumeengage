#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
void duichenchuxian(const string& s1, const string& s2){
    string reverse_s2 = s2;
    reverse(reverse_s2.begin(), reverse_s2.end());
    int max=0 ;
    auto zuobian = s1.find(s2);
    if(zuobian != string::npos){
        auto youbian = s1.rfind(reverse_s2);
        if(youbian != string::npos){
            max= youbian - zuobian - s2.size() ;
            cout<<max;
        }
        else{
            cout<<"no";
        }
    }
    else {
        cout<<"no";
    }
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    duichenchuxian(s1, s2);
}