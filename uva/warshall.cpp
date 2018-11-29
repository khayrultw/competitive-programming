#include<stdio.h>
#define INF 99999
    int main (){
    int i, j, k, n, e,a,b,c;
    int w[100][100];

     printf("Enter the number of nodes : ");
      scanf("%d",&n);

       for(i=1; i<=n; i++){
       		for(j=1; j<=n; j++){
		    	if(i==j){
		     		w[i][j] = 0;
		   	   	 }
		  		 else { 
		   			w[i][j] = INF;
		   		}
      	   }
       }
       for(i=1; i<=n; i++){
       		for(j=1; j<=n; j++){
          		 printf("%d ",w[i][j]);
         	}
       		 printf("\n");
         }
		 printf("Enter the number of edges : ");
		 scanf("%d",&e);
	     printf("Enter the number  of the adjacent nodes and value to go there : ");
	     for(i=1; i<=e; i++){
		 	scanf("%d %d %d",&a,&b,&c);
		 w[a][b] = c;
		 printf("\n");
      	}
		for (k=1; k<=n;k++){
			for(i=1; i<=n; i++){
		  		for(j=1; j<=n; j++){
		      	  	if(w[i][j]>w[i][k]+w[k][j]){
		       			 w[i][j]=w[i][k]+w[k][j];}
		    	 }
	  		}
		}

		
		 for(i=1; i<=n; i++){
		   for(j=1; j<=n; j++){
		       printf("%d ",w[i][j]);
		    }
		    printf("\n");
		 }
}
