#include<iostream>
#include<stack> 
#include<queue> 
using namespace std;

//ADT
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree; 

//建树 
void build(BiTree &T){
	char ch;
	cin>>ch;
	if(ch == '.') T = NULL;
	else{
		T = (BiTNode *)malloc(sizeof(BiTNode));
		T->data = ch;
		build(T->lchild);
		build(T->rchild); 
	}
}
//前序递归 
void PreOrder(BiTree T){
	if(T != NULL){
		cout<<T->data<<endl;;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//中序递归 
void InOrder(BiTree T){
	if(T != NULL){
		InOrder(T->lchild);
		cout<<T->data<<endl;
		InOrder(T->rchild);
	}
}

//后序递归 
void PostOrder(BiTree T){
	if(T != NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout<<T->data<<endl;;
	}
}

//前序遍历非递归版本 
//由于整个左子树被访问完才能访问右子树，故需要借助栈来保存当前子树的根节点 
void PreOrder2(BiTree T){
	stack<BiTNode*> S;//开辟一个栈 
	BiTree p = T;//迭代指针 开始指向root 
	while(p || !S.empty()){ //只要还有结点 
		if(p){ //如果当前结点不空 
			cout<<p->data<<endl; //则打印当前结点 因为是先序，遇到新结点就打印 
			S.push(p);//当前结点入栈 
			p = p->lchild;//访问其左子树，向左访问结点 
		}
		else{
			p = S.top();//如果当前结点是空的，就退回到上一个结点 
			S.pop();//退栈 
			p = p->rchild;//访问其右子树 
		}
	}
}

//中序非递归  左 中 右
//根节点必须在左结点访问之后再访问，而根节点又是先于左子节点被遍历到，故要设置一个栈来保存 
void InOrder2(BiTree T){
	stack<BiTNode*> S;//开辟一个栈 
	BiTree p = T;//迭代器 
	while(p || !S.empty()){ //如果还有结点 
		if(p){//如果当前结点不为空 
			S.push(p);// 不要急于访问根节点，先压栈。 
			p = p->lchild;//访问左子树 
		}
		else{//如果当前节点是空的。则需要退回到上一个结点 
			p = S.top();
			S.pop();//退到该子树的根节点立即访问 
			cout<<p->data<<endl;
			p = p->rchild;//继续访问右子树  
		}
	}
}

//后序非递归 双栈法
//由于是左 右 中，因此入栈次序是中右左，
//先看根节点，再看右孩子，再看左孩子 
void PostOrder2(BiTree T){
	stack<BiTNode*> S; //遍历栈 
	stack<BiTNode*> result; //结果栈 
	BiTree p = T;//迭代器 
	while(p || !S.empty()){
		if(p){ //如果当前结点不为空 
			S.push(p);//结点入栈 
			result.push(p);//结点入结果栈 
			p = p->rchild;//看其右孩子结点 
		}  
		else{ //如果当前结点为空 ，退到上一个结点 
			p = S.top();
			S.pop();//退栈 
			p = p->lchild;//找其左孩子结点 
		}
	}
	//输出后序序列 
	while(!result.empty()){
		p = result.top();
		result.pop();
		cout<<p->data<<endl;
	}
}

// 后序遍历  访问标记法
void postOrder3(BiTree T){
	stack<BiTNode*> S; //开辟一个栈 
	BiTNode* p = T; //迭代器 
	BiTNode* r = NULL; //保存最近访问过的结点 
	while(p || !S.empty()){
		if(p){ //如果当前结点不为空 则走到该子树的最左边 
			
			S.push(p);
			p = p->lchild;
		}
		else{ //若为空，退到上一个结点 
			p = S.top();
			if(p->rchild && p->rchild != r){ //如果存在右子树并且右子树没有被访问过 
				p = p->rchild;//那么就转向右子树继续 
				S.push(p); // 保存子树根节点 
				p = p->lchild; //继续向左访问左子树 
			} 
			else{
				p = S.top(); 
				S.pop();//没有右子树那就可以访问根节点了 
				cout<<p->data<<endl;
				r = p; //标记r为最近访问的结点
				p = NULL; //当前结点置为空 ，因为这棵子树的根节点都访问完了说明这颗子树就全部访问完了，就等待退回上一个子树根节点 
			}
		}
	} 
} 
 
//层序遍历 队列 
void levelOrder(BiTree T){
	queue<BiTNode*> Q;
	BiTNode *p = T;
	Q.push(T);
	while(!Q.empty()){
		p = Q.front();
		Q.pop();
		cout<<p->data<<endl;
		if(p->lchild) Q.push(p->lchild);
		if(p->rchild) Q.push(p->rchild);
	}
}

//递归求树高 
int treeDepth(BiTree T){
	if(T == NULL) return 0;
	
	int rightTree = treeDepth(T->rchild);
	int leftTree = treeDepth(T->lchild);
	
	return max(rightTree , leftTree) + 1;
}
//层序遍历求树高

int levelDepth(BiTree T){
	int level = 0;
	if(!T) return 0;
	queue<BiTNode*> Q;
	BiTNode* last = T; //记录每层最后一个结点，第一层最后一个节点就是根节点 
	BiTNode* front,*rear;//记录队首结点 队尾结点 
	
	Q.push(T);//根节点入队 
	while(!Q.empty()){
		front = Q.front();//取队首 
		Q.pop();//队首弹出 
		if(front->lchild){
		 	Q.push(front->lchild);//如果有左孩子那么左孩子入队 
		 	rear = front->lchild;
		}	
		if(front->rchild){
			Q.push(front->rchild);//如果有右孩子那么右孩子入队 
			rear = front->rchild;
		}
		if(front == last){//如果当前结点是该层最后一个结点 
			//cout<<front->data<<" ?? "<<rear->data<<endl; 
			level++;//那么层数+1 ，到达下一层 
			last = rear;//更新last，下一层的最后一个结点必然是最后入队的那个结点 
		}
	}
	return level;
} 
 
//层次遍历求树宽度
//在层次遍历基础上。增加对每一层结点数的统计，维护max 
int levelWidth(BiTree T){
	int level = 0;
	if(!T) return 0;
	queue<BiTNode*> Q;
	BiTNode* last = T; //记录每层最后一个结点，第一层最后一个节点就是根节点 
	BiTNode* front,*rear;//记录队首结点 队尾结点 
	int ans = 0;//记录最大宽度 
	int cur = 0;//记录当前层的宽度 
	Q.push(T);//根节点入队 
	while(!Q.empty()){
		front = Q.front();//取队首 
		Q.pop();//队首弹出 
		cur++;
		if(front->lchild){
		 	Q.push(front->lchild);//如果有左孩子那么左孩子入队 
		 	rear = front->lchild;  
		}	
		if(front->rchild){
			Q.push(front->rchild);//如果有右孩子那么右孩子入队 
			rear = front->rchild;
		}
		if(front == last){//如果当前结点是该层最后一个结点 
			//cout<<front->data<<" ?? "<<rear->data<<endl; 
			level++;//那么层数+1 ，到达下一层 
			last = rear;//更新last，下一层的最后一个结点必然是最后入队的那个结点
			
			//到达每层最后一个结点时就知道了这一层的总的结点数
			//维护最大值即可 
			ans = max(ans , cur);
			cur = 0; 
		}
	}
	return ans;
} 



//递归遍历求树的宽度
//相当于先序遍历一遍然后把每个结点所在的层数记录下来 
//每访问一个新结点就把该层的count加上1，最终得到所有层的宽度 
void treeWidth(BiTree T, int level, int count[]){
	if(T == NULL) return; //如果子树树根为空就不要再统计下去 
	count[level]++;//树在第level层的宽度+1 
	treeWidth(T->lchild , level+1, count);
	treeWidth(T->rchild , level+1, count);
} 

int treeWidth(BiTree T){
	int count[200] = {0};
	int maxx = 0;
	treeWidth(T,0,count);
	for(int i=0; i<200; i++){
		maxx = max(maxx , count[i]);
	}
	return maxx;
}

//判断时否是完全二叉树
//利用性质 完全二叉树与满二叉树在层次遍历上的联系和区别，前者是后者序列的一部分 

bool isComplete(BiTree T){
	queue<BiTNode*> Q;//Q中存储层次遍历序列 
	BiTNode* p;
	if(!T) return true;//空树也当成完全二叉树 它是满二叉树
	Q.push(T);//首结点入队 
	while(!Q.empty()){ //如果Q不空 
		p = Q.front(); // 取出队首 
		Q.pop();
		if(p){ //如果当前结点不空，将其左右孩子入队，不管孩子空不空 
			Q.push(p->lchild);
			Q.push(p->rchild);
		}
		else{ //如果当前结点为空，那么之后的序列不能有不空的结点，因为层次遍历ABCD.E显然是非法的 
			while(!Q.empty()){
				p = Q.front();
				Q.pop();
				if(p) return false;
			}
		}
	}
	return true; 
} 


//判断是否是二叉排序树
//递归判断

 

int main(){
	BiTree T;
	build(T);
	printf("构造完毕\n");
	cout<<"先序遍历"<<endl;
	PreOrder(T);
	cout<<"中序遍历"<<endl;
	InOrder(T);
	cout<<"后序遍历"<<endl;
	PostOrder(T);
	
	cout<<"非递归中序遍历"<<endl;
	InOrder2(T);
	cout<<"非递归先序遍历"<<endl;
	PreOrder2(T);
	cout<<"非递归后序遍历双栈法"<<endl;
	PostOrder2(T);
	cout<<"非递归后序遍历标记法"<<endl;
	postOrder3(T);
	
	cout<<"层序遍历"<<endl;
	levelOrder(T);
	
	cout<<"递归求树高："<<treeDepth(T)<<endl; 
	cout<<"层序求树高："<<levelDepth(T)<<endl;
	
	cout<<"递归求树宽度："<<treeWidth(T)<<endl;
	cout<<"非递归求树宽度: "<<levelWidth(T)<<endl;
	cout<<"是否是完全二叉树："<<isComplete(T)<<endl; 
	return 0;  
	
} 

//ABC..DE.G..F..H..
//ABS..C..DE..FG.H..I..
//ABD..E..CF... 完全二叉树  ABD..E..CF..G..满二叉树 
 
