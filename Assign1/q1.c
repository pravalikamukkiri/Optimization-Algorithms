#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define  int long long
#define BILLION  1000000000L
int p,q,x2,y2;

// int ans[1005][1005];
// int arr1[1005][1005];

typedef struct Matrix{
	int matrix[1005][1005];
}Matrix;
Matrix * ans;
Matrix * arr1;
Matrix * res;

void matrixmultiplicationijk(){
	int i,j,l,k;
	res=malloc(sizeof(Matrix));
	for(i=0;i<p;i++){
		for(j=0;j<y2;j++){
			for(k=0;k<x2;k++)
				res->matrix[i][j]+=ans->matrix[i][k]*arr1->matrix[k][j];
		}
	}
}
void matrixmultiplicationikj(){
	int i,j,l,k;
	res=malloc(sizeof(Matrix));
	for(i=0;i<p;i++){
		for(k=0;k<x2;k++){
			for(j=0;j<y2;j++)
				res->matrix[i][j]+=ans->matrix[i][k]*arr1->matrix[k][j];
		}
	}
}
void preincrement(){
	int i,j,l,k;
	res=malloc(sizeof(Matrix));
	for(i=0;i<p;++i){
		for(k=0;k<x2;++k){
			for(j=0;j<y2;++j)
				res->matrix[i][j]+=ans->matrix[i][k]*arr1->matrix[k][j];
		}
	}
}

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


int main(){
	struct timespec start, stop;

	int n,x1,y1,a,i,j,k,l;
	ans=malloc(sizeof(Matrix));	
	arr1=malloc(sizeof(Matrix));
	scanf("%lld",&n);

	// if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
 //      perror( "clock gettime" );
 //      return EXIT_FAILURE;
 //    }

	for(i=0;i<n;i++){
		scanf("%lld %lld",&x1,&y1);
		// x1=900;
		// y1=900;
		for(j=0;j<x1;j++){
			for(k=0;k<y1;k++){
				scanf("%lld",&a);
				// a=rand()%15+1;
				// printf("%lld  ",a );
				arr1->matrix[j][k]=a;
				if(i==0){
					ans->matrix[j][k]=a;
				}
			}
			// printf("\n");
		}
		if(i==0){
			p=x1;q=y1;

			continue;
		}
		// int res[p][y1];
		x2=x1;
		y2=y1;
		// matrixmultiplicationijk(); //without optimization
		// matrixmultiplicationikj(); //changing loop order
		// preincrement(); //preincreent
		onedarray(res); //storing in one d array
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

	// if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
 //      perror( "clock gettime" );
 //      return EXIT_FAILURE;
 //    }

	double S = ( stop.tv_sec - start.tv_sec );
    double NS =  (double)( stop.tv_nsec - start.tv_nsec )/(double)BILLION;
    // printf("Time: %lf\n", S + NS);

}