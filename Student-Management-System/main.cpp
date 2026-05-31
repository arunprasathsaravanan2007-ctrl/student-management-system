#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Student
{
public:
    int id;
    string name;
    int age;
    string course;
};

void addStudent()
{
    Student s;
    cout<<endl;

    cout << "Enter Student ID: ";
    cin >> s.id;
    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;
    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, s.course);

    ofstream file("students.txt", ios::app);

    file << s.id << "|"
         << s.name << "|"
         << s.age << "|"
         << s.course << endl;

    file.close();

    cout << "\nStudent Added Successfully!\n";
}


void displayStudents()
{
    ifstream file("students.txt");

    string line;
    cout<<endl;
    cout << "       STUDENT RECORDS           ";
    cout<<endl;

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void searchStudent()
{
    int searchId;
    cout<<endl;
    
    cout << "Enter Student ID to Search: ";
    cin >> searchId;

    ifstream file("students.txt");

    string line;
    bool found = false;

    while (getline(file, line))
    {
        string temp = "";
        string data[4];
        int index = 0;

        for (char ch : line)
        {
            if (ch == '|')
            {
                data[index] = temp;
                index++;
                temp = "";
            }
            else
            {
                temp += ch;
            }
        }

        data[index] = temp;

        if (stoi(data[0]) == searchId)
        {
            cout<<endl;
            cout << "    Student Found    ";
            cout<<endl;
            cout << "ID     : " << data[0] << endl;
            cout << "Name   : " << data[1] << endl;
            cout << "Age    : " << data[2] << endl;
            cout << "Course : " << data[3] << endl;

            found = true;
            break;
        }
    }

    file.close();

    if (!found)
    {
        cout << "\nStudent Not Found!\n";
    }
}

void updateStudent()
{
    int updateId;

    cout << "\nEnter Student ID to Update: ";
    cin >> updateId;
    cin.ignore();

    ifstream file("students.txt");

    vector<string> records;
    string line;
    bool found = false;

    while (getline(file, line))
    {
        string temp = "";
        string data[4];
        int index = 0;

        for (char ch : line)
        {
            if (ch == '|')
            {
                data[index] = temp;
                index++;
                temp = "";
            }
            else
            {
                temp += ch;
            }
        }

        data[index] = temp;

        if (stoi(data[0]) == updateId)
        {
            found = true;

            string newName;
            string newCourse;
            int newAge;

            cout << "Enter New Name: ";
            getline(cin, newName);

            cout << "Enter New Age: ";
            cin >> newAge;
            cin.ignore();

            cout << "Enter New Course: ";
            getline(cin, newCourse);

            string newRecord =
                to_string(updateId) + "|" +
                newName + "|" +
                to_string(newAge) + "|" +
                newCourse;

            records.push_back(newRecord);
        }
        else
        {
            records.push_back(line);
        }
    }

    file.close();

    ofstream outFile("students.txt");

    for (int i = 0; i < records.size(); i++)
    {
        outFile << records[i] << endl;
    }

    outFile.close();

    if (found)
    {
        cout << "\nStudent Updated Successfully!\n";
    }
    else
    {
        cout << "\nStudent Not Found!\n";
    }
}


void deleteStudent()
{
    int deleteId;

    cout << "\nEnter Student ID to Delete: ";
    cin >> deleteId;

    ifstream file("students.txt");

    vector<string> records;
    string line;
    bool found = false;

    while (getline(file, line))
    {
        string temp = "";
        string data[4];
        int index = 0;

        for (char ch : line)
        {
            if (ch == '|')
            {
                data[index] = temp;
                index++;
                temp = "";
            }
            else
            {
                temp += ch;
            }
        }

        data[index] = temp;

        if (stoi(data[0]) == deleteId)
        {
            found = true;
        }
        else
        {
            records.push_back(line);
        }
    }

    file.close();

    ofstream outFile("students.txt");

    for (int i = 0; i < records.size(); i++)
    {
        outFile << records[i] << endl;
    }

    outFile.close();

    if (found)
    {
        cout << "\nStudent Deleted Successfully!\n";
    }
    else
    {
        cout << "\nStudent Not Found!\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout<<endl;
        cout << " STUDENT MANAGEMENT SYSTEM"<<endl;
        cout<<endl;

        cout << "1. Add Student"<<endl;
        cout << "2. Display Students"<<endl;
        cout << "3. Search Student"<<endl;
        cout << "4. Update Student"<<endl;
        cout << "5. Delete Student"<<endl;
        cout << "6. Exit"<<endl;
        cout<<endl;
        cout << "Enter Your Choice: "<<endl;
        cout<<endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}