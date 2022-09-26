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

 l4 givemeLR (vl4 boxes, int pos, ll MAX) {
     ll height = boxes[pos].first;
    if (height == MAX ) {
        return {0,0};
     }
    else { 
        //go left
        int left = 0;
        int right = 0;
        for (int i = pos + 1; i < boxes.size(); i ++) {
            if (boxes[i].first > height) {
                right = i;
                break;
            }
        }

        for (int i = pos - 1 ; i >= 0; i -- ) {
            if (boxes[i].first > height) {
                left = i;
                break;
            }
        }
        givemeLR(boxes, left, MAX);
        givemeLR(boxes, right, MAX);
        return {left, right};
     }
 };
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
        cout << "height is " <<  box.first << " position is " << box.second << endl;
    }

    for (ll i = 0; i < N ; i ++) {
        cout << givemeLR (boxes, i, max_height).first << " " << givemeLR (boxes, i, max_height).second << endl;
    }
        //if smaller
        //
    }




