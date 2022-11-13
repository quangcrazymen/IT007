#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Process
{
public:
	int arrivalTime;
	int burstTime;
	int name;
	Process(int name=0,int arrivalTime=0,int burstTime=0){
		this->name=name;
		this->arrivalTime= arrivalTime;
		this->burstTime=burstTime;
	}
	void input()
	{
		cout << "-----------------" << endl;
		cout << "Input ID process: ";
		cin >> this->name;
		cout << "Input arrival time: ";
		cin >> this->arrivalTime;
		cout << "Input burst time: ";
		cin >> this->burstTime;
	}
	bool isDone(){
		if(burstTime==0){
			return 1;
		}
	}
	Process operator- (int number){
		this->burstTime=this->burstTime-number;
	}
};
class Scheduling{
	public:
	queue<Process> list;
	int totalTime;
	void input(){
		int n;
		cout<<"Input number of processes: ";cin>>n;
		for(auto i=0;i<n;i++){
			Process a;
			a.input();
			list.push(a);
			this->totalTime+=a.burstTime;
		}
	}
	void print(int quantum){
		queue<Process> copyList = this->list;
		queue<Process> readyQueue;
		// find the last process arrive

		while(1){
			int i=0;
			if(!copyList.empty()){
				if(burst)
				copyList.front().burstTime-1;
			}

			readyQueue
		}
	}
};


int main()
{
	Process a(1,0,12);
	Process b(2,2,7);
	Process c(3,5,9);
	Process d(4,10,2);
	Process e(5,12,5);

	Scheduling sche;
	sche.list.push(a);
	sche.list.push(b);
	sche.list.push(c);
	sche.list.push(d);
	sche.list.push(e);

	sche.print(2);
	return 0;
}