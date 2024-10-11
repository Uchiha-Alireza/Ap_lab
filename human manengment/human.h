#ifndef HUMAN_H
#define HUMAN_H
struct human
{
    char name[30];
    char * family;
    int n_code; 
    int age;
};
struct student
{
    human h;
    int std_no; 
    char field[50]; 
    double avg; 
};
void deletedn(student *&,int);
void deletedn(human *&,int);
void target_sec(struct human*&,int);
void target_sec(struct student*&,int);
void target_sec(struct student*&,int,int);
void target_sec(struct student*&,int,bool);
#endif
