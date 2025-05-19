// 모든 칸에 대해서 BFS를 돌리면서 밖으로 새나가는 지 판단한다.
// 밖으로 새나갈 경우(deque에서 pop된 좌표가 0의 값을 가진 경우) water_amount에 0으로 저장
// 밖으로 새지 않은 경우 테두리 중 최소 값에서 빼준 값을 저장한다.
// 흠
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <tuple>
using namespace std;

int n, m;
bool visit[51][51];
bool vvisit[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<vector<int>> SwimmingPool;
vector<vector<int>> WaterAmount;

void CheckValid(int x, int y){
    memset(visit, false, sizeof(visit));
    deque<pair<int, int>> dq; vector<pair<int, int>> subvec;
    dq.push_back({x, y}); subvec.push_back({x, y});
    visit[x][y] = true;
    int val = SwimmingPool[x][y];
    bool flowoutside = false;
    
    while(!dq.empty()){
        int px = dq.front().first;
        int py = dq.front().second;
        if(px == 0 || py == 0 || px == n - 1 || py == m - 1){
            flowoutside = true;
            break;
        }
        dq.pop_front();
        for(int i = 0; i < 4; i++){
            int nx = px + dx[i];
            int ny = py + dy[i];
            if((0 <= nx && nx < n) && (0 <= ny && ny < m) && !visit[nx][ny] && SwimmingPool[nx][ny] <= val){
                visit[nx][ny] = true;
                dq.push_back({nx, ny});
                subvec.push_back({nx, ny});
            }
        }
    }
    if(!flowoutside){
        int minwall = 1e9;
        for(pair<int, int>p : subvec){
            for(int i = 0; i < 4; i++){
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                if((0 <= nx && nx < n) && (0 <= ny && ny < m) && !visit[nx][ny]){
                    minwall = min(minwall, SwimmingPool[nx][ny]);
                }
            }   
        }
        for(pair<int, int>p : subvec){
            WaterAmount[p.first][p.second] = minwall - SwimmingPool[p.first][p.second];
            vvisit[p.first][p.second] = true;
        }
    }else{
        WaterAmount[x][y] = 0;
        vvisit[x][y] = true;
    }
    dq.clear(); subvec.clear();
}

int main(){
    cin >> n >> m;
    SwimmingPool.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            SwimmingPool[i][j] = c - '0';
        }
    }
    
    WaterAmount.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vvisit[i][j]){
                CheckValid(i, j);    
            }
        }
    }
    int total = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            total += WaterAmount[i][j];
            // cout << WaterAmount[i][j];
        }
        // cout << "\n";
    }
    cout << total;
    return 0;
}