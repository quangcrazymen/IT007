#include <iostream>
#include <queue>
using namespace std;

static float ave_turnaround_time = 0;
static float ave_waiting_time = 0;

class Process
{
public:
	int name;
	int burst_time;
	int arrival_time;
};

class srtf
{
public:
	Process *p = new Process[100];
	void Input( int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "-----------------" << endl;
			cout << "Input ID process: ";
			cin >> p[i].name;
			cout << "Input arrival time: ";
			cin >> p[i].arrival_time;
			cout << "Input burst time: ";
			cin >> p[i].burst_time;
		}
	}
	int minBurstTime( int n)
	{
		int min = p[0].burst_time;
		int imin = 0;
		for (int i = 0; i < n; i++)
		{
			if (p[i].burst_time < min)
			{
				min = p[i].burst_time;
				imin = i;
			}
		}
		return imin;
	}

	void sortByArrivalTime(int n)
	{
		// use bubble sort
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (p[i].arrival_time < p[j].arrival_time)
				{
					swap(p[i], p[j]);
				}
				else
				{
					if (p[i].arrival_time == p[j].arrival_time)
					{
						if (p[i].burst_time < p[j].burst_time)
						{
							swap(p[i], p[j]);
						}
					}
				}
			}
		}
	}

	void ShortestRemainingTimeFirst( int n, int time_current, int burst_time)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (p[i].burst_time < p[j].burst_time && p[i].arrival_time <= time_current && p[i].burst_time < burst_time)
				{
					swap(p[i], p[j]);
				}
			}
		}
	}

	void SelectionFunction( int n)
	{
		Process *p_temp = new Process[100];
		int time_current = 0;

		int flag_c = 1;			 
		int flag_first_come[100];
		int flag_previous;		 
		int flag_current;		 
		int waiting_time[100];	 
	
		for (int i = 0; i < 100; i++)
		{
			waiting_time[i] = 0;
			flag_first_come[i] = -1; 							 
		}
		sortByArrivalTime(n);
		flag_first_come[p[n - 1].name] = p[n - 1].arrival_time;
		
		while (n > 0)
		{
			p[n - 1].burst_time--;
			for (int i = 0; i < n; i++)
			{
				if (p[i].arrival_time <= time_current)
				{
					waiting_time[p[i].name]++;
				}
			}
			waiting_time[p[n - 1].name]--;

			if (flag_c == 1)
			{
				time_current = p[n - 1].arrival_time;
				flag_c = 0;
			}
			time_current++;
			flag_previous = p[n - 1].name;

			if (p[n - 1].burst_time == 0)
			{
				cout << p[n - 1].name << "\t\t\t\t" << flag_first_come[p[n - 1].name] - p[n - 1].arrival_time << "\t\t\t\t" 
				<< waiting_time[p[n - 1].name] << "\t\t\t\t" << (time_current - p[n - 1].arrival_time) << endl;
				ave_waiting_time += waiting_time[p[n - 1].name];
				ave_turnaround_time += time_current - p[n - 1].arrival_time;
				n--;
				if (n == 0)
					return;
			}
			ShortestRemainingTimeFirst(n, time_current, p[n - 1].burst_time);
			flag_current = p[n - 1].name;									

			if (flag_current != flag_previous)
			{
				if (flag_first_come[p[n - 1].name] == -1)
				{
					flag_first_come[p[n - 1].name] = time_current;
				}
			}
		}
	}
};

int main()
{
	int n;
	srtf sche;
	cout << "Input number of processes: ";
	cin >> n;
	sche.Input(n);
	cout << "Process   Response-time   Waiting-time   Turn around-time" << endl;

	sche.SelectionFunction(n);

	cout << "Average waiting time: " << ave_waiting_time / n << endl;
	cout << "Average turnaround time " << ave_turnaround_time / n << endl;

	return 0;
}