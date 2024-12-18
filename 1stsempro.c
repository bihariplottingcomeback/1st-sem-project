#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_BATCH_LEN 20
#define MAX_BRANCH_LEN 50
#define MAX_SUBJECT_NAME_LEN 30

// Structure to hold attendance and marks for each subject
struct Subject {
    int classesAttended;   // Number of classes attended
    int totalClasses;      // Total number of classes
    float marks;           // Marks in the subject
};

// Structure to hold student information
struct Student {
    int rollNumber;           // Roll number of the student
    char name[MAX_NAME_LEN];  // Student's name
    char batch[MAX_BATCH_LEN]; // Batch
    char branch[MAX_BRANCH_LEN]; // Branch
    int yearOfStudy;          // Year of study (e.g., 1st year, 2nd year)
    struct Subject maths;          // Nested structure for Maths
    struct Subject physics;        // Nested structure for Physics
    struct Subject electronics;    // Nested structure for Basic Electronics
    struct Subject sdf;            // Nested structure for SDF
};

// Function to update attendance for a student

// Function to display students with total attendance below a certain percentage
void updateAttendance(struct Student *students, int numStudents) {
    int rollNumber;
    int found = 0;

    // Prompt the user for the roll number of the student whose attendance needs to be updated
    printf("Enter the roll number of the student to update attendance: ");
    scanf("%d", &rollNumber);

    // Search for the student by roll number
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            // Increase the classes attended for this student in all subjects
            students[i].maths.classesAttended++;
            students[i].physics.classesAttended++;
            students[i].electronics.classesAttended++;
            students[i].sdf.classesAttended++;

            // Increase the total classes for all students
            for (int j = 0; j < numStudents; j++) {
                students[j].maths.totalClasses++;
                students[j].physics.totalClasses++;
                students[j].electronics.totalClasses++;
                students[j].sdf.totalClasses++;
            }

            printf("Attendance updated for student with roll number %d.\n", rollNumber);
            found = 1;
            break;
        }
    }

    // If no student was found with the given roll number
    if (!found) {
        printf("No student found with roll number %d.\n", rollNumber);
    }
}void updateAttendance2(struct Student *students, int numStudents) {
    int rollNumber;
    int found = 0;

    // Prompt the user for the roll number of the student whose attendance needs to be updated
    printf("Enter the roll number of the student to update attendance: ");
    scanf("%d", &rollNumber);

    // Search for the student by roll number
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            // Increase the classes attended for this student in all subjects
            students[i].maths.classesAttended++;
            students[i].physics.classesAttended++;
            students[i].electronics.classesAttended++;
            students[i].sdf.classesAttended++;

            // Increase the total classes for all students
            for (int j = 0; j < numStudents; j++) {
                students[j].maths.totalClasses++;
                students[j].physics.totalClasses++;
                students[j].electronics.totalClasses++;
                students[j].sdf.totalClasses++;
            }

            printf("Attendance updated for student with roll number %d.\n", rollNumber);
            found = 1;
            break;
        }
    }

    // If no student was found with the given roll number
    if (!found) {
        printf("No student found with roll number %d.\n", rollNumber);
    }
}void updateAttendance3(struct Student *students, int numStudents) {
    int rollNumber;
    int found = 0;

    // Prompt the user for the roll number of the student whose attendance needs to be updated
    printf("Enter the roll number of the student to update attendance: ");
    scanf("%d", &rollNumber);

    // Search for the student by roll number
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            // Increase the classes attended for this student in all subjects
            students[i].maths.classesAttended++;
            students[i].physics.classesAttended++;
            students[i].electronics.classesAttended++;
            students[i].sdf.classesAttended++;

            // Increase the total classes for all students
            for (int j = 0; j < numStudents; j++) {
                students[j].maths.totalClasses++;
                students[j].physics.totalClasses++;
                students[j].electronics.totalClasses++;
                students[j].sdf.totalClasses++;
            }

            printf("Attendance updated for student with roll number %d.\n", rollNumber);
            found = 1;
            break;
        }
    }

    // If no student was found with the given roll number
    if (!found) {
        printf("No student found with roll number %d.\n", rollNumber);
    }
}

