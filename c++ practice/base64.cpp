//先把读入一个字符串，之后是将他们
//转化成数组
//切分
//化成十进制数
//根据字典查值
//补齐到长度为4的整数倍 


#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string shu_ru;
    getline(cin, shu_ru);
    vector<int> zhuan_hua_cheng_ascma;
    vector<int> zhuan_hua_cheng_er_jin_zhi_shu;
    vector<int> zhuan_hua_cheng_de_shi_jin_zhi;
    vector<char> cha_xun_hou_de_zi_fu;
    vector<char> zi_dian = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K','L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3','4', '5', '6', '7', '8', '9', '+', '/'};

    for(char c : shu_ru){
        zhuan_hua_cheng_ascma.push_back(static_cast<int>(c));
    }
    for(int i = 0; i < zhuan_hua_cheng_ascma.size(); i++){
        int tep = zhuan_hua_cheng_ascma[i];
        vector<int> er_jin_zhi(8, 0);
        for(int j = 7; j >= 0; j--){
            er_jin_zhi[j] = tep % 2;
            tep /= 2;
        }
        for(int m = 0; m < 8; m++){
            zhuan_hua_cheng_er_jin_zhi_shu.push_back(er_jin_zhi[m]);
        }
    }
    for(int i = 0; i < zhuan_hua_cheng_er_jin_zhi_shu.size(); i+=6){
        int shi_jin_zhi = 0;
        for(int j = 0; j < 6; j++){
            if(i + j < zhuan_hua_cheng_er_jin_zhi_shu.size()){
                shi_jin_zhi = (shi_jin_zhi << 1) | zhuan_hua_cheng_er_jin_zhi_shu[i + j];
            } else {
                shi_jin_zhi = shi_jin_zhi << 1;
            }
        }
        zhuan_hua_cheng_de_shi_jin_zhi.push_back(shi_jin_zhi);
    }

    // 解释：
    // 这行代码的作用是将二进制数转换为十进制数。
    // 具体来说，它将当前的十进制数左移一位（相当于乘以2），然后将当前位的二进制数加到最低位。
    // 例如：
    // 如果 shi_jin_zhi 是 3（二进制 11），zhuan_hua_cheng_er_jin_zhi_shu[i + j] 是 1，
    // 那么 (shi_jin_zhi << 1) 是 6（二进制 110），然后 | 1 结果是 7（二进制 111）。

    // 示例 1:
    // 初始值：shi_jin_zhi = 0
    // 二进制序列：1 0 1 1
    // 过程：
    // 第1步：shi_jin_zhi = (0 << 1) | 1 = 1
    // 第2步：shi_jin_zhi = (1 << 1) | 0 = 2
    // 第3步：shi_jin_zhi = (2 << 1) | 1 = 5
    // 第4步：shi_jin_zhi = (5 << 1) | 1 = 11
    // 最终结果：shi_jin_zhi = 11

    // 示例 2:
    // 初始值：shi_jin_zhi = 0
    // 二进制序列：0 1 1 0
    // 过程：
    // 第1步：shi_jin_zhi = (0 << 1) | 0 = 0
    // 第2步：shi_jin_zhi = (0 << 1) | 1 = 1
    // 第3步：shi_jin_zhi = (1 << 1) | 1 = 3
    // 第4步：shi_jin_zhi = (3 << 1) | 0 = 6
    // 最终结果：shi_jin_zhi = 6

    // 示例 3:
    // 初始值：shi_jin_zhi = 0
    // 二进制序列：1 1 0 0
    // 过程：
    // 第1步：shi_jin_zhi = (0 << 1) | 1 = 1
    // 第2步：shi_jin_zhi = (1 << 1) | 1 = 3
    // 第3步：shi_jin_zhi = (3 << 1) | 0 = 6
    // 第4步：shi_jin_zhi = (6 << 1) | 0 = 12
    // 最终结果：shi_jin_zhi = 12

    for(int i = 0; i < zhuan_hua_cheng_de_shi_jin_zhi.size(); i++){
        cha_xun_hou_de_zi_fu.push_back(zi_dian[zhuan_hua_cheng_de_shi_jin_zhi[i]]);
    }
    if(cha_xun_hou_de_zi_fu.size() % 4 != 0){
        int bu_wei = 4 - cha_xun_hou_de_zi_fu.size() % 4;
        for(int i = 0; i < bu_wei; i++){
            cha_xun_hou_de_zi_fu.push_back('=');
        }
    }
    for(int i = 0; i < cha_xun_hou_de_zi_fu.size(); i++){
        cout << cha_xun_hou_de_zi_fu[i];
    }
    return 0;
}