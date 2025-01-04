#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string word;
    bool first = true;

    while (ss >> word) {
        if (!first) cout << " ";
        first = false;

        // 查找标点符号
        size_t pos = word.find_first_of(".,!?");
        if (pos != string::npos) {
            // 提取单词部分和标点符号部分
            string wordPart = word.substr(0, pos); // 从位置 0 到 pos 之前的子字符串
            string punctPart = word.substr(pos);   // 从位置 pos 到字符串末尾的子字符串
            reverse(wordPart.begin(), wordPart.end());
            cout << wordPart << punctPart;
        } else {
            reverse(word.begin(), word.end());
            cout << word;
        }
    }
    cout << endl; // 确保输出换行
    return 0;
}