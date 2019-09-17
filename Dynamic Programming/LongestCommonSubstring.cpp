#include <iostream>
#include <string>

using namespace std;

int max(int a, int b){
    if (a > b)
        return a;
    return b;
}

int LCS(string W, string V, int w, int n){
    int CS[w+1][n+1], index;

    memset(CS, 0, sizeof(CS));

    /*
     * If we want to find length of the lcs
     */
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= n; j++){

            if(W[i] == V[j]){
                CS[i][j] = CS[i-1][j-1] + 1;
            }
        }
    }

    /*
    * If we want to find the lcs

    int max = 0, index;
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= n; j++){
            if(W[i] == V[j]){
                CS[i][j] = CS[i-1][j-1] + 1;
            }
            if( CS[i][j] > max){
                max = CS[i][j]
                index = i
            }
        }
    }
    return W.substr(index - max, max);

    */
    return CS[w][n];
}

int main() {
    string a, b;
    int l, k, res;

    cin >> a >> b >> l >> k;
    res = LCS(a,b,l,k);
    cout << res;

    return res;
}