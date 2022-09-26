#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, P; cin >> N >> M >> P;

    //crank
    vector<int> cranks(N); 
    for (int i = 0; i < N; i ++) {
        int temp = 0; cin >> temp;
        cranks[i] = temp;
    }

    vector<int> backwheel(M); 
    for (int i = 0; i < M; i ++) {
        int temp = 0; cin >> temp;
        backwheel[i] = temp;
    }

    vector<double> ratios;
    for (auto &gear : cranks) {
        for (auto &bwgear : backwheel) {
                ratios.push_back((double)bwgear/gear);

        }
    }
    sort(ratios.begin(), ratios.end());
    //  for (auto &a: ratios) {
    //      cout << a << endl;
    //  }

    int size = ratios.size();

    for (int i = 0; i < size - 1; i ++) {
        if (ratios[i+1]/ratios[i] -1 > (double) P/100) {
            // cout<< ratios[i+1] << " " << ratios[i] << endl;
            cout << "Time to change gears!";
            return 0;
        }
    }
    cout << "Ride on!";
    
 
}