void displayHolidays() {
    // Sample holiday data for different branches and year batches
    struct HolidayData {
        char branch[50];
        int yearBatch;
        int numHolidays;
        char holidays[5][50]; // Up to 5 holidays, each with a description
    } holidayData[] = {
        {"Computer Science", 2023, 3, {"New Year's Day", "Independence Day", "Christmas"}},
        {"Mechanical", 2023, 4, {"Labor Day", "Engineer's Day", "Diwali", "Christmas"}},
        {"Electrical", 2024, 2, {"Republic Day", "Holi"}},
        {"Civil", 2024, 3, {"Easter", "Ganesh Chaturthi", "Christmas"}}
    };

    int numEntries = sizeof(holidayData) / sizeof(holidayData[0]);

    char branch[50];
    int yearBatch;

    printf("Enter branch (e.g., Computer Science, Mechanical): ");
    fgets(branch, sizeof(branch), stdin);
    branch[strcspn(branch, "\n")] = 0; // Remove trailing newline
    printf("Enter year batch (e.g., 2023, 2024): ");
    scanf("%d", &yearBatch);
    getchar(); // Clear newline character

    int found = 0;

    // Search for matching branch and year batch
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(holidayData[i].branch, branch) == 0 && holidayData[i].yearBatch == yearBatch) {
            printf("\nHolidays for %s (Batch %d):\n", branch, yearBatch);
            printf("Total holidays: %d\n", holidayData[i].numHolidays);
            for (int j = 0; j < holidayData[i].numHolidays; j++) {
                printf("- %s\n", holidayData[i].holidays[j]);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo holiday data available for %s (Batch %d).\n", branch, yearBatch);
    }
}

void displayLowAttendance(struct Student *students, int numStudents, float threshold) {
    int found = 0;

    printf("\nStudents with total attendance below %.2f%%:\n", threshold);
    for (int i = 0; i < numStudents; i++) {
        // Calculate total attended classes and total classes across all subjects
        int totalAttended = students[i].maths.classesAttended + students[i].physics.classesAttended +
                            students[i].electronics.classesAttended + students[i].sdf.classesAttended;
        int totalClasses = students[i].maths.totalClasses + students[i].physics.totalClasses +
                           students[i].electronics.totalClasses + students[i].sdf.totalClasses;

        // Calculate the attendance percentage
        float attendancePercentage = (float)totalAttended / totalClasses * 100;

        // If the attendance is below the threshold, display the student's roll number and name
        if (attendancePercentage < threshold) {
            printf("Roll No: %d, Name: %s, Attendance: %.2f%%\n", students[i].rollNumber, students[i].name, attendancePercentage);
            found = 1;
        }
    }

    // If no student was found below the threshold, print a message
    if (!found) {
        printf("No students found with attendance below %.2f%%.\n", threshold);
    }
}

