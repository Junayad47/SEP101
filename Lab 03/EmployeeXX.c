//==============================================
// Name:           Junayad Bin Forhad
// Student Number: 160158218
// Email:          jbin-forhad@myseneca.ca
// Workshop:       3
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include "Employee.h"

#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

void go_back_prompt() {
    printf("\nPress any key to go back...\n");
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
    getchar();
}

void clrscr() {
    system("cls");
}

int main(void) {
    struct Employee emp[SIZE];

    for (int i = 0; i < SIZE; i++) {
        emp[i].id = 0;
    }

    int option;

    printf("---=== EMPLOYEE DATA ===---\n\n");

    do {
        clrscr();
        printf("1. Display Employee Information\n");
        printf("2. Add Employee\n");
        printf("3. Update Employee Salary\n");
        printf("4. Remove Employee\n");
        printf("0. Exit\n");
        printf("Please select from the above options: ");

        scanf("%d", &option);

        int i, id;

        switch (option) {
            case 0:

                break;

            case 1:  // Display Employee Data
                clrscr();
                printf("EMP ID  EMP AGE  EMP SALARY\n");
                printf("======  =======  ==========\n");
                // Use "%6d%9d%11.2lf" formatting in a
                // printf statement to display
                // employee id, age and salary of
                // all employees using a loop construct

                // The loop construct will be run for SIZE times
                // and will only display Employee data
                // where the EmployeeID is > 0

                for (int i = 0; i < SIZE; i++) {
                    if (emp[i].id > 0)
                        printf("%6d  %7d  %10.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
                }
                go_back_prompt();

                break;

            case 2:  // Adding Employee
                clrscr();
                printf("Adding Employee\n");
                printf("===============\n");

                // Look for an open spot in the array (where id==0)
                // Check for limits on the array
                for (i = 0; emp[i].id > 0 && i < SIZE; i++)
                    ;

                // If an open spot exists, prompt the user for data
                if (i < SIZE) {
                    printf("Enter Employee ID: ");
                    scanf("%d", &emp[i].id);
                    printf("Enter Employee Age: ");
                    scanf("%d", &emp[i].age);
                    printf("Enter Employee Salary: ");
                    scanf("%lf", &emp[i].salary);

                    printf("\nAdding done!\n");
                }
                // If not, print an error message: "ERROR!!! Maximum Number of Employees Reached"
                else {
                    printf("ERROR!!! Maximum Number of Employees Reached\n");
                }

                go_back_prompt();

                break;

            case 3:  // Update Employee salary
                clrscr();
                printf("\e[1;1H\e[2J");
                printf("Update Employee Salary\n");
                printf("======================\n");

                // Prompt the user for the employee's id and search for the employee by id
                do {
                    printf("Enter Employee ID: ");
                    scanf("%d", &id);

                    for (i = 0; emp[i].id != id && i < SIZE; i++)
                        ;

                    // If the employee is not found, print an error message: "*** ERROR: Employee ID not found! ***"
                    if (i == SIZE) {
                        printf("*** ERROR: Employee ID not found! ***\n");
                    }

                    // If the employee is found, prompt the user for the new salary
                    else {
                        printf("The current salary is: %.2lf\n", emp[i].salary);
                        printf("Enter Employee New Salary: ");
                        scanf("%lf", &emp[i].salary);
                        printf("\nUpdating done!\n");
                    }
                } while (i == SIZE);

                go_back_prompt();

                break;

            case 4:  //Remove Employee
                clrscr();
                printf("Remove Employee\n");
                printf("===============\n");

                // Prompt the user for the employee's id and search for the employee by id
                do {
                    printf("Enter Employee ID: ");
                    scanf("%d", &id);

                    for (i = 0; emp[i].id != id && i < SIZE; i++)
                        ;

                    // If the employee is not found, print an error message: "*** ERROR: Employee ID not found! ***"
                    if (i == SIZE) {
                        printf("*** ERROR: Employee ID not found! ***\n");
                    }
                    // If the employee is found, remove the employee by setting the employee's id to 0
                    else {
                        printf("Employee %d is successfully removed!\n", emp[i].id);
                        emp[i].id = 0;
                    }
                } while (i == SIZE);

                go_back_prompt();

                break;

            default:
                clrscr();
                printf("ERROR: Incorrect Option: Try Again\n\n");
                go_back_prompt();
        }

    } while (option != 0);
    printf("Exiting Employee Data Program. Good Bye!!!\n");

    return 0;
}
