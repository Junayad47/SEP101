// Name:           Junayad Bin Forhad
// Student Number: 160158218
// Email:          jbin-forhad@myseneca.ca
//==============================================

// Would you prefer to use parallel arrays for id, age and salary or
// do you prefer an array of structures, and why?
// Ans: I would like to use an array of structure cause it's more easy
// to handle and less complicated.

// How closely related is a structure in C to a schema in a database
//(you may have to research what a database schema is)?
// Ans: Within the database, a schema is a discrete entity.
// Structure is required to guarantee that database components can display relevant data.

// What will be the output of the following program: Ans: 103 Java

#include <stdio.h>
#include "Employee.h"

#define SIZE 4

int main()

{
	// Declare a struct Employee array "emp" with SIZE elements
	struct Employee emp[SIZE];

	// and initialize all elements to zero

	for (int i = 0; i < SIZE; i++)
	{
		emp[i].id = 0;
	}

	// Add any local auxiliary variables
	int option, id, found;

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n");
		printf("Please select from the above options: ");
		// Capture input to option variable
		scanf_s("%d", &option);
		int i;

		switch (option)
		{
		case 0: // Exit the program

			break;

		case 1: // Display Employee Data

			printf("EMP ID  EMP AGE  EMP SALARY\n");
			printf("======  =======  ==========\n");
			for (i = 0; i < SIZE; i++)
			{
				if (emp[i].id > 0)
					printf("%6d  %7d  %10.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
			}
			// Use "%6d%9d%11.2lf" formatting in a
			// printf statement to display
			// employee id,age and salary of
			// all employees using a loop construct

			// The loop construct will be run for SIZE times
			// and will only display Employee data
			// where the EmployeeID is > 0
			break;

		case 2: // Adding Employee

			printf("Adding Employee\n");
			printf("===============\n");
			for (i = 0; emp[i].id > 0 && i < SIZE; i++)
				;
			if (i != SIZE)
			{
				printf("Enter Employee ID: ");
				scanf_s("%d", &emp[i].id);
				printf("Enter Employee Age: ");
				scanf_s("%d", &emp[i].age);
				printf("Enter Employee Salary: ");
				scanf_s("%lf", &emp[i].salary);
			}
			else
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			// Look for an open spot in the array (where id==0)

			// Check for limits on the array

			// If an open spot exists, prompt the user for data

			// If not, print an error message: "ERROR!!! Maximum Number of Employees Reached"
			break;

		case 3: // Update Employee salary
			printf("Update Employee Salary\n");
			printf("======================\n");
			found = 0; // the found flag
			printf("\nEnter Employee ID: ");
			scanf_s("%d", &id);
			for (int i = 0; i < SIZE; ++i)
			{
				if (emp[i].id == id)
				{
					printf("The current salary is %.2lf", emp[i].salary);
					found = 1;
					printf("Enter New Salary: ");
					scanf("%lf", &emp[i].salary);
					break;
				}
			}
			if (!found)
				printf("*** ERROR: Employee ID not found! ***\n");

			// Prompt the user for the employee's id and search for the employee by id

			// If the employee is not found, print an error message: "*** ERROR: Employee ID not found! ***"

			// If the employee is found, prompt the user for the new salary
			break;

		case 4: // Remove Employee
			printf("Remove Employee\n");
			printf("===============\n");
			printf("\nEnter Employee ID: ");
			scanf_s("%d", &id);
			found = 0;
			for (int i = 0; i < SIZE; i++)
			{
				if (emp[i].id == id)
				{
					printf("Employee %d will be removed\n", id);
					found = 1;
					emp[i].id = 0; // number 0 indicates removal, will invalidate an entire row in the array
				}
			}

			if (!found)
			{
				printf("*** ERROR: Employee ID not found! ***\n");
			}

			// Prompt the user for the employee's id and search for the employee by id

			// If the employee is not found, print an error message: "*** ERROR: Employee ID not found! ***"

			// If the employee is found, remove the employee by setting the employee's id to 0
			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}
	} while (option != 0);
	printf("Exiting Employee Data Program. Good Bye!!!\n");

	return 0;
}
