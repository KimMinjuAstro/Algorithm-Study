#include <iostream>
using namespace std;

int main() {
    long long a, b, c; cin >> a >> b >> c;
    if(b < c){
        cout << a * c / b;
    }
    else{
        cout << a * b / c;
    }
}
