#include<stdio.h>
int n,burst[30], waiting[30], turnaround[30], time=0, arrival[30], sorted[30];
float avgW, avgT;
void input(){
	printf("Enter no of processes: ");
	scanf("%d", &n);
	printf("Enter the burst time: ");
	for(int i=0; i<n; i++){
		scanf("%d", &burst[i]);
	}
	printf("Enter the arrival time: ");
	for(int i=0; i<n; i++){
		scanf("%d", &arrival[i]);
	}
}
void copy(){
	for(int i=0; i<n; i++){
		sorted[i] = burst[i];
	}
}
void sort(){
	int temp;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(arrival[i] > arrival[j]){
				temp = arrival[j];
				arrival[j] = arrival[i];
				arrival[i]=temp;
				temp = sorted[j];
				sorted[j] = sorted[i];
				sorted[i]=temp;
			}
		}
	}
}
void fcfs(){
	for(int i=0; i<n; i++){
		waiting[i]=time-arrival[i];
		time = time+sorted[i];
		turnaround[i]=sorted[i]+waiting[i];
	}
}
void Avg(){
	float sum=0;
	for(int i=0; i<n; i++){
		sum+=waiting[i];
	}
	avgW=sum/n;
	sum=0;
	for(int i=0; i<n; i++){
		sum+=turnaround[i];
	}
	avgT=sum/n;
}
void print(){
	int flag[30];
	printf("\tProcess \t Arrival Time \t Burst Time \t Waiting Time \t Turn Around Time");
	for(int i=0; i<n; i++){
		
		for(int j=0; j<n; j++){
			if(sorted[i] == burst[j] && flag[j]!=1){
			printf("\n\tP%d \t\t %d \t\t %d \t\t %d \t\t %d", j,arrival[i], sorted[i], waiting[i], turnaround[i] );
			flag[j]=1;
			break;
			}
		}
	}
	printf("\nAverage Waiting Time : %f", avgW);
	printf("\nAverage Turn Around Time : %f", avgT);
}
void main(){
	input();
	copy();
	sort();
	fcfs();
	Avg();
	print();
	
}
