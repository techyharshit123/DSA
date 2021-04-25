//Harshit
 
#include "bits/stdc++.h"
using namespace std;

std::vector<int> getSpan(std::vector<int> a,int n)
{
	stack<int>s;

	std::vector<int> ans;

	ans.push_back(1);
	s.push(0);

	for(int i=1;i<n;i++)
	{
		while(s.size()!=0 and a[s.top()]<=a[i])
		{
			s.pop();
		}

		int span=1;
		if(s.size()==0)
		{
			span=i+1;
		}
		else
		{
			span=i-s.top();
		}

		s.push(i);
		ans.push_back(span);
	}

	return ans;
}
int main() {
    std::vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    std::vector<int> v1 = getSpan(v, v.size());
    for(auto t : v1)
        cout << t << " ";
    cout << "\n";
}