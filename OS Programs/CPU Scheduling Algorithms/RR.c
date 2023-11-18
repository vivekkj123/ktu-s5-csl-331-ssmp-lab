#include <stdio.h>

int burst[20], n, waiting[20], turnaround[20], remaining[20],completed[20], ct[20], time = 0, qt;
void input() {
  printf("Enter Time Quantum: ");
  scanf("%d", &qt);	
  printf("Enter No. of Processes: ");
  scanf("%d", & n);
  for (int i = 0; i < n; i++) {
    printf("Enter Burst time for P%d: ", i + 1);
    scanf("%d", & burst[i]);
  }
}

void calculateWaiting() {
	int flag=1;
	for(int i=0; i<n; i++){
			waiting[i] = 0;
			completed[i] = 0;
	}
	while(flag){
		for(int i=0; i<n; i++){
			if(remaining[i] > 0){
				if(remaining[i] < qt){
					time += remaining[i];
					remaining[i] = 0;
				}else{
				  time += qt;
					remaining[i] = remaining[i] - qt; 
				}
				ct[i] = time;
		    	waiting[i] = ct[i] - burst[i];
			}else{
				completed[i] = 1;
				
			}
			for(int j=0; j<n; j++){
				if(completed[j]!=1){
					flag=1;
					break;
			}else{
					flag=0;
			}
		}
	}
}
}
void calculateTurnAround() {
  for (int i = 0; i < n; i++) {
    turnaround[i] = waiting[i] + burst[i];
  }
}
void printTable() {
  printf("\tProcess\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
  for (int i = 0; i < n; i++) {
    printf("\tP%d\t\t%d\t\t%d\t\t%d \n", i + 1, burst[i], waiting[i], turnaround[i]);
  }
}
float calcAverage(int a[20]) {
  float sum = 0, avg;
  for (int i = 0; i < n; i++) {
    sum = sum + a[i];
  }
  avg = sum / n;
  return avg;
}
void copyArray() {
  for (int i = 0; i < n; i++) {
    remaining[i] = burst[i];
  }
}
void main() {
  input();
  copyArray();
  calculateWaiting();
  calculateTurnAround();
  printTable();
  printf("\nAverage Waiting Time is: %f", calcAverage(waiting));
  printf("\nAverage Turn Around Time is: %f \n", calcAverage(turnaround));
}
