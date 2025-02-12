#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int N;    // 무게 추 개수
int weight[10];    // 무게 추들의 무게
int leftWeight[10];
int rightWeight[10];
int weightSum;    // 무게 추 총합
int cnt;
int used[10];
int factorials[11];

void factorial() {
   factorials[0] = 1;
   for (int i = 1; i <= 10; i++)
   {
      factorials[i] = factorials[i - 1] * i;
   }
}

void run(int level, int reamin, int leftSum, int rightSum) {
   //int leftSum = 0;
   //for (int i = 0; i < N; i++)
   //{
   //   leftSum += leftWeight[i];
   //}
   //int rightSum = 0;
   //for (int i = 0; i < N; i++)
   //{
   //   rightSum += rightWeight[i];
   //}
   if (leftSum < rightSum) {  // 왼쪽이 작으면 return
      return;
   }

   // 왼쪽합과 오른쪽 합의 차이가 남은 무게들의 합보다 크면
   // ex. 15, 6, 5 -> 5를 다 오른쪽에 놓던 왼쪽에 놓던 상관 없음
   if (leftSum - rightSum > reamin) 
   {
      cnt += pow(2, N - level) * factorials[N - level];
      return;
   }

   if (level == N) {
      cnt++;
      return;
   }

   for (int i = 0; i < N; i++)
   {
      if (used[i] == 0) {
         used[i] = 1;

         //leftWeight[level] = weight[i];
         //rightWeight[level] = 0;

         run(level + 1, reamin - weight[i], leftSum+weight[i], rightSum);

         //leftWeight[level] = 0;
         //rightWeight[level] = weight[i];

         run(level + 1, reamin - weight[i], leftSum, rightSum+weight[i]);

         //leftWeight[level] = 0;
         //rightWeight[level] = 0;

         used[i] = 0;
      }
   }
}
void init() {
   weightSum = 0;
   cnt = 0;
   memset(weight, 0, sizeof(weight));
   memset(used, 0, sizeof(used));
   //memset(leftWeight, 0, sizeof(leftWeight));
   //memset(rightWeight, 0, sizeof(rightWeight));
   factorial();
}
void input() {
   cin >> N;
   for (int j = 0; j < N; j++)
   {
      cin >> weight[j];
      weightSum += weight[j];
   }
}
void solution() {
   run(0, weightSum, 0, 0);
   //cout << cnt;
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int TC;
   cin >> TC;
   for (int i = 1; i <= TC; i++)
   {
      init();
      input();
      solution();
      cout << "#" << i << " " << cnt << "\n";
   }
}