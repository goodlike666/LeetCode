#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//最大子数组和:53
class Solution {
    
public:
    //不行用前一段减去后一段，边界不好处理
    int maxSubArray2(vector<int>& nums) {
        int sum = 0;
        vector<int> pren;
        if (nums.size() == 1)
        {
            return nums[0];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            pren.emplace_back(Sum(nums, 0, i));
        }
        int pre_max = *(max_element(pren.begin(), pren.end()));
        int pre_min =  * (min_element(pren.begin(), max_element(pren.begin(), pren.end()))) ;
        if (pre_max == nums[0])
        {
            return nums[0];
        }
        else
        {
            if (pre_min >= 0)
            {
                return pre_max;
            }
            else
            {
                return pre_max - pre_min;
            }
        }
        
      
    }
    //枚举法
    int maxSubArray1(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++) 
            {
                sum = max(sum, Sum(nums, i, j));
            }

        }
        return sum;
    }
    int Sum(vector<int>& nums ,int i ,int j)
    {
        int sum = 0;
        for (i; i <= j; ++i)
        {
            sum += nums[i];
        }
        return sum;
    }
    //自己解答
    int maxSubArray(vector<int>& nums) {
        vector<int> fn;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                fn.push_back(nums[0]);
            }
            else
            {
                fn.push_back(max(fn[i - 1]+ nums[i], nums[i]));
            }
        }
        return *(max_element(fn.begin(), fn.end()));
    }
    //官方解答
    int maxSubArray_real(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto& x : nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }


};


//int main()
//{
//    Solution s1;
//    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
//    cout << s1.maxSubArray(nums) << endl;
//    system("pause");
//    return 0;
//}