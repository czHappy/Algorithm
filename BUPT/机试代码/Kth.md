
# 寻找第K大的数
## 直接排序
- 排序后直接返回相应下标
- 若要求同样大的元素算作一个数的话可以使用unique函数
```c++
    class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            sort(nums.begin() , nums.end());
            return nums[nums.size()-k];
        }
    };
```
- 时间复杂度:O(nlogn)


## 堆排序
- 以初始序列建大根堆，然后弹出K-1个数字，此时堆顶部就是第K大的数字,可以直接使用优先队列
```c++
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int , vector<int>, greater<int> > Q;
    //priority_queue<int> Q;//默认大根堆 
    for(int i=0; i<k; i++) Q.push(nums[i]);
    for(int i=k; i<nums.size(); i++){
        Q.push(nums[i]);
        Q.pop(); 
    } 
    return Q.top(); 
}
```

- 时间复杂度:O(nlogn)

## 快速排序变形
- partition函数恰好是返回key所在的位置，如果这个位置恰好是第K大的数所在位置，那么这个数就是第K大的数
```c++

int partition(int a[] , int lo, int hi){
	int key = a[lo];
	while(lo < hi){
		while(lo < hi && a[hi] >= key) hi--;//左边找一个大的
		a[lo] = a[hi];
		while(lo < hi && a[lo] <= key) lo++;//右边找一个小的
		a[hi] = a[lo];
	}
	a[lo] = key;
	return lo;
}

// 1 3 3 4 5 6 9   N=7 K=2
int findKthLargest(int* num, int numsSize, int k){
    int lo = 0, hi = numsSize - 1;
	k = numsSize - k; //找第K大的
	int j;
	while(lo < hi){
		j = partition(num , lo, hi);
		if(j == k) break; //直到恰好找到第K'个位置的数
		else if(j < k) lo = j + 1;
		else hi = j - 1;
	}
	return num[k];
}

```
- 时间复杂度：期望值是O(n)
## 非重复数字的第K大
- 思路1：使用MAP先将不重复的数字筛选出来,得到一个新数组，然后再用上述方法找到第K大
```c++
int solve(int* a, int numsSize, int k){
    map<int ,int> mp;
    int cnt = 0;
    for(int i=0; i<numsSize; i++){
        if(!mp[a[i]]) mp[a[i]] = 1;
    } //O(nlogn)
    for(map<int,int>::iterator it = mp.begin(); it!=mp.end(); it++){
        cnt++;//记录一共有多少个不重复的数字
        a[i] = it->first;
    }
    return findKthLargest(a, cnt, k);
}
```