// Function to input student data
void inputStudentData(struct Student *student) {
    // Prompt and input for roll number
    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);
    getchar();  // To clear the newline left by scanf

    // Prompt and input for student's name
    printf("Enter student's name: ");
    fgets(student->name, MAX_NAME_LEN, stdin);
    student->name[strcspn(student->name, "\n")] = 0;  // Remove trailing newline

    // Prompt and input for batch
    printf("Enter batch: ");
    fgets(student->batch, MAX_BATCH_LEN, stdin);
    student->batch[strcspn(student->batch, "\n")] = 0;  // Remove trailing newline

    // Prompt and input for branch
    printf("Enter branch: ");
    fgets(student->branch, MAX_BRANCH_LEN, stdin);
    student->branch[strcspn(student->branch, "\n")] = 0;  // Remove trailing newline

    // Prompt and input for year of study
    printf("Enter year of study (e.g., 1 for 1st year): ");
    scanf("%d", &student->yearOfStudy);

    // Input for Maths
    printf("Enter number of classes attended for Maths: ");
    scanf("%d", &student->maths.classesAttended);
    printf("Enter total number of Maths classes: ");
    scanf("%d", &student->maths.totalClasses);
    while (student->maths.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->maths.totalClasses);
    }
    printf("Enter marks for Maths: ");
    scanf("%f", &student->maths.marks);

    // Input for Physics
    printf("Enter number of classes attended for Physics: ");
    scanf("%d", &student->physics.classesAttended);
    printf("Enter total number of Physics classes: ");
    scanf("%d", &student->physics.totalClasses);
    while (student->physics.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->physics.totalClasses);
    }
    printf("Enter marks for Physics: ");
    scanf("%f", &student->physics.marks);

    // Input for Basic Electronics
    printf("Enter number of classes attended for Basic Electronics: ");
    scanf("%d", &student->electronics.classesAttended);
    printf("Enter total number of Basic Electronics classes: ");
    scanf("%d", &student->electronics.totalClasses);
    while (student->electronics.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->electronics.totalClasses);
    }
    printf("Enter marks for Basic Electronics: ");
    scanf("%f", &student->electronics.marks);

    // Input for SDF
    printf("Enter number of classes attended for SDF: ");
    scanf("%d", &student->sdf.classesAttended);
    printf("Enter total number of SDF classes: ");
    scanf("%d", &student->sdf.totalClasses);
    while (student->sdf.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->sdf.totalClasses);
    }
    printf("Enter marks for SDF: ");
    scanf("%f", &student->sdf.marks);

    // Clear the newline left by scanf
    getchar();
}void inputStudentData2(struct Student *student) {
    // Prompt and input for roll number
    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);
    getchar();  // To clear the newline left by scanf

    // Prompt and input for student's name
    printf("Enter student's name: ");
    fgets(student->name, MAX_NAME_LEN, stdin);
    student->name[strcspn(student->name, "\n")] = 0;  // Remove trailing newline

    // Prompt and input for batch
    printf("Enter batch: ");
    fgets(student->batch, MAX_BATCH_LEN, stdin);
    student->batch[strcspn(student->batch, "\n")] = 0;  // Remove trailing newline

    // Prompt and input for branch
    printf("Enter branch: ");
    fgets(student->branch, MAX_BRANCH_LEN, stdin);
    student->branch[strcspn(student->branch, "\n")] = 0;  // Remove trailing newline

    // Prompt and input for year of study
    printf("Enter year of study (e.g., 1 for 1st year): ");
    scanf("%d", &student->yearOfStudy);

    // Input for Maths
    printf("Enter number of classes attended for Maths: ");
    scanf("%d", &student->maths.classesAttended);
    printf("Enter total number of Maths classes: ");
    scanf("%d", &student->maths.totalClasses);
    while (student->maths.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->maths.totalClasses);
    }
    printf("Enter marks for Maths: ");
    scanf("%f", &student->maths.marks);

    // Input for Physics
    printf("Enter number of classes attended for Physics: ");
    scanf("%d", &student->physics.classesAttended);
    printf("Enter total number of Physics classes: ");
    scanf("%d", &student->physics.totalClasses);
    while (student->physics.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->physics.totalClasses);
    }
    printf("Enter marks for Physics: ");
    scanf("%f", &student->physics.marks);

    // Input for Basic Electronics
    printf("Enter number of classes attended for Basic Electronics: ");
    scanf("%d", &student->electronics.classesAttended);
    printf("Enter total number of Basic Electronics classes: ");
    scanf("%d", &student->electronics.totalClasses);
    while (student->electronics.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->electronics.totalClasses);
    }
    printf("Enter marks for Basic Electronics: ");
    scanf("%f", &student->electronics.marks);

    // Input for SDF
    printf("Enter number of classes attended for SDF: ");
    scanf("%d", &student->sdf.classesAttended);
    printf("Enter total number of SDF classes: ");
    scanf("%d", &student->sdf.totalClasses);
    while (student->sdf.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->sdf.totalClasses);
    }
    printf("Enter marks for SDF: ");
    scanf("%f", &student->sdf.marks);

    // Clear the newline left by scanf
    getchar();
}void inputStudentData3(struct Student *student) {
    // Prompt and input for roll number
    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);
    getchar();  // To clear the newline left by scanf

    // Prompt and input for student's name
    printf("Enter student's name: ");
    fgets(student->name, MAX_NAME_LEN, stdin);
    student->name[strcspn(student->name, "\n")] = 0;  // Remove trailing newline

    // Prompt and input for batch
    printf("Enter batch: ");
    fgets(student->batch, MAX_BATCH_LEN, stdin);
    student->batch[strcspn(student->batch, "\n")] = 0;  // Remove trailing newline

    // Prompt and input for branch
    printf("Enter branch: ");
    fgets(student->branch, MAX_BRANCH_LEN, stdin);
    student->branch[strcspn(student->branch, "\n")] = 0;  // Remove trailing newline

    // Prompt and input for year of study
    printf("Enter year of study (e.g., 1 for 1st year): ");
    scanf("%d", &student->yearOfStudy);

    // Input for Maths
    printf("Enter number of classes attended for Maths: ");
    scanf("%d", &student->maths.classesAttended);
    printf("Enter total number of Maths classes: ");
    scanf("%d", &student->maths.totalClasses);
    while (student->maths.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->maths.totalClasses);
    }
    printf("Enter marks for Maths: ");
    scanf("%f", &student->maths.marks);

    // Input for Physics
    printf("Enter number of classes attended for Physics: ");
    scanf("%d", &student->physics.classesAttended);
    printf("Enter total number of Physics classes: ");
    scanf("%d", &student->physics.totalClasses);
    while (student->physics.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->physics.totalClasses);
    }
    printf("Enter marks for Physics: ");
    scanf("%f", &student->physics.marks);

    // Input for Basic Electronics
    printf("Enter number of classes attended for Basic Electronics: ");
    scanf("%d", &student->electronics.classesAttended);
    printf("Enter total number of Basic Electronics classes: ");
    scanf("%d", &student->electronics.totalClasses);
    while (student->electronics.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->electronics.totalClasses);
    }
    printf("Enter marks for Basic Electronics: ");
    scanf("%f", &student->electronics.marks);

    // Input for SDF
    printf("Enter number of classes attended for SDF: ");
    scanf("%d", &student->sdf.classesAttended);
    printf("Enter total number of SDF classes: ");
    scanf("%d", &student->sdf.totalClasses);
    while (student->sdf.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->sdf.totalClasses);
    }
    printf("Enter marks for SDF: ");
    scanf("%f", &student->sdf.marks);

    // Clear the newline left by scanf
    getchar();
}

