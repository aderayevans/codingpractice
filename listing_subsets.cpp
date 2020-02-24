#include <iostream>
#include <vector>
using namespace std;
vector<int> vt;
int length = 0;
void print(vector<int> address_container) {
    cout << "{";
    for (int i = 0; i < address_container.size(); i++) {
        if (i != 0) cout << "; ";
        cout << vt[address_container[i]];
    }
    cout << "}";
}
void Solution () {
    vector<int> address_container;
    int address_jump = 0, check_position = 0;
    bool first = true;
    while(true) {
        if (!first) cout << ", ";
        address_container.push_back(address_jump);
        print(address_container);
        first = false;
        if (address_jump >= (length-1) && check_position == 0) break;
        else if (address_jump >= (length-1)) {
            check_position--;
            address_container.pop_back();
            address_jump = address_container[check_position] + 1;
            address_container.pop_back();
        }
        else {
            check_position++;
            address_jump++;
        }
    }
}
void init_global() {
    std::cout << "Import length: "; std::cin >> length;
    vt.resize(length);
    for(int i = 0; i < length; i++) {
        std::cout << "Import <" << (i+1) << ">: "; std::cin >> vt[i];
    }
}
int main() {
    init_global();
    Solution();
}