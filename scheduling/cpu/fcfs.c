#include <stdio.h>

struct Process
{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int idle_present;
};

void fcfs(struct Process p[], int n);
void sort_at(struct Process p[], int n);
void sort_pid(struct Process p[], int n);
void gantt_chart(struct Process p[], int n);
void table(struct Process p[], int n);

int main()
{
	int n;
	printf("Number of processes:\t");
	scanf("%d", &n);
	struct Process p[n];
	printf("Enter process details\n\n");
	for (int i = 0; i < n; i++)
	{
		p[i].pid = i + 1;
		printf("PID:\t%d\n", p[i].pid);
		printf("Arrival Time:\t");
		scanf("%d", &p[i].at);
		printf("Burst Time:\t");
		scanf("%d", &p[i].bt);
		p[i].idle_present = 0;
	}
	fcfs(p, n);
}

void fcfs(struct Process p[], int n)
{
	sort_at(p, n);

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			p[i].ct = p[i].at + p[i].bt;
			p[i].tat = p[i].ct - p[i].at;
			p[i].wt = 0;
			p[i].idle_present = 0;
		}
		else
		{
			if (p[i].at > p[i - 1].ct)
			{
				p[i].idle_present = 1;
				p[i].ct = p[i].at + p[i].bt;
				p[i].tat = p[i].ct - p[i].at;
				p[i].wt = p[i].tat - p[i].bt;
			}
			else
			{
				p[i].idle_present = 0;
				p[i].ct = p[i - 1].ct + p[i].bt;
				p[i].tat = p[i].ct - p[i].at;
				p[i].wt = p[i].tat - p[i].bt;
			}
		}
	}
	
	printf("\n");
	gantt_chart(p, n);
	printf("\n\n");
	table(p, n);
}

void sort_at(struct Process p[], int n)
{
	struct Process temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j].at > p[j + 1].at)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void sort_pid(struct Process p[], int n)
{
	struct Process temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j].pid > p[j + 1].pid)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void gantt_chart(struct Process p[], int n) 
{
	// Top
	for (int i = 0; i < n; i++)
	{
		printf("=");
	}
	printf("=\n");
	
	// PID
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
		      if (p[i].idle_present == 0)
		      {
			    // No idle before this
			    printf("|%d\t|", p[i].pid);
		      }
		      else
		      {
		            printf("|IDLE\t|%d\t|", p[i].pid);
		            printf("%d\t|", p[i].pid);
		      }
		}
		else
		{
		      if (p[i].idle_present == 0)
		      {
			    // No idle before this
			    printf("%d\t|", p[i].pid);
		      }
		      else
		      {
		            printf("IDLE\t|%d\t|", p[i].pid);
		            printf("%d\t|", p[i].pid);
		      }
		}
	}
	printf("\n");

	// Bottom
	for (int i = 0; i < n; i++)
	{
		printf("=");
	}
	printf("=\n");

	// Timing
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
		        printf("%d\t", p[i].at);
		}
		printf("%d\t", p[i].ct);
	}
	printf("%d\n", p[n].ct);
}

void table(struct Process p[], int n) 
{
    float avg_wt = 0, avg_tat = 0;
    sort_pid(p, n);
    printf("PID  |  AT  |  BT  |  CT  |  TAT  |  WT  |\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d    |  %d  |  %d    |  %d   |  %d    |  %d   |\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
    }
    printf("\n");
    printf("Average TAT:\t%g\n", avg_tat/n);
    printf("\n");
    printf("Average WT:\t%g\n", avg_wt/n);
    printf("\n");
}
