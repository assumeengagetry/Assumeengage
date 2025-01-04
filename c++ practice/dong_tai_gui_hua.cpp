#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> v( n + 1 , 0);
    v[2] = 1;
    for(int i = 3; i <=n ;i ++){
        for(int j =1; j < i -1  ; j ++){
            v[i] = max (v[i], max(j * (i - j), j * v[i - j]));
        }
    }
    cout<<v[n];
}