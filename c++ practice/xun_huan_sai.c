#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[51];
    int jifen;
    int jingdefen;
} Team;

int cmp(const void *a, const void *b) {
    Team *teamA = (Team *)a;
    Team *teamB = (Team *)b;
    if (teamA->jifen != teamB->jifen) {
        return teamB->jifen - teamA->jifen;
    } else if (teamA->jingdefen != teamB->jingdefen) {
        return teamB->jingdefen - teamA->jingdefen;
    } else {
        return strcmp(teamA->name, teamB->name);
    }
}

void trim(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    Team teams[n];
    for (int i = 0; i < n; i++) {
        fgets(teams[i].name, 51, stdin);
        trim(teams[i].name);
        teams[i].jifen = 0;
        teams[i].jingdefen = 0;
    }
    char line[100];
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        fgets(line, 100, stdin);
        char name1[51], name2[51];
        int score1, score2;
        sscanf(line, "%[^-] - %[^:] : %d - %d", name1, name2, &score1, &score2);
        trim(name1);
        trim(name2);
        Team *team1 = NULL;
        Team *team2 = NULL;
        for (int j = 0; j < n; j++) {
            if (strcmp(teams[j].name, name1) == 0) {
                team1 = &teams[j];
            } else if (strcmp(teams[j].name, name2) == 0) {
                team2 = &teams[j];
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
    qsort(teams, n, sizeof(Team), cmp);
    for (int i = 0; i < n / 2; i++) {
        printf("%s\n", teams[i].name);
    }
    return 0;
}
