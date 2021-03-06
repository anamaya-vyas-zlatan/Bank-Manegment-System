#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include<math.h>
#define nbn 3302

//Modules:

void LoginMenu();//1
void EmployeeLogin();//2
void Transaction();//3
void loan_approval();//4
void EmployeeRecruitment();//5
void calculator();//6
void  AccountUpdate();//7

//Sub-Modules:
void UserLogin();
void MainMenu();
void Ulogin();
void registr();
void forgot();
void Employee();
void Elogin();
void EMainMenu();
void changepass();
void changephone();
void changeadd();
void changeusername();
struct person *hash_table_lookup(int);
void append_loan_ap(int salary, int colateral,char *purpose, char *employement_type ,int amount, char *email,int loan_num,int duration);
void append_loan(int loan_id, const char *loan_name, float interest);
void insert_loan_schemes();
void display_loan_details();
void display_loan_aproval_details();
void LoanApprovalMenu();
void EmployeeLoanRequest();
void EmployeeLoanSchemes();
void LoanStatus();
void print_table();
void TransactionMenu();
void Withdrawal();
void MoneyTransfer();
void CheckBalance();
void delete_loan_request(int);
void CheckEmployeeRecruitment();
void hash_append(char *name,char sex,char *aadhar,char *phone_num,char *address,char *pincode,char *dob,char *username,char *password,long int bal);
void getdatabase();

//Structures:

struct queuenode
{
    int data;
    struct queuenode *next;
} *rear=0,*front=0;

struct cand
{
    char name[50];
    char gen;
    long long int pno;
    int age;
    char add[50];
    long int pincode;
};
struct cand det[100];

//CALCULATOR
struct calc
{
    int loan_id;
    char loan_name[100];
    float interest;
    struct calc *link;
};
struct calc *root=NULL;

//loan approval
struct loan_ap
{
    int nb;//net banking number
    char name[30];
    char address[50];
    char pincode[6];
    int salary;
    int colateral;
    char purpose[500];
    char employement_type[30];
    int amount;
    char email[20];
    int duration;
    int loan_num;
    char loan_ap_name[100];
    float percent;
    struct loan_ap *next;
};
struct loan_ap *head=NULL;

//Hash Table

#define TABLE_SIZE 100

struct person
{
    int netbanking_no;
    char name[30];
    char sex;
    char dob[8];
    char phone_num[10];
    char address[50];
    //string address;
    char pincode[6];
    char aadhar[14];
    char username[32];
    char password[32];
    //char history[500];
    //string password;
	long int bal;
	int loan_count;
};

struct person *hash_table[TABLE_SIZE];//array of pointers
int netbanking_no=3302;

//Quadratic probing in case of collision.
int hashing(int h)
{
    int hash_value=h%TABLE_SIZE;
    return hash_value;
}

struct person *hash_table_lookup(int netbanking_no)
{
    int index=hashing(netbanking_no);
    if(hash_table[index]!=NULL && hash_table[index]->netbanking_no==netbanking_no)
    {
           struct person *p=hash_table[index];
           return p;
    }

    else
    {
        return NULL;
    }

}

int pin;//global declaration

int main()
{
    system("color F0");
    getdatabase();// update data of all modules
    insert_loan_schemes();
    //system("setterm -bold on");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t    ---------------- NETBANKING MANAGEMENT SYSTEM ----------------\n");
    printf("\n\t\t\t\t\t\t\t\t\t    ||                     BROUGHT TO YOU BY:                   ||\n");
    printf("\n\t\t\t\t\t\t\t\t\t    ||                            ~~~                           ||\n");
    printf("\n\t\t\t\t\t\t\t\t\t    ||              VIBHU KUMAR SINGH       19BCE0215           ||\n");
    printf("\n\t\t\t\t\t\t\t\t\t    ||              ANAMAYA VYAS            19BCE0568           ||\n");
    printf("\n\t\t\t\t\t\t\t\t\t    ||              AVNISH TIWARI           19BCE0634           ||\n");
    printf("\n\t\t\t\t\t\t\t\t\t    ||              PRADUMAN PANDEY         19BCE0208           ||\n");
    printf("\n\t\t\t\t\t\t\t\t\t    ||              ABHISHEK S.             19BCE0646           ||\n");
    printf("\n\t\t\t\t\t\t\t\t\t    ||              SHIVANGI CHAURASIA      19BCE0607           ||\n");
    printf("\n\t\t\t\t\t\t\t\t\t    --------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t\t\t\t\t                    PRESS ENTER TO CONTINUE                   ");
    getch();
    LoginMenu();
    return 0;
}


//Modules

void LoginMenu()
{
    start: system("cls");
    printf("***********************************************************************\n");
    printf("||                          Welcome to HOME PAGE                     ||\n");
    printf("***********************          MENU        **************************\n\n");
    printf("1.Login as an Employee\n\n2.Login as a User\n\n3.Apply for Bank Employee\n\n4.Exit\n\nEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
   case 1:
        EmployeeLogin();
        break;
   case 2:
        UserLogin();
        break;
   case 3:
        EmployeeRecruitment();
        break;
   case 4:
        exit(0);
        break;
   default:
        system("cls");
        printf("Invalid choice");
        goto start;
    }

}

