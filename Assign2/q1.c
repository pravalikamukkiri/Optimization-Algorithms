#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define  int long long
#define BILLION  1000000000L
int p,q,x2,y2;


typedef struct Matrix{
	int matrix[1005][1005];
}Matrix;
Matrix * ans;
Matrix * arr1;
Matrix * res;
int step_i=0;


void onedarray(){
	int i,j,l,k;
	res=malloc(sizeof(Matrix));
	int *am;
	int *rm;
	int *arm;
	for(i=0;i<p;++i){
		am=*(ans->matrix + i);
		rm=*(res->matrix + i);
		for(k=0;k<x2;++k){
			arm=*(arr1->matrix+k);
			for(j=0;j<y2;++j)
				*(rm+j)+=*(am+k)**(arm+j);
		}
	}
}

void parallelprogramming(){
	int i,j,l,k;
	res=malloc(sizeof(Matrix));
	int *am;
	int *rm;
	int *arm;
	#pragma omp parallel for
	for(i=0;i<p;++i){
		am=*(ans->matrix + i);
		rm=*(res->matrix + i);
		for(k=0;k<x2;++k){
			arm=*(arr1->matrix+k);
			for(j=0;j<y2;++j)
				*(rm+j)+=*(am+k)**(arm+j);
		}
	}
}
int min(int a,int b){
	if(a>b)
		return b;
	else
		return a;
}

void tiling(){
	int ih,il,jh,jl,l,s,kh,kl;
	s=32;
	res=malloc(sizeof(Matrix));
	#pragma omp parallel for private(jh,kh,il,jl,kl)
	for(ih=0;ih<p;ih+=s){
		for(jh=0;jh<y2; jh+=s){
			for(kh=0; kh<x2; kh+=s){
				for(il=ih;il<min(ih+s,p);++il){
					for(kl=kh; kl<min(kh+s,x2); ++kl){
						for(jl=jh; jl<min(jh+s,y2); ++jl){
							res->matrix[il][jl]+=ans->matrix[il][kl] * arr1->matrix[kl][jl];
						}
					}
				}
			}
		}
	}
}



int main(){
	struct timespec start, stop;

	int n,x1,y1,a,i,j,k,l;
	ans=malloc(sizeof(Matrix));	
	arr1=malloc(sizeof(Matrix));
	if(!scanf("%lld",&n))
		printf("not valid input\n");

	for(i=0;i<n;i++){
		if(!scanf("%lld %lld",&x1,&y1))
			printf("not valid input\n");

		for(j=0;j<x1;j++){
			for(k=0;k<y1;k++){
				if(!scanf("%lld",&a))
					printf("not valid input\n");
				arr1->matrix[j][k]=a;
				if(i==0){
					ans->matrix[j][k]=a;
				}
			}
		}
		if(i==0){
			p=x1;q=y1;

			continue;
		}
		x2=x1;
		y2=y1;
		// onedarray(); //storing in one d array
		// parallelprogramming();
		tiling();

		
		q=y1;
		for(l=0;l<p;l++){
			for(j=0;j<y1;j++){
				ans->matrix[l][j]=res->matrix[l][j];
			}
		}

	}
	printf("%lld %lld\n",p,q );
	for(l=0;l<p;l++){
		for(j=0;j<q;j++){
			printf("%lld ",ans->matrix[l][j] );
		}
		printf("\n");
	}

}