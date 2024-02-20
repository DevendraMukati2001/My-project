//simple student database management system
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void addstudent();
void studentrecord();
void searchstudent();
void delete();
struct student{
    char first_name[20];
    char last_name[20];
    int roll_no;
    char class[20];
    char address[50];
    float per;
};
int main(){
    int choice;
    while(choice!=5){
        printf("\t\t\t======STUDENT DATABASE MANAGEMENT SYSTEM=======");
        printf("\n\n\n\t\t\t\t 1. Add Student Record \n");
        printf("\t\t\t\t 2. Student Record \n");
        printf("\t\t\t\t 3. Search Student \n");
        printf("\t\t\t\t 4. Delete Record \n");
        printf("\t\t\t\t 5. Exit \n");
        printf("\t\t\t\t ....................................... \n");
        printf("\t\t\t\t  ");
        scanf("%d",&choice);

            switch(choice){
                case 1:
                addstudent();
                break;
                case 2:
                studentrecord();         
                break;
                case 3:
                searchstudent();
                break;
                case 4:
                delete();
                break;
                case 5:
                printf("\t\t\t=>Thank You for using my software <=");
                exit(0);
                default:
                printf("\t\t\t\t please enter the menu(1 -5)  \n");
                
            }
    }
}

    void addstudent(){
        char another;
        FILE *fp;
        struct student info;
        do{
            
            printf("\t\t\t\t=======Add Student info======\n\n");
            fp=fopen("Student_info.txt","a");
            printf("\n\t\t\tEnter first_name :");
            scanf("%s",info.first_name);
            printf("\n\t\t\tEnter last_name :");
            scanf("%s",info.last_name);
            printf("\n\t\t\tEnter roll no :");
            scanf("%d",&info.roll_no);
            printf("\n\t\t\tEnter class :");
            scanf("%s",info.class);
            printf("\n\t\t\tEnter Address :");
            scanf("%s",info.address);
            printf("\n\t\t\tEnter Percentage :");
            scanf("%f",&info.per);
            printf("\n\t\t\t.........................");

            if(fp==NULL)
            printf("\t\t\tCan't open file :");
            else
            printf("\n\t\t\tRecord stored successfull \n:");
            
            fwrite(&info,sizeof(struct student),1,fp);
            fclose(fp);

            printf("\t\t\tDo you want to add another record ?(y/n) : ");
            scanf("%s",&another);
        }while(another=='y' || another=='Y');
         }

         void studentrecord(){
            FILE *fp;
        struct student info;
        fp=fopen("Student_info.txt","r");
        printf("\t\t\t\t=======Student Records======\n\n\n");
            if(fp==NULL)
            printf("\t\t\tCan't open file :");
            else{
            printf("\n\t\t\t\tRecords\n");
            printf("\t\t\t\t............\n\n");
            }
        while(fread(&info,sizeof(struct student),1,fp)){
            printf("\n\t\t\t\tStudent Name is  :%s %s",info.first_name,info.last_name);
            printf("\n\t\t\t\tStudent Roll no. is :%d",info.roll_no);
            printf("\n\t\t\t\tStudent class is  :%s",info.class);
            printf("\n\t\t\t\tStudent Address is  :%s",info.address);
            printf("\n\t\t\t\tStudent per is  :%f",info.per);
            printf("\n\t\t\t\t..........................................\n");
        }
        fclose(fp);
         }

         void searchstudent(){
            FILE *fp;
            struct student info;
            int roll_no,found=0;
            fp=fopen("Student_info.txt","r");
            printf("\t\t\t\t======Search Student=====\n\n");
            printf("\t\t\tEnter roll no :");
            scanf("%d",&roll_no);
            while(fread(&info,sizeof(struct student),1,fp)){
                if(info.roll_no==roll_no){
                    found=1;
                printf("\n\t\t\t\tStudent Name is           :  %s %s",info.first_name,info.last_name);
                printf("\n\t\t\t\tStudent Roll no is        :  %d",info.roll_no);
                printf("\n\t\t\t\tStudent class is          :  %s",info.class);
                printf("\n\t\t\t\tStudent address is        :  %s",info.address);
                printf("\n\t\t\t\tStudent percentage is     :  %f",info.per);
                printf("\n\t\t\t\t.........................................................\n");
            }
            }
            if(found==0)
            printf("\t\t\tRecord not found \n");
            
            fclose(fp);
         }

    
    void delete(){
    FILE *fp, *fp1;
    struct student info;
    int roll_no;
    printf("\t\t\t\t=======Delete Student record======\n\n");
    fp=fopen("Student_info.txt","r");
    fp1=fopen("Temp.txt","w");
    printf("\t\t\tEnter roll no. : ");
    scanf("%d",&roll_no);

    if(fp==NULL){
        fprintf(stderr,"\t\t\t\tCan't open a file\n");
        return;
    }
    while(fread(&info,sizeof(struct student),1,fp)){
        if(info.roll_no==roll_no){
            printf("\n\t\t\tRecord Deleted successfully\n");
        } else {
            fwrite(&info,sizeof(struct student),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("Student_info.txt");
    rename("Temp.txt","Student_info.txt");
}
