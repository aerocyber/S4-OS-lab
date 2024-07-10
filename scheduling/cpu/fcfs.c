#include <stdio.h>

struct Process {
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int idle_prev;
};

void sort_at(struct Process p[], int n);
void sort_pid(struct Process p[], int n);
void gantt_chart(struct Process p[], int n);
void table(struct Process p[], int n);

void main() {
	int n;
	printf("Enter number of processes:\t");
	scanf("%d", &n);
	struct Process p[n], temp;
	printf("Enter process details\n");
	for (int i = 0; i < n; i++) {
		temp.pid = i + 1;
		printf("PID:\t%d\n", temp.pid);
		printf("AT:\t");
		scanf("%d", &temp.at);
		printf("BT:\t");
		scanf("%d", &temp.bt);
		temp.idle_prev = 0;
		p[i] = temp;
	}

	// FCFS
	sort_at(p, n);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			p[i].ct = p[i].at + p[i].bt;
			p[i].tat = p[i].ct - p[i].at;
			p[i].wt = 0;
		} else {
			if (p[i - 1].ct < p[i].at) {
				p[i].ct = p[i].at + p[i].bt;
				p[i].idle_prev = 1;
			} else {
				p[i].ct = p[i - 1].ct + p[i].bt;
			}
			p[i].tat = p[i].ct - p[i].at;
			p[i].wt = p[i].tat - p[i].bt;
		}
		if (p[i].wt < 0) {
			p[i].wt = 0;
		}
	}
	printf("\n");
	gantt_chart(p, n);
	printf("\n");
	table(p, n);
}

void gantt_chart(struct Process p[], int n) {
	
	// Top border
	printf("=================================================================\n");

	// PID
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			printf("|%d\t|", p[i].pid);
		} else {
			if (p[i].idle_prev == 1) {
				printf("IDLE\t|");
			}
			printf("%d\t|", p[i].pid);
		}
	}
	printf("\n");

	// Bottom border
	printf("=================================================================\n");

	// Timing
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			printf("%d\t%d\t", p[i].at, p[i].ct);
		} else {
			if (p[i].idle_prev == 1) {
				printf("%d\t", p[i].at);		
			}
			printf("%d\t", p[i].ct);
		}
	}
	printf("\n");
	
}

void table(struct Process p[], int n) {
	sort_pid(p, n);
	// PID    AT    BT    CT    TAT    WT
	printf("PID\t|AT\t|BT\t|CT\t|TAT\t|WT\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t|%d\t|%d\t|%d\t|%d\t|%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
	}
	printf("\n");
}

void sort_at(struct Process p[], int n) {
	struct Process tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (p[j].at > p[j + 1].at) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}

void sort_pid(struct Process p[], int n) {
	struct Process tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (p[j].pid > p[j + 1].pid) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}

