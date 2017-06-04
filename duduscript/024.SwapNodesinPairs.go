/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapAllPairs(head* ListNode) {
    var tmp *ListNode
    if head.Next != nil && head.Next.Next != nil {
        tmp = head.Next.Next
        head.Next.Next = tmp.Next
        tmp.Next = head.Next
        head.Next = tmp
        swapAllPairs(tmp.Next)
    }
}
 
func swapPairs(head *ListNode) *ListNode {
    head = &ListNode{0,head}
    swapAllPairs(head)
    return head.Next
}