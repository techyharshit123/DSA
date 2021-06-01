//Harshit
//This problem is solved using IBH method
//IMPORTANT
#include "bits/stdc++.h"
using namespace std;
// *******************************************************************************
//                                     MAIN CODE
// *******************************************************************************


void solve(int sword,int k,vector<int>&person)
{
    if(person.size()==1)
    {
        cout<<person[0];
        return;
    }

    sword=(sword+k)%person.size(); //sword ko us index pr pahuchao
    person.erase(person.begin()+sword);//us aadmi ko maar do
    solve(sword,k,person);//recursively bache logo m sword ko pass krwao
    return;
}
int main()
{
    int n,k;
    cin>>n>>k;
    // k is number of person to be skipped
    vector<int>v;
    for(int i=1;i<n+1;i++)
        v.push_back(i);

    k--;
    int index=0;

    solve(index,k,v);
} 