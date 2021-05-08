#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<sys/time.h>
#include<stdlib.h>
#include"preparation.h"
#define INF 1000000
#define True 1
#define False 0

char *getword(char *line,char *word){
	char *ptr=line;
	char *qtr=word;
	while(isspace(*ptr) && *ptr){
		ptr++;
	}
	while(!isspace(*ptr) && *ptr){
		*qtr++ = *ptr++;
	}
	*qtr = '\0';
	if(qtr-word==0){
		return NULL;
	}
	return ptr;
}

int main(int argc,char **argv){
	
	int d=False;
	char dnum [10];
	int dnum_int=0;
	int q=False;
	char qnum [10];
	int qnum_int=0;
	int bst=False;
	int bs=False;
	int arr=False;
	int ll=False;
	int hash=False;
	int *num_origin_d;
	int *num_origin_q;
	int *num_d;
	int *num_q;
	struct List* Keylist=NULL;
	struct node* root=NULL;
	struct nodehash* chain[size];

	for(int i=1;i<argc;i++){
	       if(strcmp(argv[i],"-d")==0){
		        d=True;
			strcpy(dnum,argv[i+1]);
			i++;	
	       }else if(strcmp(argv[i],"-q")==0){
			q=True;
			strcpy(qnum,argv[i+1]);
			i++;
	       }else if(strcmp(argv[i],"-bst")==0){
			bst=True;
	       }else if(strcmp(argv[i],"-bs")==0){
		        bs=True;
	       }else if(strcmp(argv[i],"-arr")==0){
			arr=True;
	       }else if(strcmp(argv[i],"-ll")==0){
		        ll=True;
	       }else if(strcmp(argv[i],"-hash")==0){
		       hash=True;
	       }
	}

	if(d==True){
		dnum_int=identify_num(dnum,dnum_int);
		num_origin_d=(int*)malloc(sizeof(int)*dnum_int);
		random_generation(dnum_int,num_origin_d);
	}
	if(q==True){
		qnum_int=identify_num(qnum,qnum_int);
		num_origin_q=(int*)malloc(sizeof(int)*dnum_int);
		random_generation(qnum_int,num_origin_q);
	}

	struct timeval start_bst;
	struct timeval end_bst;
	unsigned long differ_bst;
	struct timeval start_bs;
	struct timeval end_bs;
	unsigned long differ_bs;
	struct timeval start_arr;
	struct timeval end_arr;
	unsigned long differ_arr;
	struct timeval start_ll;
	struct timeval end_ll;
	unsigned long differ_ll;
	struct timeval start_hash;
	struct timeval end_hash;
	unsigned long differ_hash;
	num_d=(int*)malloc(sizeof(int)*dnum_int);
	num_q=(int*)malloc(sizeof(int)*qnum_int);
	
	if(bst==True){
		copy_q(num_q,num_origin_q,qnum_int);
		gettimeofday(&start_bst,NULL);
		root=bst_e(root,num_origin_d,dnum_int);
		bst_q(root,num_origin_q,qnum_int);
		gettimeofday(&end_bst,NULL);
		differ_bst=1000000*(end_bst.tv_sec-start_bst.tv_sec)+end_bst.tv_usec-start_bst.tv_usec;
		printf("bst: %f sec\n",differ_bst/1000000.0);
	
	}
	if(bs==True){
		copy_q(num_q,num_origin_q,qnum_int);
		gettimeofday(&start_bs,NULL);
		bs_e(num_d,num_origin_d,dnum_int);
		bs_q(num_d,num_q,dnum_int,qnum_int);
		gettimeofday(&end_bs,NULL);
		differ_bs=1000000*(end_bs.tv_sec-start_bs.tv_sec)+end_bs.tv_usec-start_bs.tv_usec;
		printf("bs: %f sec\n",differ_bs/1000000.0);
	}
	if(arr==True){
		copy_q(num_q,num_origin_q,qnum_int);
		gettimeofday(&start_arr,NULL);
		arr_e(num_d,num_origin_d,dnum_int);
		arr_q(num_d,num_q,dnum_int,qnum_int);
		gettimeofday(&end_arr,NULL);
		differ_arr=1000000*(end_arr.tv_sec-start_arr.tv_sec)+end_arr.tv_usec-start_arr.tv_usec;
		printf("arr: %f sec\n",differ_arr/1000000.0);
	}
	if(ll==True){
		copy_q(num_q,num_origin_q,qnum_int);
		gettimeofday(&start_ll,NULL);
		Keylist=ll_e(Keylist,num_origin_d,dnum_int);
		ll_q(Keylist,num_q,qnum_int);
		gettimeofday(&end_ll,NULL);
		differ_ll=1000000*(end_ll.tv_sec-start_ll.tv_sec)+end_ll.tv_usec-start_ll.tv_usec;
	printf("ll: %f sec\n",differ_ll/1000000.0);
	}
	if(hash==True){
		copy_q(num_q,num_origin_q,qnum_int);
		for(int i=0;i<size;i++){
			chain[i]=NULL;

		}
		gettimeofday(&start_hash,NULL);
		hash_e(chain,num_origin_d,dnum_int);
		hash_q(chain,num_q,qnum_int);
/*		for(int i=0;i<size;i++){
		struct nodehash* temphash=chain[i];
		printf("chain[%d]-->",i);
		while(temphash){
			printf("%d-->",temphash->data);
			temphash=temphash->next;
		}
		printf("NULL\n");
	}
*/		gettimeofday(&end_hash,NULL);
		differ_hash=1000000*(end_hash.tv_sec-start_hash.tv_sec)+end_hash.tv_usec-start_hash.tv_usec;
		printf("hash: %f sec\n",differ_hash/1000000.0);

	}
}
