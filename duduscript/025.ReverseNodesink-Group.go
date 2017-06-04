/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKNodes(head *ListNode, k int) (bool, *ListNode){
    for i:=0;i<k;i++ {
        if head == nil || head.Next == nil {
            return false,nil
        }
        head = head.Next
    }
    return true,head
}

func reverseK(head *ListNode, k int) {
    if ok,last := getKNodes(head, k); ok {
        reverseK(last,k)
        var p,q *ListNode
        for i:=0;i<k;i++ {
            if i == 0 {
                p = head.Next
                head.Next = last
                q = p.Next
                p.Next = last.Next
            } else {
                tmp := q.Next
                q.Next = p
                p = q
                q = tmp
            }
        }
    }
}
 
func reverseKGroup(head *ListNode, k int) *ListNode {
    head = &ListNode{0,head}
    reverseK(head,k)
    return head.Next
}