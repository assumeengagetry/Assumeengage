#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPseudoPalindrome(string str) {
    int len = str.size();
    int mismatchCount = 0;

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            mismatchCount++;
            if (mismatchCount > 1) return false;
        }
    }
    return mismatchCount == 1;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符

    while (n--) {
        string line;
        getline(cin, line);

        if (line.size() == 1) {
            cout << "no" << endl;
            continue;
        }

        if (isPseudoPalindrome(line)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
