#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void power_representation(int n){
    vector<int> powers;
    int a=n;
    for(int i = 0 ;n > 0 ; i++ ){
        if(n & 1){
            powers.push_back(i);
        }
        n >>= 1;
    }
    cout<< a << "=";
    for(int i = powers.size() - 1; i >= 0 ; i --){
        cout<< "2^"<<powers[i];
        if(i> 0){
            cout<<"+";
        }
    }
}
int main()
{
   int n;cin>> n;
 power_representation(n);
}