// Function to input student data
void inputStudentData4(struct Student *student) {
    // Prompt and input for roll number
    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);
    getchar();  // To clear the newline left by scanf

    // Prompt and input for student's name
    printf("Enter student's name: ");
    fgets(student->name, MAX_NAME_LEN, stdin);
    student->name[strcspn(student->name, "\n")] = 0;  // Remove trailing newline

    // Prompt and input for batch
    printf("Enter batch: ");
    fgets(student->batch, MAX_BATCH_LEN, stdin);
    student->batch[strcspn(student->batch, "\n")] = 0;  // Remove trailing newline

    // Prompt and input for branch
    printf("Enter branch: ");
    fgets(student->branch, MAX_BRANCH_LEN, stdin);
    student->branch[strcspn(student->branch, "\n")] = 0;  // Remove trailing newline

    // Prompt and input for year of study
    printf("Enter year of study (e.g., 1 for 1st year): ");
    scanf("%d", &student->yearOfStudy);

    // Input for Maths
    printf("Enter number of classes attended for Maths: ");
    scanf("%d", &student->maths.classesAttended);
    printf("Enter total number of Maths classes: ");
    scanf("%d", &student->maths.totalClasses);
    while (student->maths.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->maths.totalClasses);
    }
    printf("Enter marks for Maths: ");
    scanf("%f", &student->maths.marks);

    // Input for Physics
    printf("Enter number of classes attended for Physics: ");
    scanf("%d", &student->physics.classesAttended);
    printf("Enter total number of Physics classes: ");
    scanf("%d", &student->physics.totalClasses);
    while (student->physics.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->physics.totalClasses);
    }
    printf("Enter marks for Physics: ");
    scanf("%f", &student->physics.marks);

    // Input for Basic Electronics
    printf("Enter number of classes attended for Basic Electronics: ");
    scanf("%d", &student->electronics.classesAttended);
    printf("Enter total number of Basic Electronics classes: ");
    scanf("%d", &student->electronics.totalClasses);
    while (student->electronics.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->electronics.totalClasses);
    }
    printf("Enter marks for Basic Electronics: ");
    scanf("%f", &student->electronics.marks);

    // Input for SDF
    printf("Enter number of classes attended for SDF: ");
    scanf("%d", &student->sdf.classesAttended);
    printf("Enter total number of SDF classes: ");
    scanf("%d", &student->sdf.totalClasses);
    while (student->sdf.totalClasses == 0) {
        printf("Total number of classes cannot be zero. Enter again: ");
        scanf("%d", &student->sdf.totalClasses);
    }
    printf("Enter marks for SDF: ");
    scanf("%f", &student->sdf.marks);

    // Clear the newline left by scanf
    getchar();
}


