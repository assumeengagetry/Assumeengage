#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = {0};
        for(int i= 0; i<s.size(); i++){
            hash[s[i]- 'a'] = i;
        }
        vector<int> result;
        int left= 0 ; 
        int right = 0;
        for(int i= 0; i< s.size(); i++){
            right = max(right, hash[s[i]- 'a']);
            if(i ==right){
                result.push_back(right - left + 1);
                left = i+1;
            }
        }
        return result;
    }
};