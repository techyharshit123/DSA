//Harshit
 
#include "bits/stdc++.h"
using namespace std;
// *******************************************************************************
//                                     MAIN CODE
// *******************************************************************************


void subsets(string input,string output)
{
    if(input=="")
    {
        cout<<output<<endl;
        return;
    }

    string output1=output;
    string output2=output;

    output2.push_back(input[0]);

    input.erase(input.begin());

    subsets(input,output1);
    subsets(input,output2);
    return;
}

int main()
{
    string input;
    cin>>input;
    string output="";
    subsets(input,output);
}