// Function to add a student
void addStudent(struct Student **students, int *numStudents) {
    struct Student newStudent;

    // Input student data
    printf("\nEnter details for the new student:\n");
    inputStudentData(&newStudent);

    // Resize the array of students to add the new student
    (*numStudents)++;
    *students = realloc(*students, (*numStudents) * sizeof(struct Student));
    if (*students == NULL) {
        printf("Memory allocation failed. Unable to add student.\n");
        exit(1);
    }

    // Add the new student to the array
    (*students)[(*numStudents) - 1] = newStudent;

    printf("New student added successfully!\n");
}

// Function to delete a student by roll number
void deleteStudent(struct Student **students, int *numStudents, int rollNumber) {
    int found = 0;

    // Search for the student with the given roll number
    for (int i = 0; i < *numStudents; i++) {
        if ((*students)[i].rollNumber == rollNumber) {
            found = 1;

            // Shift the students after the deleted one to the left
            for (int j = i; j < (*numStudents) - 1; j++) {
                (*students)[j] = (*students)[j + 1];
            }

            // Resize the array
            (*numStudents)--;
            *students = realloc(*students, (*numStudents) * sizeof(struct Student));
            if (*students == NULL && *numStudents > 0) {
                printf("Memory reallocation failed.\n");
                exit(1);
            }

            printf("Student with roll number %d deleted successfully!\n", rollNumber);
            return;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}

// Function to display all students' data
void displayAllStudents(struct Student *students, int numStudents) {
    if (numStudents == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nList of all students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nRoll No: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Batch: %s\n", students[i].batch);
        printf("Branch: %s\n", students[i].branch);
        printf("Year of Study: %d\n", students[i].yearOfStudy);
        printf("Subjects and Attendance:\n");
        printf("Maths: %d/%d (%.2f%%)\n", students[i].maths.classesAttended, students[i].maths.totalClasses, (float)students[i].maths.classesAttended / students[i].maths.totalClasses * 100);
        printf("Physics: %d/%d (%.2f%%)\n", students[i].physics.classesAttended, students[i].physics.totalClasses, (float)students[i].physics.classesAttended / students[i].physics.totalClasses * 100);
        printf("Basic Electronics: %d/%d (%.2f%%)\n", students[i].electronics.classesAttended, students[i].electronics.totalClasses, (float)students[i].electronics.classesAttended / students[i].electronics.totalClasses * 100);
        printf("SDF: %d/%d (%.2f%%)\n", students[i].sdf.classesAttended, students[i].sdf.totalClasses, (float)students[i].sdf.classesAttended / students[i].sdf.totalClasses * 100);
    }
}

// Function to calculate total marks for a student
float calculateTotalMarks(struct Student *student) {
    return student->maths.marks + student->physics.marks + student->electronics.marks + student->sdf.marks;
}

// Function to find the student with the highest total marks
void findHighestMarks(struct Student *students, int numStudents) {
    if (numStudents == 0) {
        printf("No students available.\n");
        return;
    }

    struct Student *topStudent = &students[0];
    for (int i = 1; i < numStudents; i++) {
        if (calculateTotalMarks(&students[i]) > calculateTotalMarks(topStudent)) {
            topStudent = &students[i];
        }
    }

    printf("Student with highest marks:\n");
    printf("Roll No: %d, Name: %s, Total Marks: %.2f\n", topStudent->rollNumber, topStudent->name, calculateTotalMarks(topStudent));
}

// Function to find the student with the lowest total marks
void findLowestMarks(struct Student *students, int numStudents) {
    if (numStudents == 0) {
        printf("No students available.\n");
        return;
    }

    struct Student *bottomStudent = &students[0];
    for (int i = 1; i < numStudents; i++) {
        if (calculateTotalMarks(&students[i]) < calculateTotalMarks(bottomStudent)) {
            bottomStudent = &students[i];
        }
    }

    printf("Student with lowest marks:\n");
    printf("Roll No: %d, Name: %s, Total Marks: %.2f\n", bottomStudent->rollNumber, bottomStudent->name, calculateTotalMarks(bottomStudent));
}
void searchStudentByRollNumber(struct Student *students, int numStudents, int rollNumber) {
    int found = 0;

    // Loop through the list of students to find the student with the matching roll number
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            // Print the student's details if found
            printf("\nStudent Details:\n");
            printf("Roll No: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Batch: %s\n", students[i].batch);
            printf("Branch: %s\n", students[i].branch);
            printf("Year of Study: %d\n", students[i].yearOfStudy);
            printf("Subjects and Attendance:\n");
            printf("Maths: %d/%d (%.2f%%)\n", students[i].maths.classesAttended, students[i].maths.totalClasses,
                   (float)students[i].maths.classesAttended / students[i].maths.totalClasses * 100);
            printf("Physics: %d/%d (%.2f%%)\n", students[i].physics.classesAttended, students[i].physics.totalClasses,
                   (float)students[i].physics.classesAttended / students[i].physics.totalClasses * 100);
            printf("Basic Electronics: %d/%d (%.2f%%)\n", students[i].electronics.classesAttended, students[i].electronics.totalClasses,
                   (float)students[i].electronics.classesAttended / students[i].electronics.totalClasses * 100);
            printf("SDF: %d/%d (%.2f%%)\n", students[i].sdf.classesAttended, students[i].sdf.totalClasses,
                   (float)students[i].sdf.classesAttended / students[i].sdf.totalClasses * 100);
            found = 1;
            break; // Stop the loop once the student is found
        }
    }

    // If no student was found with the given roll number
    if (!found) {
        printf("No student found with roll number %d.\n", rollNumber);
    }
}

