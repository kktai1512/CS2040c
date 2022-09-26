#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

struct Player {
    string name;
    ll first,second,third;

    Player (string name, ll first, ll second, ll third): name(name), first(first), second(second), third(third) {};
    void print() const{
        cout << name << " " << first << " " << second << " " << third << endl;
    }
};
auto cmp1 = [](const Player &a, const Player &b) {
    if (a.first == b.first) {
        return a.name > b.name;
    }
    return a.first < b.first;
};
    auto cmp2 = [](const Player &a, const Player &b) {
    if (a.second == b.second) {
        return a.name > b.name;
    }
    return a.second < b.second;
};
    auto cmp3 = [](const Player &a, const Player &b) {
    if (a.third == b.third) {
        return a.name > b.name;
    }
    return a.third < b.third;
};

string GiveMe1 (priority_queue<Player, vector<Player>, decltype(cmp1)> &sth, unordered_map<string, Player> &pa){
    while (!sth.empty() ) {
        string name = sth.top().name; sth.pop();
        if (pa.find(name)!= pa.end()) {
            pa.erase(name); 
            return name;
        }
    }
    return "";
};

string GiveMe2 (priority_queue<Player, vector<Player>, decltype(cmp2)> &sth, unordered_map<string, Player> &pa){
    while (!sth.empty() ) {
        string name = sth.top().name; sth.pop();
        if (pa.find(name)!= pa.end()) {
            pa.erase(name); 
            return name;
        }
    }return "";
};

string GiveMe3 (priority_queue<Player, vector<Player>, decltype(cmp3)> &sth, unordered_map<string, Player> &pa){
    while (!sth.empty() ) {
        string name = sth.top().name; sth.pop();
        if (pa.find(name)!= pa.end()) {
            pa.erase(name); 
            return name;
        }
    }return "";
};
int main() {
    freopen("in.txt", "r", stdin);
    ll N; cin >> N;
    unordered_map<string, Player> players;

    for (int i = 0 ; i < N; i ++) {
        string name; ll first, second, third;
        cin >> name >> first >> second >> third;
        Player a = Player(name, first, second, third);
        players.insert({name,a});
        //a.print();
    }

  
   
    priority_queue<Player, vector<Player>, decltype(cmp1)> sortbyfirst(cmp1);
    priority_queue<Player, vector<Player>, decltype(cmp2)> sortbysecond(cmp2);
    priority_queue<Player, vector<Player>, decltype(cmp3)> sortbythird(cmp3);

    for (auto& p: players) {
        sortbyfirst.push(p.second);
        sortbysecond.push(p.second);
        sortbythird.push(p.second);
    }
    // while(!sortbyfirst.empty()){
    //     sortbyfirst.top().print();
    //     sortbyfirst.pop();
    //     sortbysecond.top().print();
    //     sortbysecond.pop();
    // }

    // while (!sortbyfirst.empty()) {
    //     string first = sortbyfirst.top().name;
    //     cout << first << " ";
    //     sortbyfirst.pop();
    //     players.erase(sortbyfirst.top().name);
    //     //sortbysecond.top().name()
    //}
    ll times = N/3;
    //cout << sortbyfirst.top().name;
    while (times--){
       vector<string> names = {GiveMe1(sortbyfirst, players), GiveMe2(sortbysecond, players), GiveMe3(sortbythird, players)};
       sort(names.begin(), names.end());
       for (auto &i : names) {
           cout << i <<" ";
       }  
       cout << endl;    
    }
    

    
    
}