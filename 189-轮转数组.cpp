#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.cn/problems/rotate-array/
class Solution {

public:
    //k为轮转值可为大数
    void rotate1(vector<int>& nums, int k) {
        int k1 = k % nums.size();
        vector<int> nums_k;
        for (int i = nums.size() - k1; i < nums.size(); ++i)
        {
            nums_k.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size() - k1; ++i)
        {
            nums_k.push_back(nums[i]);
        }
        nums.assign(nums_k.begin(), nums_k.end());

    }
    void rotate(vector<int>& nums, int k) {
        int k1 = k % nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k1-1);
        reverse(nums, k1, nums.size()-1);
    }
    void reverse(vector<int>& nums, int start ,int end) {
        while (start < end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }

    }
};


int main()
{
    Solution s1;
    vector<int> nums = { 1,2,3,4,5,6,7 };
    int k = 3;
    //cout << s1.merge(intervals) << endl;
    system("pause");
    return 0;
}