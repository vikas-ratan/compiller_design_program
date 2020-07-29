#include<stdio.h>
#include<string.h>
int main(){
	char inp=' ',A[30],B[30],C[30];
	int i=0,j,k,m;
	while(inp!='\n'){
		scanf("%c",&inp);
		A[i]=inp;
		i++;
		if(inp=='\n')
			break;
	}
	B[0]=A[0];
	B[1]=A[1];
	C[0]=A[0];
	C[1]='\'';
	C[2]=A[1];
	k=2;
	m=3;
	for(j=2;j<i;j++){
		if((A[j]=='|') && (A[j+1]!=A[0])){
			B[k]=A[j+1];
			B[k+1]=A[0];
			B[k+2]='\'';
			B[k+3]='|';
			k=k+4;
		}
		else if(A[j]==A[0]){
			C[m]=A[j+1];
			C[m+1]=A[0];
			C[m+2]='\'';
			C[m+3]='|';
			m=m+4;
		}
	}
	printf("\n");
	for(i=0;i<k-1;i++){
		printf("%c",B[i] );
	}
	printf("\n");
	for(i=0;i<m;i++){
		printf("%c",C[i] );
	}
	printf("epsilon\n");
}