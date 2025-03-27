#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N;
int balls[10001];
int bombBalls[10001];
void init() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
}
void input() {
   cin >> N;
   for (int i = 0; i < N; i++)
   {
      cin >> balls[i];
   }
}

int rightCheck(int idx, int curColor, int* arr) {
   int cnt = 0;
   int t = 1;
   while (1) {
      if (idx + t >= N)break;
      if (arr[idx + t] == curColor) {
         cnt++;
         t++;
      }
      else if (arr[idx + t] == 0) {
         t++;
         continue;
      }
      else break;
   }
   return cnt;
}

int leftCheck(int idx, int curColor, int* arr) {
   int cnt = 0;
   int t = 1;
   while (1) {
      if (idx - t < 0) break;
      if (arr[idx - t] == curColor) {
         cnt++;
         t++;
      }
      else if (arr[idx - t] == 0) {
         t++;
         continue;
      }
      else break;
   }
   return cnt;
}

int Bomb(int idx, int newColor, int oriColor) {
   int firstCheck = rightCheck(idx, newColor, balls) + leftCheck(idx, newColor, balls);
   if (firstCheck < 3)return N;

   memcpy(&bombBalls, &balls, sizeof(int) * N);
   int remainBalls = N;
   int leftIdx = idx;
   int rightIdx = idx;
   int curIdx = idx;
   int leftColor = bombBalls[leftIdx];
   int rightColor = bombBalls[rightIdx];
   int curColor = bombBalls[curIdx];
   while (1) {
      int right = rightCheck(rightIdx, curColor, bombBalls);
      int left = leftCheck(leftIdx, curColor, bombBalls);

      if (right + left >= 2) {
         if (rightIdx == leftIdx) remainBalls -= (right + left + 1);
         else remainBalls -= (right + left + 2);
         bombBalls[leftIdx] = 0;
         bombBalls[rightIdx] = 0;
         int t = 1;
         while (t <= left) {
            if (bombBalls[leftIdx - t] == 0 && leftIdx - t >= 0) { left++; }
            bombBalls[leftIdx - t] = 0;
            t++;
         }

         int k = 1;
         while (k <= right) {
            if (bombBalls[rightIdx + k] == 0 && rightIdx + k < N) { right++; }
            bombBalls[rightIdx + k] = 0;
            k++;
         }

         leftIdx = max(0, leftIdx - left - 1);
         rightIdx = min(N, rightIdx + right + 1);

         leftColor = bombBalls[leftIdx];
         rightColor = bombBalls[rightIdx];
         if (leftColor != rightColor)return remainBalls;
         curColor = leftColor;
      }
      else {
         return remainBalls;
      }
   }
   return remainBalls;
}
void solution() {
   int minBall = 21e8;
   for (int i = 0; i < N; i++)
   {
      int curBall = balls[i];
      for (int j = 1; j <= 3; j++)
      {
         if (curBall == j)continue;
         balls[i] = j;
         minBall = min(Bomb(i, j, curBall), minBall);
         balls[i] = curBall;
         int de = -1;
      }
   }
   cout << minBall;
}
int main() {
   init();
   input();
   solution();
}