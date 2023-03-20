/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 4; i++) {
            // 保证 a 不重复
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j <= nums.size() - 3; j++) {
                // 保证 b 不重复
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if ((long) nums[i] + nums[j] + nums[left] + nums[right] == target) {
                        res.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        // 跳过重复的数字
                        int left_ = left + 1;
                        while (left_ < right && nums[left_] == nums[left]) {
                            left_++;
                        }
                        left = left_;
                        int right_ = right - 1;
                        while (left < right_ && nums[right_] == nums[right]) {
                            right_--;
                        }
                        right = right_;
                    }
                    if ((long) nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        left++;
                    }
                    if ((long) nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

