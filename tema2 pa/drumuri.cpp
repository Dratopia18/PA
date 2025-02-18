#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

ifstream fin("drumuri.in");
ofstream fout("drumuri.out");

struct Edge {
    int to;
    long long cost;
};

void dijkstra(int start, vector<long long>& dist,
    const vector<vector<Edge>>& g) {
    int N = g.size() - 1;
    dist.assign(N + 1, LLONG_MAX);
    priority_queue<pair<long long, int>,
    vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        for (struct Edge edge : g[u]) {
            int v = edge.to;
            long long cost = edge.cost;
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }
}
int main() {
    int N, M;
    fin >> N >> M;
    vector<vector<Edge>> graph(N + 1);
    vector<vector<Edge>> reverseGraph(N + 1);
    vector<long long> distFromX, distFromY, distToZ;

    for (int i = 0; i < M; ++i) {
        int a, b;
        long long c;
        fin >> a >> b >> c;
        graph[a].push_back({b, c});
        reverseGraph[b].push_back({a, c});
    }
    int x, y, z;
    fin >> x >> y >> z;

    dijkstra(x, distFromX, graph);
    dijkstra(y, distFromY, graph);
    dijkstra(z, distToZ, reverseGraph);

    long long minCost = LLONG_MAX;
    for (int i = 1; i <= N; ++i) {
        if (distFromX[i] != LLONG_MAX &&
        distFromY[i] != LLONG_MAX && distToZ[i] != LLONG_MAX) {
            minCost = min(minCost, distFromX[i] + distFromY[i] + distToZ[i]);
        }
    }

    fout << minCost;

    fin.close();
    fout.close();

    return 0;
}
