#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <tuple>
using namespace std;

// 队伍结构体，记录队伍的相关信息
struct Team {
    int id; // 队伍ID
    string name; // 队伍名称
    int solved = 0; // 通过的题目数量
    int penalty = 0; // 总罚时
    map<int, int> attempts; // 记录每道题的尝试次数
    map<int, bool> solvedProblems; // 记录每道题是否已解决
};

// 排序函数，比较两个队伍的排名
bool cmp(const Team& a, const Team& b) {
    if (a.solved != b.solved) return a.solved > b.solved; // 通过题目数多者优先
    if (a.penalty != b.penalty) return a.penalty < b.penalty; // 罚时少者优先
    return a.id < b.id; // ID小者优先
}

// 将时间字符串转换为分钟数
int timeToMinutes(const string& time) {
    int hours = stoi(time.substr(0, 2)); // 提取小时部分并转换为整数
    int minutes = stoi(time.substr(3, 2)); // 提取分钟部分并转换为整数
    return hours * 60 + minutes  - 540; // 计算总分钟数
}

// 计算某一时刻的队伍状态
void calculateStateAtTime(vector<Team>& teams, const vector<tuple<int, int, string, int>>& submissions, int queryTime) {
    // 重置队伍状态
    for (auto& team : teams) {
        team.solved = 0;
        team.penalty = 0;
        team.attempts.clear();
        team.solvedProblems.clear();
    }

    // 处理每次提交记录
    for (const auto& submission : submissions) {
        int tid, pid, minutes;
        string status;
        tie(tid, pid, status, minutes) = submission;

        if (minutes > queryTime) break; // 只处理查询时刻之前的提交记录

        if (status == "AC") {
            if (!teams[tid].solvedProblems[pid]) {
                teams[tid].solved++;
                teams[tid].penalty += minutes + teams[tid].attempts[pid] * 20;
                teams[tid].solvedProblems[pid] = true;
            }
        } else if (status != "CE") {
            teams[tid].attempts[pid]++;
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q; // 读取提交次数、队伍总数和询问次数
    vector<Team> teams(m + 1); // 创建队伍数组，索引从1开始
    map<string, vector<int>> nameToIds; // 队伍名称到ID的映射
    vector<tuple<int, int, string, int>> submissions; // 存储所有提交记录

    // 读取每个队伍的信息
    for (int i = 1; i <= m; ++i) {
        cin >> teams[i].id >> teams[i].name;
        nameToIds[teams[i].name].push_back(teams[i].id); // 将队伍ID添加到对应名称的列表中
    }

    // 处理每次提交记录
    for (int i = 0; i < n; ++i) {
        int tid, pid;
        string status, time;
        cin >> tid >> pid >> status >> time;
        int minutes = timeToMinutes(time); // 将提交时间转换为分钟数
        submissions.emplace_back(tid, pid, status, minutes); // 存储提交记录
    }

    // 处理每次查询
    for (int i = 0; i < q; ++i) {
        int type;
        string time, query;
        cin >> type >> time >> query;
        int minutes = timeToMinutes(time); // 将查询时间转换为分钟数

        calculateStateAtTime(teams, submissions, minutes); // 计算查询时刻的队伍状态

        vector<Team> result;
        if (type == 0) { // 按队伍ID查询
            int tid = stoi(query);
            result.push_back(teams[tid]);
        } else { // 按队伍名称查询
            for (int tid : nameToIds[query]) {
                result.push_back(teams[tid]);
            }
        }

        sort(result.begin(), result.end(), cmp); // 对结果进行排序

        // 输出查询结果
        for (const Team& team : result) {
            auto it = find_if(teams.begin(), teams.end(), [&](const Team& t) { return t.id == team.id; });
            int rank = distance(teams.begin(), it) + 1;
            cout << rank - 1 << " " << team.id << " " << team.name << " " << team.solved << " " << team.penalty << endl;
        }
    }

    return 0;
}
