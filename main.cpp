#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Todolist.h"

using namespace std;

int idTodo(0);
int idTask(0);
vector<string> taskTitle;

Tache createTask() 
{
    string Title, Description, CreationDate, ClosureDate, Status, Priority, Comments, Subtasks;
    double Percentage;
    cout << "Title of the new task ? ";
    cin >> Title;
    taskTitle.push_back(Title);
    cout <<"Description ? ";
    cin >> Description;
    cout << "Date of creation ? ";
    cin >> CreationDate;
    cout << "Date of closure ? ";
    cin >> ClosureDate;
    cout << "Status ? ";
    cin >> Status;
    cout <<"Percentage of completion ? Please make sure to enter a double. ";
    cin >> Percentage;
    cout <<"Priority ? ";
    cin >> Priority;
    cout << "Comments ? ";
    cin >> Comments;
    cout << "Subtasks ? ";
    cin >> Subtasks;
    
    
    Tache Task(idTask + 1, Title, Description, CreationDate, ClosureDate, Status, Percentage, Priority, Comments, Subtasks);  
    idTask += 1;
    return Task;          
}

Todolist createTodo(vector<Tache> a)
{
    string Title;
    cout << "Title of the new todo?" << endl;
    cin >> Title;
    Todolist Todo(idTodo + 1, Title, a);
    idTodo += 1;
    return Todo;
}
            

int main()
{
    string Title, Description, CreationDate, ClosureDate, Status, Priority, Comments, Subtasks;
    string commande, parameter;
    
    cout << "You first have to create a task." << endl;

    Tache Task;
    Todolist Todo;
    Task = createTask();
    vector<Tache> a;
    a.push_back(Task);
    Task.sauvegarde();
    cout << "A todo is going to be created with your task." << endl;
    Todo = createTodo(a);
    Todo.sauvegardeTodo();
    cout << "The todo " << idTodo << " has been created with your task in the current folder."<< endl;
    

    bool stop(false);
    while (!stop)
        {
            cout << "What do you want to do ? You can type :" << endl;
            cout << "addTask removeTask addComment addSubtask changeStatus list finish" << endl;

            string commande;
            cin >> commande;
            
            if (commande == "addTask")
            {
                Tache Task;
                Task = createTask();
                Todo.ajouterTache(Task);
            }
            else if (commande == "removeTask")
            {
                cout << "Title of the task to remove ?" << endl;
                for (int i(0); i<idTask; i++)
                {
                    cout << taskTitle[i] << endl;
                }
                cin >> parameter;
                Todo.retirerTache(parameter);
            }
            else if (commande == "addComment")
            {
                cout << "Title of the Task ?" << endl;
                cin >> Title;
                cout << "You can now type the comment(s)." << endl;
                cin >> Comments;
                Todo.ajouterCommentaire_(Title, Comments);
            } 
            else if (commande == "addSubtask")
            {
                cout << "Title of the Task ?" << endl;
                cin >> Title;
                cout << "You can now type the substask(s)." << endl;
                cin >> Subtasks;
                Todo.ajouterSousTache_(Title, Subtasks);
            }
            else if (commande == "changeStatus") 
            {
                cout << "Title of the Task ?" << endl;
                cin >> Title;
                cout << "New status ?" << endl;
                cin >> Status;
                Todo.changerStatut_(Title, Status);
            }  
            else if (commande =="list")
            {
                string Priority;
                cout << "Priority ?" << endl;
                cin >> Priority;
                Todo.afficherTache(Priority);
            }
            else
            {
                Todo.sauvegardeTodo();
                stop = true;
            }
    }
    
    cout << "Thank you for all your entries and see you back soon !" << endl;
    return 0;
}