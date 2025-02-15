// 이용하는 순서가 중요하지 않고 몇 번 이용을 했는가 조합을 뽑아내야 하기 때문에 백트랙킹

// 기저 조건 == 언제 끝나는가?
//        1년동안의 사용계획 12개월치의 정보를 확인하면 끝
//    

// 재귀 기본 : 어떤 선택을 할 수 있는가
//        1. 아무것도 안 한다 (수영 X)
//        2. 하루
//        3. 1달
//        4. 3달
//        5. 1년 <- 재귀 안 해도 되니까 제외
//        가장 저렴한 것을 선택
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int year[13];    // 1년 이용계획
int day1;
int month1;
int month3;
int year1;
int sum;
int answer;
int path[10];

void func(int now)
{
   // 12개월 다 확인하면 종료
   if (now > 12)
   {
      answer = min(answer, sum);
      return;
   }

   // 원래 for문으로 돌렸던 것들을 쪼개서 생각하기. 각각의 케이스에 대해서 연산 처리

   // 아무것도 안함
   if (year[now] == 0)    // 해당 달에 이용 계획이 없으므로 패스
   {
      func(now + 1);
   }

   // 하루 선택 시 비용 계산
   sum += day1 * year[now];
   func(now + 1);
   sum -= day1 * year[now];

   // 1달 선택
   sum += month1;
   func(now + 1);
   sum -= month1;

   // 3달 선택
   sum += month3;
   func(now + 3);
   sum -= month3;
}

void init()    // 초기화
{
   answer = 21e8;    // int 최댓값. 우린 최솟값을 구할 거니까
   memset(year, 0, sizeof(year));
   // 입력 받는 배열이 TC마다 초기화되어야 하니까 memset 사용
   // memset(배열 이름, 초기화 하려 하는 값, 해당하는 사이즈)
   sum = 0;
}

void input()    // 입력 받기
{
   cin >> day1 >> month1 >> month3 >> year1;
   for (int i = 1; i <= 12; ++i)
   {
      cin >> year[i];
   }
}

void solution()    // 문제 해결
{
   func(1);        //    시작하는 건 1월부터
   answer = min(answer, year1);
}

int main()
{
   int T;
   cin >> T;

   for (int tc = 1; tc <= T; ++tc)
   {
      init();
      input();
      solution();
      cout << "#" << tc << " " << answer << "\n";
   }
}