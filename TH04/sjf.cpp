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

class sjf
{
public:
	Process *p=new Process[100];;
	void sortByArrivalTime(int n)
	{
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
					// if processes have same arrival time
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
	void sortByBurstTime(int n, int current_time)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (p[i].burst_time < p[j].burst_time && p[i].arrival_time <= current_time)
				{
					swap(p[i], p[j]);
				}
			}
		}
	}
	void Input(int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "-----------------" << endl;
			cout << "Input ID process: ";
			cin >> this->p[i].name;
			cout << "Input arrival time: ";
			cin >> this->p[i].arrival_time;
			cout << "Input burst time: ";
			cin >> this->p[i].burst_time;
		}
	}
	void SelectionFunction(int n)
	{
		int current_time;
		int flag = 1;
		// Sort the arrival time to ascending order
		sortByArrivalTime(n);
		// select which process go into queue first 
		for (int i = 0; i < n; n--)
		{
			if (flag == 1)
			{
				current_time = p[n - 1].arrival_time;
				flag = 0;
			}
			current_time += p[n - 1].burst_time;
			ave_waiting_time += current_time - p[n - 1].arrival_time - p[n - 1].burst_time;
			ave_turnaround_time += (current_time - p[n - 1].arrival_time);
			cout << p[n - 1].name << "\t\t\t" << current_time - p[n - 1].arrival_time - p[n - 1].burst_time << "\t\t\t" << current_time - p[n - 1].arrival_time - p[n - 1].burst_time << "\t\t\t" << (current_time - p[n - 1].arrival_time) << endl;
			sortByBurstTime(n - 1, current_time);
		}
	}
};

int main()
{
	int n;
	cout << "Number of processes: ";
	cin >> n;
	sjf a;
	a.Input(n);
	cout << "Process   Response-time   Waiting-time   Turn around-time" << endl;
	a.SelectionFunction(n);
	cout << "Average waiting time: " << ave_waiting_time / n << endl;
	cout << "Average turnaround time: " << ave_turnaround_time / n << endl;
	return 0;
}