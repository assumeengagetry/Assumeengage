#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool isjizhishu(int num){
    if(num <= 1){
        return false;
    }
    if(num %2 == 0){
        return false;
    }
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    if(n<= 6 || n %2 != 0){
        cout<<"ERROR";
    }
    else{
        for(int i = 2; i <= n/2; i++){
            if(isjizhishu(i) && isjizhishu(n-i)){
                cout<< i << " "<< n-i << endl;
            }
        }

    }
}