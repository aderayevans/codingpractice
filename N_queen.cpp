#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> vt) {
    cout << "[";
    for (int i = 0; i < vt.size(); i++) {
        cout << vt[i]+1 << ' ';
    }
    cout << "] ";
}
bool safe(vector<int> checklist, int queen_index, int row) {
    if (checklist.size() == 0) return true;
    int check = 0;
    for (int i = 0; i < checklist.size(); i++) {
        if (checklist[i] != row && i != queen_index)
            if ((checklist[i]+i) != (row+queen_index))
                if ((checklist[i]-i) != (row-queen_index)) {
                    check++;
                }
    }
    if (check == checklist.size()) return true;
    return false;
}
int main() {
    int testcases = 0;
    cin >> testcases;
    for (int each = 0; each < testcases; each++) {
        bool notfail = false;
        int length = 0;
        cin >> length;
        vector<int> checklist;
        int queen_index = 0, row = 0;
        while(true) {
            if (checklist.size() == length) {
                print(checklist);
                notfail = true;
                if (row > (length-1) && queen_index > (length-1) && checklist[0] == (length-1)) break;
            }
            else if (row > (length-1) && queen_index == 0) {
                break;
            }
            if (queen_index > (length-1) || row > (length-1)) {
                queen_index--;
                row = checklist[queen_index] + 1;
                checklist.pop_back();
            }
            else if (safe(checklist, queen_index, row)) {
                checklist.push_back(row);
                queen_index++;
                row = 0;
            }
            else {
                row++;
            }
        }
        if (!notfail) {
            cout << "-1";
        }
        cout << endl;
    }
}