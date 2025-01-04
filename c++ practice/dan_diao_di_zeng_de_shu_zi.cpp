#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
private:
    bool checkNUM(int num){
        int max = 10;
        while(num){
            if(num % 10 > max) return false;
            max = num % 10;
            num /= 10;
        }
        return true;
    }
public:
    int monotoneIncreasingDigits(int n) {
        for(int i = n; i > 0; i--){
            if(checkNUM(i)) return i;
        }
    }
};