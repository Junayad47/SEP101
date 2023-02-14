// StudentInfo.h - declarations for student information

// Junayad Bin Forhad
// jbin-forhad@myseneca.ca
// ID: 160158218

#define MAX_STR 32
#define NUM_SUBJECTS 6

// Create struct Subject with members
// name (char array, array size MAX_STR) and
// mark (integer)

struct Subject
{
    char name[MAX_STR];
    int mark;
};

// Create struct StudentInfo with members
// lastName (char array, array size MAX_STR),
// studentId (integer), and
// subject (struct Subject array, array size NUM_SUBJECTS)

struct StudentInfo
{
    char lastName[MAX_STR];
    int studentId;
    struct Subject subject[NUM_SUBJECTS];
};

// Create the following function prototypes:
// InitializeInfo - returns void, accepts the address of struct StudentInfo
// AverageMark - returns float, accepts the address of struct Subject
// MaximumMark - returns integer, accepts the address of struct Subject
// MinimumMark - returns integer, accepts the address struct Subject

void InitializeInfo(struct StudentInfo *student);
float AverageMark(struct Subject *subject);
int MaximumMark(struct Subject *subject);
int MinimumMark(struct Subject *subject);
