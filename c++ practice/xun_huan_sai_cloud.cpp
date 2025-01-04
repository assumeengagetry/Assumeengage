#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Team {
    string name;
    int points = 0;     
    int netScore = 0;   
    
    // 常规写法
    Team(string n) {
        name = n;
    }
    
    // 或者更简单的写法
    /*
    Team() {
        name = "";
    }
    */
};

// 按积分、净胜分、队名字典序排序
// sort函数对teams向量进行排序
// 第三个参数是一个lambda表达式，用于定义排序规则
// [](const Team& a, const Team& b) 是lambda表达式的定义
// lambda表达式比较两个Team对象a和b
// 根据积分、净胜分和队名字典序进行排序
// lambda表达式是一种匿名函数，可以在代码中定义并立即使用
// 语法：[捕获列表](参数列表) -> 返回类型 { 函数体 }
// 捕获列表：定义lambda表达式可以访问的外部变量
// 参数列表：定义传递给lambda表达式的参数
// 返回类型：定义lambda表达式的返回类型（可以省略，编译器会自动推断）
// 函数体：定义lambda表达式的具体实现
sort(teams.begin(), teams.end(), [](const Team& a, const Team& b) {
    if (a.points != b.points) return a.points > b.points;        // 积分高者优先
    if (a.netScore != b.netScore) return a.netScore > b.netScore;  // 净胜分高者优先
    return a.name < b.name;  // 字典序小者优先
});
/*
 * 循环赛排名问题
 * - n支队伍两两比赛，共n*(n-1)/2场
 * - 积分规则：胜3分，平1分，负0分
 * - 排名规则：积分高优先，净胜分次之，字典序最后
 * - 相同名次跳过对应数量排名
 * - 前n/2名次的队伍获奖
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

// 队伍结构：记录队伍比赛数据
struct Team {
    string name;
    int points = 0;     
    int netScore = 0;   
    Team(string n = "") : name(n) {}
};

int main() {
    int n;  // 队伍数量(2≤n≤1000, n是偶数)
    cin >> n;
    cin.ignore();
    
    // 初始化队伍信息和名称索引
    vector<Team> teams(n);
    map<string, int> idx;  // 队名到数组下标的映射
    for (int i = 0; i < n; i++) {
        getline(cin, teams[i].name);
        idx[teams[i].name] = i;
    }
    
    // 处理所有比赛结果：共n*(n-1)/2场比赛
    for (int i = 0; i < n * (n-1) / 2; i++) {
        string line, t1, t2;
        int s1, s2;
        getline(cin, line);
        
        // 解析比赛记录格式：team1-team2: score1-score2
        // 注意：队名和分数间的分隔符前后可能有空格
        size_t p = line.find('-'), q = line.find(':');
        t1 = line.substr(0, p);//注意这个是从0开始，截取p长度的字符串
        t2 = line.substr(p + 1, q - p - 1);//这个是从p+1开始，截取q - p - 1的长度的字符串
        // 去除队名前后空格
        t1.erase(0, t1.find_first_not_of(" "));
        t1.erase(t1.find_last_not_of(" ") + 1);
        t2.erase(0, t2.find_first_not_of(" "));
        t2.erase(t2.find_last_not_of(" ") + 1);
        // 解析比分
        // sscanf函数从字符串中读取格式化数据
        // line.substr(q + 1).c_str() 获取比分部分的子字符串并转换为C风格字符串
        // "%d-%d" 表示读取两个整数，中间用'-'分隔
        // &s1, &s2 分别存储读取到的两个整数
        sscanf(line.substr(q + 1).c_str(), "%d-%d", &s1, &s2);
        
        // 更新队伍积分和净胜分
        teams[idx[t1]].netScore += s1 - s2;  // 净胜分 = 得分 - 失分
        teams[idx[t2]].netScore += s2 - s1;
        // 根据比赛结果更新积分
        if (s1 > s2) teams[idx[t1]].points += 3;      // 胜方得3分
        else if (s1 < s2) teams[idx[t2]].points += 3;  // 胜方得3分
        else teams[idx[t1]].points++, teams[idx[t2]].points++;  // 平局各得1分
    }
    
    // 按积分、净胜分、队名字典序排序
    sort(teams.begin(), teams.end(), [](const Team& a, const Team& b) {
        if (a.points != b.points) return a.points > b.points;        // 积分高者优先
        if (a.netScore != b.netScore) return a.netScore > b.netScore;  // 净胜分高者优先
        return a.name < b.name;  // 字典序小者优先
    });

    // 输出获奖队伍（前n/2名）
    // rank表示当前名次，遇到不同积分或净胜分时递增
    for (int i = 0, rank = 1; i < n && rank <= n/2; i++) {
        cout << teams[i].name << endl;
        // 检查下一个队伍是否应该占用新的名次
        if (i+1 < n && (teams[i].points != teams[i+1].points || 
            teams[i].netScore != teams[i+1].netScore)) rank++;
    }
    
    return 0;
}
