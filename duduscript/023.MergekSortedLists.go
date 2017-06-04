/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

import "container/heap"

type Pair struct{
    val,index int
}

type PairHeap []Pair

func (h PairHeap) Len() int {
    return len(h)
}

func (h PairHeap) Less(i,j int) bool {
    return h[i].val < h[j].val
}

func (h PairHeap) Swap(i,j int) {
    h[i],h[j] = h[j],h[i]
}

func (h *PairHeap) Push(x interface{}) {
    *h = append(*h, x.(Pair))
}

func (h *PairHeap) Pop() interface{} {
	old := *h
	x := old[0]
	*h = old[1 :]
	return x
}

func mergeKLists(lists []*ListNode) *ListNode {
    h := &PairHeap{}
    result := &ListNode{0,nil}
    head := result
    for i:=0;i<len(lists);i++ {
        if lists[i] == nil { continue }
        h.Push(Pair{lists[i].Val,i})
        lists[i] = lists[i].Next
    }
    for h.Len() != 0 {
        pair := h.Pop().(Pair)
        val,idx := pair.val,pair.index
        result.Next = &ListNode{val,nil}
        result = result.Next
        if lists[idx] != nil {
            h.Push(Pair{lists[idx].Val,idx})
            lists[idx] = lists[idx].Next
        }
    }
    return head.Next
}