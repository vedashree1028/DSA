#include <iostream>
#include <string>
using namespace std;
class Job
{
public:
    string job;
    int priority;
    Job() {}
    Job(string job, int priority)
     {
        this->job = job;
        this->priority = priority;
    }
};
class DoubleEndedOutputRestricted 
{
public:
    Job jobs[10];
    int size;
    DoubleEndedOutputRestricted()
     {
        size = 0;
    }
    bool isFull() 
    {
        return size == 10;
    }
    bool isEmpty()
     {
        return size == 0;
    }

    void insertJob(string job, int priority)
     {
        if (isFull()) 
        {
            cout << "Queue is full, cannot add more jobs." << endl;
            return;
        }
        Job newJob(job, priority);
        int i;
        for (i = size - 1; i >= 0; i--) 
        {
            if (jobs[i].priority > priority)
             {
                jobs[i + 1] = jobs[i];
            } else 
            {
                break;
            }
        }
        jobs[i + 1] = newJob;
        size++;
        cout << "Job added: " << job << " with priority " << priority << endl;
    }

    void addJobAtRear(string job, int priority) 
    {
        insertJob(job, priority);
    }

    void addJobAtFront(string job, int priority) 
    {
        insertJob(job, priority);
    }

    void removeJob()
     {
        if (isEmpty())
        {
            cout << "Queue is empty, no job to remove." << endl;
            return;
        }
        cout << "Job removed: " << jobs[0].job << " with priority " << jobs[0].priority << endl;
        for (int i = 0; i < size - 1; i++) 
        {
            jobs[i] = jobs[i + 1];
        }
        size--;
    }

    void displayJobs()
     {
        if (isEmpty()) 
        {
            cout << "No jobs in the queue." << endl;
            return;
        }
        cout << "Jobs in the queue (sorted by priority):" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Job: " << jobs[i].job << ", Priority: " << jobs[i].priority << endl;
        }
    }

    void searchJob(string jobName) 
    {
        if (isEmpty()) {
            cout << "No jobs to search in the queue." << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            if (jobs[i].job == jobName) {
                cout << "Job found: " << jobs[i].job << " with priority " << jobs[i].priority << endl;
                return;
            }
        }
        cout << "Job not found in the queue." << endl;
    }
};
int main() 
{
    DoubleEndedOutputRestricted jobScheduler;
    int choice;
    string jobName;
    int priority;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Job at Rear\n";
        cout << "2. Add Job at Front\n";
        cout << "3. Remove Job from Front\n";
        cout << "4. Display Jobs\n";
        cout << "5. Search Job\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter job name: ";
            cin.ignore();
            getline(cin, jobName);
            cout << "Enter job priority: ";
            cin >> priority;
            jobScheduler.addJobAtRear(jobName, priority);
            break;
        case 2:
            cout << "Enter job name: ";
            cin.ignore();
            getline(cin, jobName);
            cout << "Enter job priority: ";
            cin >> priority;
            jobScheduler.addJobAtFront(jobName, priority);
            break;
        case 3:
            jobScheduler.removeJob();
            break;
        case 4:
            jobScheduler.displayJobs();
            break;
        case 5:
            cout << "Enter job name to search: ";
            cin.ignore();
            getline(cin, jobName);
            jobScheduler.searchJob(jobName);
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}
