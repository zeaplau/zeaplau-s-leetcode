/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool islower) {
        int left = 0;
        int right = int(nums.size()) - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            // 等于的情况单独处理
            else {
                ans = mid;
                // 在左边的情况
                if (islower) {
                    right = mid - 1;
                // 在右边的情况
                } else {
                    left = mid + 1;
                }
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // 找第一个下标（这个下标可能会直接找对 target 数字）
        int firstIdx = binarySearch(nums, target, true);
        // 找到最后一个位置的下标
        int secondIdx = binarySearch(nums, target, false) - 1;
        if (firstIdx <= secondIdx && secondIdx < nums.size() && nums[firstIdx] == target && nums[secondIdx] == target) {
            return vector<int>{firstIdx, secondIdx};
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end

