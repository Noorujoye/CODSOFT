#include <iostream>
#include<vector>
#include<string>

using namespace std;

// create a structure to store details of task using struct keyword
struct Task
{
    string description;
    bool isCompleted;
};

// create a vector to store tasks
vector<Task> tasks;

// function to add a task
void addTask(){
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore(); // we use to handle newline issues
    getline(cin, newTask.description);
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

// Function to view all tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n====== TO-DO LIST ======\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description
             << " --> Status: " << (tasks[i].isCompleted ? " Completed" : " Pending") << "\n";
    }
    cout << "========================\n";
}


// function to marks a task as completed
void completeTask(){
    viewTasks();
    if(tasks.empty())return;

    int index;
    cout << "Enter task number to marks as completed: ";
    cin >> index;
    if(index > 0 && index <= tasks.size()){
        tasks[index - 1].isCompleted = true;
        cout << "Task marked as completed!\n";
    }
    else{
        cout << "Invalid task number!\n";
    }
}

// Function to remove a task
void removeTask() {
    viewTasks();
    if (tasks.empty()) return;

    int index;
    cout << "Enter task number to remove: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + (index - 1));
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}


int main() {
    int choice;
    do {
        cout << "\nTo-Do List Manager\n";

        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: completeTask(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice, try again!\n";
        }
    } while (choice != 5);

    return 0;
}



