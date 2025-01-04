#include <iostream>
#include <vector>
#include <cmath> // 包含 pow 函数
using namespace std;

// 矩阵乘法
vector<vector<int>> matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B, int n) {
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// 矩阵幂
vector<vector<int>> matrix_power(vector<vector<int>> A, int k, int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    // 初始化为单位矩阵
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }
    while (k > 0) {
        if (k % 2 == 1) {
            result = matrix_multiply(result, A, n);
        }
        A = matrix_multiply(A, A, n);
        k /= 2;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> result = matrix_power(matrix, k, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
