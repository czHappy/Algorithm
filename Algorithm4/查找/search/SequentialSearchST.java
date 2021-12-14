package search;


//链表，内部类
public class SequentialSearchST<Key, Value>{
	
	public SequentialSearchST() {
		super();
		// TODO Auto-generated constructor stub
	}
	private Node head;//链表头指针
	//结点类 内部类
	private class Node{
		Key key;
		Value val;
		Node next;//下一个结点指针
		public Node() {}
		public Node(Key key, Value val, Node next) {
			this.key = key;
			this.val = val;
			this.next = next;
		}
		
	}
	
	//顺序查找
	public Value get(Key key) {
		Node x = head;
		while(x != null) {
			if(x.key.equals(key)) {
				return x.val;
			}
			x = x.next;
		}
		return null;
	}
		//尾插法
		public void put(Key key, Value val) {
			//先考虑key存在的情况
			Node x = head;
			while(true) {
				if(x.key.equals(key)) {
					x.val = val;
					return;
				}
				//如果下一个结点不为空，则继续向下迭代。为空，则直接把新节点插入即可
				if(x.next != null)
					x = x.next;
				else {
					x.next = new Node(key, val, null);
				}
				
			}
		}
		
		//头插法
		public void putt(Key key, Value val) {
			Node x = head;
			//先搜索一遍防止键 存在
			while(x != null) {
				if(x.key.equals(key)) {
					x.val = val;
					return;
				}
				x = x.next;
			}
			//如果 不存在则将该新节点指向旧的头指针， 新头指针指向 它
			head = new Node(key, val, head);
		}
	
}