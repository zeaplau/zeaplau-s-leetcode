/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        if (!nums.size()) {
            return -1;
        }
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }

        // 开始二分
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 关键在在于反转这个点跟 mid 的比较
            // mid 不在反转
            if (nums[mid] >= nums[0]) {
                // 如果 target 比 idx_0 要大，并且比中间的值要小，说明它在左边，左边这一侧是有序的
                if (target >= nums[0] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            // mid 在反转
            } else {
                // 如果 target 的值比 mid 还要大，并且 idx_n 大于 target，说明他在右边，右边这一侧是有序的
                if (target > nums[mid] && nums[int(nums.size()) - 1] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

