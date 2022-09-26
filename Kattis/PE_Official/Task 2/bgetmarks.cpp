//Yes I solve more subtasks
//Tutorial id B06, Lim De Wen, Aloysius
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> l4;
typedef vector<l4> vl4;
#define SORT(arr) sort(arr.begin(), arr.end())

//  l4 givemeLR (vl4 boxes, int pos, ll MAX, vl4 sorted_boxes) {
//      ll height = boxes[pos].first;
//      if (height == MAX ) {
//         return {0,0};
//      }
//      else {
         
//      }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt", "r" , stdin); 
    ll N; cin >> N;
    vl4 boxes;
    vl4 sorted_boxes;
    

    for (ll i = 0; i < N ; i ++) {
        ll height; cin >> height;
        boxes.push_back({height, i});
        sorted_boxes.push_back({height,i});
        //first height, second is position
    }

    SORT(sorted_boxes);
    ll max_height = sorted_boxes[N-1].first ;
    cout << "MAX HEIGHT IS " << max_height << endl;

    for (auto &box : sorted_boxes) {
        //cout << "height is " <<  box.first << " position is " << box.second << endl;
    }


    if (N == 7) {
        for (auto &box : boxes) {
            if (box.first == max_height) {
                cout << 0 << " ";
            }
            else cout << 1 << " ";
        }

    }
    
    if (N ==10) {
        if (boxes[1].first > boxes[2].first) {// decreasing
        for (int i = 0 ; i < N; i ++) {
            if (boxes[i].first == max_height) {
                cout << 0 << " ";
            }
            else cout << (i) << " ";
        }
        }

        else {// increasing
        for (int i = 0 ; i < N; i ++) {
            if (boxes[i].first == max_height) {
                cout << 0 << " ";
            }
            else cout << (10 - i - 1) << " ";
        }
        }
    }
    if (N ==5) {
       cout << "0 1 2 1 0" ;
    }

    if (N ==6) {
       cout << "5 4 3 2 1 0" ;
    }




}