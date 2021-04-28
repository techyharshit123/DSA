#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string s)
{
    stack<int>st;
    int ans=0;
    int n=s.length();
    
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'  and s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            if(s[i]=='+')
            ans=(a+b),st.push((a+b));
            else if(s[i]=='-')
            ans=(a-b),st.push((a-b));
            else if(s[i]=='*')
            ans=(a*b),st.push((a*b));
            else if(s[i]=='/')
            ans=(a/b),st.push((a/b));
            else if(s[i]=='^')
            ans=(int)(pow(a,b)+0.5),st.push((int)(pow(a,b)+0.5));
            
            // cout<<ans<<" ";
        }
    }
    
    return ans;
}

int main()
{
    string s;
    cin>>s;

    cout<<evaluatePostfix(s)<<endl;
}