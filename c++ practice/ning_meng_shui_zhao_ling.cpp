#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0 , twenty = 0; 
        for(int bill : bills){
            if(bill == 5) five++;
            if(bill == 10){
                if(five <= 0) return false;
                ten++;
                five--;
            }
            if(bill == 20){
                if(five > 0 && ten > 0){
                    five--;
                    ten--;
                    twenty++;
                }else if(five >= 3){
                    five -= 3;
                    twenty++;
                }else return false;
            }
    
        }
        return true;
    }

    
};