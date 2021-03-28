// Qn link--->https: //leetcode.com/problems/find-the-duplicate-number/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i])] >= 0)
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            else
                x = abs(nums[i]);
        }
        return x;
    }
};