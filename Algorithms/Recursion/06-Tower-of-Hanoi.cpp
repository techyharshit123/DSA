//Harshit
 
#include "bits/stdc++.h"
using namespace std;

// *******************************************************************************
//                                     MAIN CODE
// *******************************************************************************


// int count=0;
void towerofHanoi(int n,char source,char destination, char helper,int &count)
{
    if(n==1)
    {
        count++;
        cout<<"Move plate 1 from rod "<<source<<" to rod "<<destination<<endl;
        return;
    }

    towerofHanoi(n-1,source,helper,destination,count);
    count++;
    cout<<"Move plate "<<n<<" from rod "<<source<<" to rod "<<destination<<endl;
    towerofHanoi(n-1,helper,destination,source,count);
    return;
}
void solve()
{
    int n;
    cin>>n;
    int count=0;
    towerofHanoi(n,'s','d','h',count);
    cout<<count<<endl;
}

int main()
{
    solve();
    return 0;
}