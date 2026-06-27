#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string id;
    string name;
    string course;
    int age;
};

int main()
{
    Student student[5];

    // Input 5 students
    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "---------------------------" << endl;

        cout << "Enter name : ";
        cin >> student[i].name;

        cout << "Enter ID : ";
        cin >> student[i].id;

        cout << "Enter course : ";
        cin >> student[i].course;

        cout << "Enter age : ";
        cin >> student[i].age;

        cout << "---------------------------" << endl;
    }

    int choice;

    do
    {
        cout << "\n========== STUDENT MENU ==========\n";
        cout << "1. Display All Students\n";
        cout << "2. Search Student (Linear Search)\n";
        cout << "3. Update Student Record\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Display all students
            for (int i = 0; i < 5; i++)
            {
                cout << "\nStudent " << i + 1 << endl;
                cout << "---------------------------" << endl;
                cout << "Name   : " << student[i].name << endl;
                cout << "ID     : " << student[i].id << endl;
                cout << "Course : " << student[i].course << endl;
                cout << "Age    : " << student[i].age << endl;
            }
            break;

        case 2:
        {
            // Linear Search
            string searchID;
            bool found = false;

            cout << "Enter Student ID to search: ";
            cin >> searchID;

            for (int i = 0; i < 5; i++)
            {
                if (student[i].id == searchID)
                {
                    cout << "\nStudent Found!" << endl;
                    cout << "---------------------------" << endl;
                    cout << "Name   : " << student[i].name << endl;
                    cout << "ID     : " << student[i].id << endl;
                    cout << "Course : " << student[i].course << endl;
                    cout << "Age    : " << student[i].age << endl;

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student not found." << endl;
            }

            break;
        }

        case 3:
        {
            string searchID;
            bool found = false;

            cout << "Enter Student ID to update: ";
            cin >> searchID;

            for (int i = 0; i < 5; i++)
            {
                if (student[i].id == searchID)
                {
                    found = true;

                    int updateChoice;

                    do
                    {
                        cout << "\nUpdate Menu\n";
                        cout << "1. Name\n";
                        cout << "2. ID\n";
                        cout << "3. Course\n";
                        cout << "4. Age\n";
                        cout << "5. Finish Update\n";
                        cout << "Enter choice: ";
                        cin >> updateChoice;

                        switch (updateChoice)
                        {
                        case 1:
                            cout << "Enter new name: ";
                            cin >> student[i].name;
                            break;

                        case 2:
                            cout << "Enter new ID: ";
                            cin >> student[i].id;
                            break;

                        case 3:
                            cout << "Enter new course: ";
                            cin >> student[i].course;
                            break;

                        case 4:
                            cout << "Enter new age: ";
                            cin >> student[i].age;
                            break;

                        case 5:
                            cout << "Update completed.\n";
                            break;

                        default:
                            cout << "Invalid choice.\n";
                        }

                    } while (updateChoice != 5);

                    break;
                }
            }

            if (!found)
            {
                cout << "Student not found." << endl;
            }

            break;
        }

        case 4:
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}