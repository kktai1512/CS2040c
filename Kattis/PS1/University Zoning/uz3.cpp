#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Student {
    pair<ll,ll> coordinate; ll student_number, faculty;
    Student(ll r, ll c, ll student_number, ll faculty):
        coordinate(make_pair(r,c)),
        student_number(student_number),
        faculty(faculty){}

    Student() {}

    bool operator < (const Student &a) const {
        if (student_number < a.student_number) {
            return true;
        }
        return false;
    }
};

ll steps(pair<ll,ll>& a, pair<ll,ll>& b) {
    ll x = abs(a.first - b.first);
    ll y = abs(a.second - b.second);
    return x+y;
};

int main() {
    freopen("in.txt", "r", stdin);
    // R, C , F, S, G
    ll R, C, F, S, G; cin >> R >> C >> F >> S >> G;    

    //create a grid, all faculties set to zero
    vector<vector<ll>> grid (R, vector<ll> (C, 0));

    //create a faculty list, inside has all the coordinates
    vector <vector<pair<ll,ll>>> faculty_box_list(F);
    // F faculties
    for (ll i = 0; i < F; i++) {
        ll K; cin >> K;
        //each faculty has K coordinates
        for (ll j=0; j<K; j++) {
            ll r, c; cin >> r >> c;
            grid[r-1][c-1] = i+1;
            faculty_box_list[i].push_back(make_pair(r,c));
        }
        //sort the grid within faculties
        sort(faculty_box_list[i].begin(), faculty_box_list[i].end());
    }

    //prll for my faculty_box_list
    cout << "Faculty : \n";
    for (auto faculty: faculty_box_list) {
        for (auto coordinates: faculty) {
            cout << "(" << coordinates.first << "," << coordinates.second << ") ";
        }
        cout << "\n";
    }

    //grid output
    cout << "Grid : \n";
    for (ll i = 0; i < R; i ++) {
        for (ll j = 0; j < C; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }


    vector<pair<ll,ll>> faculty_compliance(F, make_pair(0,0));
    vector<Student> student_list(S);
    vector<vector<Student>> student_by_faculty(F);
    // S students
    for (ll i = 0 ; i < S; i ++) {
        ll r, c, std_no, fac; cin >> r >> c >> std_no >> fac; 
        Student student_temp = Student(r,c, std_no, fac);
        //add the student llo the faculty
        student_by_faculty[fac-1].push_back(student_temp);
    }

    //sort and prll for my student_by_faculty
    cout << "Student : \n";
    for (int i = 0; i<F; i++) {
        sort(student_by_faculty[i].begin(), student_by_faculty[i].end());  
        for (int j = 0; j < student_by_faculty[i].size(); j ++) {
            cout << "(" << student_by_faculty[i][j].coordinate.first << "," << student_by_faculty[i][j].coordinate.second<< ") ";
        }
        cout << "\n";
    }

    // the minimum for each faulty
    for (ll i = 0; i < F; i++) 
    {
        ll a; cin >> a;
        faculty_compliance[i].second = a;
    }

    
    //go through each faculty
    ll n_not_complied =0;
    vector<ll> min_for_each_fac(F);
    for (ll i = 0; i < F; i++) {
        ll n = student_by_faculty[i].size();
        vector<pair<pair<ll,ll>,pair<ll,ll>>> not_complied;
        //add up the compliances
        for (ll j = 0; j < n; j++) {
            if (student_by_faculty[i][j].coordinate == faculty_box_list[i][j]) {
                faculty_compliance[i].first += 1;
            }
            //if doesn't comply, flag it out
            else {
                not_complied.push_back(
                    (make_pair
                        (student_by_faculty[i][j].coordinate, faculty_box_list[i][j])
                    )
                );
            }
        }
        
    
        ll checker = faculty_compliance[i].second - faculty_compliance[i].first;
        //haven't complied, if complied very good move on
        if (checker > 0) {
            n_not_complied += 1;
            //prll
            cout << "not complied for each fac: \n";
            for (auto n: not_complied) {
                cout << "(" << n.first.first << "," << n.first.second <<  ") ";
                cout << "(" << n.second.first << "," << n.second.second <<  ") \n";
            }
            cout << "\n";

            //calculate steps needed
            vector<ll> steps_needed;
            for (auto n: not_complied) {
                ll n_of_steps = steps(n.first, n.second);
                steps_needed.push_back(n_of_steps);
                cout << "steps:" << n_of_steps << endl;
            }   
            sort(steps_needed.begin(),steps_needed.end());
            for (ll z = 0; z < checker; z ++) {
                min_for_each_fac[i] += steps_needed[z];
            }

        }
    
    }

    
    cout << "complianced for each fac: \n";
    for (auto n:faculty_compliance) {
        cout << "(" << n.first << "/" << n.second <<  ") ";
    }
    cout << "\n";

    cout << "min for each fac: \n";
    for (auto n: min_for_each_fac) {
        cout << n << " ";
    }
    cout << "\n";

    sort(min_for_each_fac.begin(),min_for_each_fac.end());
    ll final_ans = 0;
    int n_complied = F - n_not_complied;
    for (int p = n_complied; p < G; p++) {
        final_ans += min_for_each_fac[p];
    }
    cout << final_ans;
}




