#
# @lc app=leetcode.cn id=166 lang=python3
#
# [166] 分数到小数
#

# @lc code=start
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        a = numerator
        b = denominator
        res = list()
        appear_map = dict()

        # 如果能够整除，那么直接返回
        if a % b == 0:
            return str(a % b)
        
        # 如果两者的结果是负数，那么先添加 '-'
        if a * b < 0:
            res.append("-")

        a, b = abs(a), abs(b)
        # 小数点前面的
        res.append(str(a // b) + ".")
        
        while a != 0:
            appear_map[a] = len(res)
            a *= 10
            res.append(a / b)
            a %= b
            # 如果出现了相同的余数
            if a in appear_map.keys():
                return_format = "{}({})"
                length = appear_map.get(a)
                return return_format.format(res[:length], res[length:])
        return "".join(res)


# @lc code=end

