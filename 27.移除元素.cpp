/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int head = 0;
        int tail = nums.size() - 1;
        // 注意这里的边界问题
        while (head <= tail) {
            if (nums[head] == val) {
                nums[head] = nums[tail];
                tail--;
            } else {
                head++;
            }
        }
        return head;
    }
};
// @lc code=end

