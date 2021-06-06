//print k closest elements to x
#include "bits/stdc++.h"
using namespace std;



vector<int> kclosest(int a[], int n, int k, int x)
{
    vector<int>v;

    //O(k) building a max heap
    priority_queue<pair<int, int>>pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({abs(a[i] - x), a[i]});
    }


    // O((n-k)*logk)
    for (int i = k; i < n; i++)
    {
        int top = pq.top().first;

        if (a[i] < top)
        {
            pq.pop();
            pq.push({abs(a[i] - x), a[i]});
        }
    }


    while (pq.size())
    {
        v.push_back(pq.top().second);
        pq.pop();
    }

    //to return items in sorted increasing order
    reverse(v.begin(), v.end());
    return v;
}
int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int>ans = kclosest(a, n, k, x);

    for (auto x : ans)
        cout << x << " ";


}