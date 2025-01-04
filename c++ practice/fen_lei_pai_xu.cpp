#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int n;cin>>n;cin.ignore();
    while(n--){
        string line;
        getline(cin,line);
        stringstream ss(line);
        int x;
        vector<int> jishu;
        vector<int> oushu;
        while(ss >> x){
            if(x%2==0)
                oushu.push_back(x);
            else
                jishu.push_back(x);
        }
        sort(jishu.begin(),jishu.end());
        sort(oushu.begin(),oushu.end());
        for(int i=0;i<jishu.size();i++)
            cout<<jishu[i]<<" ";
        for(int i=0;i<oushu.size();i++)
            cout<<oushu[i]<<" ";
        cout<<endl;
    }
}