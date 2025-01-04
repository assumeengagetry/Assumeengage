#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// 队伍结构体
struct Team {
    char name[30];     // 队伍名称
    int id;            // 队伍ID
    int score = 0;     // 通过题目数
    int penalty = 0;   // 总罚时
    int attempts[10] = {}; // 记录题目尝试次数
    bool passed[10] = {};  // 记录题目是否通过
};

// 提交记录结构体
struct Submission {
    int teamID;        // 队伍ID
    int problemID;     // 题目ID
    char status[10];   // 提交状态
    int time;          // 提交时间（分钟）
};

// 时间转换函数：将 HH:MM 格式转化为分钟数
int timeToMinutes(int hour, int minute) {
    return hour * 60 + minute - 540; // 比赛从 9:00 开始
}

// 比较规则：得分优先，罚时次之，ID 最后
bool compareTeams(const Team &a, const Team &b) {
    if (a.score != b.score)
        return a.score > b.score;
    if (a.penalty != b.penalty)
        return a.penalty < b.penalty;
    return a.id < b.id;
}

// 更新队伍信息（处理提交记录）
void processSubmissions(vector<Team> &teams, const vector<Submission> &submissions, int currentTime) {
    for (auto &team : teams) {
        memset(team.attempts, 0, sizeof(team.attempts)); // 重置队伍题目尝试次数
        memset(team.passed, 0, sizeof(team.passed));     // 重置队伍题目通过状态
        team.score = 0;
        team.penalty = 0;
    }

    for (const auto &sub : submissions) {
        if (sub.time > currentTime)
            continue;

        auto &team = *find_if(teams.begin(), teams.end(), [&](const Team &t) { return t.id == sub.teamID; });

        if (team.passed[sub.problemID - 1] || strcmp(sub.status, "CE") == 0)
            continue;

        if (strcmp(sub.status, "AC") == 0) {
            team.passed[sub.problemID - 1] = true;
            team.score++;
            team.penalty += sub.time + team.attempts[sub.problemID - 1] * 20;
        } else {
            team.attempts[sub.problemID - 1]++; // 增加错误尝试次数
        }
    }
}

// 主程序
int main() {
    int n, m, q; // 提交记录数，队伍数，查询数
    cin >> n >> m >> q;

    vector<Team> teams(m);
    vector<Submission> submissions(n);

    // 输入队伍信息
    for (int i = 0; i < m; i++) {
        cin >> teams[i].id >> teams[i].name;
    }

    // 输入提交记录
    for (int i = 0; i < n; i++) {
        int hour, minute;
        cin >> submissions[i].teamID >> submissions[i].problemID >> submissions[i].status >> hour >> minute;
        submissions[i].time = timeToMinutes(hour, minute);
    }

    // 处理查询
    for (int i = 0; i < q; i++) {
        int queryType, hour, minute;
        cin >> queryType >> hour >> minute;
        int currentTime = timeToMinutes(hour, minute);

        processSubmissions(teams, submissions, currentTime);
        sort(teams.begin(), teams.end(), compareTeams);

        if (queryType == 1) { // 按队伍名称查询
            char queryName[30];
            cin >> queryName;
            for (int rank = 0; rank < m; rank++) {
                if (strcmp(teams[rank].name, queryName) == 0) {
                    cout << rank + 1 << " " << teams[rank].id << " " << teams[rank].name
                         << " " << teams[rank].score << " " << teams[rank].penalty << endl;
                }
            }
        } else { // 按队伍 ID 查询
            int queryID;
            cin >> queryID;
            for (int rank = 0; rank < m; rank++) {
                if (teams[rank].id == queryID) {
                    cout << rank + 1 << " " << teams[rank].id << " " << teams[rank].name
                         << " " << teams[rank].score << " " << teams[rank].penalty << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
