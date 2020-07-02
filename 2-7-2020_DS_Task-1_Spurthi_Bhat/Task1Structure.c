#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student
{
   int stud_id;
   char stud_name[30];
   char stud_year[15];
   float stud_cgpa;
};
int main()
{
    struct Student student1;
    struct Student student2;
    struct Student student3;
    struct Student student4;

    printf("\nEnter the name of first student:");
    gets(student1.stud_name);
    fflush(stdin);

    printf("\nEnter the id of first student:");
    scanf("%d",&student1.stud_id);
    fflush(stdin);

    printf("\nEnter the year of first student:");
    scanf("%s",student1.stud_year);

    printf("\nEnter the CGPA of first Student:");
    scanf("%f",&student1.stud_cgpa);

    printf("\nEnter the name of second student:");
    gets(student2.stud_name);
    gets(student2.stud_name);
    fflush(stdin);

    printf("\nEnter the id of second student:");
    scanf("%d",&student2.stud_id);
    fflush(stdin);

    printf("\nEnter the year of second student:");
    scanf("%s",student2.stud_year);
    fflush(stdin);

    printf("\nEnter the CGPA of second Student:");
    scanf("%f",&student2.stud_cgpa);
    fflush(stdin);

   printf("\nEnter the name of third student:");
    gets(student3.stud_name);
    fflush(stdin);

    printf("\nEnter the id of third student:");
    scanf("%d",&student3.stud_id);
    fflush(stdin);

    printf("\nEnter the year of third student:");
    scanf("%s",student3.stud_year);
    fflush(stdin);

    printf("\nEnter the CGPA of third Student:");
    scanf("%f",&student3.stud_cgpa);
    fflush(stdin);

    printf("\nEnter the name of fourth student:");
    gets(student4.stud_name);
    fflush(stdin);

    printf("\nEnter the id of fourth student:");
    scanf("%d",&student4.stud_id);
    fflush(stdin);

   printf("\nEnter the year of fourth student:");
    scanf("%s",student4.stud_year);
    fflush(stdin);

    printf("\nEnter the CGPA of fourth Student:");
    scanf("%f",&student4.stud_cgpa);
    fflush(stdin);

    printf("\nDetails of the First Student are:");
    printf("\nStudent Name:%s",student1.stud_name);
    printf("\nStudent ID:%d",student1.stud_id);
    printf("\nStudent Year:%s",student1.stud_year);
    printf("\nStudent CGPA:%f",student1.stud_cgpa);

    printf("\n\nDetails of the Second Student are:");
    printf("\nStudent Name:%s",student2.stud_name);
    printf("\nStudent ID:%d",student2.stud_id);
    printf("\nStudent Year:%s",student2.stud_year);
    printf("\nStudent CGPA:%f",student2.stud_cgpa);

    printf("\n\nDetails of the Third Student are:");
    printf("\nStudent Name:%s",student3.stud_name);
    printf("\nStudent ID:%d",student3.stud_id);
    printf("\nStudent Year:%s",student3.stud_year);
    printf("\nStudent CGPA:%f",student3.stud_cgpa);

    printf("\n\nDetails of Fourth Student are:");
    printf("\nStudent Name:%s",student4.stud_name);
    printf("\nStudent ID:%d",student4.stud_id);
    printf("\nStudent Year:%s",student4.stud_year);
    printf("\nStudent CGPA:%f",student4.stud_cgpa);
}
