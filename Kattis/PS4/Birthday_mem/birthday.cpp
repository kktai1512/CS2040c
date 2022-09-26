#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

int main() {
    freopen ("in.txt", "r", stdin);
    
    ll N; cin >> N; //number of friends
    unordered_map <string, pair<string, int>> birthday_list;
    vector<string> names;
    for (int i = 0; i < N; i++) {
        //cout <<"hello";
        string firstname; ll likeness; string birthday;
        cin >> firstname >> likeness >> birthday;
        //cout << "name " <<  firstname << " likeness " << likeness << " birthday " << birthday << endl;
        if (birthday_list.find(birthday) != birthday_list.end()){
            //cout << "found and gonna replace" << endl;
            if (likeness > birthday_list[birthday].second) {
                birthday_list[birthday] = {firstname,likeness};
            }
        }
        else birthday_list.insert({birthday, {firstname, likeness}});
    }
   
    for (auto& i : birthday_list) {
        names.push_back(i.second.first);
    }
    sort(names.begin(), names.end());
    cout << names.size()<<endl;
    for (auto &name : names) {
        cout << name << endl;
    }
   
}