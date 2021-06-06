#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKArrays(vector<vector<int> > arr) {
    //Complete this function
    vector<int> res;
    priority_queue<node, vector<node>, greater<node>>pq;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }

    while (!pq.empty())
    {
        node current = pq.top();
        pq.pop();

        int element = current.first;
        int xidx = current.second.first;
        int yidx = current.second.second;
        res.push_back(element);
        yidx++;

        if (yidx < arr[xidx].size())
        {
            pq.push({arr[xidx][yidx], {xidx, yidx}});
        }

    }

    return res;
}

int main()
{
    vector<vector<int>>arr = {{2, 5, 6, 8},
        {3, 6, 776, 888, 900},
        {2, 234, 454}
    };

    vector <int> result = mergeKArrays(arr);
    for (auto x : result)
        cout << x << " ";
}