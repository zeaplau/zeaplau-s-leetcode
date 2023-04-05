#
# @lc app=leetcode.cn id=71 lang=python3
#
# [71] 简化路径
#

# @lc code=start
class Solution:
    def simplifyPath(self, path: str) -> str:
        path_names = path.split("/")
        stack = []
        for name in path_names:
            if name == "..":
                if len(stack) > 0:
                    stack.pop()
            elif name and name != ".":
                stack.append(name)
        return "/" + "/".join(stack)
# @lc code=end

