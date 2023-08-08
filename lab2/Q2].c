#include<stdio.h>

struct student{
char name[30];
int roll_no;
char grade;

};

void read(int n, struct student s[]){
    int i=0;
    while(i!=n){
        printf("Enter Name of  student\n");
        scanf("%s", s[i].name);
        printf("Enter Roll No of  student\n");
        scanf("%d", &s[i].roll_no);
        printf("Enter Grade of  student\n");
        scanf("%ch", &s[i].grade);
        fflush(stdin);
        i++;
    }
    return;
}

void display(int n, struct student s[]){
    int i=0;
    while(i!=n){
        printf("Enter Name of  student: ");
        printf("%s\n", s[i].name);
        printf("Enter Roll No of  student: ");
        printf("%d\n", &s[i].roll_no);
        printf("Enter Grade of  student: ");
        printf("%ch\n", &s[i].grade);
        fflush(stdin);
        i++;
    }
    return;
}

int main(){
    struct student s[10];
    int n;
    printf("How many stdudents");
    scanf("%d", &n);

    read(n,s);
    display(n,s);


}
