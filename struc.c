// #include<stdio.h>
// #include<String.h>
// struct stud{
//     char name[20];
//     float cpi;
//     int rollno;
// };
// int main(){
//     int n=0;
//     printf("Enter number of students: ");
//     scanf("%d",&n);
//     struct stud s[n];
//     for(int i=0;i<n;i++){
//         scanf("%s %d %f",s[i].name,&s[i].rollno,&s[i].cpi);
//     }

//     // for(int i=0;i<n;i++){
//     //     printf("%s %d %f\n",s[i].name,s[i].rollno,s[i].cpi);
//     // }
//     float temp;
//     int temp2;
//     char temp1[20];
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<n-i-1;j++){
//             if(s[j].cpi>s[j+1].cpi){
//                 temp=s[j].cpi;
//                 temp1[20]=s[j].name[20];
//                 temp2=s[j].rollno;
//                 s[j].name[20]=s[j+1].name[20];
//                 s[j].rollno=s[j+1].rollno;
//                 s[j].cpi=s[j+1].cpi;
//                 s[j+1].cpi=temp;
//                 s[j+1].name[20]=temp1[20];
//                 s[j+1].rollno=temp2;
//             }
//         }
//     }
//         printf("Details of Student are:\n ");
//     for(int i=0;i<n;i++){
//         printf("%s %d %f\n",s[i].name,s[i].rollno,s[i].cpi);
//     }
// }

#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int rollno;
    float cgpa;
};

void swap(struct student s[], int i, int j) {
    struct student temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void sort_by_cgpa(struct student s[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (s[j].cgpa > s[j+1].cgpa) {
                swap(s, j, j+1);
            }
        }
    }
}

int main() {
    struct student s[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter name, roll number, and CGPA of student %d: ", i+1);
        scanf("%s %d %f", s[i].name, &s[i].rollno, &s[i].cgpa);
    }
    sort_by_cgpa(s, 5);

    printf("\nSorted by CGPA:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t%d\t%f\n", s[i].name, s[i].rollno, s[i].cgpa);
    }
    return 0;
}
