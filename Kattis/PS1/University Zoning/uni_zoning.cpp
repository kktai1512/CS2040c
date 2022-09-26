#include <bits/stdc++.h>

using namespace std;

struct Student {
    pair<int,int> coordinate; int student_number, faculty, grid_row_size, grid_col_size;
    Student(int r, int c, int student_number, int faculty, int grid_row_size, int grid_col_size):
        coordinate(make_pair(r,c)),
        student_number(student_number),
        faculty(faculty),
        grid_row_size(grid_row_size),
        grid_col_size(grid_col_size){}

    Student() {}

    int getStudentNo() {
        return this -> student_number;
    }
    int getFaculty() {
        return this -> faculty;
    }

    tuple<int,int> getCoordinate() {
        return this -> coordinate;
    }

    bool move (char direction) {
        if (direction == 'U' && coordinate.first - 1 >= 0 ) {
            coordinate.first -= 1;
            return true;
        }
        if (direction == 'D' && coordinate.first + 1 < grid_row_size) {
            coordinate.first -= 1;
            return true;
        }
        if (direction == 'L' && coordinate.second - 1 >= 0) {
            coordinate.first -= 1;
            return true;
        }
        if (direction == 'R' && coordinate.second + 1 < grid_col_size) {
            coordinate.first += 1;
            return true;
        }
        return false;
    }

    bool operator < (Student a) {
        if (this -> student_number < a.getStudentNo()) {
            return true;
        }
        return false;
    }
};

struct Faculty {
    int faculty_id;
    int num_of_cells;
    vector<pair<int, int>> coordinates_list;

    Faculty(int faculty_id, int num_of_cells) : faculty_id(faculty_id), num_of_cells(num_of_cells) {}

    void addCoordinate(pair <int,int> coordinate) {
        coordinates_list.push_back(coordinate);
    }

    vector<pair<int,int>> get_coordinates_list() {
        return coordinates_list;
    }
};

int main() {
    // R, C , F, S, G
    int R, C, F, S, G; cin >> R >> C >> F >> S >> G;    

    //create a grid, all faculties set to zero
    vector<vector<int>> grid (R, vector<int> (C, 0));

    // F faculties
    for (int i = 1; i <= F; i++) {
        int K; cin >> K;
        //each faculty has K coordinates
        for (int j=0; j<K; j++) {
            int r, c;
            cin >> r >> c;
            cout << "r: " << r << "c:" << c << "\n";
            grid[r-1][c-1] = i;
        }
    }    

    vector<int> faculty_compliance(F, 0);
    vector<Student> student_list(S);
    // S students
    for (int i = 0 ; i < S; i ++) {
        int r, c, std_no, fac;
        cin >> r >> c >> std_no >> fac;
        student_list[i] = Student(r,c,std_no, fac, R, C);
        //check if the rnc belongs to the fac, if yes add 1 to the fac
        if (grid[r-1][c-1] == fac) {
            faculty_compliance[fac - 1] += 1;
        }
    }

    vector<int> faculty_T_pair(F);
    // the minimum for each faulty
    for (int i = 0; i < F; i++) 
    {
        int a; cin >> a;
        faculty_T_pair[i] = a;
    }
    
    //grid output
    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    // go through each faculty, check if T is met 
    for (int i = 0; i < F; i++) {
        if (faculty_compliance[i] = faculty_T_pair[i])
    }
    // if T is met, go to next faculty
    // T is not met, means there's some students of that faculty elsewhere
    // look through students, see which students not in their own faculty
    // get a list of those students, find the student that is closest to any grid of the closest faculty
    // ( no need to be empty)
    // move towards the grid
    // repeat until T is met
    // move on to the next faculty

    //

}