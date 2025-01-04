#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> fen_zi, fen_mu;
    
    // 读取分数
    for(int i = 0; i < n; i++){
        int a, b;
        char slash;
        cin >> a >> slash >> b;
        if(b == 0){
            cout << "error" << endl;
            return 0;
        }
        fen_zi.push_back(a);
        fen_mu.push_back(b);
    }
    
    // 通分计算
    int fen_mu_sum = 1;
    for(int i = 0; i < n; i++){
        fen_mu_sum *= fen_mu[i];
    }
    
    int fen_zi_sum = 0;
    for(int i = 0; i < n; i++){
        fen_zi_sum += fen_zi[i] * (fen_mu_sum/fen_mu[i]);
    }
    
    // 结果化简
    int zui_da_gong_yin_shi = __gcd(abs(fen_zi_sum), fen_mu_sum);
    
    // 输出处理
    if(fen_zi_sum == 0){
        cout << 0 << endl;
    }
    else if(fen_zi_sum % fen_mu_sum == 0){
        cout << fen_zi_sum/fen_mu_sum << endl;
    }
    else{
        cout << fen_zi_sum/zui_da_gong_yin_shi << "/" 
             << fen_mu_sum/zui_da_gong_yin_shi << endl;
    }
    
    return 0;
}