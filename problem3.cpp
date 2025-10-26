#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;
    input += "a";

    int n = 0;
    bool flag = false;
    int sum=0;
    for (char c : input) {
        if (c >= '0' && c <= '9') {
            n = n * 10 + c - '0';
            flag = true;
        }
        else if (flag) {
            cout << n << endl;
            sum=sum+n;
            n = 0;
            flag = false;
        }
    }
    cout<<sum;
    return 0;
}
