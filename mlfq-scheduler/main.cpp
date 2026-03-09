#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct Process {
    int id;
    int burst;
    int remaining;
    int queue_level;
};

int main() {
    std::vector<Process> processes = {
        							{1, 20, 20, 0},
        							{2, 3, 3, 0},
        							{3, 6, 6, 0}
    								};

    std::queue<int> q0, q1, q2;

    for (int i = 0; i < processes.size(); i++)
        q0.push(i);

    int quantum[3] = {4, 8, 16};
    int time = 0;

    while (!q0.empty() || !q1.empty() || !q2.empty()) {
        int q_level = -1;
        if (!q0.empty()) q_level = 0;
        else if (!q1.empty()) q_level = 1;
        else if (!q2.empty()) q_level = 2;

        std::queue<int>* current_queue;
        if (q_level == 0) current_queue = &q0;
        else if (q_level == 1) current_queue = &q1;
        else current_queue = &q2;

        int idx = current_queue->front();
        current_queue->pop();

        Process &p = processes[idx];
        int run_time = std::min(quantum[q_level], p.remaining);

        std::cout << "time " << time << " : P" << p.id 
                  << " running in Q" << q_level 
                  << " for " << run_time << "ms\n";

        p.remaining -= run_time;
        time += run_time;

        if (p.remaining > 0) {
            if (q_level < 2) p.queue_level++;
            if (p.queue_level == 0) q0.push(idx);
            else if (p.queue_level == 1) q1.push(idx);
            else q2.push(idx);
        } else {
            std::cout << "time " << time << " : P" << p.id << " finished\n";
        }
    }

    return 0;
}