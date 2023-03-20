/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()) ;
        int best = 1e7;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    return sum;
                }
                // update value
                if (abs(sum - target) < abs(best - target)) {
                    best =sum;
                }
                if (sum > target) {
                    int right_ = right - 1;
                    while (left < right_ && nums[right_] == nums[right]) {
                        right_--;
                    }
                    right = right_;
                } else {
                    int left_ = left + 1;
                    while (left_ < right && nums[left_] == nums[left]) {
                        left_++;
                    }
                    left = left_;
                }
            }
        }
        return best;
    }
};
// @lc code=end

