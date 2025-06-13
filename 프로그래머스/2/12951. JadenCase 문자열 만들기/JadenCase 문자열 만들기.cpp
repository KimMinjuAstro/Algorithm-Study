#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int len = s.length();
    
    for(int i = 0; i < len; i++){
        string word = "";
        while(s[i] != ' ' && i < len){
            if(i == 0 || s[i-1] == ' '){
                if(s[i]>='a' && s[i]<='z')word += s[i] - 32;
                else word += s[i];
            }
            else{
                if(s[i]>='A' && s[i]<='Z')word += s[i] + 32;
                else word += s[i];
            }
            i++;
        }
        answer += word + ' ';
    }
    
    if(s[len-1]!=' ')answer = answer.substr(0, answer.length()-1);
    return answer;
}