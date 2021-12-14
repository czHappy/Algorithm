#include<iostream>
#include<stack> 
#include<queue> 
using namespace std;

//ADT
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree; 

//���� 
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
//ǰ��ݹ� 
void PreOrder(BiTree T){
	if(T != NULL){
		cout<<T->data<<endl;;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//����ݹ� 
void InOrder(BiTree T){
	if(T != NULL){
		InOrder(T->lchild);
		cout<<T->data<<endl;
		InOrder(T->rchild);
	}
}

//����ݹ� 
void PostOrder(BiTree T){
	if(T != NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout<<T->data<<endl;;
	}
}

//ǰ������ǵݹ�汾 
//������������������������ܷ���������������Ҫ����ջ�����浱ǰ�����ĸ��ڵ� 
void PreOrder2(BiTree T){
	stack<BiTNode*> S;//����һ��ջ 
	BiTree p = T;//����ָ�� ��ʼָ��root 
	while(p || !S.empty()){ //ֻҪ���н�� 
		if(p){ //�����ǰ��㲻�� 
			cout<<p->data<<endl; //���ӡ��ǰ��� ��Ϊ�����������½��ʹ�ӡ 
			S.push(p);//��ǰ�����ջ 
			p = p->lchild;//��������������������ʽ�� 
		}
		else{
			p = S.top();//�����ǰ����ǿյģ����˻ص���һ����� 
			S.pop();//��ջ 
			p = p->rchild;//������������ 
		}
	}
}

//����ǵݹ�  �� �� ��
//���ڵ�������������֮���ٷ��ʣ������ڵ������������ӽڵ㱻����������Ҫ����һ��ջ������ 
void InOrder2(BiTree T){
	stack<BiTNode*> S;//����һ��ջ 
	BiTree p = T;//������ 
	while(p || !S.empty()){ //������н�� 
		if(p){//�����ǰ��㲻Ϊ�� 
			S.push(p);// ��Ҫ���ڷ��ʸ��ڵ㣬��ѹջ�� 
			p = p->lchild;//���������� 
		}
		else{//�����ǰ�ڵ��ǿյġ�����Ҫ�˻ص���һ����� 
			p = S.top();
			S.pop();//�˵��������ĸ��ڵ��������� 
			cout<<p->data<<endl;
			p = p->rchild;//��������������  
		}
	}
}

//����ǵݹ� ˫ջ��
//�������� �� �У������ջ������������
//�ȿ����ڵ㣬�ٿ��Һ��ӣ��ٿ����� 
void PostOrder2(BiTree T){
	stack<BiTNode*> S; //����ջ 
	stack<BiTNode*> result; //���ջ 
	BiTree p = T;//������ 
	while(p || !S.empty()){
		if(p){ //�����ǰ��㲻Ϊ�� 
			S.push(p);//�����ջ 
			result.push(p);//�������ջ 
			p = p->rchild;//�����Һ��ӽ�� 
		}  
		else{ //�����ǰ���Ϊ�� ���˵���һ����� 
			p = S.top();
			S.pop();//��ջ 
			p = p->lchild;//�������ӽ�� 
		}
	}
	//����������� 
	while(!result.empty()){
		p = result.top();
		result.pop();
		cout<<p->data<<endl;
	}
}

// �������  ���ʱ�Ƿ�
void postOrder3(BiTree T){
	stack<BiTNode*> S; //����һ��ջ 
	BiTNode* p = T; //������ 
	BiTNode* r = NULL; //����������ʹ��Ľ�� 
	while(p || !S.empty()){
		if(p){ //�����ǰ��㲻Ϊ�� ���ߵ�������������� 
			
			S.push(p);
			p = p->lchild;
		}
		else{ //��Ϊ�գ��˵���һ����� 
			p = S.top();
			if(p->rchild && p->rchild != r){ //�����������������������û�б����ʹ� 
				p = p->rchild;//��ô��ת������������ 
				S.push(p); // �����������ڵ� 
				p = p->lchild; //����������������� 
			} 
			else{
				p = S.top(); 
				S.pop();//û���������ǾͿ��Է��ʸ��ڵ��� 
				cout<<p->data<<endl;
				r = p; //���rΪ������ʵĽ��
				p = NULL; //��ǰ�����Ϊ�� ����Ϊ��������ĸ��ڵ㶼��������˵�����������ȫ���������ˣ��͵ȴ��˻���һ���������ڵ� 
			}
		}
	} 
} 
 
//������� ���� 
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

//�ݹ������� 
int treeDepth(BiTree T){
	if(T == NULL) return 0;
	
	int rightTree = treeDepth(T->rchild);
	int leftTree = treeDepth(T->lchild);
	
	return max(rightTree , leftTree) + 1;
}
//�������������

int levelDepth(BiTree T){
	int level = 0;
	if(!T) return 0;
	queue<BiTNode*> Q;
	BiTNode* last = T; //��¼ÿ�����һ����㣬��һ�����һ���ڵ���Ǹ��ڵ� 
	BiTNode* front,*rear;//��¼���׽�� ��β��� 
	
	Q.push(T);//���ڵ���� 
	while(!Q.empty()){
		front = Q.front();//ȡ���� 
		Q.pop();//���׵��� 
		if(front->lchild){
		 	Q.push(front->lchild);//�����������ô������� 
		 	rear = front->lchild;
		}	
		if(front->rchild){
			Q.push(front->rchild);//������Һ�����ô�Һ������ 
			rear = front->rchild;
		}
		if(front == last){//�����ǰ����Ǹò����һ����� 
			//cout<<front->data<<" ?? "<<rear->data<<endl; 
			level++;//��ô����+1 ��������һ�� 
			last = rear;//����last����һ������һ������Ȼ�������ӵ��Ǹ���� 
		}
	}
	return level;
} 
 
//��α����������
//�ڲ�α��������ϡ����Ӷ�ÿһ��������ͳ�ƣ�ά��max 
int levelWidth(BiTree T){
	int level = 0;
	if(!T) return 0;
	queue<BiTNode*> Q;
	BiTNode* last = T; //��¼ÿ�����һ����㣬��һ�����һ���ڵ���Ǹ��ڵ� 
	BiTNode* front,*rear;//��¼���׽�� ��β��� 
	int ans = 0;//��¼����� 
	int cur = 0;//��¼��ǰ��Ŀ�� 
	Q.push(T);//���ڵ���� 
	while(!Q.empty()){
		front = Q.front();//ȡ���� 
		Q.pop();//���׵��� 
		cur++;
		if(front->lchild){
		 	Q.push(front->lchild);//�����������ô������� 
		 	rear = front->lchild;  
		}	
		if(front->rchild){
			Q.push(front->rchild);//������Һ�����ô�Һ������ 
			rear = front->rchild;
		}
		if(front == last){//�����ǰ����Ǹò����һ����� 
			//cout<<front->data<<" ?? "<<rear->data<<endl; 
			level++;//��ô����+1 ��������һ�� 
			last = rear;//����last����һ������һ������Ȼ�������ӵ��Ǹ����
			
			//����ÿ�����һ�����ʱ��֪������һ����ܵĽ����
			//ά�����ֵ���� 
			ans = max(ans , cur);
			cur = 0; 
		}
	}
	return ans;
} 



//�ݹ���������Ŀ��
//�൱���������һ��Ȼ���ÿ��������ڵĲ�����¼���� 
//ÿ����һ���½��ͰѸò��count����1�����յõ����в�Ŀ�� 
void treeWidth(BiTree T, int level, int count[]){
	if(T == NULL) return; //�����������Ϊ�վͲ�Ҫ��ͳ����ȥ 
	count[level]++;//���ڵ�level��Ŀ��+1 
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

//�ж�ʱ������ȫ������
//�������� ��ȫ�����������������ڲ�α����ϵ���ϵ������ǰ���Ǻ������е�һ���� 

bool isComplete(BiTree T){
	queue<BiTNode*> Q;//Q�д洢��α������� 
	BiTNode* p;
	if(!T) return true;//����Ҳ������ȫ������ ������������
	Q.push(T);//�׽����� 
	while(!Q.empty()){ //���Q���� 
		p = Q.front(); // ȡ������ 
		Q.pop();
		if(p){ //�����ǰ��㲻�գ��������Һ�����ӣ����ܺ��ӿղ��� 
			Q.push(p->lchild);
			Q.push(p->rchild);
		}
		else{ //�����ǰ���Ϊ�գ���ô֮������в����в��յĽ�㣬��Ϊ��α���ABCD.E��Ȼ�ǷǷ��� 
			while(!Q.empty()){
				p = Q.front();
				Q.pop();
				if(p) return false;
			}
		}
	}
	return true; 
} 


//�ж��Ƿ��Ƕ���������
//�ݹ��ж�

 

int main(){
	BiTree T;
	build(T);
	printf("�������\n");
	cout<<"�������"<<endl;
	PreOrder(T);
	cout<<"�������"<<endl;
	InOrder(T);
	cout<<"�������"<<endl;
	PostOrder(T);
	
	cout<<"�ǵݹ��������"<<endl;
	InOrder2(T);
	cout<<"�ǵݹ��������"<<endl;
	PreOrder2(T);
	cout<<"�ǵݹ�������˫ջ��"<<endl;
	PostOrder2(T);
	cout<<"�ǵݹ���������Ƿ�"<<endl;
	postOrder3(T);
	
	cout<<"�������"<<endl;
	levelOrder(T);
	
	cout<<"�ݹ������ߣ�"<<treeDepth(T)<<endl; 
	cout<<"���������ߣ�"<<levelDepth(T)<<endl;
	
	cout<<"�ݹ�������ȣ�"<<treeWidth(T)<<endl;
	cout<<"�ǵݹ��������: "<<levelWidth(T)<<endl;
	cout<<"�Ƿ�����ȫ��������"<<isComplete(T)<<endl; 
	return 0;  
	
} 

//ABC..DE.G..F..H..
//ABS..C..DE..FG.H..I..
//ABD..E..CF... ��ȫ������  ABD..E..CF..G..�������� 
 
