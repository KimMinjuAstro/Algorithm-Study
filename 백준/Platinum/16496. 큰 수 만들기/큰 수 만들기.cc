#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> nums;

bool compare(string s1, string s2){
    // 0 처리
    string s1s2 = s1+s2;
    string s2s1 = s2+s1;
    if(s1s2 == s2s1){
        return false;
    }
    else if(s1s2 < s2s1){
        return false;
    }
    else{
        return true;
    }
}

string solution(vector<int> numbers) {
    vector<string> s_numbers;
    for(int nums : numbers){
        s_numbers.push_back(to_string(nums));
    }
    sort(s_numbers.begin(), s_numbers.end(), compare);
    string answer = "";
    for(string s_nums : s_numbers){
        answer += s_nums;
    }
    return answer;
}

int main(){
    int n;
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    string s = solution(nums);
    if(s[0] == '0'){
        cout << "0";
    }
    else{
        cout << s;   
    }
    
    return 0;
}