#include<iostream>
#include<vector> 
#include<string>
#include<algorithm>
#include<map>
using namespace std;

struct Team {
    string name;
    int points = 0;
    int netScore = 0;
};

// 修正cmp函数的返回类型为bool
bool cmp(const Team& a, const Team& b) {
    if (a.points != b.points) return a.points > b.points;
    if (a.netScore != b.netScore) return a.netScore > b.netScore;
    return a.name < b.name;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符

    vector<Team> teams(n);
    map<string, int> idx;
    for (int i = 0; i < n; ++i) {
        getline(cin, teams[i].name);
        idx[teams[i].name] = i;
    }

    for (int i = 0; i < n * (n - 1) / 2; i++) {
        string name1, name2, line;
        int score1, score2;
        getline(cin, line);
        size_t p = line.find('-'), q = line.find(':');
        name1 = line.substr(0, p);
        name2 = line.substr(p + 1, q - p - 1);
        name1.erase(0, name1.find_first_not_of(" "));
        name2.erase(0, name2.find_first_not_of(" "));
        name1.erase(name1.find_last_not_of(" ") + 1);
        name2.erase(name2.find_last_not_of(" ") + 1);
        sscanf(line.substr(q + 1).c_str(), "%d-%d", &score1, &score2);
        teams[idx[name1]].netScore += score1 - score2;
        teams[idx[name2]].netScore += score2 - score1;
        if (score1 > score2) {
            teams[idx[name1]].points += 3;
        } else if (score1 < score2) {
            teams[idx[name2]].points += 3;
        } else {
            teams[idx[name1]].points += 1;
            teams[idx[name2]].points += 1;
        }
    }

    sort(teams.begin(), teams.end(), cmp);

    for (int i = 0; i < n / 2; i++) {
        cout << teams[i].name << endl;
    }

    return 0;
}