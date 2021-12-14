package search;

import java.util.Random;

public class LinearProbingHashST<Key , Value> {
	
	private int N = 0;//当前使用量
	private int M = 16;//默认容量大小为M
	//并行数组
	private Key[] keys;
	private Value[] vals;
	
	public LinearProbingHashST() {
		// TODO Auto-generated constructor stub
		alloc();
		
	}
	public LinearProbingHashST(int cap) {
		M = cap;
		alloc();
	}
	
	private void alloc() {
		keys = (Key[])new Object[M];
		vals = (Value[]) new Object[M];
	}
	
	private int hash(Key key) {
		return (key.hashCode() &  0x7fffffff) % M;
	}
	
	//插入 查询 定理：  目标键与hash值所在的键  位于同一条长键之中，中间不可能有空隙
	public void show() {
		for(int i=0; i<M; i++) {
			if(keys[i] != null)
				System.out.println(keys[i].toString() + ":" +vals[i].toString());
		}
	}
	//插入操作 冲突 循环后移再探测
	public void put(Key key, Value val) {
		//保证使用量不超过额定容量的一半
		//System.out.println("put :" + N + " " + M/2);
		if(N > M/2) {
			resize(2*M);
//			System.out.println("*************************resize*************************" + M);
//			show();
//			System.out.println("**************************************************");
		}
		
		int index = hash(key);
		for(; keys[index] != null;  index = (index+1) % M) {
			if(keys[index].equals(key)) {
				vals[index] = val;
				return ;//如果该键已经存在则改值后 return
			}
		}
		keys[index] = key;
		vals[index] = val;
		N++;
	}
	
	//这种赋值方式不行 思考一下为什么  从hash值的模出发
	private void resizes(int cap) {
		// TODO Auto-generated method stub
		Key[] ks =  (Key[]) new Object[2*cap];
		Value[] vs =  (Value[]) new Object[2*cap];
		
		for(int i=0; i<M; i++) {
			ks[i] = keys[i] ;
			vs[i] = vals[i] ;
		}
		keys =  ks;
		vals = vs;
		M = cap;
		
	}
	
	private void resize(int cap) {
		LinearProbingHashST<Key , Value> t;
		t = new LinearProbingHashST<Key , Value>(cap);
		
		for(int i=0; i<M; i++) {
			if(keys[i] != null)
				t.put(keys[i], vals[i]);
		}
		this.keys = t.keys;
		this.vals = t.vals;
		this.M = t.M;
	}
	
	public Value get(Key key) {
		int index = hash(key);
		//首先算出hash值得到预期位置，如果正好这个位置的键等于key，那么命中，直接返回对应的val
		//如果发现key不相等，则说明发生冲突，由插入算法可知，要查找的键必然是和冲突键位于同一组长 键之中
		//继续查找直到遇到空为止 遇到空说明该键不存在
		for(int i = index; keys[i] != null; i = (i+1) % M) {
			if(keys[i].equals(key)) {
				return vals[i];
			}
		}
		return null;
	}
	
	//根据插入查询定理 目标键与hash值所在的键处于同一个长键之中，中间不能有缝隙
	//如果因为删除一个键后导致中间断裂，会导致查询失效
	
	//G H KLOMN  U  ML hash值相等  KN hash值不等
	//只能将该【长键中】所删除的键置为空然后将其右边的所有键重新插入
	
	public void delete(Key key) {
		int index = hash(key);
		int pos = index;
		boolean flag = false;
		for(; keys[index] != null; index = (index + 1) % M) {
			if(keys[index].equals(key)) {
				//找到这个键了 把位置记录下来一会用，index继续增加得到边界
				flag = true;
				pos = index;
				keys[index] = null;
				vals[index] = null;
				N--;
			}
		}
		 //没找到需要删除的键 就算了
		if(!flag)
			return ;
		//从pos+1的位置 到 index-1的位置所有键需要重新弄插入 注意位置序号需要取模
		pos = pos + 1;
		pos %= M;
		while(pos != index) {
			Key k = keys[pos];
			Value v = vals[pos];
			keys[pos] = null;
			vals[pos] = null;
			put(k , v);//重新插入
			pos = (pos + 1) % M;//后移pos位置
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinearProbingHashST<Integer , Integer> hashST;
		hashST = new LinearProbingHashST<Integer, Integer>();
		Random r = new Random();
		for(int i=0; i<1500000; i++) {
			Integer key = new Integer(r.nextInt(10000000));
			Integer value = new Integer(r.nextInt(10000000));
			//System.out.println("key = " + key + " value = " + value);
			hashST.put(key, value);
			//System.out.println("N = " + hashST.N + " M = " + hashST.M);
		}
		//System.out.println("put 操作完毕");
		hashST.put(88888, 88888);
		hashST.put(88888, 99999);
		
		//System.out.println(hashST.get(88888));
		System.out.println("删除前*****************");
		//hashST.show();
		
		//hashST.delete(88888);
		
		
		System.out.println("删除后*****************");
		
		//hashST.show();
		System.out.println(hashST.get(88888));
		System.out.println("OK");
	}

}
