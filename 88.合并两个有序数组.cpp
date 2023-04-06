/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int curPos = nums1.size() - 1;
        int idx = m - 1;
        int iidx = n - 1;

        while (idx >= 0 || iidx >= 0) {
            // nums1 用完了，那就只用把 nums2 的丢进去
            if (idx < 0) {
                nums1[curPos] = nums2[iidx];
                iidx = iidx - 1;
            // nums2 用完了，那就只用把 nums1 丢进去
            } else if (iidx < 0) {
                nums1[curPos] = nums1[idx];
                idx = idx - 1;
            // 如果此时 nums1 的数比 nums2 的数还要大，那就把 nums1 的
            // 数放进去
            } else if (nums1[idx] > nums2[iidx]) {
                nums1[curPos] = nums1[idx];
                idx = idx - 1;
            // 如果此时 nums1 的数比 nums2 的数还要大，那就把 nums2 的
            // 数放进去
            } else {
                nums1[curPos] = nums2[iidx];
                iidx = iidx - 1;
            }
            curPos = curPos - 1;
            // for (auto &c : nums1) {
            //     cout << c << " ";
            // }
            // cout << endl;
        }
    }
};
// @lc code=end

