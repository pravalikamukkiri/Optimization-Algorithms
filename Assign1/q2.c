#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  int long long
#define BILLION  1000000000L
int v;
int **graph;
int floydwarshell(){
	int i,j,k;
	for(k=1;k<=v;k++){
		for(i=1;i<=v;i++){
			for(j=1;j<=v;j++){
				if(graph[i][k]+graph[k][j] < graph[i][j]){
					graph[i][j]=graph[i][k]+graph[k][j];
				}
			}
		}
	}
}
int onedarray(){
	int i,j,k;
	int *rowi;
	int *rowk;
	for(k=1;k<=v;k++){
		rowk=*(graph+k);
		for(i=1;i<=v;i++){
			rowi=*(graph+i);
			for(j=1;j<=v;j++){
				if(*(rowi+k)+*(rowk+j) < *(rowi+j)){
					*(rowi+j)=*(rowi+k)+*(rowk+j);
				}
			}
		}
	}
}

int preincrement(){
	int i,j,k;
	int *rowi;
	int *rowk;
	for(k=1;k<=v;++k){
		rowk=*(graph+k);
		for(i=1;i<=v;++i){
			rowi=*(graph+i);
			for(j=1;j<=v;++j){
				if(*(rowi+k)+*(rowk+j) < *(rowi+j)){
					*(rowi+j)=*(rowi+k)+*(rowk+j);
				}
			}
		}
	}
}


int main()
{
	struct timespec start, stop;
	int t,n,i,j,k,e,x,y,w;
	scanf("%lld %lld",&v,&e);
	// if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
 //      perror( "clock gettime" );
 //      return EXIT_FAILURE;
 //    }

	// v=2000;
	// e=89896;
	graph=(int **)malloc((v+5) *sizeof(int));
	for (i=0;i<v+5;i++)
		graph[i]=(int *)malloc((v+5)*sizeof(int));
	srand(time(0));
	for(i=1;i<=v;i++){
		for(j=1;j<=v;j++){
			graph[i][j]=9999999;
		}
	}
	for(i=1;i<=e;i++){
		scanf("%lld %lld %lld",&x,&y,&w);
		// x=rand()%v+1;
		// y=rand()%v+1;
		// w=rand()%100000+1;
		graph[x][y]=w;
	}
	for(i=1;i<=v;i++)
		graph[i][i]=0;

	// floydwarshell();
	// onedarray();
	preincrement();
	// checkingconditionsoutisde();
	// printf("\n\n\n");
	for(i=1;i<=v;i++){
		for(j=1;j<=v;j++){
			if(graph[i][j]==9999999)
				printf("%d ",-1);
			else
				printf("%lld ",graph[i][j] );
		}
		printf("\n");
	}
	// if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
 //      perror( "clock gettime" );
 //      return EXIT_FAILURE;
 //    }

	// double S = ( stop.tv_sec - start.tv_sec );
    // double NS =  (double)( stop.tv_nsec - start.tv_nsec )/(double)BILLION;
    // printf("Time: %lf\n", S + NS);
	return 0;

}