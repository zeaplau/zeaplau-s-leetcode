/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> fp;
        int slashFlag = 0;
        string tmp_fp = "";
        // split function
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (tmp_fp != "") {
                    fp.push_back(tmp_fp);
                    tmp_fp = "";
                    continue;
                }
            }
            tmp_fp += path[i];
        }

        int n = fp.size();
        vector<string> final_paths;
        // if meet '.', do noting
        // if meet '..'. pop if stack contains more than 1 element
        for (int i = 0; i < n; i++) {
            if (fp[i] == ".") {
                continue;
            }
            if (fp[i] == "..") {
                if (final_paths.size() == 0) {
                    continue;
                } else {
                    final_paths.pop_back();
                }
            }
            final_paths.push_back(fp[i]);
        }

        // join
        string res = "";
        if (final_paths.size() == 0) {
            return "/";
        } else {
            for (int i = 0; i < final_paths.size(); i++) {
                res += "/" + final_paths[i];
            }
        }
        return res;
    }
};
// @lc code=end

