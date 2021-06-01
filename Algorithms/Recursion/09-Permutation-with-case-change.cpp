//Harshit

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
    

    output1.push_back(input[0]); //pehle output m same case ka letter rakho --> choice1

    //doosre output m doosre case waala choice hoga --> choice2
    if(input[0]>='a' and input[0]<='z')
    output2.push_back(toupper(input[0]));
    else if(input[0]>='A' and input[0]<='Z')
    output2.push_back(tolower(input[0]));
    
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
    solve(input,output);
    sort(v.begin(),v.end());

    for(auto x:v)
        cout<<x<<endl;
        
} 