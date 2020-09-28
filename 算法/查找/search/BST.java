package search;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Random;

public class BST<Key extends Comparable<Key> , Value> {
	private Node root;
	//结点内部类声明
	private class Node{
		private Key key;//键
		private Value val;//值
		private Node left , right;//左孩子和右孩子
		private int N ; //该子树的总结点个数
		public Node() {}
		public Node(Key key, Value val, int N) {
			this.key = key;
			this.val = val;
			this.N = N;
		}
		
	}
	public int size(){
		return size(root);
	}
	private int size(Node x) {
		if(x == null) return 0;
		return x.N;
	}
	//根据键找值
	public Value get(Key key) {
		return get(root , key);
	}
	private Value get(Node x, Key key) {
		if(x == null) return null;
		int cmp = x.key.compareTo(key);
		if(cmp == 0) return x.val;
		else if(cmp > 0) return get(x.left , key);
		else return get(x.right , key);
	}
	public void put(Key key, Value val) {
		root = put(root , key, val);
	}
	private Node put(Node x , Key key, Value val) {
		//如果没有这个键就新增一个
		if(x == null) {
			return x = new Node(key , val, 1);
		}
		//沿途二分找键，遇到的根节点键大，则在其左子树递归查找，键小，在右子树递归查找，
		//直到找到相等或者发现根节点为空为止
		int cmp = x.key.compareTo(key);
		if(cmp > 0) {
			x.left = put(x.left , key, val);
		}
		else if(cmp < 0) {
			x.right = put(x.right , key , val);
		}
		else {
			x.val = val;
		}
		//沿途回溯更新结点的size  自底向上
		x.N = size(x.left) + size(x.right) + 1;
		return x;
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
	
	//删除一棵树的最小结点
	public void deleteMin() {
		root = deleteMin(root);
	}

	private Node deleteMin(Node x) {
		// TODO Auto-generated method stub
		if(x.left != null) {
			x.left = deleteMin(x.left);
			x.N = size(x.left) + size(x.right) + 1;
			return x;
		}
		return x.right;
	}
	
	public void delete(Key key) {
		root = delete(root , key);
	}
	public Node delete(Node x, Key key) {
		if(x ==  null) return null;
		int cmp = x.key.compareTo(key);
		if(cmp > 0) {
			x.left = delete(x.left , key);
		}
		else if(cmp < 0) {
			x.right = delete(x.right ,  key);
		}
		else {
			//找到要删除的结点了
			if(x.left == null) return x.right;
			if(x.right == null) return x.left;
			
			Node t = x;
			x = minK(t.right);
			x.right = deleteMin(t.right);
			x.left = t.left;
		}
		x.N = size(x.left) + size(x.right) + 1;
		return x;
	}
	
	//返回整棵树的迭代对象
	public Iterable<Key> keys(){
		return keys(minK() , maxK());
	}
	
	//返回范围[lo , hi]内所有key的迭代对象
	public Iterable<Key> keys(Key lo, Key hi) {
		// TODO Auto-generated method stub
		Queue<Key> queue = new LinkedList<Key>();
		keys(root , queue, lo, hi);
		return queue;
	}
	//把[lo , hi]范围内的所有元素加入指定迭代对象中
	private void keys(Node x, Queue<Key> queue, Key lo, Key hi) {
		// TODO Auto-generated method stub
		if(x == null) return ;
		int cmplo = x.key.compareTo(lo);
		int cmphi = x.key.compareTo(hi);
		//如果根节点大于lo说明根节点的左子树可能还有元素在此范围内
		if(cmplo > 0) {
			keys(x.left, queue, lo, hi);
		}
		//如果根节点小于hi说明根节点的右子树可能还有元素在此范围内
		if(cmphi < 0) {
			keys(x.right, queue, lo, hi);
		}
		//遇到一个结点在此范围内就将其加入集合
		if(cmplo >= 0 && cmphi <= 0) {
			queue.add(x.key);
		}
	}
	//前序遍历 左中右遍历  顺序遍历
	public void show(Node x) {
		if(x != null) {
			show(x.left);
			System.out.println(x.key.toString() + " : " + x.val.toString());
			show(x.right);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BST bst = new BST<Integer , Integer>();
		Random r = new Random();
		for(int i=0; i<10; i++) {
			Integer key = new Integer(r.nextInt(1000));
			Integer value = new Integer(r.nextInt(1000));
			System.out.println("key = " + key + " value = " + value);
			bst.put(key, value);
		}
		System.out.println("put 操作完毕");
		// 186 244 336 481 507 514 663 729 743 759 761 891
		bst.show(bst.root);
		
		System.out.println("show 操作完毕");
		
		//bst.put(759, 19999);
		//bst.put(761, 19999);
		System.out.println(bst.get(9999));
		System.out.println(bst.get(8888));
		
		System.out.println(bst.floor(760));
		System.out.println(bst.ceiling(760));
		System.out.println(bst.maxK());
		System.out.println(bst.select(5));
		System.out.println(bst.rank(500));
		bst.deleteMin();
		bst.put(1000, 9999);
		bst.show(bst.root);
		bst.delete(1000);
		bst.show(bst.root);
		System.out.println("################");
		Iterable<Integer> it = bst.keys(200,600);
		for(Integer i : it) {
			System.out.print(i.toString() + " ");
		}
	}
	
	

}

