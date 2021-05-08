void random_generation(int,int[]);
int identify_num(char[],int);
void copy_q(int*,int*,int);
struct node* bst_e(struct node*,int*,int);
void bs_e(int*,int*,int);
void arr_e(int*,int*,int);
struct List* ll_e(struct List*,int*,int);
void hash_e();
void bst_q(struct node*,int*,int);
void bs_q(int*,int*,int,int);
void arr_q(int*,int*,int,int);
void ll_q(struct List*,int*,int);
void hash_q();
struct List{
	int num;
	struct List* next;
};
struct node{
	int key;
	struct node *left,*right;
};
struct nodehash{
	int data;
	struct nodehash *next;
};
#define size 10
