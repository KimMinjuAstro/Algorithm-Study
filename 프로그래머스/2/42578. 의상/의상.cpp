#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int>umap;
    for(auto cloth : clothes){
        if(umap.find(cloth[1]) == umap.end())umap[cloth[1]] = 1;
        else umap[cloth[1]]++;
    }
    
    for(auto u : umap){
        answer *= u.second + 1;  
    }
    
    return answer - 1;
}