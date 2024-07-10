#include <stdio.h>

struct Process {
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int rt;
	int priority;
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
		p[i].pid = i + 1;
		printf("PID:\t%d\n", p[i].pid);
		printf("AT:\t");
		scanf("%d", &p[i].at);
		printf("BT:\t");
		scanf("%d", &p[i].bt);
		printf("Priority:\t");
		scanf("%d", &p[i].priority);
		p[i].idle_prev = 0;
		p[i].rt = p[i].bt;
		// p[i] = temp;
	}

	// Priority
	sort_at(p, n);
	int time = 0;
	int completed = 0;
	while (completed != n) {
		int shortest = -1;
		int max_prio = 9999;
		for (int i = 0; i < n; i++) {
			if (p[i].priority > -1 && p[i].at <= time && p[i].priority < max_prio) {
				shortest = i;
				max_prio = p[i].rt;
			}
		}

		if (shortest == -1) {
			time++;
			continue;
		}

		p[shortest].priority = -1;
		time = time + p[shortest].bt;
		p[shortest].ct = time;
		p[shortest].tat = p[shortest].ct - p[shortest].at;
		p[shortest].wt = p[shortest].tat - p[shortest].bt;

		if (p[shortest].wt < 0) {
			p[shortest].wt = 0;
		}
		completed++;
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
	// for (int i = 0; i < n; i++) {
	// 	if (i == 0) {
	// 		printf("|%d\t|", p[i].pid);
	// 	} else {
	// 		if (p[i].idle_prev == 1) {
	// 			printf("IDLE\t|");
	// 		}
	// 		printf("%d\t|", p[i].pid);
	// 	}
	// }
	// printf("\n");

	for (int i = 0; i < n; i++) {
		if (i > 0) {
			if (p[i].at > p[i - 1].ct) {
				printf("IDLE\t|");
			}
		}
		printf("%d\t|", p[i].pid);
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

