#include <bits/stdc++.h>
using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, x;
    vector<int> v;

    void read_input() {
        ifstream fin("in");
        fin >> n;
        for (int i = 0, e; i < n; i++) {
            fin >> e;
            v.push_back(e);
        }
        fin >> x;
        fin.close();
    }

    int find_first() {
        // TODO: Cautati prima pozitie pe care se afla valoarea x
        // In cazul in care x nu apare in sir, returnati -1
        int left = 0;
        int right = n - 1;
        int mid = 0;
        int res = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (v[mid] >= x) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (res != -1 && v[res] == x)
            return res;
        else 
            return -1;
    }

    int find_last() {
        // TODO: Cautati ultima pozitie pe care se afla valoarea x
        // In cazul in care x nu apare in sir, returnati -1
        int left = 0;
        int right = n - 1;
        int mid = 0;
        int res = -1;
        while (left <= right) {
            mid =  (left + right) / 2;
            if (v[mid] <= x) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (res != -1 && v[res] == x)
            return res;
        else 
            return -1;
    }

    int get_result() {
        // TODO: Calculati numarul de aparitii ale lui x in vectorul v
        int first = find_first();
        int last = find_last();
        if (first != -1 && last != -1) {
            return last - first + 1;
        } else {
            return 0;
        }
    }

    void print_output(int result) {
        ofstream fout("out");
        fout << result;
        fout.close();
    }
};

// [ATENTIE] NU modifica functia main!
int main() {
    // * se aloca un obiect Task pe heap
    // (se presupune ca e prea mare pentru a fi alocat pe stiva)
    // * se apeleaza metoda solve()
    // (citire, rezolvare, printare)
    // * se distruge obiectul si se elibereaza memoria
    auto* task = new (nothrow) Task(); // hint: cppreference/nothrow
    if (!task) {
        cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
