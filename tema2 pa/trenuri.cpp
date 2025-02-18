#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

ifstream fin("trenuri.in");
ofstream fout("trenuri.out");
unordered_set<string> visited;
vector<string> res;


void solve_dfs(unordered_map<string, vector<string>>& graph, string city) {
    stack<pair<string, int>> s;
    s.push({city, 0});
    while (!s.empty()) {
        string current = s.top().first;
        size_t index = s.top().second;
        s.pop();
        if (index == graph[current].size()) {
            res.push_back(current);
            continue;
        }
        s.push({current, index + 1});
        if (visited.find(graph[current][index]) == visited.end()) {
            visited.insert(graph[current][index]);
            s.push({graph[current][index], 0});
        }
    }
}

int main() {
    string start, end;
    fin >> start >> end;
    int N;
    fin >> N;
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> dp;

    for (int i = 0; i < N; ++i) {
        string x, y;
        fin >> x >> y;
        graph[x].push_back(y);
    }

    solve_dfs(graph, start);
    reverse(res.begin(), res.end());
    for (string city : res) {
        dp[city] = INT_MIN;
    }

    dp[start] = 0;

    for (string city : res) {
        if (dp[city] != INT_MIN) {
            for (string neighbor : graph[city]) {
                dp[neighbor] = max(dp[neighbor], dp[city] + 1);
            }
        }
    }
    fout << dp[end] + 1;

    fin.close();
    fout.close();

    return 0;
}
