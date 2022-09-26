#include <bits/stdc++.h>

using namespace std;

int main() {
    int h,c; cin >> h >> c;
    vector<pair<int, int>> cw_ann_in (c);

    for (int i  = 0; i < c; i ++) {
        int a, d; cin >> a >> d;
        cw_ann_in[i] =  make_pair(a,d);
    }
     
    

    for (int i = 0; i < h; i ++ ){
        pair<int, int> curr_maxann_index = make_pair(cw_ann_in[0].first + cw_ann_in[0].second, 0);
        for (int j = 0; j < c ; j ++) {
            if (cw_ann_in[j].first + cw_ann_in[j].second < curr_maxann_index.first) {
                curr_maxann_index.first = cw_ann_in[j].first + cw_ann_in[j].second;
                curr_maxann_index.second = j;
            }
        }
        cw_ann_in[curr_maxann_index.second].first = curr_maxann_index.first;
    }
    sort (cw_ann_in.begin(), cw_ann_in.end(), [](pair<int,int>a, pair<int, int>b) {return a.first < b.first;});
    // for ( auto item : cw_ann_in) {
        
    // }
    cout << cw_ann_in[c-1].first;
 }