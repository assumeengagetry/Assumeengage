#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Team {
    string name;
    int ji_fen = 0;
    int jing_de_fen = 0;
};
// 比较函数
bool cmp(const Team &a, const Team &b) {
    if (a.ji_fen != b.ji_fen) return a.ji_fen > b.ji_fen;
    if (a.jing_de_fen != b.jing_de_fen) return a.jing_de_fen > b.jing_de_fen;
    return a.name < b.name;
}
// 计算得分
void de_fen(int a, int b, Team &team1, Team &team2) {
    if (a > b) team1.ji_fen += 3;
    else if (a < b) team2.ji_fen += 3;
    else {
        team1.ji_fen += 1;
        team2.ji_fen += 1;
    }
    team1.jing_de_fen += a - b;
    team2.jing_de_fen += b - a;
}
int main() {
    int n;cin >> n;
    cin.ignore();
    vector<Team> teams(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, teams[i].name);
    }
    for (int i = 0; i < n * (n - 1) / 2; ++i) {
        string name1, name2, line;
        int score1, score2;
        getline(cin, line);
        size_t p = line.find('-'), q = line.find(':');
        name1 = line.substr(0, p);
        name2 = line.substr(p + 1, q - p - 1);
        score1 = stoi(line.substr(q + 1, line.find('-', q) - q - 1));
        score2 = stoi(line.substr(line.find('-', q) + 1));
        auto &team1 = *find_if(teams.begin(), teams.end(), [&](const Team &t) { return t.name == name1; });
        auto &team2 = *find_if(teams.begin(), teams.end(), [&](const Team &t) { return t.name == name2; });
        de_fen(score1, score2, team1, team2);
    }
    sort(teams.begin(), teams.end(), cmp);
    for(int i = 0; i < n / 2; ++i) {
        cout << teams[i].name << endl;
    }   
}