#include <iostream>
#include <queue>
using namespace std;

static queue<int> pStart_time;
static double ave_turnaround_time = 0;
static double ave_waiting_time = 0;
static int waiting_time[100];

class Process
{
public:
    int name;
    int burst_time;
    int arrival_time;
};


class RoundRobin
{
public:
    Process *p = new Process[100];
    void Input(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "-----------------" << endl;
            cout << "Nhap ID process: ";
            cin >> this->p[i].name;
            cout << "Nhap arrival time: ";
            cin >> this->p[i].arrival_time;
            cout << "Nhap burst time: ";
            cin >> this->p[i].burst_time;
        }
    }
    void sortByArrivalTime(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (p[i].arrival_time > p[j].arrival_time)
                {
                    swap(p[i], p[j]);
                }
            }
        }
    }

    int check(int flag[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (flag[i] == 1)
                return 1;
        }
        return 0;
    }

    queue<Process> SelectionFunction(int n, int quantum_time)
    {
        int time_current = 0;
        int flag_c = 1;
        queue<Process> pQueue;
        int flag[100];
        sortByArrivalTime(n);
        for (int i = 0; i < n; i++)
        {
            flag[i] = 1;
            waiting_time[i] = p[i].arrival_time;
        }
        while (check(flag, n))
        {
            // Duyệt qua hết 1 lượt các process
            for (int i = 0; i < n; i++)
            {
                // process nào đã đến & còn burst time mới được xét
                if (time_current >= p[i].arrival_time && flag[i] == 1)
                {
                    pQueue.push(p[i]);
                    if (flag_c == 1)
                    {
                        time_current = p[i].arrival_time;
                        flag_c = 0;
                    }
                    pStart_time.push(time_current);
                    p[i].burst_time -= quantum_time;
                    if (p[i].burst_time <= 0)
                    {
                        flag[i] = 0;
                        ave_turnaround_time += time_current + (p[i].burst_time + quantum_time) - p[i].arrival_time;
                    }
                    ave_waiting_time += (time_current - waiting_time[i]);
                    if (p[i].burst_time < 0)
                    {
                        time_current += p[i].burst_time + quantum_time;
                    }
                    else
                    {
                        time_current += quantum_time;
                    }
                    waiting_time[i] = time_current;
                }
            }
        }
        return pQueue;
    }

    void Print(queue<Process> &pQueue)
    {
        while (pQueue.empty() == 0)
        {
            cout << pQueue.front().name << " -- ";
            pQueue.pop();
        }
        cout << endl;
        while (pStart_time.empty() == 0)
        {

            cout << pStart_time.front() << " -- ";
            pStart_time.pop();
        }
        cout << endl;
    }
};

int main()
{
    queue<Process> Queue;
    RoundRobin sche;
    int n, quantum_time;
    cout << "Input number of processes: ";
    cin >> n;
    cout << "Input quantum time: ";
    cin >> quantum_time;
    sche.Input(n);
    int total_time = 0;
    for (int i = 0; i < n; i++)
    {
        total_time += sche.p[i].burst_time;
    }
    int quantum_step = total_time / n;
    if (quantum_step * n < total_time)
        quantum_step++;
    Queue = sche.SelectionFunction(n, quantum_time);
    sche.Print(Queue);
    cout << "Average waiting time: " << ave_waiting_time / n << endl;
    cout << "Average turnaround time: " << ave_turnaround_time / n << endl;
    return 0;
}