package list

import(
    "fmt"
    "math"
)

type Val_t int

//defination of ListNode and List
type ListNode struct{
	Val Val_t
	Next *ListNode
}

type List struct{
	Head *ListNode
	Tail *ListNode
	Len int
}

func NewList()(lst *List)  {
	lst = &List{}
	return
}

func (lst *List) IntsToLst(nums []Val_t){
	if len(nums) <= 0{
		return
	}

	dummy := &ListNode{Val:math.MaxInt32}
	pre := dummy
	lst.Len = 0

	//create new node and link it into lst
	for _,n := range nums{
		newNode := &ListNode{Val:n}
		pre.Next = newNode
		pre = newNode
		lst.Len++
	}
	//update head and tail
	if lst.Len > 0{
		lst.Head = dummy.Next
		lst.Tail = pre
	}
}

//get node at index idx
func (lst *List) GetAt(idx int) *ListNode{
	if(idx < 0 || idx > lst.Len){
		panic("index is out of boundary")
	}

	cur := lst.Head
	for idx > 0{
		cur = cur.Next
		idx--
	}
	return cur
}

//append node at tail
func (lst *List) PushBack(n Val_t){
	newNode := &ListNode{Val:n}
	if lst.Len <= 0{
		lst.Head,lst.Tail = newNode,newNode
	}else{
		lst.Tail.Next = newNode
		lst.Tail = newNode
	}
	lst.Len++
}

//append node as head
func (lst *List) PushFront(n Val_t){
	newNode := &ListNode{Val:n}
	if lst.Len <= 0{
		lst.Head,lst.Tail = newNode,newNode
	}else{
		newNode.Next = lst.Head
		lst.Head = newNode
	}
	lst.Len++
}

//insert node at index idx
func (lst *List) InsertAt(idx int, n Val_t){
	if(idx < 0 || idx > lst.Len){
		panic("index is out of boundary")
	}

	newNode := &ListNode{Val:n}

	dummy := &ListNode{Val:math.MaxInt32}
	dummy.Next = lst.Head
	pre,cur := dummy,dummy.Next
	for idx > 0{
		pre = cur
		cur = cur.Next
		idx--
	}

	//insert new node
	pre.Next = newNode
	newNode.Next = cur
	
	//update the ref of head and tail
	lst.Len++
	lst.Head = dummy.Next

	tail := lst.Head
	for tail.Next != nil{
		tail = tail.Next
	}
	lst.Tail = tail
}

//delete tail node
func (lst *List) PopBack()(ret Val_t){
	if lst.Len < 1{
		panic("no item to pop")
	}

	ret = lst.Tail.Val
	if lst.Len == 1{
		lst.Head,lst.Tail = nil,nil
	}else{
		preTail := lst.Head
		for preTail.Next != lst.Tail{
			preTail = preTail.Next
		}
		preTail.Next = nil
		lst.Tail = preTail
	}
	lst.Len--
	return
}

//delete head node
func (lst *List) PopFront() (ret Val_t){
	if lst.Len < 1{
		panic("no item to pop")
	}
	ret = lst.Head.Val
	if lst.Len == 1{
		lst.Head,lst.Tail = nil,nil
	}else{
		lst.Head = lst.Head.Next
	}
	lst.Len--
	return
}

//delete node at index idx
func (lst *List) RemoveAt(idx int) (ret Val_t){
	if lst.Len < 1{
		panic("no item to pop")
	}
	cur := lst.GetAt(idx)
	ret = cur.Val
	if(idx == 0){
		return lst.PopFront()
	}else if idx == lst.Len-1{
		return lst.PopBack()
	}else{
		pre,next := lst.GetAt(idx-1),lst.GetAt(idx+1)
		pre.Next = next
		lst.Len--
	}
	return
}

//reverse list
func reverse(head *ListNode) *ListNode{
	dummy := &ListNode{Val:math.MaxInt32}
	pre,cur := dummy,head
	pre.Next = head
	for cur != nil{
		next := cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}
	return pre
}

//reverse list between idx1 and idx2
func (lst *List) Reverse (idx1,idx2 int){
	if idx1 < 0 || idx1 >= lst.Len || idx2 < 0||idx2 >= lst.Len{
		panic("index out of boundary")
	}

	if idx1 == idx2{
		return
	}

	var start, end, pre, next *ListNode
	cur := lst.Head

	for i:=0 ; i <= idx2; i++{
		if i < idx1{
			pre = cur
		}
		if i == idx1{
			start = cur
		}
		if i == idx2{
			end = cur
		}
		cur = cur.Next
	}
	next = end.Next
	end.Next = nil 

	//relink idx1-idx2 list
	if pre !=nil{
		pre.Next = reverse(start)
	}else{
		lst.Head = reverse(start)
	}

	//relink
	start.Next = next
	lst.Tail = start

	//update the tail
	for lst.Tail.Next != nil{
		lst.Tail = lst.Tail.Next
	}
}

func (lst *List) Print(){
	cur := lst.Head
	if lst.Len > 0{
		fmt.Println("[len]",lst.Len,"[head}",lst.Head.Val,"[Tail]",lst.Tail.Val)
	}else{
		fmt.Println("len",lst.Len)
	}

	for cur != nil{
		fmt.Printf("%v",cur.Val)
		if cur != lst.Tail{
			fmt.Printf("->")
		}else{
			fmt.Printf("\n")
		}
		cur = cur.Next
	}
}

func ListTest(){
	fmt.Println("ListTest: ")
	nums := []Val_t{3,5,2,4,6}
	lst := NewList()
	lst.Print()

	lst.IntsToLst(nums)
	lst.Print()
	lst.Reverse(0,lst.Len-1)
	lst.Print()
	lst.PushBack(7)
	lst.Print()
	lst.PushFront(1)
	lst.Print()
	lst.InsertAt(4,3)
	lst.Print()
	fmt.Printf("3rd item: %v\n", lst.GetAt(3))
 
	lst.PopBack()
	lst.Print()
	lst.PopFront()
	lst.Print()
    fmt.Printf("remove 3rd item: %v \n", lst.RemoveAt(3))
    lst.Print()
}