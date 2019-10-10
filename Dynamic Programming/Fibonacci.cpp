#include <iostream>
#include <string>

using namespace std;

int fibonacci(int n){

    int Fib[n+1];

    Fib[0] = 0;
    Fib[1] = 1;

    for(int i = 2; i <= n; i++){
        Fib[i] = Fib[i-1] + Fib[i-2];
    }

    return Fib[n];
}

int main(){

    int n;
    cin >> n;

    cout << fibonacci(n);
    return 0;
}
