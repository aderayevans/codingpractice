#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<double> the_vector (390);
    double result = 0;
    for (double i : the_vector){
        cin >> i;
        result += i;
        cout << "After added: " << result << endl;
    };
    cout << "Result: " << result;
}