#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int zero = 0;

    string temp = s;
    while(temp != "1"){
        cnt++; 
        
        string res = "";
        for(int i = 0; i < temp.length(); i++){
            if(temp[i]=='0')zero++;
            else res+='1';
        }
        //cout<<"res : "<<res<<"\n";
        int len = res.length();

        temp.clear();
        temp += to_string(len & 1);
        int tempcnt = 0;
        
        while(len > 0){
            temp += to_string((len >> 1) & 1);
            len = len >> 1;
            tempcnt++;
        }
        
        temp = temp.substr(0, temp.length()-1);
    }
    answer.push_back(cnt);
    answer.push_back(zero);
    return answer;
}