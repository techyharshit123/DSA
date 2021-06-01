//Harshit

#include "bits/stdc++.h"
using namespace std;
// *******************************************************************************
//                                     MAIN CODE
// *******************************************************************************


vector<string>ans;
void solve(int open,int close,string output)
{
    if(open==0 and close==0)
    {
        ans.push_back(output);
        return;
    }
    if(open!=0) //we always have a opening bracket choice if it's count is greater than 0 (deduced after drawing the recursive tree)
    {
        string output1=output;
        output1.push_back('(');
        solve(open-1,close,output1);
    }
    if(close>open) //By observation skill, on observing the recursive tree we get to know that only at the point where no. of closing bracket > no. of opening bracket we have a choice to insert the closing bracket
    {
        string output2=output;
        output2.push_back(')');
        solve(open,close-1,output2);
    }
}

//simple implementation by me
void solve2(int open,int close,string output)
{
    if(open==0 and close==0)
    {
        ans.push_back(output);
        return;
    }
    if(open==0)
    {
        string output1=output;
        output1.push_back(')');
        solve(open,close-1,output1);
        return;
    }
    else if(open==close)
    {
        string output1=output;
        output1.push_back('(');
        solve(open-1,close,output1);
        return;
    }
    else
    {
        string output1=output;
        string output2=output;
        output1.push_back('(');
        output2.push_back(')');
        solve(open-1,close,output1);
        solve(open,close-1,output2);
        return;
    }
}
int main()
{
    int n;
    cin>>n;
    int open=n,close=n;
    string output="";
    solve(open,close,output);
    for(auto x:ans)
        cout<<x<<endl;
        
} 