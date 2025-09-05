#include<bits/stdc++.h>
using namespace std;

class Task{
  public:
    string name;
    int start_time;
    int finish_time;
    int burst_time;

    Task(string name, int burst_time)
      :name(name), burst_time(burst_time), finish_time(-1), start_time(-1){}

};

void fcfs(vector<Task>& tasks){
  int current_time = 0;

  for(Task& task : tasks){
    task.start_time = current_time;
    task.finish_time = task.start_time + task.burst_time;
    cout<<task.name<<": start at "<<task.start_time<<", finish at "<<task.finish_time<<endl;

    current_time += task.burst_time;
  }
}

int main(){
  vector<Task> tasks = {
        Task("Task1", 5),
        Task("Task2", 3),
        Task("Task3", 8)
    };

    cout << "FCFS Scheduling:" << endl;
    fcfs(tasks);

    return 0;
}
