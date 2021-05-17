#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"preparation.h"
void random_generation(int num,int arr[]){
	for(int i=0;i<num;i++){
		arr[i]=i;
	}
	srand(time(NULL));
	for(int i=0;i<num;i++){
		int num1=rand()%num;
		int num2=rand()%num;
		
		int t=arr[num1];
		arr[num1]=arr[num2];
		arr[num2]=t;
	}
}
//----------------------------------------------------------
int identify_num(char num[],int num_int){
	int front;
	int back;
	int sum=1;
	int flag=0;
	for(int i=0;i<strlen(num);i++){
		if(num[i]=='e'){
			flag=1;
			front=num[i-1]-'0';
			back=num[i+1]-'0';
			break;
		}
	}
	if(flag==1){
		while(back--){
			sum*=(front*10);
		}
		return sum;
	}
	return atoi(num);
}
//---------------------------------------------------------
void copy_q(int* num_q,int* num_origin_q,int qnum_int){
	for(int i=0;i<qnum_int;i++){
		num_q[i]=num_origin_q[i];
	}
}
//---------------------------------------------------------------
/*void inorder(struct node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d\n",root->key);
		inorder(root->right);
	}
}*/
struct node* newNode(int item){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->key=item;
	temp->left=temp->right=NULL;
	return temp;
}
struct node* insertbst(struct node* node,int key){
	if(node==NULL){return newNode(key);}
	if(key<node->key)
		node->left=insertbst(node->left,key);
	else if(key>node->key)
		node->right=insertbst(node->right,key);
	return node;
}
struct node* bst_e(struct node* root,int* num_origin_d,int dnum_int){
	for(int i=0;i<dnum_int;i++){
		root=insertbst(root,num_origin_d[i]);
	}
	return root;
}
//-------------------------------------------------------------
void swap(int* a,int* b){
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int* num_d,int low,int high){
	int pivot=num_d[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		if(num_d[j]<=pivot){
			i++;
			swap(&num_d[i],&num_d[j]);
		}
	}
	swap(&num_d[i+1],&num_d[high]);
	return i+1;
}
void quicksort(int* num_d,int low,int high){
	if(low<high){
		int pivot=partition(num_d,low,high);
		quicksort(num_d,low,pivot-1);
		quicksort(num_d,pivot+1,high);
	}
}
void bs_e(int* num_d,int *num_origin_d,int dnum_int){
	for(int i=0;i<dnum_int;i++){
		num_d[i]=num_origin_d[i];
	}
	quicksort(num_d,0,dnum_int-1);
}
//----------------------------------------------------------
void arr_e(int* num_d,int *num_origin_d,int dnum_int){
	for(int i=0;i<dnum_int;i++){
		num_d[i]=num_origin_d[i];
	}
}
//----------------------------------------------------------
struct List* insert(struct List *Keylist,int num_origin_d){
	struct List* t=(struct List*)malloc(sizeof(struct List));
	t->num=num_origin_d;
	t->next=Keylist;
	return t;
	
/*	struct List* origin;
	t->num=num_origin_d;
	origin=t;
	if(Keylist==NULL){
		return t;
	}
	t=Keylist;
	while(t->next){
		t=t->next;
	}
	origin->next=NULL;
	t->next=origin;
	return Keylist;
*/}
struct List* ll_e(struct List *Keylist,int* num_origin_d,int dnum_int){
	for(int i=0;i<dnum_int;i++){
		Keylist=insert(Keylist,num_origin_d[i]);
	}
	return Keylist;	
}
//----------------------------------------------------------------
void printhash(struct nodehash** chain){
	for(int i=0;i<size;i++){
		struct nodehash* temphash=chain[i];
		printf("chain[%d]-->",i);
		while(temphash){
			printf("%d-->",temphash->data);
			temphash=temphash->next;
		}
		printf("NULL\n");
	}
}
struct nodehash** inserthash(struct nodehash** chain, int value){
	struct nodehash *newNodehash=(struct nodehash*)malloc(sizeof(struct nodehash));
	newNodehash->data=value;
	newNodehash->next=NULL;
	int key=value%size;
	if(chain[key]==NULL){
		chain[key]=newNodehash;
		return chain;
	}
	else{
		struct nodehash* temphash=chain[key];
		struct nodehash* tempano=chain[key]->next;
		newNodehash->next=tempano;
		temphash->next=newNodehash;
		return chain;
/*		while(temphash->next){
			temphash=temphash->next;
		}
		temphash->next=newNodehash;
*/	}
}
void hash_e(struct nodehash** chain,int* num_origin_d,int dnum_int){
	for(int i=0;i<dnum_int;i++){
		chain=inserthash(chain,num_origin_d[i]);
	}
}
//--------------------------------------------------------------
/*struct node* minValueNode(struct node* node){
	struct node* current=node;
	while(current&&current->left!=NULL)
		current=current->left;
	return current;
}*/
struct node* find(struct node* root,int key){
	if(root==NULL)return root;
	if(key<root->key)
		root->left=find(root->left,key);
	else if(key>root->key)
		root->right=find(root->right,key);
	else{
		return root;
		/*if(root->left==NULL){
			//struct node* temp=root->right;
			printf("%d\n",temp->key);//<delete> free(root);
			return temp;
		}else if(root->right==NULL){
			//struct node* temp=root->left;
			printf("%d\n",temp->key);//<delete>
			return temp;
		}*/
		/*struct node* temp=minValueNode(root->right);
		root->key=temp->key;
		root->right=find(root->right,temp->key);*/
	}
	return root;
}
void bst_q(struct node* root,int* num_q,int qnum_int){
	for(int i=0;i<qnum_int;i++){
		find(root,num_q[i]);
	}
}
//--------------------------------------------------------------
int binarysearch(int* num_d,int l,int r,int x){
	if(r>=l){
		int mid=l+(r-l)/2;
		if(num_d[mid]==x){
			return mid;
		}
		if(num_d[mid]>x){
			return binarysearch(num_d,l,mid-1,x);
		}
		return binarysearch(num_d,mid+1,r,x);
	}
	return -1;
}
void bs_q(int* num_d,int* num_q,int dnum_int,int qnum_int){
	for(int i=0;i<qnum_int;i++){
		binarysearch(num_d,0,dnum_int-1,num_q[i]);
	}
}
//--------------------------------------------------------------
void arr_q(int* num_d,int* num_q,int dnum_int,int qnum_int){
	for(int i=0;i<qnum_int;i++){
		for(int j=0;j<dnum_int;j++){
			if(num_q[i]==num_d[j]){
				break;
			}
		}
	}
}
//--------------------------------------------------------------
void ll_q(struct List* Keylist,int* num_origin_q,int qnum_int){
	struct List* p;
	for(int i=0;i<qnum_int;i++){
		p=Keylist;
		while(p!=NULL){
			if(p->num==num_origin_q[i]){
				break;
			}
			p=p->next;
		}
	}
}
//----------------------------------------------------------------
void findhash(struct nodehash** chain,int value){
	int key=value%size;
	struct nodehash* temp=chain[key];
	while(temp->next){
		if(temp->data==value)break;
		else temp=temp->next;
	}
}
void hash_q(struct nodehash** chain,int* num_q,int qnum_int){
	for(int i=0;i<qnum_int;i++){
		findhash(chain,num_q[i]);
	}
}
