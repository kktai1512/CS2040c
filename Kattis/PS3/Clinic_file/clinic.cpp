#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
class Patient {
    private: 
        ll arrival_time;
        string name;
        ll severity; 
    public :
        Patient(ll T, string M, ll S) : arrival_time(T), name(M), severity(S) {};
        ll get_sv (ll current_time, ll K) const{
            return severity + K * (current_time - arrival_time);
        }
        string get_name() const {
            return name;
        }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("in.txt", "r", stdin);
    ll N, K; cin >> N >> K;
    const ll ct = 10000000;
    auto cmp = [K,ct](const Patient &a, const Patient &b) {
        if (a.get_sv(ct,K) == b.get_sv(ct,K)) {
            return a.get_name() > b.get_name();
        }
        return a.get_sv(ct,K) < b.get_sv(ct,K);
        };
    priority_queue<Patient, vector<Patient>, decltype(cmp)> q(cmp);
    unordered_set<string> removed;

    for (ll i  = 0 ; i < N; i++) {
        ll Q; cin >> Q;
    
        if (Q == 1) {
            ll T; string M ; ll S; cin >> T >> M >> S;
            Patient p = Patient(T,M,S);
            q.push(p);
            //cout << "this is" << M<< " " << p.get_sv(ct,K) <<endl;
        }

        if (Q == 2) {
            ll T; cin >> T;
            if (!q.empty()){
                while (!q.empty() && (removed.find(q.top().get_name() ) != removed.end())) {
                    removed.erase(q.top().get_name());
                    q.pop();
                }
                if (!q.empty()) {
                    cout <<  q.top().get_name() << endl;;
                    q.pop();
                }
                else {
                    cout<< "doctor takes a break" << endl;
                }
            }

            else {
                cout<< "doctor takes a break" << endl;
            }
        }

        if (Q == 3) {
            ll T; string S; cin >> T >> S;
            removed.insert(S);
            // cout << "this is";
            // for (auto &ele : removed){
            //     cout << ele << endl;
            }
        }
    }
    
