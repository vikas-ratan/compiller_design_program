#include<stdio.h>
int main(){
	int q=0;
	char s;
	while(!s){
		scanf("%c",&s);
		if(s=='0'||s=='1'){
			q=1;
		}
		else{
			q=0;
			break;
		}
	}
	if(q==1){
		printf("String is accepted.\n");
	}
	else{
		printf("String is not accepted.\n");
	}
}
