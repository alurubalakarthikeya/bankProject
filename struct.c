#include <stdio.h>
struct student
{
    char sname[30];
    int age;
    float marks;
};

struct student *student()
{
    struct student *s = (struct student *)malloc(sizeof(struct student));
    strcpy(s->sname, "Krishna");
    s->age = 18;
    s->marks = 85.5;
    return s;
}
int main()
{
    struct student *s = student();
    printf("Name: %s\nAge: %d\nMarks: %.2f\n", s->sname, s->age, s->marks);
    free(s);
    return 0;
}