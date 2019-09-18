#include <iostream>
#include <string>
#include<vector>

using namespace std;

#define LINE_NUMBER 2

int min(int a, int b){
    if (a < b)
        return a;
    return b;
}

int scheduling(int totalNode, vector <vector<int> > process, vector<vector<int> > transfer, int exitingTimes[], int startingTimes[]){

    int dp[LINE_NUMBER][totalNode+1];

    dp[0][0] = startingTimes[0] + process[0][0];
    dp[1][0] = startingTimes[1] + process[1][0];

    for(int i = 1; i < totalNode; i++){

        dp[0][i] = min( dp[0][i-1], dp[1][i-1] + transfer[1][i-1] ) + process[0][i];
        dp[1][i] = min( dp[1][i-1], dp[0][i-1] + transfer[0][i-1] ) + process[1][i-1];

    }

    dp[0][totalNode] = dp[0][totalNode-1] + exitingTimes[0];
    dp[1][totalNode] = dp[1][totalNode-1] + exitingTimes[1];

    return min(dp[0][totalNode], dp[1][totalNode]);
}

int main()
{
    int totalNode ;
    /*
     * The input for totalNode must be given here
     */
    vector<vector<int> > processingTimes(LINE_NUMBER, vector<int>(totalNode));
    vector<vector<int> > transferTimes(LINE_NUMBER, vector<int>(totalNode-1));

    int startingTimes[];
    int exitingTimes[];

    /*
     * The input for the other parameters must be given here
     */


    /*
     * The function may be called here
     */
    return 0;
}