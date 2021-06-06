#include<bits/stdc++.h>
using namespace std;


int main()
{
    int data; //input stream
    cin >> data;

    priority_queue<int>leftheap; //max heap
    priority_queue<int, vector<int>, greater<int>>rightheap; //min heap

    float median = data;

    leftheap.push(data);

    cin >> data;
    while (data != 1)
    {
        // if size of leftheap(maxheap) is greater than size of rightheap(minheap)
        if (leftheap.size() > rightheap.size())
        {
            if (data >= median)
            {
                rightheap.push(data);
            }
            else
            {
                int lefttop = leftheap.top();
                leftheap.pop();
                leftheap.push(data);
                rightheap.push(lefttop);

            }
            median = (leftheap.top() + rightheap.top()) / 2.0;
        }
        else if (leftheap.size() == rightheap.size())
        {
            if (data >= median)
            {
                rightheap.push(data);
                median = rightheap.top();
            }
            else
            {
                leftheap.push(data);
                median = leftheap.top();
            }
        }
        else
        {
            if (data >= median)
            {
                int righttop = rightheap.top();
                rightheap.pop();
                leftheap.push(righttop);
                rightheap.push(data);
            }
            else
            {
                leftheap.push(data);
            }

            median = (leftheap.top() + rightheap.top()) / 2.0;
        }

        cout << median << endl;
        cin >> data;
    }
}