#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

string solution(string s) {
    string answer = "";
    
    int len = s.length();
    vector<int>v;
    
    for(int i = 0; i < len; i++){
        // 양수 시작
        if(s[i]>='0' && s[i]<='9'){
            string numstr = "";
            while(s[i]!=' ' && i < len){
                numstr += s[i];
                i++;
            }
            int num = atoi(numstr.c_str());
            cout<<num<<" ";
            v.push_back(num);
            continue;
        }
        
        // 음수 시작
        else if(s[i]=='-'){
            i++;
            string numstr = "-";
            while(s[i]!=' ' && i < len){
                numstr += s[i];
                i++;
            }
            int num = atoi(numstr.c_str());
            cout<<num<<" ";
            v.push_back(num);
            continue;
        }
    }
    
    sort(v.begin(), v.end());
    answer += to_string(v[0]) + " " + to_string(v[v.size()-1]);
    return answer;
}