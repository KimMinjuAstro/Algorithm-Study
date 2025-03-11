#include<iostream>
#include<vector>
using namespace std;
long long len[100];
int M;

// 길이 계산하는 함수
long long Recursion(int n) {
   if (n == 1)return 5;
   if (n == 2)return 13;
   if (len[n] != 0)return len[n];
   return len[n] = Recursion(n - 1) + Recursion(n - 2) + 1;
}

char findChar(int n, long long M) {
   if (n == 1)return "Messi"[M - 1];
   if (n == 2)return "Messi Gimossi"[M - 1];

   long long len = Recursion(n - 1);
   if (M <= len) {
      return findChar(n - 1, M);
   }
   else if (M == len + 1) {
      return ' ';
   }
   else {
      return findChar(n - 2, M - len - 1);
   }
}

int main() {
   cin >> M;

   int n = 1;
   while (Recursion(n) < M)n++;

   char result = findChar(n, M);

   if (result == ' ') {
      cout << "Messi Messi Gimossi";
   }
   else {
      cout << result;
   }

   return 0;
}