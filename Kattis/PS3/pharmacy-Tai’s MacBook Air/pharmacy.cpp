#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct triplet
{
    ll dtime;
    char type;
    ll ftime;

    triplet(ll dtime, char type, ll ftime) : dtime(dtime), type(type), ftime(ftime) {}

    bool operator<(const triplet& other) const
    {
        if (dtime == other.dtime) {
            if (type == 'S' and other.type == 'R') {
                return true;
            }
            if (type == 'R' and other.type == 'S') {
                return false;
            }
            if (type ==  other.type ) {
                return ftime < other.ftime;
            }
        }
        return dtime < other.dtime;
    }

    void print() const {
        cout <<  "(" << dtime << "," << type << "," << ftime << ")\n"; 
    }

};

int main() {
    freopen("in.txt", "r" , stdin); 
    ll n, t; cin >> n >> t;

    vector<triplet> prescriptions;
    vector<pair<bool, ll> >avail_tech(t, make_pair(true,1));

    vector<ll> in_store_time;
    vector<ll> remote_time;

    for (ll i = 0; i < n; i ++) {
        ll d; char c; ll k;
        cin >> d >> c >> k;
        prescriptions.push_back(triplet(d,c,k));
    }

    sort(prescriptions.begin(), prescriptions.end());
    // for (auto &item : prescriptions) {
    //     item.print();
    // }
    
    auto cmp = [](const triplet &a, const triplet &b) {
        //"all S is greater than R regardless"
        if (a.type == 'S' and b.type == 'R') {
                return false;
        }
        
        else if (a.type == 'R' and b.type == 'S') {
                return true;
        }

        //after comparing types, same type
        else if (a.dtime == b.dtime) {
            // if (a.type == 'S' and b.type == 'R') {
            //     return false;
            // }
            // if (a.type == 'R' and b.type == 'S') {
            //     return true;
            // }
            if (a.type ==  b.type ) {
                return a.ftime > b.ftime;
            }
        }
        // same type, diff times, then
        return a.dtime > b.dtime;
    };
    priority_queue<triplet, vector<triplet>, decltype(cmp)> queue(cmp);
    int counter = 0;
    vector<int> time_list;
    for (ll T = 1; T < LLONG_MAX; T ++) {
        cout << "currently is " << T << endl;
        //search through prescriptions, get T = 1;
        if (in_store_time.size() + remote_time.size() == prescriptions.size() ) {
            break;
        }
        int k = 0;
        for (ll i = counter; i < prescriptions.size(); i++) {
            if (prescriptions[i].dtime == T) {
                queue.push(prescriptions[i]); 
                k++;
                //cout << "this is T: " << T;;
                //prescriptions[i].print();
            }
        }
        counter += k;
        triplet min_in_prescription = *min_element(prescriptions.begin()+ counter, prescriptions.end());
        int min_pres = min_in_prescription.dtime;
        cout << "current min in prescription" << min_pres << endl;;
        for (ll n_tech = 0; n_tech < t; n_tech ++) {
           
            //if completed time is now, set to free
            if (avail_tech[n_tech].second <= T) {
                avail_tech[n_tech].first = true;
            }
            //cout << "technician" << n_tech << " available? " <<avail_tech[n_tech].first<< endl;
            //check any free
            if (!queue.empty() && queue.top().dtime <= T) {
                if (avail_tech[n_tech].first == true) {
                    cout << "technician " << n_tech << " processing: ";
                    queue.top().print();
                    ll completed_time = T + queue.top().ftime;
                    cout << "completed time" << completed_time << endl;
                    avail_tech[n_tech].second = completed_time;
                    avail_tech[n_tech].first = false;
                    time_list.push_back(completed_time);
                    sort(time_list.begin(), time_list.end());


                    if (queue.top().type == 'S') {
                        in_store_time.push_back(completed_time - queue.top().dtime);
                        cout << "debug";
                        cout << completed_time - queue.top().dtime << endl;
                    }
                    if (queue.top().type == 'R') {
                        remote_time.push_back(completed_time - queue.top().dtime);
                    }
                    queue.pop();
                }
            }
        }
        if (!time_list.empty()){
                cout << "im here" << endl;
                //cout << time_list.size()<<endl;
                auto pointer = upper_bound(time_list.begin(), time_list.end(), T) ;
                int min_time = *pointer;
                cout << "min time: " << min_time << endl;
                int target = min(min_time, min_pres);
                if (T < target) { 
                    //jump to completion time or prescription time
                    cout << "we jump to " << min(min_time, min_pres) << endl;
                    T = target -1;
                }
                if (min_time == 0) {
                    cout << "we jump to " << min_pres << endl;
                    T = min_pres -1;
                }
        }
            // if (T < min_pres -1) {
            //     cout << "we jump to " << min_pres  << endl;
            //     T = min_pres - 1;
            // }
    }

    
    // while (!queue.empty()) {
    //     queue.top().prll();
    //     queue.pop();
    // }
    // cout << "instore \n";
    // for (auto &item : in_store_time) {
    //     cout << item << " ";
    // }

    // cout << "remote\n";
    // for (auto &item : remote_time) {
    //     cout <<item << " ";
    // }
    float in_store_average = in_store_time.size() != 0 ? 
        accumulate( in_store_time.begin(), in_store_time.end(), 0.000000)/ in_store_time.size() : 0;
    float remote_average = remote_time.size() != 0? 
        accumulate( remote_time.begin(), remote_time.end(), 0.000000) / remote_time.size() : 0;
    
    cout << fixed << setprecision(6) <<  in_store_average << " " << remote_average << endl;
}