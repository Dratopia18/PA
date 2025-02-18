#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

ifstream fin("criptat.in");
ofstream fout("criptat.out");

double compare(const pair<pair<int, int>, double> &a,
               const pair<pair<int, int>, double> &b) {
    return a.second > b.second;
}

void procesPerechi(unordered_map<char, vector<pair<pair<int, int>,
                   double>>> &literaStats, char c, int i, int j) {
    pair<pair<int, int>, double> pair1 = literaStats[c][i];
    pair<pair<int, int>, double>  pair2 = literaStats[c][j];
    if (pair1.first.first + pair2.first.first >
       (pair1.first.second + pair2.first.second) / 2) {
        pair<int, int> newPair = make_pair(pair1.first.first +
        pair2.first.first, pair1.first.second + pair2.first.second);
        literaStats[c].erase(literaStats[c].begin() + i);
        literaStats[c].erase(literaStats[c].begin() + j - 1);
        literaStats[c].insert(literaStats[c].begin(),
        make_pair(newPair, (double)newPair.first / newPair.second));
        } else {
        literaStats[c].erase(literaStats[c].begin() + j);
    }
}

int main() {
    int N;
    fin >> N;
    vector<string> words(N);
    set<char> letters;
    for (int i = 0; i < N; i++) {
        fin >> words[i];
        for (char c : words[i]) {
            letters.insert(c);
        }
    }

    unordered_map<char, vector<pair<pair<int, int>, double>>> literaStats;
    vector<pair<pair<int, int>, double>> maxPereche =
    {make_pair(make_pair(0, 0), 0)};

    for (char c : letters) {
        for (string &word : words) {
            int contor = count(word.begin(), word.end(), c);
            double raport = (double)contor / word.size();
            literaStats[c].push_back(make_pair
            (make_pair(contor, word.size()), raport));
        }
        sort(literaStats[c].begin(), literaStats[c].end(), compare);

        int i = 0;
        int j = 1;
        long long countdown = literaStats[c].size();

        while (countdown > 0) {
            procesPerechi(literaStats, c, i, j);
            if (literaStats[c].front().first.first >=
            maxPereche.front().first.first &&
            literaStats[c].front().first.second >=
            maxPereche.front().first.second) {
                maxPereche = literaStats[c];
            }
            countdown--;
        }
    }

    fout << maxPereche.front().first.second;
    fin.close();
    fout.close();
    return 0;
}

