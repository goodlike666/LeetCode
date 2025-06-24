#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {

public:
    //排序一一比较只能针对全正整数
    int firstMissingPositive1(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int curr = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - curr == 1 || nums[i] - curr == 0)
            {
                curr = nums[i];
            }
            else
            {
                return curr + 1;
            }
        }
        if (curr == nums[nums.size() - 1])
        {
            return curr + 1;
        }

    }
    int firstMissingPositive(vector<int>& nums) {
        set<int> s1 ;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]> 0)
            {
                s1.insert(nums[i]);
            }
            else{}
        }
        int curr = 0;
        if (!s1.empty()) {
         
            if (*s1.begin() != 1)
            {
                return 1;
            }
        }
        else {
            return 1;
        }
        
        for (auto it = s1.begin(); it != s1.end(); ++it)
        {
            if (*it - curr == 1 )
            {
                curr = *it;
            }
            else
            {
                return curr + 1;
            }
        }
        return curr + 1;
    }
};

int main()
{
    Solution s1;
    vector<int> nums = { 1,2,3,4 };
    
    //cout << a[0] << endl;
    system("pause");
    return 0;
}