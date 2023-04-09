/*
 * @lc app=leetcode.cn id=93 lang=golang
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
package main

import "strconv"

const SEG_COUNT = 4

var (
	ans      []string
	segments []int
)

func dfs(s string, segId, segStart int) {
	// 如果遍历到第四个 ip 段同时，还到了最后的字符
	if segId == SEG_COUNT {
		if segStart == len(s) {
			ipAddr := ""
			// 遍历每个 segment，并且将他们拼接 "."
			for i := 0; i < SEG_COUNT; i++ {
				ipAddr += strconv.Itoa(segments[i])
				// 拼接
				if i != SEG_COUNT-1 {
					ipAddr += "."
				}
			}
			// 拼接完毕加入到答案里面
			ans = append(ans, ipAddr)
		}
		// debug：漏了这个，在这里已经处理好了
		return
	}

	// 到达最后一个字符，但是没有塞满 4 个字段
	if segStart == len(s) {
		return
	}

	// 如果存在前导零，那么这个段只能存在一个数字
	if s[segStart] == '0' {
		segments[segId] = 0
		dfs(s, segId+1, segStart+1)
	}

	// 从 segStart 这个位置开始遍历
	addr := 0
	for segEnd := segStart; segEnd < len(s); segEnd++ {
		addr = addr*10 + int(s[segEnd]-'0')
		// 如果这个 addr 符合单个字段的范围，那就继续
		if addr > 0 && addr <= 0xFF {
			segments[segId] = addr
			dfs(s, segId+1, segEnd+1)
		} else {
			break
		}
	}
}

func restoreIpAddresses(s string) []string {
	segments = make([]int, SEG_COUNT)
	ans = []string{}
	dfs(s, 0, 0)
	return ans
}

// @lc code=end
