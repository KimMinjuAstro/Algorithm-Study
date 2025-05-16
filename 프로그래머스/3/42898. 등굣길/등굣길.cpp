#include <string>
#include <vector>
#include <iostream>
#define mod 1'000'000'007
using namespace std;
long long DP[101][101];
int obs[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i = 0; i < puddles.size(); i++){
        obs[puddles[i][1]-1][puddles[i][0]-1] = 1;
    }
    DP[0][0]=1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i==0 && j==0)continue;
            else if(obs[i][j]==1)DP[i][j]=0;
            else if(i == 0) DP[i][j] = DP[i][j-1];
            else if(j == 0) DP[i][j] = DP[i-1][j];
            else if(obs[i-1][j]==1)DP[i][j]=DP[i][j-1];
            else if(obs[i][j-1]==1)DP[i][j]=DP[i-1][j];
            else{DP[i][j]=(DP[i-1][j] % mod +DP[i][j-1] % mod) % mod;}
        }
    }
    
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < m ; j++){
    //         cout<<DP[i][j]<<" ";
    //     }cout<<"\n";
    // }
    return DP[n-1][m-1] % mod;
}