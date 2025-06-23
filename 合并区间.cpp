#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//合并区间:56
class Solution {

public:
    //右端点排序不行，最后一个区间会出现问题
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
            });
        if (intervals.size() == 1)
        {
            return intervals;
        }
        vector<vector<int>> ans;
        vector<int> curr = intervals[0];
        //ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] >= curr[0] && intervals[i][0] <= curr[1]) {
                curr[1] = intervals[i][1];
                if (i == intervals.size() - 1) {
                    ans.push_back(curr);
                }
            }
            else if(intervals[i][0] < curr[0])
            {
                curr[0] = intervals[i][0];
                curr[1] = intervals[i][1];
                if (i == intervals.size() - 1) {
                    ans.push_back(curr);
                }
            }
            else
            {
                ans.push_back(curr);
                curr[0] = intervals[i][0];
                curr[1] = intervals[i][1];
                if (i == intervals.size() - 1) {
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
            });
        vector<int> curr = intervals[0];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] >= curr[0] && intervals[i][1] <= curr[1])
            {
                continue;
            }
            else if (intervals[i][1] >= curr[1] && intervals[i][0] <= curr[1])
            {
                curr[1] = intervals[i][1];
            }
            else
            {
                ans.push_back(curr);
                curr[0] = intervals[i][0];
                curr[1] = intervals[i][1];
            }
        }
        ans.push_back(curr);

        return ans;
    }
};


int main()
{
    Solution s1;
    vector<vector<int>> intervals = { {1, 3},{2, 6},{8, 10},{15, 18} };
    //cout << s1.merge(intervals) << endl;
    system("pause");
    return 0;
}