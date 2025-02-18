#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("compresie.in");
ofstream fout("compresie.out");

int main() {
    int n, m;
    long long sumFirst = 0, sumSecond = 0;
    fin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        fin >> A[i];
        sumFirst += A[i];
    }
    fin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        fin >> B[i];
        sumSecond += B[i];
    }

    int i = 0, j = 0;
    int count = 0;
    int sumA = 0, sumB = 0;

    while (i <= n && j <= m) {
        if (sumA == sumB && sumA != 0 && sumB != 0) {
            count++;
            sumA = 0;
            sumB = 0;
        } else if (sumA < sumB) {
            sumA += A[i];
            i++;
        } else {
            sumB += B[j];
            j++;
        }
    }

    if (sumFirst == sumSecond) {
        fout << count;
    } else {
        fout << -1;
    }
    fin.close();
    fout.close();
    return 0;
}
