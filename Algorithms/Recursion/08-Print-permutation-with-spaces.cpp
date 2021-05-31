//Harshit
// returned vector should contain (A B C) (A BC) (AB C) (ABC)
#include "bits/stdc++.h"
using namespace std;
// *******************************************************************************
//                                     MAIN CODE
// *******************************************************************************


vector<string>v;
void solve(string input,string output)
{
    if(input.length()==0)
    {
        v.push_back(output);
        return;
    }
    
    string output1=output;
    string output2=output;
    
    output1.push_back(input[0]);// bina space k push krdo ---->Decision1
    output2.push_back(' '); //Space k saath push krdo ----->Decision2
    output2.push_back(input[0]);
    
    input.erase(input.begin());
    
    solve(input,output1);
    solve(input,output2);
    return;
    
}

int main()
{
    string input;
    cin>>input;
    string output="";
    output.push_back(input[0]);
    input.erase(input.begin());
    solve(input,output);
    sort(v.begin(),v.end());

    for(auto x:v)
        cout<<x<<endl;
        
}