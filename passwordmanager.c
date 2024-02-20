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

    fp=fopen("Password.txt","a");
    fwrite(&p1,sizeof(struct pass),1,fp);
    fclose(fp);

    printf("\n\t\t\tId registered successfully .............\n");
}
void login(){
    char username[50];
    char password[50];
    FILE*fp;
    struct pass p1;
    fp=fopen("Password.txt","r");
    while(fread(&p1, sizeof(struct pass), 1, fp)){
    printf("\n\n\t\t\t======LOGIN PAGE=====\t\t\t\n\n");
    printf("\t\t\tEnter the username :");
    scanf("%s",username);
    printf("\n\t\t\tEnter the password :");
    scanf("%s",password);
    if(strcmp(p1.username, username) == 0 && strcmp(p1.password, password) == 0){
        printf("\n\t\t\tLogin successfully =:");
    }
    else if(strcmp(p1.username, username) != 0)
        printf("\n\t\t\tEntered wrong username :");
    else if(strcmp(p1.password, password) != 0){
        printf("\n\t\t\tEntered wrong Password :");
        forget();
    }
    else
        printf("\n\t\t\tPlease try again later Something else......");
    }
    fclose(fp);

}

void forget(){
    char password[50],ans;
    int dob;
    FILE *fp;
    FILE *fp1;
    struct pass p1;
    
    
    printf("\n\n\t\t\t======Forget Password=====\t\t\t\n\n");
    printf("\n\t\t\tEnter the DOB :");
    scanf("%d",&dob); 
    fp=fopen("Password.txt","r");
    fp1=fopen("text1.txt","w");
    
    while(fread(&p1,sizeof(struct pass),1,fp)){
    if(p1.dob==dob){
        printf("\n\t\t\tEnter the new password :");
        scanf("%s",password);
        strcpy(p1.password, password);
        fclose(fp); 
        fp=fopen("Password.txt","w"); 
        fwrite(&p1,sizeof(struct pass),1,fp);
        fclose(fp); 
        login();
        break;
    }
    else{
       
       fwrite(&p1,sizeof(struct pass),1,fp1);
       printf("\n\t\t\tWrong DOB :");
    }
    }
    fclose(fp); 
    fclose(fp1);
    remove("Password.txt");
    rename("text1.txt","Password.txt");
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
    fp=fopen("Password.txt","r");
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