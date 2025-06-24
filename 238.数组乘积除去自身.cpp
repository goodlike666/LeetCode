#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.cn/problems/rotate-array/
class Solution {

public:
    vector<int> productExceptSelf1(vector<int>& nums) 
    {
        vector<int> ans;
        //for (int i = 0; i < nums.size(); ++i)
        //{
        //    ans.emplace_back(recursive(nums, i, nums.size()-1));
        //}
        //return ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0)
            {
                ans.emplace_back(recursive1(nums, nums.size() - 1,1));
            }
            else if (i == nums.size() - 1)
            {
                ans.emplace_back(recursive1(nums, nums.size() - 2,0));
            }
            else
            {
                ans.emplace_back(recursive1(nums, i-1, 0) * recursive1(nums, nums.size() - 1, i+1));
            }
        }
        return ans;
    }

    int recursive(vector<int> nums, int n , int a)
    {
        
        if (a == n)
        {
            
            if (a == 0)
            {
                return 1;
            }
            else {
                return recursive(nums, n, a - 1);
            }
        }
        else if (a == 0 && n!=0)
        {
            return nums[0];
        }
        else
        {
            return nums[a] * recursive(nums, n , a-1);
        }
    }
    //纯递归也不行超过时间限制
    int recursive1(vector<int> nums,  int a ,int n)
    {

        
        if (a == n )
        {
            return nums[n];
        }
        else
        {
            return nums[a] * recursive1(nums, a - 1,n);
        }
    }
    //for循环遍历
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());//ans[i]表示左侧乘积
        ans[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int R = 1;
        for (int i = nums.size()-1; i > -1; --i)
        {
            ans[i] = ans[i] * R;
            R = R * nums[i];
        }
        return ans;
    }
};


//int main()
//{
//    Solution s1;
//    vector<int> nums = { 1,2,3,4 };
//    vector<int> a = s1.productExceptSelf(nums);
//    cout << a[0] << endl;
//    system("pause");
//    return 0;
//}