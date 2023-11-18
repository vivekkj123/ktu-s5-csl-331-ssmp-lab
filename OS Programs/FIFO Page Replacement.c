#include<stdio.h>
int refString[30], frame[30], allocated[30], pageFaults, nr, nf,hit, flag, k=0;
void input(){
	printf("Enter no. of Reference Strings: ");
	scanf("%d", &nr);
	printf("Enter Reference String sizes:");
	for(int i=0; i<nr; i++){
		scanf("%d", &refString[i]);
	}
	printf("Enter no. of Frames: ");
	scanf("%d", &nf);
}
void fifo(){
	int rp, val, rpVal;
	for(int i=0; i<nf; i++){
		frame[i] = -1;
	}
	for(int i=0; i<nr; i++){
		flag=0;
		for(int j=0; j<nf; j++){
			if(frame[j] == refString[i]){
				flag=1;
				hit++;
				break;
			}
		}
		if(flag==0){
			frame[k] = refString[i];
			k=(k+1)%nf;
			pageFaults++;
		}
	}
}

void print(){
	printf("\n  No. of Page Faults: %d \n No. of Page hits: %d \n", pageFaults, hit);
	printf(" Final Frame Status: \n");
	for(int i=nf; i>0; i--){
		printf("%d \n", frame[i]);
	}
}
void main(){
	input();
	fifo();
	print();
}
