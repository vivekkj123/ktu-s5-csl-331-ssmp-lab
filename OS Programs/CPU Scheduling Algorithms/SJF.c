#include <stdio.h>

int burst[20], n, waiting[20], turnaround[20], sorted[20], time = 0;
void input() {
  printf("Enter No. of Processes: ");
  scanf("%d", & n);
  for (int i = 0; i < n; i++) {
    printf("Enter Burst time for P%d: ", i + 1);
    scanf("%d", & burst[i]);
  }
}
void calculateWaiting() {
  for (int i = 0; i < n; i++) {
    waiting[i] = time;
    time += sorted[i];
  }
}
void calculateTurnAround() {
  for (int i = 0; i < n; i++) {
    turnaround[i] = waiting[i] + sorted[i];
  }
}
void printTable() {
  int flag[n];
  printf("\tProcess\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (burst[j] == sorted[i] && flag[j] != 1) {

        printf("\tP%d", j + 1);
        flag[j] = 1;
        break;
      }
    }
    printf("\t\t%d\t\t%d\t\t%d \n", sorted[i], waiting[i], turnaround[i]);
  }
}
int calcAverage(int a[20]) {
  int sum = 0, avg;
  for (int i = 0; i < n; i++) {
    sum = sum + a[i];
  }
  avg = sum / n;
  return avg;
}
void copyArray() {
  for (int i = 0; i < n; i++) {
    sorted[i] = burst[i];
  }
}
void sort() {
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (sorted[i] > sorted[j]) {
        temp = sorted[j];
        sorted[j] = sorted[i];
        sorted[i] = temp;
      }
    }
  }
}

void main() {
  input();
  copyArray();
  sort();
  calculateWaiting();
  calculateTurnAround();
  printTable();
  printf("\nAverage Waiting Time is: %d", calcAverage(waiting));
  printf("\nAverage Turn Around Time is: %d \n", calcAverage(turnaround));
}
