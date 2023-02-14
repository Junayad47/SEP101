// StudentInfo.c - function definitions for student information

// Junayad Bin Forhad
// jbin-forhad@myseneca.ca
// ID: 160158218

#include <stdbool.h>
#include "StudentInfo.h"

// InitializeInfo - returns void, accepts the address of struct StudentInfo
void InitializeInfo(struct StudentInfo *student)

// Sets the last name to a null string. This can be accomplished by setting the first character
//                                      in the last name array to the null terminator '\0'.
// Sets the student id to 0.
// Goes through the subject array (NUM_SUBJECTS) and for each subject
//      sets name to a null string and
//      sets mark to 0.

{
    student->lastName[0] = '\0';
    student->studentId = 0;
    for (int i = 0; i < NUM_SUBJECTS; ++i)
    {
        student->subject[i].name[0] = '\0';
        student->subject[i].mark = 0;
    }
}
// AverageMark - returns float, accepts the address of struct Subject
//
// Uses a for-next loop to go through all the marks (up to NUM_SUBJECTS).
//     Once an invalid mark is reached (mark equals zero), the loop terminates
//
// Returns the running total divided by the number of marks.

float AverageMark(struct Subject *subject)
{
    float total = 0;
    int i;
    for (i = 0; i < NUM_SUBJECTS && subject[i].mark > 0; i++)
    {
        total += (float)subject[i].mark;
    }
    float average = total / i;
    return average;
}

// MaximumMark - returns integer, accepts the address of struct Subject
//
// Uses a for-next loop to go through all the marks (up to NUM_SUBJECTS).
// Once an invalid mark is reached (mark equals zero), the loop terminates
// The index of the maximum mark is returned

int MaximumMark(struct Subject *subject)
{
    int max = subject[0].mark;
    int maximumIndex = 0;
    for (int i = 1; i < NUM_SUBJECTS && subject[i].mark > 0; i++)
    {
        if (subject[i].mark > max)
        {
            maximumIndex = i;
            max = subject[i].mark;
        }
    }
    return maximumIndex;
}

// MinimumMark - returns integer, accepts the address struct Subject
// int MinimumMark(struct Subject *subject);
// Uses a for-next loop to go through all the marks (up to NUM_SUBJECTS).
// Once an invalid mark is reached (mark equals zero), the loop terminates
// The index of the minimum mark is returned

int MinimumMark(struct Subject *subject)
{
    int min = subject[0].mark;
    int minimumIndex = 0;
    for (int i = 1; i < NUM_SUBJECTS && subject[i].mark > 0; i++)
    {
        if (subject[i].mark < min)
        {
            minimumIndex = i;
            min = subject[i].mark;
        }
    }
    return minimumIndex;
}
