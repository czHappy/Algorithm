package search;

public class SeparateChainingHashST<Key , Value> {
	private int N; //键值对总数
	private int M;//散列表的大小
	private SequentialSearchST<Key, Value>[] st;
	
	public SeparateChainingHashST() {
		// TODO Auto-generated constructor stub
		this(997);
	}

	//初始化，为每一个hash值都创建一个链表 M个
	public SeparateChainingHashST(int M) {
		// TODO Auto-generated constructor stub
		this.M = M;
		st = (SequentialSearchST<Key, Value>[]) new SequentialSearchST[M];
		for(int i=0; i<M; i++) {
			st[i] = new SequentialSearchST();
		}
	}
	
	private int hash(Key key) {
		return (key.hashCode() & 0x7fffffff) % M;
	}
	
	public Value get(Key key) {
		return (Value)st[hash(key)].get(key);
				
	}
	
	public void put(Key key, Value val) {
		st[hash(key)].put(key, val);
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
