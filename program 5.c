#include <stdio.h>
// Define the structure for a student
struct Student
{
int studentID;
char name[50];
char grade;
float marks[5];
float averageMarks;
};
// Function to calculate the average marks for a student
void calculateAverage(struct Student *student)
{
float totalMarks = 0.0;
for (int i = 0; i < 5; i++)
{
totalMarks += student->marks[i];
}
student->averageMarks = totalMarks / 5;
}
// Function to assign grades based on average marks
void assignGrades(struct Student *student)
{
if (student->averageMarks >= 90)
{student->grade = 'A';
}
else if (student->averageMarks >= 80)
{
student->grade = 'B';
}
else if (student->averageMarks >= 70)
{
student->grade = 'C';
}
else if (student->averageMarks >= 60)
{
student->grade = 'D';
}
else
{
student->grade = 'F';
}
}
int main()
{
struct Student students[5];
// Input student information
for (int i = 0; i < 5; i++)
{
printf("Enter Student ID: ");
scanf("%d", &students[i].studentID);
printf("Enter Name: ");
scanf("%s", students[i].name);
printf("Enter marks for 5 subjects:\n");
for (int j = 0; j < 5; j++) {
printf("Subject %d: ", j + 1);
scanf("%f", &students[i].marks[j]);
}
// Calculate average marks and assign grades
calculateAverage(&students[i]);
assignGrades(&students[i]);
}
// Display student information
printf("\nStudent Information:\n");
for (int i = 0; i < 5; i++)
{
printf("Student ID: %d\n", students[i].studentID);
printf("Name: %s\n", students[i].name);
printf("Average Marks: %.2f\n", students[i].averageMarks);
printf("Grade: %c\n", students[i].grade);
printf("\n");
}
return 0;
}
