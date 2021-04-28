#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*' or c=='/')
		return 2;
	else if(c=='+' or c=='-')
		return 1;
	else
		return -1;
}
string infixtopostfix(string s)
{
	string res="";
	stack<char>st;

	int n=s.length();

	for(int i=0;i<n;i++)
	{
		if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z') or (s[i]>='0' and s[i]<='9'))
			res+=s[i];
		else if(s[i]=='(')
			st.push(s[i]);
		else if(s[i]==')')
		{
			 while(!st.empty() and st.top()!='(')
			 {
			 	res+=st.top();
			 	st.pop();
			 }
			 st.pop();
		}
		else
		{
			while(!st.empty() and prec(s[i])<=prec(st.top()))
			{
				res+=st.top();
				st.pop();
			}

			st.push(s[i]);
		}
	}

	while(!st.empty())
	{
		res+=st.top();
		st.pop();
	}
	return res;
}
int main()
{
	string s;
	cin>>s;

	cout<<infixtopostfix(s)<<endl;
}