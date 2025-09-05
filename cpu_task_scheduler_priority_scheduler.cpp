#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Task {
public:
    string name;
    int burst_time;
    int priority;
    int start_time;
    int finish_time;

    Task(string name, int burst_time, int priority)
        : name(name), burst_time(burst_time), priority(priority), start_time(-1), finish_time(-1) {}
};

void priority_scheduling(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), [](Task& a, Task& b) {
        return a.priority < b.priority;
    });

    int current_time = 0;

    for (auto& task : tasks) {
        task.start_time = current_time;
        current_time += task.burst_time;
        task.finish_time = current_time;
        cout<<task.name<<" (Priority "<<task.priority << ")";
        cout<<": start at "<<task.start_time<<", finish at "<<task.finish_time<<endl;
    }
}

int main() {
    vector<Task> tasks = {
        Task("Task1", 5, 3),
        Task("Task2", 3, 1),
        Task("Task3", 8, 2)
    };
    
    cout << "\nPriority Scheduling (Non-Preemptive):" << endl;
    priority_scheduling(tasks);
    return 0;
}
