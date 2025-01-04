#include<iostream>
using namespace std;
bool isPrime(int n){
    if(n < 2) return false;
    if(n %2 == 0) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    if(n%2 != 0 || n <= 6){
        cout << "ERROR" << endl;
    }
    else{
        for(int i =2; i< n/2; i++){
            if(isPrime(i) && isPrime(n - i)){
                cout << i << " " << n - i << endl;
            }
        }
    }
}