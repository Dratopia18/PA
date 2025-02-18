#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

#define MOD 1000000007

ifstream fin("numarare.in");
ofstream fout("numarare.out");

void countCommonPaths(int N, vector<vector<int>>& graph1,
vector<vector<int>>& graph2, vector<int>& dp1, vector<int>& dp2,
vector<int>& inDegree) {
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph1[node]) {
            dp1[neighbor] = (dp1[neighbor] + dp1[node]) % MOD;
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }

        for (int neighbor : graph2[node]) {
            dp2[neighbor] = (dp2[neighbor] + dp2[node]) % MOD;
        }
    }
}

int main() {
    int N, M;
    fin >> N >> M;
    vector<vector<int>> graph1(N + 1);
    vector<vector<int>> graph2(N + 1);
    vector<int> dp1(N + 1);
    vector<int> dp2(N + 1);
    vector<int> inDegree(N + 1);
    dp1[1] = 1;
    dp2[1] = 1;

    for (int i = 0; i < M; ++i) {
        int x, y;
        fin >> x >> y;
        graph1[x].push_back(y);
        inDegree[y]++;
    }

    for (int i = 0; i < M; ++i) {
        int x, y;
        fin >> x >> y;
        if (find(graph1[x].begin(), graph1[x].end(), y) != graph1[x].end()) {
            graph2[x].push_back(y);
        }
    }

    countCommonPaths(N, graph1, graph2, dp1, dp2, inDegree);

    int result = 0;

    if (dp1[N] > dp2[N]) {
        result = min(dp1[N], dp2[N]);
    } else {
        result = max(dp1[N], dp2[N]);
    }

    fout << result;

    fin.close();
    fout.close();
    return 0;
}
