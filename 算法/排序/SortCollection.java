package sort;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Random;

public class SortCollection {

	//交换函数，交换a数组中i,j两位置
	public static void exch(Comparable[] a, int i, int j) {
		Comparable t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	
	//打印元素的值
	//如果是对象要重写一下toString方法
	public static void show(Comparable[] a, int st, int ed)  {
		if(st < 0 || ed > a.length) {
			System.out.println("OutOfBound!");
			return;
		}
		for(int i=st; i<=ed; i++) {
			Method method;
			try {
				method = a[i].getClass().getMethod("getValue");
				System.out.print(method.invoke(a[i]).toString()+" ");;
			} catch (NoSuchMethodException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (SecurityException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IllegalAccessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IllegalArgumentException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InvocationTargetException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
			
		System.out.println();
	}
	
	//比较函数   可以自定义比较关键字
	//注意，该对象需要实现Comparable接口并且重写compareTo方法
	private static int cmp(Comparable a, Comparable b) {
		// TODO Auto-generated method stub
		return a.compareTo(b);
	}
	
	//选择排序
	public static void selectSort(Comparable[] a) {
		for(int i=0; i<a.length; i++) {
			Comparable min = a[i];//记录该轮排序的最小值
			int pos = i;//记录最小值的位置
			for(int j=i+1; j<a.length; j++) {
				if(cmp(a[j] , a[pos]) < 0) {
					pos = j;
					min = a[j];
				}
			}
			exch(a, i, pos);//对a数组交换第i和第pos元素的位置
		}
	}
	
	//插入排序
	public static void insertSort(Comparable[] a) {
		for(int i=1; i<a.length; i++) {//把第一个数看做是有序的，从第二个数开始
			for(int j=i; j>0; j--) {//寻找插入位置
				if(cmp(a[j] , a[j-1]) >= 0) {//发现前面的数比它小，那说明位置已经找到了，不需要再找
					break;
				}
				else {//否则不断与相邻元素交换位置
					exch(a , j, j-1);
				}
			}
		}
	}

	
	//希尔排序 
	public static void shellSort(Comparable[] a ) {
		//构造h
		int h = 1;
		int n = a.length;
		while(h <= n/3) h = h*3+1;// h = 1 4 13 40 121...
		while(h >= 1) { //每一轮使原数组变成h有序数组
			for(int i=h; i<n; i++) { //插入排序的变形，之前是两两相邻，现在是h相邻
				for(int j=i; j>=h && cmp(a[j] , a[j-h]) < 0; j-=h) { //
					exch(a , j , j-h); //
				}
			}
			h = h/3;//h收缩，直至1，此时的h有序数组就是有序数组
		}
	}
	
	//归并排序
	private static Comparable[] aux;
	//merge方法
	public static void merge(Comparable[] a,  int lo, int mid , int hi) {
		int p = lo, q = mid+1;
		for(int i=lo; i<=hi; i++) aux[i] = a[i];
		int cnt = lo;
		while( p <= mid && q <= hi) {
			
			if(cmp(aux[p] , aux[q]) < 0) a[cnt++] = aux[p++];
			else a[cnt++] = aux[q++];
		}
		while(p <= mid) a[cnt++] = aux[p++];
		while(q <= hi) a[cnt++] = aux[q++];
	}
	
	//sort方法
	public static void sort(Comparable[] a, int lo, int hi) {
		if(lo >= hi) return ; //如果low > high则返回
		int mid = lo + ((hi - lo) >> 1);//取中间点为中点 
		sort(a , lo , mid);//对左边的归并
		sort(a , mid + 1, hi);//对右边的归并
		merge(a , lo , mid , hi);//左右归并好了则归并到一起
	}
	
	//启动函数
	public static void mergeSort(Comparable[] a) {
		aux = new Comparable[a.length];
		sort(a , 0, a.length - 1);
	}
	//from bottom to up
	public static void mergeSortBU(Comparable[] a) {
		int n = a.length;
		aux = new Comparable[n];
		for(int sz = 1; sz < n; sz += sz) {
			for(int lo = 0; lo < n - sz + 1; lo += sz+sz) {
				merge(a , lo, lo+sz-1, Math.min(lo+sz+sz-1 , n-1));
			}
		}
	}
	
	//切分函数
	private static int partition(Comparable[] a, int lo, int hi) {
		Comparable v = a[lo];
		int i = lo, j = hi;//i,j分别是左部分指针，右部分指针
		while(true) {
			//左边要找一个比他大的，否则一直找知道i指针到终点hi
			while(i<=hi) 
				if(cmp(a[++i] , v) <= 0); else break;	
				
			//右边要找一个比他小的，否则一直找到j指针到起点lo
			while(j>lo) 
				if(cmp(a[j] , v) >= 0) j--; else break;
				
			//如果ij指针相遇  则说明已经找到a[lo]的位置，
			if(i>=j) break;//这里等号应该取不到因为上面设置的是严格大和严格小，不加等号也 是对的
			exch(a , i , j);//交换位置，把不正确的位置纠正过来，把左边大的与右边小的元素位置互换
		}
		exch(a , lo , j);//最后把第lo个元素放到该 放到的地方
		return j;//返回该轮排序的切分点

	}
	
	//递归排序
	private static void qsort(Comparable[] a, int lo, int hi) {
		// TODO Auto-generated method stub
		
		if(lo >= hi) return ;
		int mid = partition(a , lo, hi);
		qsort(a , lo, mid-1);
		qsort(a,  mid+1, hi);
	}
	//快速排序启动函数
	
	public static void quickSort(Comparable[] a) {
		
		qsort( a, 0, a.length - 1);
	}
	//三向切分快速排序
	public static void qsort3(Comparable[] a, int lo, int hi) {
		if(lo >= hi) return ;
		//lo lt gt hi四个指针 
		//事实上，从lt一开始指向关键字a[lo]，lt就一直指向的值是V，并且lt指的是第一个V值，它存的其实是边界
		//排好序后lt ~ gt都是V值
		int lt = lo, i = lo+1 , gt = hi;
		Comparable v = a[lo];
		while(i <= gt ) {
			int re = cmp(a[i] , v);
			if(re < 0) exch(a , i++ ,lt++);
			else if( re > 0) exch(a , i, gt--);
			else i++;
		}
		//只需要再排不等于V的两个部分
		qsort3(a , lo, lt - 1);
		qsort3(a , gt+1 , hi);
	}
	public static void quickSort3(Comparable[] a) {
		
		qsort3( a, 0, a.length - 1);
	}
	
	
	//堆排序 ， 注意数组a从下标1开始，0号元素没有用
	public static void heapSort(Comparable[] a) {
		int N = a.length-1;//N是最后一个元素下标
		for(int k = N/2; k>0; k--) {
			sink(a , k, N);
		}
		while(N > 1) { //不斷地冒頂，把頂部元素逐個安排到n-1,n-2,...,2,最後一個不用再安排
			exch(a , 1, N--);//冒頂到尾
			sink(a , 1, N);//頂部元素下沉保持1~N-1有序，N是逐漸減少的
		}	
	}
	//下沉調節 事實上，sink函數適用於在頂元素被替代後的調整動作，而swim函數適用於末尾新插入元素調整位置
	//一定要注意第三个参数N是当前选定的最后一个位置， 并不一直是数组末尾元素
	private static void sink(Comparable[] a, int k, int N) {

		while(2*k <= N) {
			int j = 2*k;//J指向左孩子
			//比較一下左右孩子，J指向大的
			if(j < N && cmp(a[j] , a[j+1]) < 0) {
				j++;
			}
			if(cmp(a[k] , a[j]) >= 0) { //如果父親結點大於大孩子，就算了
				break;
			}//如果父親結點小與大孩子，則需要交換
			exch(a , k , j);
			k = j;//繼續下沉交換
		}
	}
	
	//冒泡排序
	public static void bubbleSort(Comparable[] a) {
		boolean flag;//标志该趟是否有交换发生，如果没有那就说明排序可以停止了
		int n=a.length;
		for(int i=0; i<n; i++) {
			flag = false;
			for(int j=n-1; j>i; j--) {
				if(cmp(a[j-1] , a[j]) > 0) {
					exch(a , j-1 , j);
					flag = true;
				}
			}
			if(!flag) break;
		}
	}
	
	
	public static void main(String[] args) throws NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException  {
		// TODO Auto-generated method stub
		Random random = new Random(10);
		Item[] a = new Item[10];//Integer内部实现了Comparable接口
		for(int i=0; i<a.length; i++) {
			a[i] = new Item();
			a[i].setValue(random.nextInt(50));	
		}
		
		//show(a);//排序前
		//shellSort(a);
		//show(a,0,a.length-1);
		
		//show(a,1,a.length-1);
		//heapSort(a);//堆排序需要從1開始 
		//show(a,1,a.length - 1);
		
		bubbleSort(a);
		show(a , 0 , a.length-1);
		
	}
	
}
