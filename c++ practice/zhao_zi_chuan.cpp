#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
using namespace std;
int main()
{
    string s,target;
    getline(cin,s);
    getline(cin,target);
    string s_lower=s;
    string target_lower=target;
    transform(s_lower.begin(),s_lower.end(),s_lower.begin(),::tolower);
    transform(target_lower.begin(),target_lower.end(),target_lower.begin(),::tolower);
    size_t pos=0;
    while((pos=s_lower.find(target_lower,pos)) != string::npos){
        s.insert(pos,"/*");
        s_lower.insert(pos+target.size(),"*/");
        s.insert(pos+target.size()+2,"*/");
        s_lower.insert(pos+target.size()+4,"*/");
        pos += target.size()+4;
    }
    cout<<s;
    return 0;
}
    

        