/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <vector>

using namespace std;


class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = int(nums.size()) - 1;
        int ans = 0;
        // 二分
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                ans = mid;
                break;
            }
            if (nums[mid] < target) {
                left = mid + 1;
                ans = left;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return ans;
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target);
    }
};
// @lc code=end

