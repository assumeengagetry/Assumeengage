#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> que;
        for(int i= 0 ; i< people.size(); i++){
            int position = people[i][1];
            que.insert(que.begin() + position, people[i]);
        }
        return que;
    }
};