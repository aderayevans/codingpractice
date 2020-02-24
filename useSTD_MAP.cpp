#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    map<string, int> phoneBook;
    int n, value;
    string key;
    cin >> n;
    while (n > 0) {
        cin >> key >> value;
        phoneBook[key] = value;
        n--;
    }
    while (cin >> key) {
        if (phoneBook.find(key) != phoneBook.end()) {
            cout << key << '=' << phoneBook.find(key)->second << endl;
        }
        else
            cout << "Not found\n";
    }   
    return 0;
}