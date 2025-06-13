#include <string>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

int solution(int n) {
    int answer = 0;
    
    queue<int>q;
    int sum = 0;
    int i = 1;
    while(i <= n+1){
        if(sum > n){
            sum -= q.front();
            q.pop();
        }
        else if(sum == n){
            //cout<<q.front();
            sum -= q.front();
            q.pop();
            answer++;

        }else{
            sum += i;
            q.push(i);
            i++;
        }
    }
    
    return answer;
}