// Function to find the student with the highest attendance in any subject
void findHighestAttendance(struct Student *students, int numStudents) {
    if (numStudents == 0) {
        printf("No students available.\n");
        return;
    }

    struct Student *topAttendanceStudent = &students[0];
    float maxAttendance = (float)students[0].maths.classesAttended / students[0].maths.totalClasses * 100;

    // Compare attendance across all subjects
    for (int i = 1; i < numStudents; i++) {
        float maxStudentAttendance = (float)students[i].maths.classesAttended / students[i].maths.totalClasses * 100;
        if ((float)students[i].physics.classesAttended / students[i].physics.totalClasses * 100 > maxStudentAttendance) {
            maxStudentAttendance = (float)students[i].physics.classesAttended / students[i].physics.totalClasses * 100;
        }
        if ((float)students[i].electronics.classesAttended / students[i].electronics.totalClasses * 100 > maxStudentAttendance) {
            maxStudentAttendance = (float)students[i].electronics.classesAttended / students[i].electronics.totalClasses * 100;
        }
        if ((float)students[i].sdf.classesAttended / students[i].sdf.totalClasses * 100 > maxStudentAttendance) {
            maxStudentAttendance = (float)students[i].sdf.classesAttended / students[i].sdf.totalClasses * 100;
        }

        if (maxStudentAttendance > maxAttendance) {
            topAttendanceStudent = &students[i];
            maxAttendance = maxStudentAttendance;
        }
    }

    printf("Student with highest attendance:\n");
    printf("Roll No: %d, Name: %s, Attendance: %.2f%%\n", topAttendanceStudent->rollNumber, topAttendanceStudent->name, maxAttendance);
}

