#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int nr, requests[40], inPos, pos, dist=0;
void input(){
	printf("Enter no. of Requests: ");
	scanf("%d", &nr);
	printf("Enter Requests Sequence: ");
	for(int i=0; i<nr; i++){
		scanf("%d", &requests[i]);
	}
	printf("Enter Initial head position: ");
	scanf("%d", &pos);
	inPos = pos;
}
void fcfs(){
	for(int i=0; i<nr; i++){
		dist = dist+abs(pos-requests[i]);
		pos = requests[i];
	}
}
void output(){
	printf("Total seek distance is %d", dist);
	printf("\n Seek Movement sequece:");
	printf("%d", inPos);
	for(int i=0; i<nr; i++){
		printf("-> %d ", requests[i]);
	}
}
void main(){
	input();
	fcfs();
	output();
}
