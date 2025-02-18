#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream fin("oferta.in");
ofstream fout("oferta.out");

int main() {
    int N, K;
    fin >> N >> K;
    vector<double> preturi(N);
    for (int i = 0; i < N; ++i) {
        fin >> preturi[i];
    }
    vector<double> dp(N + 1);
    dp[0] = 0.0;
    for (int i = 1; i <= N; ++i) {
        dp[i] = dp[i - 1] + preturi[i - 1];
        if (i >= 2) {
            double produs_redus = min(preturi[i - 1], preturi[i - 2]) / 2;
            dp[i] = min(dp[i], dp[i - 2] + preturi[i - 1] + preturi[i - 2]
            - produs_redus);
        }
        if (i >= 3) {
            double pret_min =
            min({preturi[i - 1], preturi[i - 2], preturi[i - 3]});
            dp[i] = min(dp[i], dp[i - 3] + preturi[i - 1] +
            preturi[i - 2] + preturi[i - 3] - pret_min);
        }
    }
    if (K == 1) {
    fout << fixed << setprecision(1) << dp[N] << '\n';
    } else {
    fout << -1;
    }
    fin.close();
    fout.close();
    return 0;
}
