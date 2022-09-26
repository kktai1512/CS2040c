#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;

struct Patient {
    int index; int arrival; int departure;
    Patient(int index, int arrival, int departure) : index(index), arrival(arrival), departure(departure) {}

    bool operator<(const Patient& other) const
    {
        return arrival < other.arrival;
    }
}; 

typedef tuple <int, int, int, int>  fourplet;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt", "r" , stdin); 

    int N, D;
    cin >> N >> D;

    int C; cin >> C;

    vi initial_affected(N);
    auto cmp = [](const Patient &a, const Patient &b) {
        //"all S is greater than R regardless"
        return a.arrival > b.arrival;
    };
    priority_queue<Patient, vector<Patient>, decltype(cmp)> patient_list(cmp);

    while (C--) {
        int I; cin >> I;
        cout << "affected index " << I - 1 << endl;
    }


   for (int i = 0; i < N; i ++) {
        int S, T; cin >> S >> T;
        //Patient a = Patient (i, S, T);
        patient_list.push(Patient (i, S, T));
        cout << "index " << i << " : arrival " << S << "leave " << T << endl;
    }

    while (!patient_list.empty()) {
        cout << patient_list.top().index << endl; patient_list.pop();
    }
    

    ///tupleeeeee
    fourplet a = {1000,1,1,1};
    fourplet b(1000,1,1,1);
    cout << get<0>(b);
    

    //mapping
    
}
   