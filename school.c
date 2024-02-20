#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct pass{
    char username[50];
    char password[50];
    char city[50];
    int dob;
};

void Register();
void login();
void forget();
void find();
void call();

int main(){
    int choice = 0;
    while(choice!=5){
        printf("\n\n\t\t\t======PASSWORD MANAGER=====\t\t\t");
        printf("\n\n\n\t\t\t\t 1. Register \n");
        printf("\t\t\t\t 2. Login \n");
        printf("\t\t\t\t 3. Forget password \n");
        printf("\t\t\t\t 4. Find username \n");
        printf("\t\t\t\t 5. Exit \n");
        printf("\t\t\t\t ....................................... \n");
        printf("\t\t\t\t  ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                Register();
                break;
            case 2:
                login();    
                break;
            case 3:
                forget();
                break;
            case 4:
                find();
                break;
            case 5:
                printf("\t\t\t=>Thank You for using my software <=");
                exit(0);
            default:
                printf("\t\t\t\t please enter the menu(1 -5)  \n");
        }
    }
}

void login(){
    char username[50];
    char password[50];
    FILE*fp;
    struct pass p1;
    fp=fopen("spassword.txt","r");
    if(fp == NULL) {
    printf("\n\t\t\tError opening file!\n");
    return;
    }
    fread(&p1, sizeof(struct pass), 1, fp);
    printf("\n\n\t\t\t======LOGIN PAGE=====\t\t\t\n\n");
    printf("\t\t\tEnter the username :");
    scanf("%s",username);
    printf("\n\t\t\tEnter the password :");
    scanf("%s",password);
    if(strcmp(p1.username, username) == 0 && strcmp(p1.password, password) == 0){
        printf("\n\t\t\tLogin successfully =:\n");
        call();
    
    }
    else if(strcmp(p1.username, username) != 0)
        printf("\n\t\t\tEntered wrong username :");
    else if(strcmp(p1.password, password) != 0){
        printf("\n\t\t\tEntered wrong Password :");
        forget();
    }
    else
        printf("\n\t\t\tPlease try again later Something else......");
    fclose(fp);
}

void Register(){
    FILE *fp;
    struct pass p1;

    printf("\n\n\t\t\t======Registration=====\t\t\t\n\n");
    printf("\t\t\tEnter the username :");
    scanf("%s",p1.username);
    printf("\n\t\t\tEnter the password :");
    scanf("%s",p1.password);
    printf("\t\t\tEnter the DOB :");
    scanf("%d",&p1.dob);
    printf("\n\t\t\tEnter the city :");
    scanf("%s",p1.city);

    fp=fopen("spassword.txt","a");
    fwrite(&p1,sizeof(struct pass),1,fp);
    fclose(fp);

    printf("\n\t\t\tId registered successfully .............\n");
}

void forget(){
    char password[50],ans;
    int dob;
    FILE *fp;
    struct pass p1;
    
    
    printf("\n\n\t\t\t======Forget Password=====\t\t\t\n\n");
    printf("\n\t\t\tEnter the DOB :");
    scanf("%d",&dob); 
    fp=fopen("spassword.txt","r");
    
    while(fread(&p1,sizeof(struct pass),1,fp)){
    if(p1.dob==dob){
        printf("\n\t\t\tEnter the new password :");
        scanf("%s",password);
        strcpy(p1.password, password);
        fclose(fp); 
        fp=fopen("spassword.txt","w"); 
        fwrite(&p1,sizeof(struct pass),1,fp);
        fclose(fp); 
        login();
        break;
    }
    else{
       printf("\n\t\t\tWrong DOB :");
    }
    }
    fclose(fp); 
    
}


void find(){
    char ans;
    int dob;
     FILE *fp;
    struct pass p1;
    do{

    printf("\n\n\t\t\t======Find Username=====\t\t\t\n\n");
    printf("\n\t\t\tEnter the dob :");
    scanf("%d",&dob);
    fp=fopen("spassword.txt","r");
    while(fread(&p1,sizeof(struct pass),1,fp)){
    if(p1.dob==dob){
        printf("\n\t\t\tUsername is  =: %s",p1.username);
        break;
    }
    else{
        printf("\n\t\t\tWrong DOB :");
        
    }
    }
    fclose(fp);
    
    printf("\n\t\t\tpress y to login or press n:");
    scanf("%s",&ans);
    if(ans=='Y'||ans=='y')
    login();
    break;
    
    }while(ans=='y'||ans=='Y');
    }
    
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

void call(){
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

