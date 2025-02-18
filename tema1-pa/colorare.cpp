#include <iostream>
#include <fstream>
#include <vector>

#define MOD 1000000007

using namespace std;

ifstream fin("colorare.in");
ofstream fout("colorare.out");

long long log_pow(long long base, long long exp) {
    if (!exp) {
        return 1;
    }

    long long tmp = 1;
    while (exp != 1) {
        if (exp % 2 == 0) {
            base = (1LL * base * base) % MOD;
            exp /= 2;
        } else {
            tmp = (1LL * tmp * base) % MOD;
            exp--;
        }
    }

    return (1LL * tmp * base) % MOD;
}
long long calculeazaModuriColorare(int K, vector<pair<int, char>> piese) {
    long long totalModuri = 1;

    for (int i = 0; i < K; ++i) {
        if (i == 0) {
            if (piese[0].second == 'V') {
                totalModuri = (totalModuri *
                (3 * log_pow(2, piese[0].first - 1))) % MOD;
            } else if (piese[0].second == 'H') {
                totalModuri = (totalModuri *
                (2 * log_pow(3, piese[0].first))) % MOD;
            }
        } else {
            if (piese[i].second == 'H' && piese[i - 1].second == 'H') {
                totalModuri = (totalModuri * log_pow(3, piese[i].first)) % MOD;
            } else if (piese[i].second == 'H' && piese[i - 1].second == 'V') {
                totalModuri = (totalModuri *
                (2 * log_pow(3, piese[i].first - 1))) % MOD;
            } else if (piese[i].second == 'V' && piese[i - 1].second == 'V') {
                totalModuri = (totalModuri * log_pow(2, piese[i].first)) % MOD;
            } else if (piese[i].second == 'V' && piese[i - 1].second == 'H') {
                totalModuri = (totalModuri * log_pow(2, piese[i].first - 1))
                % MOD;
            }
        }
    }

    return totalModuri;
}

int main() {
    int K;
    fin >> K;
    vector<pair<int, char>> piese(K);
    for (int i = 0; i < K; ++i) {
        fin >> piese[i].first >> piese[i].second;
    }
    long long result = calculeazaModuriColorare(K, piese);
    fout << result;
    fin.close();
    fout.close();
    return 0;
}
