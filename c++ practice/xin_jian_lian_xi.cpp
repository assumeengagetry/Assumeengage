#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int L, zhi_shu_shu = 0, sum = 0;
    cin >> L;
    for(int i = 2; ; i++){
        bool isPrime = true;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            sum += i;
            zhi_shu_shu++;
        }
        if(sum > L){
            cout << zhi_shu_shu - 1 << endl;
            break;
        } else if(sum == L){
            cout << zhi_shu_shu << endl;
            break;
        }
    }
    return 0;
}