// Function to find the student with the lowest attendance in any subject
void findLowestAttendance(struct Student *students, int numStudents) {
    if (numStudents == 0) {
        printf("No students available.\n");
        return;
    }

    struct Student *bottomAttendanceStudent = &students[0];
    float minAttendance = (float)students[0].maths.classesAttended / students[0].maths.totalClasses * 100;

    // Compare attendance across all subjects
    for (int i = 1; i < numStudents; i++) {
        float minStudentAttendance = (float)students[i].maths.classesAttended / students[i].maths.totalClasses * 100;
        if ((float)students[i].physics.classesAttended / students[i].physics.totalClasses * 100 < minStudentAttendance) {
            minStudentAttendance = (float)students[i].physics.classesAttended / students[i].physics.totalClasses * 100;
        }
        if ((float)students[i].electronics.classesAttended / students[i].electronics.totalClasses * 100 < minStudentAttendance) {
            minStudentAttendance = (float)students[i].electronics.classesAttended / students[i].electronics.totalClasses * 100;
        }
        if ((float)students[i].sdf.classesAttended / students[i].sdf.totalClasses * 100 < minStudentAttendance) {
            minStudentAttendance = (float)students[i].sdf.classesAttended / students[i].sdf.totalClasses * 100;
        }

        if (minStudentAttendance < minAttendance) {
            bottomAttendanceStudent = &students[i];
            minAttendance = minStudentAttendance;
        }
    }

    printf("Student with lowest attendance:\n");
    printf("Roll No: %d, Name: %s, Attendance: %.2f%%\n", bottomAttendanceStudent->rollNumber, bottomAttendanceStudent->name, minAttendance);
}

int main() {
    int numStudents = 0;
    struct Student *students = NULL; // Start with no students

    int choice, rollNumberToDelete,rollNumberToSearch;
    float attendanceThreshold;

    while (1) {
        printf("\n1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display All Students\n");
        printf("4. Search Student by Roll Number\n");
        printf("6. View Students with Low Attendance\n");
        printf("7. View Student with Highest Marks\n");
        printf("8. View Student with Lowest Marks\n");
        printf("9. View Student with Highest Attendance\n");
        printf("10. View Student with Lowest Attendance\n");
        printf("11. Update Attendance\n");
        printf("12.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To clear the newline

        switch (choice) {
            case 1:
                addStudent(&students, &numStudents);
                break;
            case 2:
                printf("Enter roll number of student to delete: ");
                scanf("%d", &rollNumberToDelete);
                deleteStudent(&students, &numStudents, rollNumberToDelete);
                break;
            case 3:
                displayAllStudents(students, numStudents);
                break;
            case 4:
                printf("Enter roll number to search: ");
                scanf("%d", &rollNumberToSearch);
                searchStudentByRollNumber(students, numStudents, rollNumberToSearch);
                break;
            case 6:
                printf("Enter attendance threshold (percentage): ");
                scanf("%f", &attendanceThreshold);
                displayLowAttendance(students, numStudents, attendanceThreshold);
                break;
            case 7:
                findHighestMarks(students, numStudents);
                break;
            case 8:
                findLowestMarks(students, numStudents);
                break;
            case 9:
                findHighestAttendance(students, numStudents);
                break;
            case 10:
                findLowestAttendance(students, numStudents);
                break;
            case 11:
                updateAttendance(students, numStudents);
                break;
            case 12:
                printf("Exiting program.\n");
                free(students); // Free allocated memory
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
