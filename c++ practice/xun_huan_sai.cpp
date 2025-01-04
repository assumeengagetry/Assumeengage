#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
using namespace std;

struct Team {
    string name;
    int jifen = 0;
    int jingdefen = 0;
};

int cmp(const Team &a, const Team &b) {
    if (a.jifen != b.jifen) {
        return a.jifen > b.jifen;
    } else if (a.jingdefen != b.jingdefen) {
        return a.jingdefen > b.jingdefen;
    } else {
        return a.name < b.name;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<Team> teams(n);
    for (int i = 0; i < n; i++) {
        string name;
        getline(cin, name);
        teams[i].name = name;
    }
    string line;
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        getline(cin, line);
        stringstream ss(line);
        string name1, name2;
        int score1, score2;
        getline(ss, name1, '-');
        getline(ss, name2, ':');
        name1.erase(0, name1.find_first_not_of(" "));
        name1.erase(name1.find_last_not_of(" ") + 1);
        name2.erase(0, name2.find_first_not_of(" "));
        name2.erase(name2.find_last_not_of(" ") + 1);
        ss >> score1;
        ss.ignore();
        ss >> score2;

        Team *team1 = nullptr;
        Team *team2 = nullptr;
        for (auto &team : teams) {
            if (team.name == name1) {
                team1 = &team;
            } else if (team.name == name2) {
                team2 = &team;
            }
        }
        if (score1 > score2) {
            team1->jifen += 3;
        } else if (score1 < score2) {
            team2->jifen += 3;
        } else {
            team1->jifen += 1;
            team2->jifen += 1;
        }
        team1->jingdefen += (score1 - score2);
        team2->jingdefen += (score2 - score1);
    }
    sort(teams.begin(), teams.end(), cmp);
    for (int i = 0; i < n / 2; i++) {
        cout << teams[i].name << endl;
    }
}