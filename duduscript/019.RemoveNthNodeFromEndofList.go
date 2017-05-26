/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    count,p,q := 0,head,head
    for p != nil { count,p = count+1,p.Next }
    if count == n { return head.Next }
    p = head
    for i:=0;i<count-n;i++ {
        q = p
        p = p.Next
    }
    q.Next = p.Next
    return head
}