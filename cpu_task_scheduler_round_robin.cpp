#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Task {
public:
    string name;
    int burst_time;
    int remaining_time;  
    int start_time;
    int finish_time;

    Task(string name, int burst_time)
        : name(name), burst_time(burst_time), remaining_time(burst_time), start_time(-1), finish_time(-1) {}
};

void round_robin(vector<Task>& tasks, int quantum) {
    cout << "\nRound Robin Scheduling:" << endl;
    queue<Task*> task_queue;  
    int current_time = 0;  

    for (Task& task : tasks) {
        task_queue.push(&task);
    }

    while (!task_queue.empty()) {
        Task* task = task_queue.front();
        task_queue.pop();

        if (task->start_time == -1) {
            task->start_time = current_time;
        }
        if (task->remaining_time > quantum) {
            current_time += quantum;
            task->remaining_time -= quantum;
            task_queue.push(task);
        } else {
            current_time += task->remaining_time;
            task->remaining_time = 0;
            task->finish_time = current_time;
            cout<< task->name <<": start at "<<task->start_time<<", finish at "<<task->finish_time<<endl;
        }
    }
}

int main() {
    vector<Task> tasks = {
        Task("Task1", 5),
        Task("Task2", 3),
        Task("Task3", 8)
    };

    int quantum = 2;  
    round_robin(tasks, quantum);  

    return 0;
}
