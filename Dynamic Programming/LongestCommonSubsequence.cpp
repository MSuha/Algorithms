#include <iostream>
#include <string>

using namespace std;

int max(int a, int b){
    if (a > b)
        return a;
    return b;
}
int LCS(string W, string V, int n, int m){
    int CS[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){

            if(i == 0 || j == 0){
                CS[i][j] = 0;
            }
            else if(W[i] == V[j]){
                CS[i][j] = CS[i-1][j-1] + 1;
            }
            else{
                CS[i][j] = max(CS[i-1][j], CS[i][j-1]);
            }
        }
    }
    return CS[n][m];
}

int main() {
    string a, b;
    int l, k, res;

    cin >> a >> b >> l >> k;
    res = LCS(a,b,l,k);
    cout << res;

    return res;
}