// StudentMain.c - main function for student information

// Junayad Bin Forhad
// jbin-forhad@myseneca.ca
// ID: 160158218

// 1.Do you prefer using the functions InitializeInfo, AverageMark, MaximumMark,
// MinimumMark or would you prefer all this code to be a part of the main()
// function and why?

// Ans: I would like to use function because I can use it multiple times without writing
//  the same code again and it's more convenient in this program. The code is more clear
//  and editable this way.

// 2.Are you comfortable passing variables from main() to the other functions by
// pass-by-address, or would you prefer these variables to have global scope, so they
// wouldn't have to be passed from main() to any function, and why?
// Keep in mind that if the variables have global scope, they are visible to main
// and all the other functions.
// Ans: I would like to pass the variables via pass by address. I don't think I have
// to make the variables global as it's not needed.

#include <stdio.h>
#include "StudentInfo.c"

int main(void)
{
	struct StudentInfo student;
	int numSubjects;

	InitializeInfo(&student);
	printf("Enter the student's last name: ");
	scanf_s("%s", student.lastName, MAX_STR);
	printf("Enter the student's id: ");
	scanf_s("%d", &student.studentId);
	printf("Enter the number of subjects: ");
	scanf_s("%d", &numSubjects);
	for (int i = 0; i < numSubjects; ++i)
	{
		printf("Enter the name of subject %d: ", i + 1);
		scanf_s("%s", student.subject[i].name, MAX_STR);
		printf("Enter the mark for %s: ", student.subject[i].name);
		scanf_s("%d", &student.subject[i].mark);
	}
	float average = AverageMark(student.subject);
	int maxIndex = MaximumMark(student.subject);
	int minIndex = MinimumMark(student.subject);

	printf("\n");
	printf("%s with id %d has an average mark of %.2f.\n", student.lastName, student.studentId, average);
	printf("%s's highest mark was %d in %s.\n", student.lastName, student.subject[maxIndex].mark, student.subject[maxIndex].name);
	printf("%s's lowest mark was %d in %s.\n", student.lastName, student.subject[minIndex].mark, student.subject[minIndex].name);

	return 0;
}