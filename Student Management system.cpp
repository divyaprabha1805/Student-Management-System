#include <iostream>
#include <string>

struct student {
    std::string first_name;
    std::string last_name;
    int roll_number;
    double cgpa;
    int course_id[10];
} students[110];

int number_of_students = 0;

void addStudentDetails()
{
    std::cout << "Enter the new student details\n";

    std::cout << "Enter the Roll Number of the student\n";
    int roll_no;
    std::cin >> roll_no;

    for (int i = 0; i < number_of_students; i++)
    {
        if (students[i].roll_number == roll_no)
        {
            std::cout << "Student with the given roll number already exists in the database\n";
            return;
        }
    }

    std::cout << "Enter the first name of the student\n";
    std::cin >> students[number_of_students].first_name;

    std::cout << "Enter the last name of the student\n";
    std::cin >> students[number_of_students].last_name;

    students[number_of_students].roll_number = roll_no;

    std::cout << "Enter the CGPA of the student\n";
    std::cin >> students[number_of_students].cgpa;

    std::cout << "Enter the course ID of each course in which the student is enrolled in\n";
    for (int i = 0; i < 5; i++) {
        std::cin >> students[number_of_students].course_id[i];
    }

    number_of_students++;
}

void findStudentByRollNumber()
{
    int roll_no;
    std::cout << "Enter the Roll Number of the student\n";
    std::cin >> roll_no;

    bool found = false;

    for (int i = 0; i < number_of_students; i++) {
        if (roll_no == students[i].roll_number) {
            found = true;

            std::cout << "The Students Details are:\n";

            std::cout << "The First name is " << students[i].first_name << "\n";
            std::cout << "The Last name is " << students[i].last_name << "\n";
            std::cout << "The CGPA is " << students[i].cgpa << "\n";
            std::cout << "The course ID of each course\n";

            for (int j = 0; j < 5; j++) {
                std::cout << students[i].course_id[j] << " ";
            }

            break;
        }
    }

    if (!found)
        std::cout << "No such student with the given roll number\n";
}

void findStudentByCourseId()
{
    int id;
    std::cout << "Enter the course id\n";
    std::cin >> id;

    bool found = false;

    for (int i = 0; i < number_of_students; i++) {

        for (int j = 0; j < 5; j++) {

            if (id == students[i].course_id[j]) {

                found = true;
                std::cout << "The Students Details are\n";

                std::cout << "The First name is " << students[i].first_name << "\n";
                std::cout << "The Last name is " << students[i].last_name << "\n";
                std::cout << "The CGPA is " << students[i].cgpa << "\n";
                std::cout << "\n";
            }
        }

    }

    if (!found)
        std::cout << "No such students with the given course id\n";
}

void findTotalStudents()
{
    std::cout << "The total number Students are " << number_of_students << "\n";
    std::cout << "You can have a maximum of 110 students in the database\n";
}

void deleteStudentByRollNumber()
{
    int roll_no;
    std::cout << "Enter the Roll Number that you want to delete\n";
    std::cin >> roll_no;

    bool found = false;
    for (int i = 0; i < number_of_students; i++) {
        if (roll_no == students[i].roll_number) {
            found = true;
            for (int j = i; j < 109; j++)
                students[j] = students[j + 1];
            number_of_students--;
        }
    }

    if (found) {
        std::cout << "The Roll Number is removed Successfully\n";
    }
    else {
        std::cout << "Roll number not found in the database\n";
    }

}

void updateStudentDetails()
{
    std::cout << "Enter the roll number whose details you want to update\n";
    int roll_no;
    std::cin >> roll_no;

    bool found = false;
    for (int i = 0; i < number_of_students; i++) {
        if (students[i].roll_number == roll_no) {

            found = true;
            std::cout << "1. Update first name\n"
                "2. Update last name\n"
                "3. Update roll number.\n"
                "4. Update CGPA\n"
                "5. Update courses\n";

            int choice;
            std::cin >> choice;

            switch (choice) {
            case 1:
                std::cout << "Enter the new first name\n";
                std::cin >> students[i].first_name;
                break;

            case 2:
                std::cout << "Enter the new last name\n";
                std::cin >> students[i].last_name;
                break;

            case 3:
                std::cout << "Enter the new roll number\n";
                std::cin >> students[i].roll_number;
                break;

            case 4:
                std::cout << "Enter the new CGPA\n";
                std::cin >> students[i].cgpa;
                break;

            case 5:
                std::cout << "Enter the new courses \n";
                for (int k = 0; k < 5; k++) {
                    std::cin >> students[i].course_id[k];
                }
                break;

            }
        }
    }

    if (found) {
        std::cout << "Details updated successfully.\n";
    }
    else {
        std::cout << "Student not found in the database.\n";
    }
}

int main()
{
    int taskToPerform;
    while (1)
    {
        std::cout << "\nEnter the task that you want to perform\n";
        std::cout << "1. Add a new Student Detail\n";
        std::cout << "2. Find the details of a Student using Roll Number\n";
        std::cout << "3. Find the details of Students enrolled in a specific course\n";
        std::cout << "4. Find Total number of Students\n";
        std::cout << "5. Delete the details of an Student\n";
        std::cout << "6. Update the details of an Student\n";
        std::cout << "7. Exit\n";
        std::cin >> taskToPerform;

        switch (taskToPerform)
        {
        case 1:
            addStudentDetails();
            break;
        case 2:
            findStudentByRollNumber();
            break;
        case 3:
            findStudentByCourseId();
            break;
        case 4:
            findTotalStudents();
            break;
        case 5:
            deleteStudentByRollNumber();
            break;
        case 6:
            updateStudentDetails();
            break;
        case 7:
            exit(0);
            break;
        }
    }

    return 0;
}
