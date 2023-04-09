/*
 * @lc app=leetcode.cn id=92 lang=golang
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
package main

// type ListNode struct {
// 	Val  int
// 	Next *ListNode
// }

func reverseList(node *ListNode) {
	var pre *ListNode
	cur := node
	for cur != nil {
		// 需要注意的是这一个，用个暂时的变量保存
		next := cur.Next
		// 因为要反转，所以要指到前面那个
		cur.Next = pre
		// 指完了，就将现在这个节点变为之前的节点
		pre = cur
		// 把下一个节点作为当前的处理
		cur = next
	}
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	dummy := &ListNode{Next: head}
	fast := dummy
	prev := dummy

	// 移动前后指针
	// 慢指针的前一个指针
	for i := 0; i < left-1; i++ {
		prev = prev.Next
	}
	// 快指针正常移动
	for i := 0; i < right; i++ {
		fast = fast.Next
	}

	slow := prev.Next
	next := fast.Next

	prev.Next = nil
	fast.Next = nil

	reverseList(slow)

	prev.Next = fast
	slow.Next = next
	return dummy.Next
}

// @lc code=end
