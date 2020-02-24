#include <iostream>
using namespace std;

template<typename type> type init() {
    type type_;
    cout << "Import: ";
    cin >> type_;
    return type_;
}
template<typename type> void print(type type_) {
    cout << type_ << endl;
}
int main() {
    int int_;
    string string_;
    int_ = init<int>();
    string_ = init<string>();
    print<int>(int_);
    print<string>(string_);
}