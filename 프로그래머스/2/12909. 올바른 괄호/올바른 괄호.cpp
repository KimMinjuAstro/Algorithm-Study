#include<string>
#include <iostream>
#include <stack>

using namespace std;
stack<char>st;

bool solution(string s)
{
    bool answer = true;

    for(int i = 0; i < s.length(); i++){
        if(st.empty() && s[i]==')')
            return false;
        if(s[i]=='(')
            st.push(s[i]);
        else{
            if(st.top()=='(')
                st.pop();
            else
                return false;
        }
    }

    if(st.empty())return true;
    else return false;
}