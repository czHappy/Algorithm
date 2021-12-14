package search;

import java.util.Random;
/*
 * 基于有序数组的二叉搜索树
 * */
public class BinarySearchST<Key extends Comparable<Key> , Value> {
	private Key[] keys; //键
	private Value[] vals; //值
	private int N;// 当前使用容量
	
	public BinarySearchST(int capacity) {
		keys = (Key[]) new Comparable[capacity];
		vals = (Value[]) new Object[capacity];
	}
	
	public int size() {
		return N;
	}
	//根据键来查找对应值
	public Value get(Key key) {
		//找出该键在数组中的下标
		int pos = rank(key);
		//如果找到的下标在范围内并且确实是这个键，说明找到了
		if(pos < N && keys[pos].compareTo(key) == 0) {
			return vals[pos];
		}
		else return null;//否则没有找到，返回空
	}
	//二分法查找键的位置
	public int rank(Key key) {
		int lo = 0, hi = N - 1;
		//二分查找
		while(lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if(keys[mid].compareTo(key) > 0) {
				hi = mid - 1;
			}
			else if(keys[mid].compareTo(key) < 0 ) {
				lo = mid + 1;
			}
			else {
				return mid;
			}
		}
		//如果找不到 之前一步lo必定等于hi， 看这个数字是大于还是小于，不论怎样，lo的位置都代表如果这个数存在
		//它应该处于的位置
		return lo;
	}
	
	public void put(Key key, Value val) {
		int pos = rank(key);//先看这个键有木有
		//如果有只需要修改一下值就行了
		if(pos < N && keys[pos].compareTo(key) == 0) {
			vals[pos] = val;
		}
		//如果没有就新建一个键值对 插入
		//插入的位置正好是pos 那么pos之后的数都要后移一位
		//如果容量已满需要扩容
		for(int i=N-1; i>=pos; i--) {
			keys[i + 1] = keys[i];
			vals[i + 1] = vals[i];
		}
		//空出来的位置插入新键值对
		keys[pos] = key;
		vals[pos] = val;
		N++;
	}
	
	public void delete(Key key) {
		int pos = rank(key);//先看这个键有木有
		//如果有就删除 并且后移一位
		if(pos < N && keys[pos].compareTo(key) == 0) {
			for(int i=pos; i<N-1; i++) {
				keys[i] = keys[i+1];
				vals[i] = vals[i+1];
			}
			N--;
		}
		//如果没有就返回
		return;
	}
	
	public void show() {
		for(int i=0; i<N; i++) {
			System.out.println(keys[i].toString() + " : " + vals[i].toString());
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BinarySearchST<Integer, Integer> bs = new BinarySearchST<Integer , Integer>(20);
		Random r = new Random();
		for(int i=0; i<10; i++) {
			Integer t1 = new Integer(r.nextInt(1000));
			Integer t2 = new Integer(r.nextInt(1000));
			bs.put(t1, t2);
		}
		bs.show();
		System.out.println("size = " + bs.size());
		System.out.println("*********************");
		bs.put(999, 999);
		bs.put(555, 555);
		bs.show();
		System.out.println("size = " + bs.size());
		System.out.println("*********************");
		bs.delete(555);
		bs.delete(1024);
		bs.show();
		System.out.println("size = " + bs.size());
	}

}
