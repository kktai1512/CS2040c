#include <iostream>  // question 1a
using namespace std; // question 1b
template <class T>   // question 1c
class ListArray
{
private:
    int N;
    T A[10]; // question 1d
public:
    ListArray() : N(0) {} // question 1e
    T get(int i)
    {
        return A[i]; // question 1f
    }
    int search(T v)
    {
        for (int i = 0; i < N; ++i)
            if (A[i] == v)
                return i;
        return -1;
    }
    void insert(int i, T v)
    {
        if ((N == 10) || (i < 0) || (i > N))
            return;                      // question 1g
        for (int j = i; j <= N - 1; ++j) // question 1h
            A[j + 1] = A[j];
        A[i] = v;
        ++N;
    }
    void remove(int i)
    {
        for (int j = i; j < N - 1; ++j) // question 1i
            A[j] = A[j + 1];
        --N;
    }
    void printList()
    {
        for (int i = 0; i < N; ++i)
        {
            if (i)
                cout << " ";
            cout << A[i];
        }
        cout << "\n";
    }
    void sortList()
    { // sort array A, question 1j
    }
};
int main()
{
    ListArray<int> *LA = new ListArray<int>(); // question 1k
    LA->insert(0, 5);
    LA->insert(0, 1);
    LA->insert(0, 4);
    LA->insert(0, 7);
    LA->insert(0, 2);              // we should have A = {2, 7, 4, 1, 5} by now
    cout << LA->get(3) << "\n";    // 1, A[3] = 1
    cout << LA->search(4) << "\n"; // 2, A[2] = 4
    cout << LA->search(6) << "\n"; // not found, -1
    LA->remove(1);                 // we should have A = {2, 4, 1, 5} by now
    cout << LA->search(4) << "\n"; // 1, A[1] = 4 now
    cout << LA->search(7) << "\n"; // not found, -1
    LA->printList();               // unsorted
    LA->sortList();                // we should have A = {1, 2, 4, 5} by now
    LA->printList();               // sorted
    return 0;
} // please copy paste the code above, test compile, and run it yourself
