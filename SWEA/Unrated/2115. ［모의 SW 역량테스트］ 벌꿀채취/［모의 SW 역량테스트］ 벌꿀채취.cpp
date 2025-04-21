#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, c;
int ans;
int map[11][11];
int square[11][11];
int ydir[] = { -1,0,1,0 };
int xdir[] = { 0,1,0,-1 };
int cost[11][11];
void init() {
   memset(map, 0, sizeof(map));
   memset(square, 0, sizeof(square));
   memset(cost, 0, sizeof(cost));
}
void input() {
   cin >> n >> m >> c;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cin >> map[i][j];
         square[i][j] = map[i][j] * map[i][j];
      }
   }
}

vector<int>v;
void dfs(int y, int x, int now, int sum, int profit) {
   if (now >= x + m) {
      cost[y][x] = max(cost[y][x], profit);
      //for (int i = 0; i < v.size(); i++)
      //{
      //   cout << v[i] << " ";
      //}cout << cost[y][x] << "\n";
      return;
   }
   
   for (int pick = 0; pick <= 1; pick++)
   {
      int value = map[y][now] * pick;
      if (sum + value > c)continue;
      if (now > n - 1)continue;
      //v.push_back(value);
      dfs(y, x, now + 1, sum + value, profit + square[y][now] * pick);
      //v.pop_back();
   }
}


void solution() {
   int maxSum = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         dfs(i, j, j, 0, 0);
      }
   }
   
   for (int fy = 0; fy < n; fy++)
   {
      for (int fx = 0; fx < n; fx++)
      {
         for (int sy = fy; sy < n; sy++)
         {
            for (int sx = 0; sx < n; sx++)
            {
               if (sy == fy && sx - fx < m)continue;
               //cout << fy << "," << fx << " " << sy << "," << sx << " : " << cost[fy][fx] + cost[sy][sx] << "\n";
               if (maxSum < cost[fy][fx] + cost[sy][sx]) {
                  maxSum = max(maxSum, cost[fy][fx] + cost[sy][sx]);
               }
            }
         }
      }
   }

   ans = maxSum;
}
int main() {
   int TC;
   cin >> TC;
   for (int i = 1; i <= TC; i++)
   {
      init();
      input();
      solution();
      cout << "#" << i << " " << ans << "\n";
   }
}
