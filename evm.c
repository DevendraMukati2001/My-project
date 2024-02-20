#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct evm{
    char name[20];
    char dob[20];
    char pin[20];
};

void create();
void login();
void vote();

int main(){
    struct evm e1;
    FILE *fp;
    
    printf("\n\t\t\t======EVM VOTE COUNTING SYSTEM======\n");
    printf("\n\t\tEnter the name :");
    scanf("%s",e1.name);
    printf("\n\t\tEnter Your DOB :");
    scanf("%s",e1.dob);
    printf("\n\t\tEnter You Pincode :");
    scanf("%s",e1.pin);
    fp=fopen("EVM.txt","a");
    if(fp==NULL)
    {
        printf("\t\t\t\tCan't create a file $$$$..");
        exit(0);
    }
    fwrite(&e1,sizeof(struct evm),1,fp);
    fclose(fp);
    create();
}

void create(){
    struct evm e1;
    
    FILE *fp;
    fp=fopen("EVM.txt","r");
    
    if(fp==NULL)
    {
        printf("\t\t\t\tCan't open the file $$$$..");
        exit(0);
    }
    fread(&e1,sizeof(struct evm),1,fp);
    printf("\n\t\t\t======EVM ID Generator======\n");
    printf("\n\t\t\tYour Voter ID is =>%s%s%s",e1.pin,e1.name,e1.dob);
    printf("\n\t\t\t Note your voter id for login and voting :");
    char str[]="Thank You !";
    printf("\n\t\t\t\t%s",strupr(str));
    fclose(fp);
    login();
}

void login(){
    char voterid[20],dob[20];
    struct evm e1;
    
    FILE *fp;
    fp=fopen("EVM.txt","r");
    fread(&e1,sizeof(struct evm),1,fp);
    printf("\n\t\t\t======EVM LOGIN======\n");
    printf("\n\t\tPlease Enter your voter id : ");
    scanf("%s",voterid);
    printf("\n\t\tEnter you dob : ");
    scanf("%s",dob);
    char str1[50],str2[50],str3[50];
    strcpy(str1,e1.pin);
    strcpy(str2,e1.name);
    strcpy(str3,e1.dob);
    strcat(str1,str2);
    strcat(str1,str3);
    
    if(strcmp(str1,voterid)==0 && strcmp(str3,dob)==0){
        printf("\n\t\tLogin successfully : ");

    int choice = 0;
    int bjpcount=0,congresscount=0,bspcount=0,aapcount=0,notacount=0;
        printf("\n\n\t\t\t======Party=====\t\t\t");
        printf("\n\n\n\t\t\t\t 1. BJP \n");
        printf("\t\t\t\t 2. CONGRESS \n");
        printf("\t\t\t\t 3. BSP \n");
        printf("\t\t\t\t 4. AAM AaDMI Party\n");
        printf("\t\t\t\t 5. NOTA \n");
        printf("\t\t\t\t 6. Vote Counting \n");
        printf("\t\t\t\t ....................................... \n");
        printf("\t\t\t\t  ");
        printf("\n\t\tEnter you choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                bjpcount;
                break;
            case 2:
                congresscount;    
                break;
            case 3:
                bspcount;
                break;
            case 4:
                aapcount;
                break;
            case 5:
                notacount;
                printf("\t\t\t=>Thank You for using my software <=");
                break;
            case 6:
                printf("\n\t\t\tBJP=%d\n\t\t\tCongress=%d\n\t\t\tBsp=%d\n\t\t\tAAP=%d\n\t\t\tNOTA=%d\n",bjpcount,congresscount,bspcount,aapcount,notacount);
                break;
            default:
                printf("\t\t\t\t please enter the menu(1 -6)  \n");
        }
    }
    main();

fclose(fp);
}
