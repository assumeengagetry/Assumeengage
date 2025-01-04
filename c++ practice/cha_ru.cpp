#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int main(){
    string line,target;
    getline(cin, line);
    getline(cin, target);
    string xiao_xie_line = line;
    string xiao_xie_target = target;
    transform(xiao_xie_line.begin(), xiao_xie_line.end(), xiao_xie_line.begin(), ::tolower);
    transform(xiao_xie_target.begin(), xiao_xie_target.end(), xiao_xie_target.begin(), ::tolower);
    
    int pos = 0;  // 改用 int 类型
    while((pos = xiao_xie_line.find(xiao_xie_target, pos)) != string::npos) {
        // 在原字符串中插入注释
        line.insert(pos, "/*");
        line.insert(pos + target.length() + 2, "*/");
        
        // 在小写字符串中也插入相同的标记，保持同步
        xiao_xie_line.insert(pos, "/*");
        xiao_xie_line.insert(pos + xiao_xie_target.length() + 2, "*/");
        
        // 更新位置，跳过已处理的部分
        pos += target.length() + 4;
    }
    
    cout << line << endl;
    return 0;
}