void UserLogin()
{
    int choice;
    start: system("cls");
    printf("***********************************************************************\n");
    printf("||                   Welcome to USER LOGIN PAGE                      ||\n");
    printf("*******************           MENU        *****************************\n\n");
    printf("1.Login\n");
    printf("2.Register\n");
    printf("3.Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    printf("\n");
    switch(choice)
    {
        case 1:
            Ulogin();
            break;
        case 2:
            registr();
            break;
        case 3:
            LoginMenu();
            break;
        default:
            system("cls");
            printf("Invalid choice, please try again!");
            getch();
            goto start;
        }
}

void EmployeeLogin()
{
    int choice;
    start: system("cls");
    printf("***********************************************************************\n");
    printf("||                 Welcome to EMPLOYEE LOGIN PAGE                    ||\n");
    printf("***********************          MENU        **************************\n\n");
    printf("1.Login\n\n2.Back to Main Menu\n\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        Elogin();
        break;
    case 2:
        LoginMenu();
        break;
    default:
        printf("INVALID CHOICE");
        goto start;
    }
}

void Elogin()
{
    char username[32],password[32];
    start: system("cls");
    printf("***********************************************************************\n");
    printf("||                 Welcome to EMPLOYEE LOGIN PAGE                    ||\n");
    printf("***********************************************************************\n");
    printf("ENTER LOGIN CREDENTIALS:\n\nUsername: ");
    scanf("%s",&username);
    printf("Password: ");
    int i;
    char a;
    for(i=0;;)//infinite loop
        {
            a=getch();//stores char typed in a
            if((a>='a'&& a<='z')||(a>='A'&& a<='Z')||(a>='0'&&a <='9')||a=='%'||(a>='!'&&a<='~'))
                //check if a is numeric or alphabet
            {
                password[i]=a;//stores a in pass
                ++i;
                printf("*");
            }
            if(a=='\b'&& i>=1)//if user typed backspace
                //i should be greater than 1.
            {
                printf("\b \b");//rub the character behind the cursor.
                --i;
            }
            if(a=='\r')//if enter is pressed
            {
                password[i]='\0';//null means end of string.
                break;//break the loop
            }
        }
    //scanf("%s",&password);
    if(strcmp(username,"Vibhukumar7")==0 && strcmp(password,"Vibhu@1224")==0)
    {
        system("cls");
        printf("Login successful!");
        getch();
        EMainMenu();
    }
    else
    {
        system("cls");
        printf("Wrong credentials entered, please try again.");
        getch();
        goto start;
    }
}
void EMainMenu()
{
    system("cls");
    printf("***********************************************************************\n");
    printf("||                  Welcome to EMPLOYEE HOME PAGE                    ||\n");
    printf("***********************          MENU        **************************\n\n");
    printf("1.Check Loan Requests\n\n2.Recruitment Interview\n\n3.Check Account Details\n\n4.Modify Loan Schemes\n\n5.Logout\n\n6.Exit\n\nEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        display_loan_aproval_details();
        break;
    case 2:
        CheckEmployeeRecruitment();
        break;
     case 3:
        //
        print_table();
        break;
    case 4:
        EmployeeLoanSchemes();
        break;
     case 5:
        system("cls");
        printf("You have been successfully logged out!");
        getch();
        LoginMenu();
        break;
    case 6:
        //
        exit(0);
        break;

    }
}

void Ulogin()
{
        int flag1=0,flag2=0,i=0,k=0,l=0;
        char user[32];
        char pass[32];//to store password.
        char a;//a Temp char
        system("cls");
        printf("***********************************************************************\n");
        printf("||                   Welcome to USER LOGIN PAGE                      ||\n");
        printf("***********************************************************************\n");
        printf("Please enter the following details:\n");
        printf("\nUsername: ");
        scanf("%s",&user);
        printf("Net-Banking No: ");
        scanf("%d",&pin);
        printf("Password: ");
        for(i=0;;)//infinite loop
        {
            a=getch();//stores char typed in a
            if((a>='a'&& a<='z')||(a>='A'&& a<='Z')||(a>='0'&&a <='9')||a=='%'||(a>='!'&&a<='~'))
                //check if a is numeric or alphabet
            {
                pass[i]=a;//stores a in pass
                ++i;
                printf("*");
            }
            if(a=='\b'&& i>=1)//if user typed backspace
                //i should be greater than 1.
            {
                printf("\b \b");//rub the character behind the cursor.
                --i;
            }
            if(a=='\r')//if enter is pressed
            {
                pass[i]='\0';//null means end of string.
                break;//break the loop
            }
        }
        //printf("%s",pass);
        struct person *temp=hash_table_lookup(pin);
        if(pin==temp->netbanking_no)
        {
            while(temp->password[k]!='\0')
            {
                if(temp->password[k]==pass[k])
                {
                    flag1=1;
                }
                else
                {
                    flag1=0;
                    break;
                }
                k++;
            }
            while(temp->username[l]!='\0')
            {
                if(temp->username[l]==user[l])
                {
                    flag2=1;
                }
                else
                {
                    flag2=0;
                    break;
                }
                l++;
            }
        }
        if(flag1==1 && flag2==1)
        {
            system("cls");
            printf("\nHello %s \nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n",temp->username);
            getch();
            MainMenu();
        }
        else
        {
            printf("\nLOGIN ERROR\nPlease check your username and password\n");
            getch();
            UserLogin();
        }
}

void registr()
{
    int index,i,j;
    char a,b,c;
    system("cls");
    printf("***********************************************************************\n");
    printf("||                       Welcome to REGISTER PAGE                    ||\n");
    printf("***********************************************************************\n");
    printf("\n------------ENTER PERSONAL DETAILS---------------\n\n");
    printf("\nDetails of user: ");
    //person *p=new person;
    struct person *p;
    p=(struct person*)malloc(sizeof(struct person));
    index=hashing(netbanking_no);

    hash_table[index]=p;
    p->netbanking_no=netbanking_no;
    p->bal=5000;
    p->loan_count=0;
    char temp; char temp1; char temp2;
    scanf("%c",&temp);

    name: printf("\nFull Name: ");
    char name[30];
    //cin>>p->name;
    scanf("%[^\n]", p->name);
    scanf("%c",&temp1);
    gender: printf("Enter Gender M, F or O: ");
    scanf("%c",&p->sex);
    if(!(p->sex!='F'||p->sex!='M'||p->sex!='O'||p->sex!='f'||p->sex!='m'||p->sex!='o'))
    {
        printf("\nINVALID ENTRY\n");
        getch();
        goto gender;
    }
    dob: printf("Enter DOB[DD/MM/YYYY]: ");
    scanf("%s",&p->dob);
    //printf("%s",p->dob);

    phone_num: printf("ENTER 10 DIGIT PHONE NUMBER: ");
    scanf("%s",&p->phone_num);
    //printf(p->phone_num);
    if(strlen(p->phone_num)!=10)
    {
        printf("\nINVALID PHONE NUMBER\n");
        getch();
        goto phone_num;
    }
    for(int i=0;i<strlen(p->phone_num);i++)
    {
        if(isdigit(p->phone_num[i])==0)
        {
            printf("\nINVALID PHONE NUMBER\n");
            getch();
            goto phone_num;
            break;
        }
    }
        //cout<<p->phone_num;
    scanf("%c",&temp2);
    printf("Address: ");
    scanf("%[^\n]", p->address);
    //printf("%s",p->address);



    pincode: printf("Pincode: ");
    scanf("%s",&p->pincode);
    if(strlen(p->pincode)!=6)
    {
        printf("\nINVALID PINCODE\n");
        getch();
        goto pincode;
    }
    for(int i=0;i<strlen(p->pincode);i++)
    {
        if(isdigit(p->pincode[i])==0)
        {
            printf("\nINVALID PINCODE\n");
            getch();
            goto pincode;
            break;
        }
    }
            //cout<<p->pincode;

    aadhar: printf("Enter Aadhar Card Number: ");
    scanf("%s",&p->aadhar);
    if(strlen(p->aadhar)!=12)
    {
        printf("\nINVALID AADHAR CARD NUMBER\n");
        getch();
        goto aadhar;
    }

    username: printf("Choose Username: ");
    scanf("%s",&p->username);
            //cout<<p->username;

    password: printf("Set password: ");
    char pass[32];
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')||a=='%'||(a>='!'&&a<='~'))
                    //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
            printf("*");
        }
        if(a=='\b'&&i>=1)//if user typed backspace
                    //i should be greater than 1.
        {
            printf("\b \b");//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    //printf("%s",pass);
    int flag1=0,flag2=0,flag3=0,length;
    length=strlen(pass);
    if(length>=8)
    {
        for(int i=0;i<length;i++)
        {
            if(pass[i]=='&'|| pass[i]=='%' || pass[i]=='$' || pass[i]=='@' || pass[i]=='!' || pass[i]=='#')
            {
                flag1++;
            }
            if(isdigit(pass[i])==1)
            {
                flag2++;
            }
            if(pass[i]>='A' && pass[i]<='Z')
            {
                flag3++;
            }
        }
    }
    else
    {
        printf("\nPassword too short\n");
        getch();
        goto password;
    }
    if(flag1>0 && flag2>0 && flag3>0)
    {
        printf("\nPassword strength: Good\n");
    }
    else if(flag1==0)
    {
        printf("\nPassword must contain at least one special character[!,@,#,$,%,&]\n");
        getch();
        goto password;
    }
    else if(flag2==0)
    {
        printf("\nPassword must contain at least one number\n");
        getch();
        goto password;
    }
    else if(flag3==0)
    {
        printf("\nPassword must contain at least one upper-case letter\n");
        getch();
        goto password;
    }
    char confpass[32];
    printf("Confirm password: ");
    for(j=0;;)//infinite loop
    {
        b=getch();//stores char typed in a
        if((b>='a'&&a<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9')||b=='%'||(b>='!'&&b<='~'))
                    //check if a is numeric or alphabet
        {
            confpass[j]=b;//stores a in pass
            ++j;
            printf("*");
        }
        if(b=='\b'&&j>=1)//if user typed backspace
                    //i should be greater than 1.
        {
            printf("\b \b");//rub the character behind the cursor.
            --j;
        }
        if(b=='\r')//if enter is pressed
        {
            confpass[j]='\0';//null means end of string.
            break;//break the loop
        }
    }
            //cout<<confpass;
    int k=0,flag=0;
    if(strlen(pass)!=strlen(confpass))
    {
        flag=0;
    }
    else
    {
        while(pass[k]!='\0')
        {
            if(pass[k]==confpass[k])
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }
            k++;
        }
    }
    int l=0;
    if(flag==1)
    {
        while(pass[l]!='\0')
        {
            p->password[l]=pass[l];
            p->password[l+1]='\0';
            l++;
        }
        system("cls");
        printf("************************************************\n");
        printf("||          Registration Successful!          ||\n");
        printf("************************************************\n\n");
        printf("YOUR UNIQUE NET-BANKING NUMBER IS: %d",netbanking_no);
        netbanking_no++;
    }
    else
    {
        printf("PASSWORDS DONOT MATCH");
        getch();
        goto password;
    }
    //printf("%s",&p->password);
    getch();
    UserLogin();
}

void MainMenu()
{
    start: system("cls");
    struct person *p3;
    p3=hash_table_lookup(pin);
    printf("***********************************************************************\n");
    printf("                       WELCOME %s                                \n",p3->username);
    printf("***********************          MENU        **************************\n\n");
    int choice;
    printf("1.Transactions\n\n2.Apply for a Loan\n\n3.Loan Calculator\n\n4.Account Updation\n\n5.Logout\n\n6.Exit\n\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        TransactionMenu();
        break;
    case 2:
        system("cls");
        LoanApprovalMenu();
        getch();
        break;
    case 3:
        calculator();
        break;
    case 4:
        AccountUpdate();
        break;
    case 5:
        system("cls");
        printf("You have been successfully logged out!");
        getch();
        LoginMenu();
        break;
    case 6:
        printf("\nThanks for using our program!\n");
        exit(0);
        break;
    default:
        printf("Invalid choice.");
        getch();
        goto start;
    }
}

void  AccountUpdate()
{
    int ch;
     system("cls");
     printf("***********************************************************************\n");
    printf("||                Welcome to Account Updation Page                    ||\n");
    printf("***********************          MENU        **************************\n\n");
     printf("1.Change Password");
     printf("\n\n2.Change Phone Number");
     printf("\n\n3.Change Address");
     printf("\n\n4.Change Username");
     printf("\n\nEnter your choice: ");
     scanf("%d",&ch);
     switch(ch)
     {
     case 1:
        changepass();
        break;
     case 2:
        changephone();
        break;
     case 3:
        changeadd();
        break;
     case 4:
        changeusername();
        break;
    default:
        system("cls");
        printf("Invalid choice");
        MainMenu();
     }
}
void changepass()
{
    system("cls");
    //p=(struct person*)malloc(sizeof(struct person));
    int i,k,flag1=0;
    char x;
    char a,b,c;
    char oldpass[32];
    char newpass[32];
    char confpass[32];
    struct person *temp=hash_table_lookup(pin);
    pass: printf("Enter your existing password: ");
    scanf("%s",&oldpass);
    for(i=0;i<strlen(temp->password);i++)
            {
                if(temp->password[i]==oldpass[i])
                {
                    flag1=1;
                }
                else
                {
                    flag1=0;
                    break;
                }
            }

    if(flag1!=0)
    {
        password: printf("Set password: ");
        char pass[32];
        for(i=0;;)//infinite loop
        {
            a=getch();//stores char typed in a
            if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')||a=='%'||(a>='!'&&a<='~'))
                //check if a is numeric or alphabet
            {
                newpass[i]=a;//stores a in pass
                ++i;
                printf("*");
            }
            if(a=='\b'&&i>=1)//if user typed backspace
                //i should be greater than 1.
            {
                printf("\b \b");//rub the character behind the cursor.
                --i;
            }
            if(a=='\r')//if enter is pressed
            {
                newpass[i]='\0';//null means end of string.
                break;//break the loop
            }
        }
        //printf("%s",newpass);
        int flag1=0,flag2=0,flag3=0,length;
        length=strlen(newpass);
        if(length>=8)
        {
            for(int i=0;i<length;i++)
            {
                if(newpass[i]=='&'|| newpass[i]=='%' || newpass[i]=='$' || newpass[i]=='@' || newpass[i]=='!' || newpass[i]=='#')
                {
                    flag1++;
                }
                if(isdigit(newpass[i])==1)
                {
                    flag2++;
                }
                if(newpass[i]>='A' && newpass[i]<='Z')
                {
                    flag3++;
                }
            }
        }
        else
        {
            printf("\nPassword too short\n");
            getch();
            goto password;
        }
        if(flag1>0 && flag2>0 && flag3>0)
        {
            printf("\nPassword strength: Good\n");
        }
        else if(flag1==0)
        {
            printf("\nPassword must contain at least one special character[!,@,#,$,%,&]\n");
            getch();
            goto password;
        }
        else if(flag2==0)
        {
            printf("\nPassword must contain at least one number\n");
            getch();
            goto password;
        }
        else if(flag3==0)
        {
            printf("\nPassword must contain at least one upper-case letter\n");
            getch();
            goto password;
        }
        char confpass[32];
        printf("\nConfirm password: ");
        for(int j=0;;)//infinite loop
        {
            b=getch();//stores char typed in a
            if((b>='a'&&a<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9')||b=='%'||(b>='!'&&b<='~'))
                //check if a is numeric or alphabet
            {
                confpass[j]=b;//stores a in pass
                ++j;
                printf("*");
            }
            if(b=='\b'&&j>=1)//if user typed backspace
                //i should be greater than 1.
            {
                printf("\b \b");//rub the character behind the cursor.
                --j;
            }
            if(b=='\r')//if enter is pressed
            {
                confpass[j]='\0';//null means end of string.
                break;//break the loop
            }
        }
        //printf("%s",confpass);
        int k=0,flag=0;
        if(strlen(newpass)!=strlen(confpass))
        {
            flag=0;
        }
        else
        {
            while(newpass[k]!='\0')
            {
                if(newpass[k]==confpass[k])
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                    break;
                }
                k++;
            }
        }
        int l=0;
        if(flag==1)
        {
            while(newpass[l]!='\0')
            {
                temp->password[l]=newpass[l];
                temp->password[l+1]='\0';
                l++;
            }

        }
        else
        {
            printf("\nPASSWORDS DONOT MATCH\n");
            getch();
            goto password;
        }

        printf("\nPassword changed successfully");
        getch();
        MainMenu();
    }
    else{
        printf("\nWRONG password");
        goto pass;
    }


}
void changephone()
{
    system("cls");
    int i,y=0;
    struct person *temp=hash_table_lookup(pin);
    char ph[10];
    phone: printf("Enter your 10 digit new Phone number: ");
    scanf("%s",&ph);
    if(strlen(ph)!=10)
    {
        printf("\nPhone number does not contain 10 digit\n");
        getch();
        goto phone;
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            if(isdigit(ph[i])==0){
                printf("\nInvalid Phone Number\n");
                getch();
                y=1;
                break;
                goto phone;
            }
        }
        if(y==0)
        {
            strcpy(temp->phone_num,ph);
        }
        printf("\nPhone number changed successfully to %s",temp->phone_num);
    }
    getch();
    MainMenu();
}
void changeadd()
{
    system("cls");
    int i;
    struct person *temp=hash_table_lookup(pin);
    char d,c;
    char address[50];
    scanf("%c",&d);
    printf("Enter new Adress: ");
    scanf("%[^\n]",&address);
    strcpy(temp->address,address);
    printf("\nAddress changed Successfully!");
    //printf("%s",temp->address);
    getch();
    MainMenu();
}
void changeusername()
{
    system("cls");
    int i;
    struct person *temp=hash_table_lookup(pin);
    char d,c;
    char username[32];
    printf("Enter new username: ");
    scanf("%s",&username);
    strcpy(temp->username,username);
    printf("\nUsername changed Successfully!");
    getch();
    MainMenu();
}
void LoanApprovalMenu()
{
    start: system("cls");
    printf("***********************************************************************\n");
    printf("||                  Welcome to LOAN REQUEST PAGE                     ||\n");
    printf("***********************          MENU        **************************\n\n");
    printf("1.Apply for a new Loan\n\n2.Check Status of Loan\n\n3.Back to Main Menu\n\nEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system("cls");
        loan_approval();
        break;
    case 2:
        system("cls");
        LoanStatus();
        break;
    case 3:
        system("cls");
        MainMenu();
        break;
    default:
        printf("Invalid Input");
        getch();
        goto start;
    }
}
void hash_append(char *name,char sex,char *aadhar,char *phone_num,char *address,char *pincode,char *dob,char *username,char *password,long int bal)
{
    int index;
    struct person *p;
    p=(struct person*)malloc(sizeof(struct person));
    index=hashing(netbanking_no);

    hash_table[index]=p;
    p->netbanking_no=netbanking_no;
    strcpy(p->name,name);
    p->sex=sex;
    strcpy(p->aadhar,aadhar);
    strcpy(p->phone_num,phone_num);
    strcpy(p->address,address);
    strcpy(p->pincode,pincode);
    strcpy(p->dob,dob);
    strcpy(p->username,username);
    strcpy(p->password,password);
    p->bal=bal;
    p->loan_count=0;
    netbanking_no++;
}
void getdatabase()
{
    hash_append("Vibhu Kumar Singh",'M',"123456789012","8076570505","9/1224, Vasundhara, Ghaziabad","201012","12/11/2000","Vibhukumar7","Vibhu@1224",120000);
    hash_append("Avnish Tiwari",'M',"121796721182","7597912999","25 Kasturba Nagar, Jaipur","302019","14/03/2001","Avnish_14","Avnish@10",10000);
    //hash_append("Abhishek S            ",'M',"135725788882","9791856299","Pashan, Pune                 ","411021","18/03/2001","Abhi_21","Abhi_S@12",10000);
    hash_append("Shivangi Chaurasia",'F',"273474658912","7752938868","5/154 , Aurangabad, Varanasi","221010","30/01/2000","shivangi30","Random@123",100000);
    hash_append("Anamaya Vyas",'M',"908765432156","8824569035","C-Scheme, Jaipur","130210","05/11/2000","Anamaya_z10","Zlatan@10",82000);
    hash_append("Praduman Pandey",'M',"908765432159","9935505011","Lahartara, Varanasi","221002","30/08/2000","praduman.pandey","Pandey@123",60000);
    hash_append("Abhishek S",'M',"135725788882","9791856299","Pashan, Pune","411021","18/03/2001","Abhishek_S","Abhi_S@12",10000);
}
void print_table()
{
    system("cls");
    int i;
    int count=0;
    printf("***********************************************************************\n");
    printf("||                          USER DETAILS                             ||\n");
    printf("***********************************************************************\n\n");
    for(i=0; i<TABLE_SIZE; i++)
    {
        if(hash_table[i]!= NULL)
        {
            printf("The Account details of User %d: ",i-1);
            printf("\n---------------------------------\n");
            printf("NETBANKING NO: %d\n",hash_table[i]->netbanking_no);
            printf("NAME: %s\n",hash_table[i]->name);
            printf("SEX: %c\n",hash_table[i]->sex);
            //printf("AADHAR: %s\n",hash_table[i]->aadhar);
            //printf("PHONE NUMBER: %s\n",hash_table[i]->phone_num);
            printf("AADRESS: %s\n",hash_table[i]->address);
            printf("PINCODE: %s\n",hash_table[i]->pincode);
            printf("DOB: %s\n",hash_table[i]->dob);
            printf("USERNAME: %s\n",hash_table[i]->username);
            //printf("PASSWORD: %s\n",hash_table[i]->password);
            printf("BALANCE: %ld\n",hash_table[i]->bal);
            printf("\n");
        }
        else
        {
            count++;
            printf("");
        }
    }
    if(count==TABLE_SIZE)
    {
        printf("\n\n\t\tNO USERS AS YET!!\n\n");
    }
    getch();
    EMainMenu();
}


//INSERTION OF LOAN DETAILS IN A SINGLE LINKED LIST
void append_loan_ap(int salary, int colateral,char *purpose, char *employement_type ,int amount, char *email,int loan_num,int duration)
{
    struct person *p6;
    p6=hash_table_lookup(pin);
	struct loan_ap *newnode;
	newnode=(struct loan_ap*)malloc(sizeof(struct loan_ap));
	newnode->nb=pin;
	strcpy(newnode->name,p6->name);
	strcpy(newnode->pincode,p6->pincode);
	strcpy(newnode->address,p6->address);
	newnode->duration=duration;
	newnode->salary=salary;
    newnode->colateral = colateral;
    strcpy(newnode->purpose,purpose);
    strcpy(newnode->employement_type,employement_type);
    newnode->amount = amount;
    strcpy(newnode->email,email);
    newnode -> loan_num = loan_num;
    newnode->next=NULL;
	if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct loan_ap *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void loan_approval()
{
    struct person *p3;
    p3=hash_table_lookup(pin);
    printf("***********************************************************************\n");
    printf("||                          LOAN APPLICATION                         ||\n");
    printf("***********************************************************************\n\n");
    if(p3->loan_count==1)
    {
        system("cls");
        printf("You have already applied for a loan.");
        getch();
        LoanApprovalMenu();
    }
    else if(p3->loan_count==2)
    {
        system("cls");
        printf("Your have a recent loan request approved. Try Again Later.");
        getch();
        LoanApprovalMenu();
    }
	int salary,duration;
	int colateral;
	char purpose[500];
    char employement_type[30];
    int amount;
    char email[32];
    int loan_num;
    char loan_ap_name[100];
	salary :
	 printf("Enter your Monthly Salary: ");
	scanf("%d",&salary);
	if(salary<0)
    {
        printf("\nSALARY CANNOT BE NEGATIVE\n");
        getch();
        goto salary;
    }
    if(salary==0)
    {
        printf("\nSALARY CANNOT BE ZERO\n");
        getch();
        goto salary;
    }


	colateral:
	printf("Enter your estimated colateral value: ");
	scanf("%d",&colateral);
	if(colateral<0)
    {
        printf("\nCOLATERAL CANNOT BE NEGATIVE\n");
        getch();
        goto colateral;
    }
    if(colateral==0)
    {
        printf("\nCOLATERAL CANNOT BE ZERO\n");
        getch();
        goto colateral;
    }
    char temp;
    int i;
    scanf("%c",&temp);
    purpose:
	printf("Enter the purpose of taking loan: \n");
    scanf("%[^\n]",&purpose);
    printf("\n");


	scanf("%c",&temp);
    employement_type:
	printf("Enter the source of earning(SALARIED / SELF): ");
    scanf("%s", employement_type);
    for (i=0; i<strlen(employement_type); i++)
    {
        if(isdigit(employement_type[i]) != 0)
        {
            printf("\nINVALID INPUT\n");
            scanf("%c",&temp);
            goto employement_type;
        }
    }
    if(!(strcmp(employement_type,"SALARIED")==0 || strcmp(employement_type,"SELF")==0))
     {
            printf("\nINVALID CHOICE\n");
            getch();
            goto employement_type;
    }

    amount :
	printf("Enter the amount you want to borrow: ");
	scanf("%d",&amount);
	if(amount<0)
    {
        printf("\n AMOUNT CANNOT BE NEGATIVE\n");
        getch();
        goto amount;
    }
    if(amount<2000)
    {
        printf("\nAMOUNT CANNOT BE LESS THAN 2000\n");
        getch();
        goto amount;
    }
    //printf("%d",amount);
    scanf("%c",&temp);
    duration:
    printf("Enter the duration of loan(in months): ");
    scanf("%d",&duration);
    if(duration<0)
    {
        printf("\nDURATION CANNOT BE NEGATIVE\n");
        getch();
        goto duration;
    }
    email: printf("Enter your Email ID: ");
    scanf("%s",&email);



    loan_num: system("cls");
    display_loan_details();
    printf("\n\nEnter loan id for the loan you want to apply: ");
    scanf("%d",&loan_num);
    struct calc *p;
        p = root;

            bool valid=false;

                while(p!=NULL)
                {
                    if(loan_num==p->loan_id)
                    {
                        valid=true;
                    }
                    p=p->link;
                }

            if (valid==true)
            {
            	printf("\nSuccessfully Applied for Loan!");
            }

            else
            {
                printf("\nINVALID LOAN ID\n");
                getch();
                goto loan_num;
            }
    append_loan_ap(salary,colateral,purpose,employement_type ,amount,email,loan_num,duration);
    struct calc* t;
    t = root;
    struct loan_ap* q;
    q=head;
	while(t!=NULL)
    {
    	if(t->loan_id == q->loan_num)
    	{
    		strcpy(q -> loan_ap_name,t -> loan_name);
    		q->percent=t->interest;
    		break;
		}
		t = t -> link;
	}
    struct person *p1;
    p1=hash_table_lookup(pin);
    p1->loan_count=1;
    getch();
    LoanApprovalMenu();
}
void display_loan_aproval_details()
{
//    printf("\n--------------------------------------------------LOAN REQUEST DETAILS----------------------------------------------\n\n");
//    printf("NETBANKING NO\tNAME\t");
//    printf("				       (COMPOUNDED MONTHLY)\n\n");
    start: system("cls");
    struct loan_ap *p;
    p=head;
    if(p==NULL)
    {
        printf("There are no Loan Requests!");
        getch();
        EMainMenu();
    }

    while(p!=NULL)
    {
        printf("%d\n",p->nb);
        printf("%s\n",p->name);
        printf("%s\n",p->address);
        printf("%s\n",p->pincode);
        printf("%d\n",p->salary);
		printf("%d\n",p->colateral);
        printf("%s\n",p->purpose);
        printf("%s\n",p->employement_type);
		printf("%d\n",p->amount);
        printf("%s\n",p->email);
        printf("%d\n",p->loan_num);
        //printf("%s\n",p->loan_ap_name);
        //printf("%.2f\n",p->percent);
		printf("\n");
        p=p->next;
    }
    //EmployeeLoanRequest();
    printf("Enter the Net-banking Number: ");
    int pin_nb,choice;
    scanf("%d",&pin_nb);
    struct person *p2;
    //p2=(struct person*)malloc(sizeof(struct person));
    p2=hash_table_lookup(pin_nb);
    if(p2->loan_count==0)
    {
        system("cls");
        printf("There is no loan request from this user.\n\n");
        getch();
        int ch;
        error: printf("1.Continue\n2.Back to Main Menu\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            goto start;
        case 2:
            EMainMenu();
        default:
            printf("Invalid Input");
            getch();
            goto error;
            break;
        }
    }
    else if(p2->loan_count==1)
    {
        approve: printf("1.Approve\n2.Reject\n3.Back to Main Menu\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            system("cls");
            printf("Request Successfully Approved!");
            p2->loan_count=2;
            delete_loan_request(pin_nb);
            getch();
            EMainMenu();
            break;
        case 2:
            system("cls");
            printf("Request Successfully Rejected!");
            p2->loan_count=3;
            delete_loan_request(pin_nb);
            getch();
            EMainMenu();
            break;
        case 3:
            EMainMenu();
        default:
            printf("Invalid Input");
            getch();
            goto approve;
        }
    }
    /*else if(p2->loan_count==2)
    {
        system("cls");
        printf("Request Approved");
        getch();
        EMainMenu();
    }*/
}
void LoanStatus()
{
    struct person *p3;
    p3=hash_table_lookup(pin);
    system("cls");
    printf("***********************************************************************\n");
    printf("||                             LOAN STATUS                           ||\n");
    printf("***********************************************************************\n\n");
    if(p3->loan_count==0)
    {
        printf("There is no Request in Queue.\n");
        getch();
        LoanApprovalMenu();
    }
    else if(p3->loan_count==1)
    {
        printf("Your Request is still in Queue.");
        getch();
        LoanApprovalMenu();
    }
    else if(p3->loan_count==2)
    {
        printf("Congrats! Your Loan Request has been approved!");
        getch();
        LoanApprovalMenu();
    }
    else if(p3->loan_count==3)
    {
        printf("Sorry! We cannot accept your request. Try again.");
        getch();
        p3->loan_count=0;
        LoanApprovalMenu();
    }
}
void calculator()
{
	int loan_num;
	float principle_amount;
	float time;
	float percent;
	float payment;
	system("cls");
	amount:system("cls");
	display_loan_details();
	printf("\nEnter the loan amount: ");
	scanf("%f",&principle_amount);
	if(principle_amount<0)
	{
		printf("\nAMOUNT CANNOT BE NEGATIVE!");
		getch();
		goto amount;
	}
	time:system("cls");
	display_loan_details();
	printf("\nEnter loan time period(in months): ");
	scanf("%f",&time);
	if(time<0)
	{
		printf("\nTIME CANNOT BE NEGATIVE!");
		getch();
		goto time;
	}
	loan_id : system("cls");
	display_loan_details();
	printf("\nEnter loan_id: ");
	scanf("%d",&loan_num);
	struct calc *p;
        p = root;

            bool valid=false;

                while(p!=NULL)
                {
                    if(loan_num==p->loan_id)
                    {
                        valid=true;
                    }
                    p=p->link;
                }

            if (valid==true)
            {
            	struct calc* t;
    			t = root;
    			while(t!=NULL)
    			{
    				if(t->loan_id == loan_num)
    				{
    					percent=t->interest;
    					break;
					}
					t = t -> link;
				}
            }

            else
            {
                printf("\nINVALID LOAN ID\n");
                getch();
                goto loan_id;
            }
    system("cls");
    display_loan_details();
	float P,r,t,A;
    const int n = 12;
	P = principle_amount;
	r = percent/100;
	t = time;
	A = P*pow((1 + (r/n)), (n*t));
	printf("\nprinciple amount = %0.2f",P);
	printf("\ninterest = %0.2f",r*100);
	printf("\nBy the end of %0.1f Months you will have to pay the bank a sum of %0.2f Rupees ",t,A);
	printf("\nThis interest was calculated using the compund interest formula");
	getch();
	MainMenu();
}
void insert_loan_schemes()
{
	append_loan(13234, "FARM LOAN" , 8.5);
	append_loan(13235, "PROPERTY LOAN" , 2.5);
	append_loan(13236, "BUISENESS LOAN" , 6.52);
	append_loan(13237, "EDUCATION LOAN" , 5.67);
	append_loan(13238, "GOLD LOAN" , 9.02);
	append_loan(13239, "INTERN LOAN" , 2.08);
	append_loan(13240, "CAR LOAN" , 4.29);
	append_loan(13241, "TRAVEL LOAN" , 1.23);
	append_loan(13242, "HEALTH LOAN" , 8.25);
	append_loan(13223, "QUICK LOAN" , 7.61);
	append_loan(13244, "STARTUP LOAN" , 1.95);
	append_loan(13245, "ENTHUSIAST LOAN" , 4.5);
	append_loan(13246, "WEDDING LOAN" , 1.5);
}
//INSERTION OF LOAN DETAILS INTO A SINGLE LINKED LIST
void append_loan(int loan_id, const char *loan_name, float interest)
{

	struct calc *temp;

	temp=(struct calc *)malloc(sizeof(struct calc));
	temp->loan_id = loan_id;
	temp->interest = interest;
	strcpy(temp->loan_name,loan_name);

	temp->link = NULL;


	if(root==NULL)
    {
		root = temp;
	}

	else
	{
	    struct calc *p;
        p=root;
		while(p->link != NULL)
		{
			p = p->link;
		}
		p->link = temp;
	}
}
void add_scheme()
{
	start: system("cls");
	display_loan_details();
	int loan_id;
	float interest;
	char loan_name[100];
	char temp;
	loan_id : printf("\nEnter loan id: ");
	scanf("%d",&loan_id);
	if(loan_id<0)
    {
        printf("LOAN ID CANNOT BE NEGATIVE\n");
        goto loan_id;
    }
    if(loan_id>99999)
    {
        printf("LOAN ID CANNOT EXCEED FIVE DIGITS\n");
        goto loan_id;
    }
    struct calc *p;
    p=root;

    while(p!=NULL)
    {
        if(loan_id==p->loan_id)
        {
            printf("LOAN ID ALREADY EXISTS\n");
            getch();
            goto loan_id;
        }
        p=p->link;
    }
	scanf("%c",&temp);


    loan_name: printf("Enter Loan Scheme Name: ");
    scanf("%[^\n]", loan_name);

    int i,c;
    char temp2;

      for (i=0; i<strlen(loan_name); i++)
        {
                if(isdigit(loan_name[i]) != 0)
                {
                    printf("\nINVALID INPUT\n");
                    scanf("%c",&temp2);
                    goto loan_name;
                }

        }
    interest: printf("Enter interest pa: ");
    scanf("%f",&interest);
    if(interest<0)
    {
        printf("INTEREST CANNOT BE NEGATIVE\n");
        getch();
        goto interest;
    }
    if(interest==0)
    {
        printf("INTEREST CANNOT BE ZERO\n");
        getch();
        goto interest;
    }
    if(interest>25)
    {
        printf("INTEREST CANNOT EXCEED 25%\n");
        getch();
        goto interest;
    }
    append_loan(loan_id, loan_name, interest);
    system("cls");
    printf("\n\nNEW DEAL SUCCESFULLY ADDED!\n\n");
    getch();
}
void display_loan_details()
{
    printf("\n------------------------------------------------LOAN SCHEME DETAILS----------------------------------------------\n\n");
    printf("ID      LOAN NAME                      ANNUAL INTEREST(in %)\n");
    printf("				       (COMPOUNDED MONTHLY)\n\n");

    struct calc *p;
    p=root;

    while(p!=NULL)
    {
        printf("%d\t",p->loan_id);
        printf("%s\t\t",p->loan_name);
        printf("\t\t%.2f",p->interest);
        printf("\n");
        p=p->link;
    }
}
void update_interest_rate()
{
    int loan_num;
	float percent;
	system("cls");
	loan_id : system("cls");
	display_loan_details();
	printf("\nEnter loan_id: ");
	scanf("%d",&loan_num);
	struct calc *p;
        p = root;

            bool valid=false;

                while(p!=NULL)
                {
                    if(loan_num==p->loan_id)
                    {
                        valid=true;
                    }
                    p=p->link;
                }

            if (valid==true)
            {
            	update:system("cls");
            	display_loan_details();
				printf("\nEnter new interest rate: ");
            	scanf("%f",&percent);
            	if(percent<0)
            	{
            		printf("INVALID, INTEREST CANNOT BE NEGATIVE!");
            		getch();
            		goto update;
				}
				if(percent>25)
            	{
            		printf("INVALID, INTEREST CANNOT BE GREATER THAN 25%!");
            		getch();
            		goto update;
				}
				struct calc* t;
    			t = root;
    			while(t!=NULL)
    			{
    				if(t->loan_id == loan_num)
    				{
    					t->interest = percent;
    					break;
					}
					t = t -> link;
				}
				printf("The new interest value has been updated!");
				getch();
            }

            else
            {
                printf("\nINVALID LOAN ID\n");
                getch();
                goto loan_id;
            }

}
void delete_scheme()
{
    int loan_num;
	system("cls");
	loan_id : system("cls");
	display_loan_details();
	printf("\nEnter loan_id: ");
	scanf("%d",&loan_num);
	struct calc *p;
        p = root;

            bool valid=false;

                while(p!=NULL)
                {
                    if(loan_num==p->loan_id)
                    {
                        valid=true;
                        break;
                    }
                    p=p->link;
                }

            if (valid==true)
            {
				struct calc *t,*l;
				t = root;
				l = root;
				while(l->link->link!=NULL)
				{
					if(l->link->loan_id!=loan_num)
					{
						l=l->link;
					}
					else
					{
						break;
					}
				}
				while(t!=NULL)
				{
					if(t->loan_id==loan_num)
					{
						if(t==root)
						{
							root=root->link;
							t->link=NULL;
							free(t);
							break;
						}
						else if(t->link==NULL)
						{
							free(t);
							l->link=NULL;
							break;
						}
						else
						{
							l->link=t->link;
							free(t);
//							t->link=NULL;
							break;
						}
					}
					t=t->link;
				}
				printf("The scheme has been deleted!!");
				getch();
            }
            else
            {
                printf("\nINVALID LOAN ID\n");
                getch();
                goto loan_id;
            }
		display_loan_details();
}
void EmployeeLoanSchemes()
{
    start: system("cls");
    printf("***********************************************************************\n");
    printf("||                  Welcome to LOAN SCHEMES PAGE                    ||\n");
    printf("***********************          MENU        **************************\n\n");
    printf("1.Add New Scheme\n\n2.Update Existing Scheme\n\n3.Delete Existing Scheme\n\n4.Back to Main Menu\n\nEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add_scheme();
        EMainMenu();
        break;
    case 2:
        update_interest_rate();
        EMainMenu();
        break;
    case 3:
        delete_scheme();
        EMainMenu();
        break;
    case 4:
        EMainMenu();
        break;
    default:
        printf("Invalid input");
        getch();
        goto start;
    }
}
void TransactionMenu()
{
    start: system("cls");
    printf("***********************************************************************\n");
    printf("||                  Welcome to TRANSACTIONS PAGE                     ||\n");
    printf("***********************          MENU        **************************\n\n");
    int choice;
    printf("1.Withdrawal Money\n\n2.Money Transfer\n\n3.Check Balance\n\n4.Back to Main Menu\n\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        Withdrawal();
        break;
    case 2:
        MoneyTransfer();
        break;
    case 3:
        CheckBalance();
        break;
    case 4:
        MainMenu();
        break;
    default:
        printf("Invalid Input");
        getch();
        goto start;
    }
}
void Withdrawal()
{
    start: system("cls");
    printf("Enter the amount you want to withdraw: ");
    long int amount;
    scanf("%ld",&amount);
    struct person *temp;
    temp=hash_table_lookup(pin);
    if(amount<=500)
    {
        printf("\nAmount too small\n");
        getch();
        goto start;
    }
    else if(amount<0)
    {
        printf("\nAmount cannot be negative\n");
        getch();
        goto start;
    }
    else if(amount>(temp->bal))
    {
        printf("\nInsufficient balance in your account\n");
        getch();
        goto start;
    }
    password:
    printf("Password: ");
    char pass[32];
//scanf("%s",&pass);
    int i=0,k=0,flag1=0;
    char a;
        for(i=0;;)//infinite loop
        {
            a=getch();//stores char typed in a
            if((a>='a'&& a<='z')||(a>='A'&& a<='Z')||(a>='0'&&a <='9')||a=='%'||(a>='!'&&a<='~'))
                //check if a is numeric or alphabet
            {
                pass[i]=a;//stores a in pass
                ++i;
                printf("*");
            }
            if(a=='\b'&& i>=1)//if user typed backspace
                //i should be greater than 1.
            {
                printf("\b \b");//rub the character behind the cursor.
                --i;
            }
            if(a=='\r')//if enter is pressed
            {
                pass[i]='\0';//null means end of string.
                break;//break the loop
            }
        }
        //printf("%s",pass);
        struct person *temp4=hash_table_lookup(pin);
        if(pin==temp4->netbanking_no)
        {
            while(temp4->password[k]!='\0')
            {
                if(temp4->password[k]==pass[k])
                {
                    flag1=1;
                }
                else
                {
                    flag1=0;
                    break;
                }
                k++;
            }
        }
        if(flag1==0)
        {
            printf("\nIncorrect password\n");
            goto password;
        }
    system("cls");
    temp->bal=temp->bal-amount;
    printf("Withdrawal Successful!\nCurrent Balance: %ld",temp->bal);


    getch();
    TransactionMenu();
}
void MoneyTransfer()
{
    start: system("cls");
    printf("Enter the NetBanking Number: ");
    int netb;
    scanf("%d",&netb);
    if(netb==pin)
    {
        printf("\nCannot Transfer Money to own account\n");
        getch();
        goto start;
    }
    struct person *temp3;
    temp3=hash_table_lookup(netb);
    if(temp3==NULL)
    {
        printf("User Doesn't Exist");
        getch();
        goto start;
    }
    amount: printf("Enter the amount you want to transfer: ");
    long int amount;
    scanf("%ld",&amount);
    struct person *temp;
    temp=hash_table_lookup(pin);
    if(amount<=500)
    {
        printf("\nAmount too small\n");
        getch();
        goto amount;
    }
    else if(amount<0)
    {
        printf("\nAmount cannot be negative\n");
        getch();
        goto amount;
    }
    else if(amount>(temp->bal))
    {
        printf("\nInsufficient balance in your account\n");
        getch();
        goto amount;
    }
    password:
    printf("Password: ");
    char pass[32];
//scanf("%s",&pass);
    int i=0,k=0,flag1=0;
    char a;
        for(i=0;;)//infinite loop
        {
            a=getch();//stores char typed in a
            if((a>='a'&& a<='z')||(a>='A'&& a<='Z')||(a>='0'&&a <='9')||a=='%'||(a>='!'&&a<='~'))
                //check if a is numeric or alphabet
            {
                pass[i]=a;//stores a in pass
                ++i;
                printf("*");
            }
            if(a=='\b'&& i>=1)//if user typed backspace
                //i should be greater than 1.
            {
                printf("\b \b");//rub the character behind the cursor.
                --i;
            }
            if(a=='\r')//if enter is pressed
            {
                pass[i]='\0';//null means end of string.
                break;//break the loop
            }
        }
        //printf("%s",pass);
        struct person *temp4=hash_table_lookup(pin);
        if(pin==temp4->netbanking_no)
        {
            while(temp4->password[k]!='\0')
            {
                if(temp4->password[k]==pass[k])
                {
                    flag1=1;
                }
                else
                {
                    flag1=0;
                    break;
                }
                k++;
            }
        }
        if(flag1==0)
        {
            printf("Incorrect password");
            goto password;
        }
    system("cls");
    temp->bal=temp->bal-amount;
    temp3->bal=temp3->bal+amount;
    printf("\nMoney Transfer Successful!\nCurrent Balance: %ld",temp->bal);
    getch();
    TransactionMenu();
}
void CheckBalance()
{
    struct person *temp;
    temp=hash_table_lookup(pin);
    system("cls");
    printf("Current Balance: %ld",temp->bal);
    getch();
    TransactionMenu();
}
void delete_loan_request(int n)
{
    struct loan_ap *t,*l;
    t = head;
    l = head;
    if(t->next==NULL)
    {
        free(t);
        head=NULL;
    }
    else
    {
        while(l->next->next!=NULL)
        {
            if(l->next->nb!=n)
            {
                l=l->next;
            }
            else
            {
                break;
            }
        }
        while(t!=NULL)
        {
            if(t->nb==n)
            {
                if(t==head)
                {
                    head=head->next;
                    t->next=NULL;
                    free(t);
                    break;
                }
                else if(t->next==NULL)
                {
                    free(t);
                    l->next=NULL;
                    break;
                }
                else
                {
                    l->next=t->next;
                    free(t);
    //							t->link=NULL;
                    break;
                }
            }
            t=t->next;
        }
    }
}
void add_cand(int a)
{
    struct queuenode *p;
    p = (struct queuenode*)malloc(sizeof(struct queuenode));
    p->data = a;
    p->next = 0;
    if(front == 0)
    front = rear = p;
    else
    {
        rear->next = p;
        rear = p;
    }
}
void rem_cand()
{
    if (front==0)
    {
        printf("No candidates\n");
    }
    else
    {
        struct queuenode *temp;
        temp = front;
        front= front->next;
        free(temp);
    }
}
void display()
{
    system("cls");
    printf("***********************************************************************\n");
    printf("||                       UPDATED INTERVEIW QUEUE                     ||\n");
    printf("***********************************************************************\n");
    if(front==0)
    {
        printf("\nNo Data available in the Queue\n");
    }
    else
    {
        struct queuenode *t=front;
        while(t != 0)
        {
            printf("\t\t\t\t%d\n",t->data);
            t = t->next;
        }
    }
}
int num=0; //global
int canid=100;
void EmployeeRecruitment()
{
    start: system("cls");
    int choice,i,j=0,ch,k=0;
    printf("***********************************************************************\n");
    printf("||                Welcome to EMPLOYEE INTERVIEW PAGE                 ||\n");
    printf("***********************          MENU        **************************\n\n");
    printf("1.Apply for Employee\n\n2.Check Interview Order\n\n3.Back to Main Menu\n\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system("cls");
        add:printf("***********************************************************************\n");
            printf("||                     EMPLOYEE APPLICATION FORM                     ||\n");
            printf("***********************************************************************\n\n");
        num++;k++;
        printf("Enter Personal Information:\n\n");
        char tempo;
        scanf("%c",&tempo);
        printf("Enter Name: ");
        scanf("%[^\n]",&det[k].name);
        j=0;
        while(j==0)
        {
            ph: printf("Enter Contact Number(10 DIGITS ONLY): ");
            scanf("%lld",&det[k].pno);
            if((det[k].pno>9999999999))
            {
                printf("\nInvalid entry[Number cannot be greater than 10 digits], Try Again\n");
                getch();
                goto ph;

            }
            else if(det[k].pno<1000000000)
            {
                printf("\nInvalid Entry[Number cannot be lesser than 10 digits or Negative], Try Again\n");
                getch();
                goto ph;
            }

            else
            {
                j=1;
            }
        }
        j=0;
        char temp;
        scanf("%c",&temp);
        while(j==0)
        {
            gen: printf("Enter Gender [M, F or O]: ");
            scanf("%c",&det[k].gen);
            if(det[k].gen!='M' && det[k].gen!='F' && det[k].gen!='O' )
            {
                printf("\nInvalid Entry. Enter Valid Options only\n");
                getch();
                goto gen;
                scanf("%c",&temp);
            }
            else
            {
                j=1;
            }
        }
        j=0;
        while(j==0)
        {
            ag: printf("Enter Age: ");
            scanf("%d",&det[k].age);
            if(det[k].age<0)
            {
                printf("\nInvalid Entry, Age cannot be negative. Try again.\n");
                getch();
                goto ag;
            }
            else if(det[k].age>=123)
            {
                printf("\nInvalid Entry, Age cannot be higher than 119. Try again.\n");
                getch();
                goto ag;
            }
            else
            {
                j=1;
            }
        }
        char o;
        scanf("%c",&o);
        printf("Enter Address: ");
        scanf("%[^\n]",&det[k].add);
        j=0;
        while(j==0)
        {
            pincode: printf("Enter Pincode: ");
            scanf("%ld",&det[k].pincode);
            if(det[k].pincode>999999)
            {
                printf("\nInvalid Entry, Pincode must be 6 digits only. Try Again\n");
                getch();
                goto pincode;
            }
            else if(det[k].pincode<=99999)
            {
                printf("\nInvalid Entry, Pincode must be 6 digits only or Pincode in India starts from 110001. Try Again\n");
                getch();
                goto pincode;
            }
            else if(det[k].pincode<110001)
            {
                printf("\nInvalid Entry,Pincode in India starts from 110001. Try Again\n");
                getch();
                goto pincode;
            }
            else if(det[k].pincode<=0)
            {
                printf("\nInvalid Entry, Pincode cannot be negative. Try Again\n");
                getch();
                goto pincode;
            }
            else
            {
                j=1;
            }
        }
        system("cls");
        printf("\n\nGenerated Candidate ID: %d\n\n",++canid);
        add_cand(canid);
        getch();
        goto start;
        break;
    case 2:
        system("cls");
        if(num==0)
        {
            printf("No Data input available\n\n");
        }
        else
            display();
        printf("\n");
        getch();
        goto start;
        break;
    case 3:
        LoginMenu();
        break;
    default:
        printf("Invalid Input");
        getch();
        goto start;
    }
}
void CheckEmployeeRecruitment()
{
    start: system("cls");
    printf("***********************************************************************\n");
    printf("||                 EMPLOYEE RECRUITMENT INTERVIEW                    ||\n");
    printf("***********************          MENU        **************************\n\n");
    int choice,i,canid=100,j=0,ch,k=0;
    printf("1.Check Interview Order\n\n2.End Interview of Current Candidate\n\n3.Show Details of Current Candidate\n\n4.Back to Main Menu\n\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system("cls");
        if(num==0)
        {
            printf("No Data input available\n\n");
        }
        else
            display();
            printf("\n");
        getch();
        goto start;
        break;
    case 2:
        system("cls");
        if(num==0)
        {
            printf("There is no Current Candidate!");
            getch();
            CheckEmployeeRecruitment();
        }
        rem_cand();
        num--;
        if(num!=0)
        {
            display();
            printf("\n");
        }
        if(num==0)
        {
            system("cls");
            printf("All your Interviews are over!\n");
            getch();
            CheckEmployeeRecruitment();
        }
        getch();
        goto start;
        break;
    case 3:
        system("cls");
        if(front!=0)
        {
            printf("\n");
            printf("Candidate ID: %d\n",front->data);
            printf("Name: %s\n",det[(front->data)%100].name);
            printf("Contact Number: %lld\n",det[(front->data)%100].pno);
            printf("Gender: %c\n",det[(front->data)%100].gen);
            printf("Age: %d\n",det[(front->data)%100].age);
            printf("Address: %s\n",det[(front->data)%100].add);
            printf("Pincode: %d\n\n",det[(front->data)%100].pincode);
        }
        else
        {
            system("cls");
            printf("There is no Current Candidate!");
            getch();
            goto start;
        }
        getch();
        goto start;
        break;
    case 4:
        EMainMenu();
        break;
    default:
        printf("Invalid Input");
        getch();
        goto start;
    }
}
