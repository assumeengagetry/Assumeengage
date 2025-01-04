#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

bool isValidChar(char c) {
    return (c >= 'a' && c <= 'z') || 
           (c >= 'A' && c <= 'Z') || 
           (c >= '0' && c <= '9') || 
           c == '_' || c == '-';
}

int main(){
    string email;
    cin >> email;
    
    // 检查@数量和位置
    int atPos = email.find('@');
    if (atPos == string::npos || atPos == 0 || atPos == email.length()-1 || 
        email.find('@', atPos+1) != string::npos) {
        cout << "no" << endl;
        return 0;
    }
    
    // 检查.数量和位置
    int dotPos = email.find('.');
    if (dotPos == string::npos || dotPos == email.length()-1 || 
        email.find('.', dotPos+1) != string::npos || 
        dotPos == atPos+1) {
        cout << "no" << endl;
        return 0;
    }
    
    // 检查所有字符是否合法
    for (char c : email) {
        if (c != '@' && c != '.' && !isValidChar(c)) {
            cout << "no" << endl;
            return 0;
        }
    }
    
    cout << "yes" << endl;
    return 0;
}
