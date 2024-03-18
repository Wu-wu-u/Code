#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

typedef struct CourseNode {
    char name[MAX_NAME_LEN];
    struct StudentNode* students;
    struct CourseNode* next;
} CourseNode;

typedef struct StudentNode {
    char name[MAX_NAME_LEN];
    struct CourseNode* courses;
    struct StudentNode* next;
} StudentNode;

// Add a student to a course
void addStudentToCourse(StudentNode* student, CourseNode* course) {
    StudentNode* newStudentNode = (StudentNode*)malloc(sizeof(StudentNode));
    strcpy(newStudentNode->name, student->name);
    newStudentNode->next = course->students;
    course->students = newStudentNode;

    CourseNode* newCourseNode = (CourseNode*)malloc(sizeof(CourseNode));
    strcpy(newCourseNode->name, course->name);
    newCourseNode->next = student->courses;
    student->courses = newCourseNode;
}

// Print the students' name list for each course
void printStudentsForCourses(CourseNode* courses) {
    for (CourseNode* course = courses; course != NULL; course = course->next) {
        printf("Course: %s\n", course->name);
        for (StudentNode* student = course->students; student != NULL; student = student->next) {
            printf("  Student: %s\n", student->name);
        }
    }
}

// Print the registered classes' list for each student
void printCoursesForStudents(StudentNode* students) {
    for (StudentNode* student = students; student != NULL; student = student->next) {
        printf("Student: %s\n", student->name);
        for (CourseNode* course = student->courses; course != NULL; course = course->next) {
            printf("  Course: %s\n", course->name);
        }
    }
}

int main() {
    // Initialize some students and courses
    StudentNode students[] = {
        {"Alice", NULL, students + 1},
        {"Bob", NULL, students + 2},
        {"Charlie", NULL, NULL}
    };
    CourseNode courses[] = {
        {"Math", NULL, courses + 1},
        {"English", NULL, courses + 2},
        {"Physics", NULL, NULL}
    };

    // Register students for courses
    addStudentToCourse(&students[0], &courses[0]);
    addStudentToCourse(&students[0], &courses[1]);
    addStudentToCourse(&students[1], &courses[0]);
    addStudentToCourse(&students[1], &courses[2]);
    addStudentToCourse(&students[2], &courses[1]);
    addStudentToCourse(&students[2], &courses[2]);

    // Print the students' name list for each course
    printStudentsForCourses(courses);

    // Print the registered classes' list for each student
    printCoursesForStudents(students);

    return 0;
}