/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    plus, rtn := 0, &ListNode{0,nil}
    p := rtn
    for l1 != nil && l2 != nil {
        p.Next = &ListNode{0,nil}
        p.Next.Val = (plus + l1.Val + l2.Val)%10
        plus = (plus + l1.Val + l2.Val)/10
        l1,l2,p = l1.Next,l2.Next,p.Next
    }
    if l1 == nil {l1 = l2}
    for l1 != nil {
        p.Next = &ListNode{(plus+l1.Val)%10,nil}
        plus = (plus + l1.Val)/10
        l1,p = l1.Next,p.Next
    }
    if plus != 0 { p.Next = &ListNode{1,nil} }
    return rtn.Next
}