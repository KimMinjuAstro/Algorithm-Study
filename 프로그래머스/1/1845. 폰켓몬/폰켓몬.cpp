#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int>umap;
    for(auto num : nums){
        if(umap.find(num) == umap.end()){umap[num] = 1;}
        else{umap[num]++;}
    }
    
    int size = nums.size();
    for(int i = 1; i <= size / 2 ; i++){

        if(!umap.empty()){
            umap.erase(umap.begin()->first);
            answer++;
        }
        else{break;}
    }
    return answer;
}