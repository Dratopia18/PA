#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

ifstream fin("servere.in");
ofstream fout("servere.out");

double calcul_putere_minima(vector<int>& puteri, vector<int>& curenti,
                            double curent, int n) {
    double min_putere = puteri[0] - abs(curent - curenti[0]);
    for (int i = 1; i < n; i++) {
        double putere_server = puteri[i] - abs(curent - curenti[i]);
        min_putere = min(min_putere, putere_server);
    }
    return min_putere;
}

double curent_minim(vector<int>& curenti, int n) {
    double min;

    min = curenti[0];
    for (int i = 1; i < n; i++) {
        if (curenti[i] < min) {
            min = curenti[i];
        }
    }

    return min;
}

double curent_maxim(vector<int>& curenti, int n) {
    double max;

    max = curenti[0];
    for (int i = 1; i < n; i++) {
        if (curenti[i] > max) {
            max = curenti[i];
        }
    }

    return max;
}

double cautare_binara_curent(vector<int>& puteri, vector<int>& curenti, int n) {
    double stanga = curent_minim(curenti, n);
    double dreapta = curent_maxim(curenti, n);
    double mijloc;

    while (dreapta - stanga > 0.001) {
        mijloc = (stanga + dreapta) / 2;
        if (calcul_putere_minima(puteri, curenti, mijloc - 0.001, n) >=
            calcul_putere_minima(puteri, curenti, mijloc, n)) {
            dreapta = mijloc;
        } else {
            stanga = mijloc;
        }
    }

    mijloc = (stanga + dreapta) / 2;
    return mijloc;
}

int main() {
    int n;
    fin >> n;
    vector<int> puteri(n), curenti(n);
    for (int i = 0; i < n; ++i) {
        fin >> puteri[i];
    }
    for (int i = 0; i < n; ++i) {
        fin >> curenti[i];
    }
    double curent_optim = cautare_binara_curent(puteri, curenti, n);
    double putere_sistem = calcul_putere_minima(puteri, curenti,
    curent_optim, n);
    fout << fixed << setprecision(1) << putere_sistem;
    fin.close();
    fout.close();
    return 0;
}
