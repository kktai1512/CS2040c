#include <bits/stdc++.h>
using namespace std;

/////////main template
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt", "r" , stdin); 
}

//priority queue with custom comp
auto cmp = [](const  type &a, const type &b) {
        return a.dtime > b.dtime; 
        // if we want .top() to return the smallest, we need to use the larger comparator, ie the
        // the statement needs to be false (so 3 < 5)
    };

priority_queue<type, vector<type>, decltype(cmp)> queue(cmp);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//type definition
struct Patient {
    int index; int arrival; int departure;
    Patient(int index, int arrival, int departure) : index(index), arrival(arrival), departure(departure) {}

    bool operator<(const Patient& other) const
    {
        return arrival < other.arrival;
    }

    void print() {
        cout << "index" << index << "arrival " << arrival << "departure " << departure;
    }
}; 


///////input parsing////////////////////////////////////////////////////////////////////////////
string line; cin >> line;
stringstream ss(line);
string separated;
while getline(ss, separated, ';')
separated.find("-") == string::npos


//ub and lb
auto ub = upper_bound(array.begin(), array.end(), 7); // returns first thats strictly greater than 7
auto lb = lower_bound(array.begin(), array.end(), 7); // returns first thats equal or greater (ie not less than 7)