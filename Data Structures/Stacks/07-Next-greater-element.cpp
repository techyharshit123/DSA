//Harshit
 
#include "bits/stdc++.h"
using namespace std;

//O(n) solution    we can easily write a O(n^2) solution using two nested loops
std::vector<int> getSpan(std::vector<int> a,int n)
{	
 	reverse(a.begin(),a.end());
	stack<int>s;

	std::vector<int> ans;

	ans.push_back(-1);
	s.push(a[0]);

	for(int i=1;i<n;i++)
	{
		while(s.size()!=0 and s.top()<=a[i])
		{
			s.pop();
		}

		int span=1;
		if(s.size()==0)
		{
			span=-1;
		}
		else
		{
			span=s.top();
		}

		s.push(a[i]);
		ans.push_back(span);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main() {
    std::vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    std::vector<int> v1 = getSpan(v, v.size());
    for(auto t : v1)
        cout << t << " ";
    cout << "\n";
}
