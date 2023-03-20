#
# @lc app=leetcode.cn id=43 lang=python3
#
# [43] 字符串相乘
#

# @lc code=start
class Solution:
    def calculate(self, nums: str, digit: str, idx: int) -> int:
        res = 0
        nums_len = len(nums) - 1
        ord_zero = ord("0")
        digit_ = ord(digit) - ord_zero
        for i in range(len(nums)):
            # selected_num * 10 ** nums_len + post_num * idx ** 10
            num = (ord(nums[i]) - ord_zero) * 10 ** nums_len * (10 ** idx * digit_)
            nums_len -= 1
            res += num
        return res

    def multiply(self, num1: str, num2: str) -> str:
        num2_len = len(num2)
        results = [self.calculate(nums=num1, digit=digit, idx=num2_len - idx - 1) for idx, digit in enumerate(num2)]
        multi_res = sum(results)
        return str(multi_res)

# @lc code=end

