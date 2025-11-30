#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;

struct GenreCnt{
    string genre;
    int cnt;

    bool operator<(const GenreCnt right) const{
        return cnt < right.cnt; 
    }
};

struct Song{
    int play;
    int num;

    bool operator<(const Song right) const{
        if(play != right.play) return play < right.play; 
        return num > right.num; 
    }    
};
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int>genremap;
    unordered_map<string, priority_queue<Song>>song_db;
    
    for(int i = 0; i < genres.size(); i++){
        genremap[genres[i]] += plays[i];
        song_db[genres[i]].push({plays[i], i});
    }
    
    priority_queue<GenreCnt> gpq;
    for(auto g : genremap){
        gpq.push({g.first, g.second});
    }

    while(!gpq.empty()){
        GenreCnt cur = gpq.top();
        gpq.pop();
        
        string g_name = cur.genre;

        for(int k=0; k<2; k++){
            if(song_db[g_name].empty()) break; 
            
            Song s = song_db[g_name].top();
            song_db[g_name].pop();
            answer.push_back(s.num);
        }
    }
    
    return answer;
}