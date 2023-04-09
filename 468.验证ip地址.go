/*
 * @lc app=leetcode.cn id=468 lang=golang
 *
 * [468] 验证IP地址
 */

// @lc code=start
package main

import (
	"strconv"
	"strings"
)

func validIPAddress(queryIP string) string {
	// 依照 `.` 进行分裂，如果分割后有 4 段，那就说明有可能是 ipv4
	if sp := strings.Split(queryIP, "."); len(sp) == 4 {
		for _, s := range sp {
			// 如果在后面三个段出现了一个前导 0，
			// 那就是寄
			if len(s) > 1 && s[0] == '0' {
				return "Neither"
			}
			// 如果超过了 255，那就是寄
			if v, err := strconv.Atoi(s); err != nil || v > 255 {
				return "Neither"
			}
		}
		return "IPv4"
	}

	// 按照 `:` 进行分裂，如果分裂后有 8 段，那么说明可能是 ipv6
	if sp := strings.Split(queryIP, ":"); len(sp) == 8 {
		for _, s := range sp {
			// 如果包含的字符超过了 4 位
			if len(s) > 4 {
				return "Neither"
			}
			// 进行解析，如果这个字符能够按照 16 进制成功解析
			if _, err := strconv.ParseUint(s, 16, 64); err != nil {
				return "Neither"
			}
		}
		return "IPv6"
	}
	return "Neither"
}

// @lc code=end
