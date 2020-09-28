package search;

import java.util.Random;


public class RedBlackBST<Key extends Comparable, Value> {
	private static final boolean RED = true;
	private static final boolean BLACK = false;
	Node root;
	private class Node{
		Key key;
		Value val;
		Node left , right;
		int N;
		boolean color;
		Node(Key key, Value val, boolean color){
			this.key = key;
			this.val = val;
			this.color = color;
			this.N = 1;
		}
	}
	
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		if(root == null) return true;
		return false;
	}
	
	public int size() {
		return size(root);
	}
	
	
	private int size(Node h) {
		// TODO Auto-generated method stub
		if(h == null) return 0;
		return h.N;
	}
	
	private boolean isRed(Node h) {
		if(h == null) return BLACK;
		return h.color == RED;		
	}
	
	
	private Node rotateLeft(Node h) {
		Node x = h.right;
		h.right = x.left;
		x.left = h;
		x.color = h.color;
		h.color = RED;
		x.N = h.N;
		h.N = size(h.left) + size(h.right) + 1;
		return x;
	}
	private Node rotateRight(Node h) {
		Node x = h.left;
		h.left = x.right;
		x.right = h;
		x.color = h.color;
		h.color = RED;
		x.N = h.N;
		h.N = size(h.left) + size(h.right) + 1;
		return x;
	}
	private void flipColors(Node h) {
		if(h == null) return ;
		h.color = !h.color;
		if(h.left != null)
			h.left.color = !h.color;
		if(h.right != null)
			h.right.color = !h.color;
	}
	public void put(Key key, Value val) {
		root = put(root , key, val);
		root.color = BLACK;
	}

	private Node put(Node h, Key key, Value val) {
		// TODO Auto-generated method stub
		if(h == null) return new Node(key,val,RED);
		int cmp = key.compareTo(h.key);
		if(cmp > 0) h.right = put(h.right , key, val);
		else if(cmp < 0) h.left = put(h.left, key, val);
		else h.val = val;
		
		if(isRed(h.right) && !isRed(h.left)) h = rotateLeft(h);
		if(isRed(h.left) && isRed(h.left.left)) h = rotateRight(h);
		if(isRed(h.left) && isRed(h.right)) flipColors(h);

		h.N = size(h.left) + size(h.right) + 1;
		return h;
	}
	//根据键找值
	public Value get(Key key) {
		return get(root , key);
	}
	private Value get(Node h, Key key) {
		if(h == null) return null;
		int cmp = key.compareTo(h.key);
		if(cmp == 0) return h.val;
		else if(cmp > 0) return get(h.right , key);
		else return get(h.left , key);
	}
	
	//注意从左侧一直往下，保证h必然是红结点（非2-结点）
	//接下来的情况可以分为这几种，查看h的左子树x
	//1. 接下来是一个非空2-结点x(黑)，很显然，该2-结点的左子节点的颜色还是黑(空结点的颜色设为黑) 这种情况需要借结点
	//1.1 首先x的父节点h肯定是红结点，所以肯定可以向父亲借结点，若x的右兄弟结点y也是2-结点， 则把父节点【2-3概念中的结点】的最小的那个结点(红结点，其实就是h)拉下来
	//怎么拉下来呢，其实就是使xy变红，h变黑，这样xhy组成了一个4-结点【2-3概念中的结点】
	//1.2 若x的右兄弟结点y不是2-结点则把y中最小键移到x中，需要先右旋y把最小键传递给父节点，再左旋h把h中最小值传给x
	
	//处理非2-结点
	private Node moveRedLeft(Node h) {
		flipColors(h);//使xy变红父节点拉下
		//如果y不是2-结点，那么将 y中的一个最小键转交给父节点，如果不转交，平衡性破坏
		//如何转交？左节点转交给父亲是右旋，右节点转交给父亲是左旋
		if(h.right != null && isRed(h.right.left)) {
			//y结点最小键准备交付，完成后最小键将紧贴根节点的右部，一左旋根节点就交付
			h.right = rotateRight(h.right);
			//转交
			h = rotateLeft(h);
			flipColors(h);
		}
		return h;
	}
	
	public void deleteMin() {
		if(root == null) return ;
		//保证从左往下遍历的每一个结点都不是2-结点
		if(!isRed(root.left) && !isRed(root.right)) {
			root.color = RED;
		}
		root = deleteMin(root);
		if(!isEmpty()) root.color = BLACK;
	}

	private Node deleteMin(Node h) {
		//如果它左下方没有孩子了，那它就是要被删除的，返回空，它将会被置空
		if(h.left == null) return null;
		//如果左子结点 是一个2-结点  （满足这两个条件才能是一个2-结点）
		if(judgeLeft(h)) {
			//将此2-结点处理成非2结点
			h = moveRedLeft(h);
		}
		//继续向下尝试删除
		h.left = deleteMin(h.left);
		return balance(h);
	}
	
	private Node balance(Node h) {
		if(isRed(h.right)) h = rotateLeft(h);
		if(isRed(h.right) && !isRed(h.left)) h = rotateLeft(h);
		if(isRed(h.left) && isRed(h.left.left)) h = rotateRight(h);
		if(isRed(h.left) && isRed(h.right)) flipColors(h);
		h.N = size(h.left) + size(h.right) + 1;
		return h;
	}
	
	//保证在右侧遍历的时候，当前结点永远不是2-结点
	//另外一个条件是以当前结点为根节点的子树是一颗红黑树
	private Node moveRedRight(Node h) {
		
		//先不管是哪种情况，父节点都要先拉下来
		flipColors(h);
		//如果左孩子不是一个2-结点，就借，先找父亲借，借到了之后兄弟结点还一个给父亲
		if(h.left != null && isRed(h.left.left)) {
			//现在父节点拉下来了，把父节点给右孩子
			h = rotateRight(h);
			//左节点还一个给父节点
			flipColors(h);
		}
		//如果左孩子是一个2-结点，那父节点拉下来就拉下来了,不用管了
		return h;
	}
	
	//判断h的左节点是不是2-结点
	private boolean judgeLeft(Node h) {
		if(isRed(h.left)) return true;
		if(h.left != null) {
			if(isRed(h.left.left)) return true;
		}
		return false;
	}
	
	//判断h的右节点是不是2-结点
	private boolean judgeRight(Node h) {
		if(isRed(h.right)) return true;
		if(h.right != null) {
			if(isRed(h.right.left)) return true;
		}
		return false;
	}
	
	
	public void deleteMax() {
		if(root == null) return;
		if(!isRed(root.left) && !isRed(root.right)) {
			root.color = RED;
		}
		root = deleteMax(root);
		if(!isEmpty()) root.color = BLACK;
	}
	
	public Node deleteMax(Node h) {
		//如果左侧还有红色结点，也就是3-结点，要先左旋，防止左节点丢失
		if(isRed(h.left)) h = rotateRight(h);
		
		if(h.right == null) return null;
		//如果右结点不为空，则看看右节点是不是2-结点，如果不是那就把它变成2-结点
		if(judgeRight(h)) {
			h = moveRedRight(h);
		}
		h.right = deleteMax(h.right);
		return balance(h);
	}
	
	//删除key 键值对
	public void delete(Key key) {
		
		if(root == null) return;
		
		if(!isRed(root.left) && !isRed(root.right)) {
			root.color = RED;
		}
		root = delete(root, key);
		if(!isEmpty()) root.color = BLACK;
	}
	
	private Node delete(Node h, Key key) {
		int cmp = key.compareTo(h.key);
		//如果结果小于0，则需要在左子树中删除
		if(cmp < 0) {
			//要保证在沿左子树的图中当前结点不是2-结点
			//if(h.right == null) System.out.println("??????????????????????????????");
			if(judgeLeft(h)) {
				h = moveRedLeft(h);
			}
			h.left = delete(h.left , key);
		}
		else {
			//如果左边是不是2-结点，需要右旋
			if(isRed(h.left)) h = rotateRight(h);
			//如果是删当前结点并且其右子树为空，直接将其设空即可
			if(cmp == 0 && h.right == null) return null;
			//现在要么是删当前结点，要么是删当前结点的右子树中的结点，不论哪种情况，必然要使沿途中的结点不是2-结点
			if(judgeRight(h)) {
				h = moveRedRight(h);
			}
			//如果是删当前 结点 并且右子树不空，则需要与右子树最小值与之替换
			if(cmp == 0) {
				Node x = minK(h.right);
				h.key = x.key;
				h.val = x.val;
				h.right = deleteMin(h.right);
			}
			else {
				h.right = delete(h.right, key);
			}
		}
		return balance(h);
	}
	
	//返回键的最小值
	public Key minK() {
		return minK(root).key;
	}
	private Node minK(Node x) {
		if(x.left != null) {
			return minK(x.left);
		}
		return x;
	}
	//返回键的最小值
	public Key maxK() {
		return maxK(root).key;
	}
	private Node maxK(Node x) {
		if(x.right != null) {
			return maxK(x.right);
		}
		return x;
	}
	//返回小于等于key的最大值
	public Key floor(Key key) {
		Node x = floor(root , key);
		if(x != null) return x.key;
		return null;
	}

	//返回小于等于key的最大值所在结点
	private Node floor(Node x , Key key) {
		if(x == null) return null;
		//比较当前根节点的键值是否大于key
		int cmp = x.key.compareTo(key);
		if(cmp == 0) return x;
		//如果根结点的键值小于key，那么小于等于key的键值有可能在根节点的右子树中，如果没有则就是根节点
		else if(cmp < 0) {
			Node t =  floor(x.right , key);
			if(t == null) return x;
			else {
				return t;
			}
		}
		//如果根节点的键值大于key，则小于等于key的键值必定在根节点的左子树中
		else {
			return floor(x.left , key);
		}
	}
	
	public Key ceiling(Key key) {
		Node x = ceiling(root , key);
		if(x != null) return x.key;
		return null;
	}

	//返回大于等于key的最小值所在结点
	private Node ceiling(Node x , Key key) {
		if(x == null) return null;
		//比较当前根节点的键值是否大于key
		int cmp = x.key.compareTo(key);
		if(cmp == 0) return x;
		//如果根节点的键值大于key，则大于等于key的键值有可能在根节点的左子树中，如果没有就是根节点
		else if(cmp > 0) {
			Node t =  ceiling(x.left , key);
			if(t == null) return x;
			else {
				return t;
			}
		}
		//如果根结点的键值小于key，那么大于等于key的键值一定在根节点的右子树中
		else {
			return ceiling(x.right , key);
		}
	}

	//查找排名为K的键(树中恰好有K个小于他的键)
	public Key select(int k) {
		Node x = select(root , k);
		if(x == null) return null;
		return x.key;
	}
	private Node select(Node x , int k) {
		if(x == null) return null;
		int t = size(x.left);
		if( t > k) {
			return select(x.left , k);
		}
		else if(t == k) {
			return x;
		}
		else {
			return select(x.right , k - t - 1);
		}
	}

	//给定一个键求其排名(即求有多少个键小于它)
	public int rank(Key key) {
		return rank(root , key);
	}
	private int rank(Node x , Key key) {
			if(x == null) return 0;
			int cmp = x.key.compareTo(key);
			if(cmp == 0) {
				return size(x.left);
			}
			else if(cmp > 0) {
				return rank(x.left , key);
			}
			else {
				return size(x.left) + rank(x.right , key) + 1; 
			}
		}
	//前序遍历 左中右遍历  顺序遍历
	public void show() {
		show(root);
	}
	private void show(Node x) {
		if(x != null) {
			show(x.left);
			System.out.println(x.key.toString() + " : " + x.val.toString());
			show(x.right);
		}
	}	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		RedBlackBST<Integer , Integer> rbt = new RedBlackBST<Integer , Integer>();
		Random r = new Random();
		for(int i=0; i<2000; i++) {
			Integer key = new Integer(r.nextInt(10000000));
			Integer value = new Integer(r.nextInt(10000000));
			//System.out.println("key = " + key + " value = " + value);
			rbt.put(key, value);
		}
		System.out.println("put 操作完毕");
		// 186 244 336 481 507 514 663 729 743 759 761 891
		//rbt.show(rbt.root);
		
		//System.out.println("show 操作完毕");
//		rbt.put(222, 1998);
//		System.out.println(rbt.get(9999));
//		System.out.println(rbt.floor(760));
//		System.out.println(rbt.ceiling(760));
//		System.out.println(rbt.maxK());
//		System.out.println(rbt.minK());
//		System.out.println(rbt.select(5));
//		System.out.println(rbt.rank(567));
		
		//rbt.put(444, 99999999);
		//rbt.put(6666, 99999999);
		System.out.println("删除前##################################");
		rbt.show();
		System.out.println("size = " + rbt.size());
		//rbt.delete(444);
		//rbt.delete(6666);
		rbt.deleteMax();
		rbt.deleteMax();
		rbt.deleteMax();
		System.out.println("删除后##################################");
		
		rbt.show();
		System.out.println("size = " + rbt.size());
	}

	
		// TODO Auto-generated method stub
		
	

}
