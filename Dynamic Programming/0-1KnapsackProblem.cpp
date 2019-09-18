#include <iostream>
#include <string>

using namespace std;

int max(int a, int b){
    if (a > b)
        return a;
    return b;
}

int knapSack(int maxWeight, int weights[], int values[], int totalItem){

    int knapSack[totalItem+1][maxWeight+1];

    int i, j;

    for( i = 0; i <= totalItem; i++){
        for( j = 0; j <= maxWeight; j++){

            if(i == 0 ||j == 0){
                knapSack[i][j] = 0;
            }
            else if(weights[i-1] <= j){
                knapSack[i][j] = max(values[i-1] + knapSack[i-1][j-weights[i-1]], knapSack[i-1][j] );
            }
            else{
                knapSack[i][j] = knapSack[i-1][j];
            }
        }
    }
    return knapSack[totalItem][maxWeight];
}

int main()
{
    int weights[] = {1, 3, 4, 5};
    int values[] = {1, 4, 5, 7};
    int  W = 7, result;
    int n = sizeof(values)/sizeof(values[0]);

    result = knapSack(W, weights, values, n);

    cout << result << "\n";

    return result;
}