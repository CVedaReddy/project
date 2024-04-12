#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>  // for sleep function
#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define ESC 27
#define ENTER 13
#define BKSP 8
#define FUNCTION       int passwordsecure(char pswd[])
#define DECLARATION      int a=0, A=0, num=0, spe=0;
#define LOOP           for(int i=0; i<strlen(pswd); i++)
#define LENGTH         if(strlen(pswd)<7)  return 2;
#define SMALL          if(pswd[i]>='a' && pswd[i]<='z') a=1;
#define LARGE          else if(pswd[i]>='A' && pswd[i]<='Z') A=1;
#define NUMBER         else if(pswd[i]>='0' && pswd[i]<='9')  num=1;
#define SEP_CHAR       else if( (pswd[i]>='!' && pswd[i]<='/') || pswd[i]=='@' || pswd[i] == '_') spe=1;
#define INVALIDCHAR   else if( (pswd[i]>=':' && pswd[i]<='?') || (pswd[i]>='[' && pswd[i]<='`') || (pswd[i]>='{' && pswd[i]<='~') ) return 3;
#define STRENGTH       if(a==1 && A==1 && num==1 && spe==1) return 1;
#define INLOOP        { SMALL LARGE NUMBER SEP_CHAR INVALIDCHAR }
#define RETURN         return 2;
#define SPE_CHAR      (( (uname[i]>='!' && uname[i]<='/') || uname[i]=='@' || uname[i]==' ')
#define INVALID_CHAR  ( (uname[i]>=':' && uname[i]<='?') || (uname[i]>='[' && uname[i]<='`') || (uname[i]>='{' && uname[i]<='~') ) )
int i;
char pswd[];
struct { char name[20]; char pswd[20]; }user;     
struct{char name[20];char pswd[20];}use;
FILE *fptr;
char uname[30];

int main()
{
    system("cls"); 
    int n;
    system("color 70");                                   /// CAN USE TO CHANGE INTERFACE AND TEXT COLOUR
    while(1)
    {
        n= logprompt();
        switch(n)
        {
            case F1 : login();   break;
            case F2 : userreg(); break;
            case F3 : about ();  break;
            case ESC : escape();
        }
        system("cls");                                       /// CLEARS SCREEN
    }
}
///  ========================  *   ===  *  === * S E C U R E . N O T E P A D * ===  *  ===  * ==========================
/*
    ===================================================================================================================
    ABOUT THE PROJECT :

    A BRIEF OVERVIEW OF "Secure Notepad" project by Veda,Varshitha and Mohitha of 1st year UG
    This Project is coded in C Language using concepts like: FILE HANDLING , FUNCTION , POINTERS , HEADER FILE , TIME , SYSTEM 

    Secure Notepad provides a user-friendly interface which he/she can use to access their text 
    It has a password protection, and a USER can either Login or Register themselves accordingly
    LOGIN_USER.h      have login functionalities and        login()   performs Login task
    REGISTER_USER.h   have register functionalities and     userreg() performs REGISTERATION task
    Interface is presented beautifully using gotoxy(), delay() functions.
    gotoxy() helps to set co-ordinate on console
    delay()  is used in a manner such that it provides a little animation

    AFTER USER CREATES ACCOUNT OR LOGIN HE CAN ACCESS TO HIS PERSONAL TEXT SERVICE


                                            --------------------------------------------


    Various functionalities are provide for NOTEPAD  Has Different Modes - READ , OVERWRITE , ADD , DEMO
    READ MODE - It displays all the text USER entered previously on interface
                "NOTEPAD_DISPLAY.h"  has all functionalities for READ MODE
    OVERWRITE - It deletes all the previous memory and starts storing everything again
                "NOTEPAD_WRITE.h" has all functionalities of OVERWRITE MODE
    ADD MODE  - It add more data after previously stored data.
                "NOTEPAD_ADDTEXT.h" has all functionalities of ADD MODE
    DEMO MODE - It provides a user-friendly interface where a user can check how everything works.
                "NOTEPAD_DEMO.h" has all functionalities of DEMO MODE
                                        ----------------------------------------------------
    NOTEPAD & INTERFACE PROVIDED ARE DIFFERENT IN BEHAVIOUR AND HAVE CERTAIN SET OF RULES TO USE

    1. NOTES CAN BE SAVED WITH TIMESTAP
    2. BACKSPACE HIT IS SPECIFIED WITH <- SYMBOL
    3. ONLY UNIQUE USERS EXIST 4. OVERWRITE MODE DELETES PREXISTING FILE AND ADD NEW TEXT
    5. TEXT EDITOR MODE CONTINUES TO WRITE AFTER LAST LEFT
    6. TO END INSERTION MODE HIT ESC KEY
    7. READ MODE SHOWS ALL TEXT USER LAST ENTERED IN FILE
    8. DEMO MODE PROVIDES VISUAL DEMO OF HOW TEXT IS INSERTED
    9. DEMO MODE DOESN'T SAVE TEXT TO FILE
    10. IT DOESN'T SUPPORT KEYBORD SHORTCUTS ( CTRL+V, CTR+S) ETC
    11. HIT ENTER IF LESS SPACE IS AVAILABLE TO MAINTAIN MARGIN

    THEY ARE PROVIDE IN "NOTEPAD_HELP.h" FILE

                                             -----------------------------------------

    It also provides many other functionalities like
    i)   securepassword() : IT CHECKS WEATHER PASSWORD ENTERED IS STRONG OR NOT
    ii)  timestamp()      : IT STORES THE TIMING WHEN DATA IS ENTERED
    iii) username_valid() : ALLOWS ONLY VALID USERNAME WITHOUT ANY SPECIAL CHAR OTHER THAN  ' _ '
    iv)  userchk()        : IT MAKES SURE THAT ONLY UNIQUE USERNAME EXISTS. IF USERNAME EXITS ALREADY IT DISALLOWS TO MAKE CHANGES AND ASK TO LOGIN
    v)   inputuser()      : Stores userdata credentials to a file

    ======================================================================================================================
*/

///                              F U N C T I O N S . h

///  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///  It holds all frequently called functions like -
///  gotoxy()      : Sets co-ordinates in console according to parameters passed
///  logprompt()   : Presents initial opening window
///  escape()      : Ends program
///  delay         : Helps in presenting little animation'

///  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void gotoxy(int x, int y)                               /// PERFORM GOTO X , Y CO-ORDINATE IN PROMPT
{
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void delay(ms)                                          /// DELAY's OPERATION
{
    clock_t timeDelay=ms+ clock();
    while(timeDelay>clock());
}

int logprompt()                                        /// OPENING PROMPT FOR USER
{
    int n;
    gotoxy(9,6);
    printf("---- xx ------- xx ------- S e C u R e . N o T e P a D ------- xx -------- xx ----");
     sleep(3);
    gotoxy(18,10);
    for(int i=0; i<61; i++) //why?
    { 
        printf("=");
        }
    gotoxy(38,13);
    printf("** PRESS F1 TO LOGIN **");
    sleep(2);
    gotoxy(36,15);
    printf("** PRESS F2 TO REGISTER **");
     sleep(2);
    gotoxy(35,17);
    printf("** PRESS F3 TO SEE ABOUT **");
     sleep(2);
    gotoxy(37,19);
    printf("** PRESS ESC TO EXIT **");
     sleep(2);
    gotoxy(25,21);
    printf("---------------*-*-**-**-**-**-*-*-------------\n\n");
    gotoxy(18,24);
    for(int i=0; i<61; i++)
    { 
        printf("=");
        }
         printf("\n\n\n");
    n=getch();
    // After displaying the entire opening message, the program waits for the user to press a key using the getch() function.
// getch() reads a single character from the keyboard without echoing it to the screen.
// The value of the pressed key (in ASCII) is stored in the variable n
    return n;
}


void escape()                                              /// ESC HIT CODE
{
    system("cls");

    gotoxy(10,12);
    for(int i=0; i<85; i++)
    { printf("="); delay(10);}
    delay(50);
    gotoxy(30,16); delay(400);
    printf("!!!!!!!! -x-x-x-x- NoTePaD CloSeD -x-x-x-x-  !!!!!! \n\n\n\n");
    gotoxy(10,20);
    for(int i=0; i<85; i++)
    { printf("="); delay(20);}
    gotoxy(0,30); getch();
    exit(1); // to terminate the program with a return code of 1
}
void about()
{
    system("cls");
    printf("\n\n\n\n");
    printf(" ================  *   ===  *  === * S E C U R E . N O T E P A D * ===  *  ===  * ==================== \n\n\n");
    printf("     ============================================================================================\n\n");
    printf("    ABOUT PROJECT :\n\n");
    printf("    A BRIEF OVERVIEW OF 'Secure Notepad'  \n");
    printf("    PROJECT by Veda,Varshitha and Mohitha, 1st year UG   \n\n");
    printf("    This Project is  coded in C Language using concepts like: FILE HANDLING , FUNCTION, POINTERS, HEADER FILE, TIME ");
     sleep(3);
    printf("    Secure Notepad provides a user-friendly interface which he/she can use to access their text from \n");
    printf("    It has a password protected, and a USER can either Login or Register themselves accordingly \n");
    printf("    Interface is presented beautifully using gotoxy(), delay() functions. \n");
    printf("    gotoxy() helps to set co-ordinate on console \n");
    printf("    delay()  is used in a manner such that it provides a little animation \n\n");
    printf("    AFTER USER CREATES ACCOUNT OR LOGIN HE CAN ACCESS TO HIS PERSONAL TEXT SERVICE \n\n\n");
    printf("    -------------------------------------------- \n\n\n");
    printf("    OVERWRITE - It deletes all the previous memory and starts storing everything again\n");
    printf("    ADD MODE  - It add more data after previously stored data.\n");
    printf("    DEMO MODE - It provides a user-friendly interface where a user can check how everything works.\n");
    printf("    ------------------------------------------------------------- \n\n\n\n");
    printf("    NOTEPAD & INTERFACE PROVIDED ARE DIFFERENT IN BEHAVIOUR AND HAVE CERTAIN SET OF RULES TO USE \n\n");
    printf("    1. NOTES CAN BE SAVED WITH TIMESTAP \n");
    printf("    2. BACKSPACE HIT IS SPECIFIED WITH <- SYMBOL \n");
    printf("    3. ONLY UNIQUE USERS EXIST 4. OVERWRITE MODE DELETES PREXISTING FILE AND ADD NEW TEXT \n");
    printf("    5. TEXT EDITOR MODE CONTINUES TO WRITE AFTER LAST LEFT \n");
    printf("    6. TO END INSERTION MODE HIT ESC KEY \n");
    printf("    7. READ MODE SHOWS ALL TEXT USER LAST ENTERED IN FILE \n");
    printf("    8. DEMO MODE PROVIDES VISUAL DEMO OF HOW TEXT IS INSERTED \n");
    printf("    9. DEMO MODE DOESN'T SAVE TEXT TO FILE \n");
    printf("    10. IT DOESN'T SUPPORT KEYBORD SHORTCUTS ( CTRL+V, CTR+S) ETC \n");
    printf("    11. HIT ENTER IF LESS SPACE IS AVAILABLE TO MAINTAIN MARGIN \n\n");

    printf("    THEY ARE PROVIDE IN 'NOTEPAD_HELP.h' FILE \n\n");

    printf("    ------------------------------------------- \n\n");
    sleep(3);
    printf("    It also provides many other functionalities like \n");
    printf("    i)   securepassword() : IT CHECKS WEATHER PASSWORD ENTERED IS STRONG OR NOT \n");
    printf("    ii)  timestamp()      : IT STORES THE TIMING WHEN DATA IS ENTERED \n");
    printf("    iii) username_valid() : ALLOWS ONLY VALID USERNAME WITHOUT ANY SPECIAL CHAR OTHER THAN  ' _ ' \n");
    printf("    iv)  userchk()        : IT MAKES SURE THAT ONLY UNIQUE USERNAME EXISTS. IF USERNAME EXITS ALREADY \n");
    printf("                            IT DISALLOWS TO MAKE CHANGES AND ASK TO LOGIN \n");
    printf("    v)   inputuser()      : Stores userdata credentials to a file \n\n");
 sleep(3);
    printf("    ================================================================================================= \n\n\n\n");
    gotoxy(37,73); printf("** PRESS ESC TO GO BACK ** \n\n\n");
    printf("    ================================================================================================= \n\n\n\n");
    while(1)
    {
        int k=getch(); if(k==27)main();
    }
}
///                       L  O  G  I  N  _  U  S  E  R
///  ================================================================================

///  ALL LOGIN FUNCTIONALITIES ARE PRESENT IN THIS HEADERFILE
///  login()       : It is main function that calls other additional functions
///  checkuser()   : It checks weather enter credentials match or not
///  register()    : It is called when there exists no user record

///  =================================================================================

                                                   ///  WHEN NO USERFILE DATA IS FOUND THIS FUNCTION IS CALLED
                                                   ///  IT TELLS USER TO FIRST REGISTER THEM & THEN LOGIN
void register()
{   gotoxy(22,12);
    {  
         printf("-"); delay(10);
    }
    gotoxy(27,14); printf("---x---xx--xx- NO USERFILE EXIT -xx--xx---x---");
    gotoxy(38, 16); printf("-- REGISTER FIRST --");
    gotoxy(32, 18); delay(800);
    printf("---- PRESS F2 FOR REGISTERATION ----\n");
    while(1)// loop will continuously prompt the user until they register or exit the program
    {
        int k=getch(); 
        if(k==F2)
        userreg();
    }  
}
                                                  ///  CHECKS WEATHER ENTERED CREDENTIALS ARE VALID OR NOT
void checkuser(char uname[], char upass[])
{  
     fptr = fopen("userrecord.bin", "rb");         
// You should use "r" for opening text files in read only
//You should use "rb" if you're opening non-text files..Open the binary file in read mode. If the file does not exist, the open() function returns NULL.
//file_name: This is of C string type and accepts the name of the file that is needed to be opened.
//mode_of_operation: This is also of C string type and refers to the mode of the file access
///  opens file in read mode
    if(fptr==NULL)  register();
    int chku, chkp, found=0;
    while(!feof(fptr))
    // The feof() function is used to check whether the file pointer to a stream is pointing to the end of the file or not.
    // It returns a non-zero value if the end is reached, otherwise, it returns 0.
    {  
         fread(&use, sizeof(use), 1,fptr);//reads data from the file
         // it compares the entered username and password with the stored username and password using a function called check()
        chku= check(uname, use.name);           
        chkp= check(upass, use.pswd);             /// it basically takes parameter and tells weather string are equal or not

        if(chku==1 && chkp==1)
        {   found=1; fclose(fptr);               
            for(int i=0; i<53; i++)
            gotoxy(22,12);
            for(int i=0; i<53; i++)
            { 
                printf("-");delay( 10); 
                }          
            gotoxy(27,14);
            printf("---x---xx--xx- DETAILS MATCHED -xx--xx---x---");
            gotoxy(29,16); delay(300);
            printf("---- PRESS ENTER TO OPEN NOTEPAD ----\n");
            gotoxy(22,18);
            for(int i=0; i<53; i++)
            {
                printf("-");
                delay(10);
            }   printf("\n");
            int k=getch();
            while(1)
            { if(k==13) notepadinput(uname); k= getch();}   //why?

        }   
        else continue;
    }

    if(found==0)                                            /// When Details did'nt match
    {   gotoxy(22,12);
        for(int i=0; i<53; i++)
        { printf("-");delay(10); }
        gotoxy(26,14);
        printf("---x---xx--xx- INVALID LOGIN -xx--xx---x---");
        gotoxy(34, 16); delay(800);
        printf("---- PRESS F1 TO TRY AGAIN ----\n");
        while(1){int k=getch(); if(k==F1) login();}
    }
}



void login()                                                ///  MAIN LOGIN FUNCTION    ///
{  
     char uname[20], upass[20], c;
    int i;
    gotoxy(25, 26);
    for(int i=0; i<46; i++)
    { 
        printf(">"); delay(15);
        }

    system("cls"); 
    gotoxy(25, 6);
    printf("------------------ LOGIN PROMPT ----------------");
    gotoxy(38,8);
    printf("ENTER USERNAME: ");
     scanf("%s", uname);
    gotoxy(36,10);  
    printf("ENTER PASSWORD: ");
    for(i=0; c!=13; i++)
    {  
         c=getch();
        if(c==8) 
        { 
            i-=2;
             continue; }
        upass[i]=c; printf("*");
    }   
    upass[i-1]='\0';
    gotoxy(30,10); checkuser(uname, upass); return;
}
FUNCTION
{
    DECLARATION
    LENGTH
    LOOP
    SMALL
    LARGE
    NUMBER
    SEP_CHAR
    INVALIDCHAR
    INLOOP
    STRENGTH
    RETURN
}


///                      R E G I S T E R _ U S E R . h
///  ========================================================================

///   ALL REGISTERATION FUNCTIONALITIES ARE PRESENT IN THIS HEADERFILE
///   userreg()         :   Main reg. function that calls other function
///   username_valid()  :   Checks weather username entered is valid or not
///   userchk()         :   Checks if username entered already exists
///   inputuser()       :   Enters userdata to a file.
///   check()           :   Checks weather parameters passed are equal or not

///  =========================================================================
                      /// DATA TYPE FOR USER  ///



int check(char upass[], char rpass[])                               /// CHECKS WEATHER STRING PASSED ARE EQUAL
{   if(strlen(upass)==strlen(rpass))
    {   for(int i=0; i<strlen(upass); i++)
        { if(upass[i]!=rpass[i]) 
        return 0; 
        }
         return 1;
    }
     else
      return 0;
}



void inputuser()                                                   ///  ADDS USERDATA TO RECORD FOR LATER USE  ///
{
    fptr = fopen("userrecord.bin", "ab");                          /// .bin is binary file & 'ab' opens
    fwrite(&user,sizeof(user),1,fptr);                             /// file in binary mode and append data
    fclose(fptr);
    gotoxy(37,18);
    printf("USER SUCCESSFULLY ADDED");
    delay(400); printf("  :");
    delay(400); printf("-");
    delay(400); printf(")\n\n");
    gotoxy(33,20); delay(300);
    printf("--- PRESS ENTER TO OPEN NOTEPAD ---\n\n");
    while(1){
        int k=getch(); 
    if(k==13)
     notepadinput(user.name);}
}



void userchk(FILE *usercheck, char uname[])                      ///  CHECKS WEATHER USERNAME ALREADY EXISTS  ///
{
    int chku;
    while(!feof(usercheck))
    {
        fread(&use, sizeof(use), 1,usercheck);
        chku= check(uname, use.name);

        if(chku==1)
        {   fclose(usercheck); gotoxy(22,10);
            for(int i=0; i<62; i++) { printf("-"); delay(10);}
            gotoxy(28,14);
            printf("---x---xx--xx- USER ALREDY EXISTS -xx--xx---x----");
            gotoxy(22,18);
            for(int i=0; i<61; i++) { printf("-"); delay(10) ;}
            gotoxy(38,20); delay(600);
            printf("---- PRESS F1 TO LOGIN ----");
            gotoxy(36,22); delay(600);
            printf("---- PRESS F2 TO TRY AGAIN ----");
            gotoxy(22,24);
            for(int i=0; i<61; i++)
            { 
                printf("-"); 
                delay(10) ;}
                printf("\n");
            getch();
            while(1)
            {   int k=getch();
             if(k==F1)
             login();
                else if(k==F2) 
                userreg();
            }
        } else 
        continue;
    }
}


void username_valid()                                           ///  CHECKS WEATHER USERNAME IS VAILD OR NOT  ///
{
    int k=0; 
    char uname[30];
     strcpy(uname, user.name);
    if(strlen(uname)<7)
    {   gotoxy(22,12);
        for(int i=0; i<61; i++)
        { printf("-"); 
        delay(10); }
         k=1;
        gotoxy(34, 15); 
        printf("USER NAME MUST BE OF ATLEAST 7 CHARACKTERS\n\n");
    }
    else
    {   for(int i=0; uname[i]!='\0'; i++)
        {   if SPE_CHAR || INVALID_CHAR
            {   gotoxy(22,12);
                if(uname[i]=='_')
                 continue;
                for(int i=0; i<61; i++)
                { printf("-"); 
                delay(10) ;}
                k=1;
                gotoxy(38, 14); 
                printf("xxxx INVALID USERNAME xxxx\n\n");
                gotoxy(28,16);  
                printf("USERNAME CAN ONLY HAVE 1 , A , a , _ CHAR & NO SPACE "); 
                 break;
            }   else 
            continue;
        }
    }
    if(k==1) // if invalid details
    {  
         gotoxy(22,18);
        for(int i=0; i<61; i++)
        { printf("-"); delay(10) ;}
        gotoxy(36,20); delay(600);
        printf("---- PRESS F2 TO TRY AGAIN ----\n");
        gotoxy(33,22);
        for(int i=0; i<19; i++)
        {
            printf("/"); 
            delay(10);
            printf("\\"); 
            delay(10);
        }   printf("\n");
        getch();
        while(1)
        {
             int k=getch(); 
             if(k==F2) 
             userreg();
             }
    }
    else return;
}

void userreg()                                                  ///  MAIN REGISTERATION FUNCTION, IT CALLS ALL OTHER FUNCTIONS  ///
{
       FILE *usercheck= fopen("userrecord.bin", "rb");
    char c, repass[20]; int n, i;

    gotoxy(25,26);
    for(int i=0; i<46; i++)
    {printf("~"); delay(20);}
    system("cls"); gotoxy(25, 6);
    printf("------------------ REGISTERATION PROMPT -----------------");
    gotoxy(40,8);
     printf("ENTER USERNAME: ");
    scanf("%s", user.name);
     username_valid();

    if(usercheck!=NULL)
        userchk(usercheck, user.name);
    gotoxy(40,10);
    printf("ENTER PASSWORD: ");
    scanf("%s", user.pswd);
    int j= passwordsecure(user.pswd);
    if(j==1)
    {
        gotoxy(38,12);
        printf("RE-ENTER PASSWORD: ");
        for(i=0; c!=13; i++)
        {   c=getch();
            if(c==8) 
            {i-=2; 
            printf("<-");
            continue;}
            repass[i]=c; //why??
            printf("*");
        }   repass[i-1]='\0';
        int ch= check(user.pswd, repass);
        gotoxy(22,14);
        for(int i=0; i<61; i++)
        { printf("-");
        delay(10);}

        if(ch==1)
        {   gotoxy(40, 16);
            printf("PRESS ENTER TO CONTINUE \n\n");
            while(1){ 
                int n=getch();
             if(n==13) 
             inputuser();}
        }
        else
        {   gotoxy(40, 16);
            printf("PASSWORD DOES NOT MATCH \n\n");
            gotoxy(22,18);
            for(int i=0; i<61; i++)
            { printf("-"); 
            delay(10) ;}
            gotoxy(34,20);
             delay(600);
            printf("---- PRESS F2 TO TRY AGAIN ---- \n");
            gotoxy(33,22);
            for(int i=0; i<19; i++)
            {
                printf("/"); 
                delay(10);
                printf("\\");
                 delay(10);
            }   printf("\n");
            while(1)
            {
                int n=getch(); 
                if(n==F2)
                 userreg();
            }
        }
    }
    else if(j==2)
    { 
          gotoxy(30,12);
        for(int i=0; i<46; i++)
        {printf("-");
        delay(20);}
        gotoxy(45,14); 
        printf("WEAK PASSOWORD");
        gotoxy(24, 16);
        printf(" PASSWORDS MUST HAVE ATLEAST 7 CHAR & ALL CHAR A , a , 1 , @  \n");
        gotoxy(22,18);
        for(int i=0; i<61; i++)
        { printf("-"); 
        delay(10) ;}
        gotoxy(36, 20); 
        delay(800);
        printf("---- PRESS F2 TO TRY AGAIN ---- \n");
        gotoxy(33,22);
        for(int i=0; i<19; i++)
        {  
             printf("/");
              delay(10);
            printf("\\");
             delay(10);
        }  
         printf("\n");
        while(1){
            int n=getch();
         if(n==F2)
          userreg();}
    }
    else if(j==3)
    {   gotoxy(22,12);
        for(int i=0; i<61; i++)
        { printf("-");delay(20);}
        gotoxy(30,14);
        printf("CHAR LIKE = , ^ , ~ , ~ , \" , ' , ARE INVALID \n");
        gotoxy(34, 16); delay(800);
        printf("---- PRESS F2 TO TRY AGAIN ----\n");
        while(1)
        {
            int n=getch(); 
            if(n==F2) 
            userreg();
            }
    }   return;
}


///                             N o T e P a D . H

///   """"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

///   It has main notepad functionalities and call functions from other notepad file
///   notepadinput()  :  Presents opening window of NOTEPAD
///   choice()        :  Presents different functionalities to perform

///  """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void notepadinput(char name[])                      /// MAIN NOTEPAD FUNCTION
{
    system("cls");
    strcpy(uname, name);
    gotoxy(14, 4);
    printf("---^---x--^x^--- WELCOME %s , TO SECRET WORLD OF TEXT ---^x^--x---^---", name);
    gotoxy(37, 6); printf("e x p l o r e . f r e e l y ");
    gotoxy(29,10); printf("-+-+-+-+- ENTER YOUR CHOICE -+-+-+-+-");gotoxy(20,12);

    for(int i=0; i<57; i++) { printf("-");delay(15); }
    gotoxy(34,14); printf(">>> PRESS F1 FOR HELP <<<");
    gotoxy(34,16); printf(">>> PRESS F2 FOR DEMO <<<");
    gotoxy(31,18); printf(">>> PRESS F3 TO DISPLAY TEXT <<<");
    gotoxy(33,20); printf(">>> PRESS F4 TO ADD TEXT <<<\n\n");
    gotoxy(29,22);printf(">>>> PRESS F5 TO OVERWRITE FILE <<<<\n\n");
    gotoxy(34,24); printf(">>> PRESS ESC TO EXIT <<<"); gotoxy(20,26);

    for(int i=0; i<57; i++)
     { 
        printf("-"); 
        delay(10);
        } 
        gotoxy(3, 30);
    while(1)
    {   int n=getch();
        switch(n)
        {
            case F1 : 
            notehelp();
            break;
            case F2 : 
            notedemo();
            break;
            case F3:  
            notedisplay();
            break;
            case F4: 
             noteadd(); 
             break;
            case F5:  
            notewrite(); 
            break;
            case ESC: 
            escape(); 
            break;
        }
    }
}


///                  N O T E P A D _ H E L P . h

///  ````````````````````````````````````````````````````````````````````````````
///  It tells all important instructions regarding the use of notepad

///  ````````````````````````````````````````````````````````````````````````````

void notehelp()
{
    gotoxy(25,10); 
    printf(". . . . . .^. i n s t r u c t i o n s .^. . . . . . .");
    gotoxy(33,12);
    for(int i=0; i<19; i++)
    {
        printf("/"); 
        delay(10);
        printf("\\");
         delay(10);
    }

    gotoxy(20,14);
    for(int i=0; i<63; i++)
    { printf("-");
     delay(10); }

    gotoxy(32,16); 
    printf("1. NOTES CAN BE SAVED WITH TIMESTAP ");
    gotoxy(28,18); 
    printf("2. BACKSPACE HIT IS SPECIFIED WITH <- SYMBOL ");
    gotoxy(34,20);
     printf("3. ONLY UNIQUE USERS EXIST ");
    gotoxy(19,22);
     printf("4. OVERWRITE MODE DELETES PREXISTING FILE AND ADD NEW TEXT ");
    gotoxy(22,24);
     printf("5. TEXT EDITOR MODE CONTINUES TO WRITE AFTER LAST LEFT ");
    gotoxy(30,26); 
    printf("6. TO END INSERTION MODE HIT ESC KEY ");
    gotoxy(24,28); 
    printf("7. READ MODE SHOWS ALL TEXT USER LAST ENTERED IN FILE");
    gotoxy(23,30);
     printf("8. DEMO MODE PROVIDES VISUAL DEMO OF HOW TEXT IS INSERTED");
    gotoxy(30,32);
     printf("9. DEMO MODE DOESN'T SAVE TEXT TO FILE ");
    gotoxy(20,34); 
    printf("10. IT DOESN'T SUPPORT KEYBORD SHORTCUTS ( CTRL+V, CTR+S) ETC ");
    gotoxy(21,36); 
    printf("11. HIT ENTER IF LESS SPACE IS AVAILABLE TO MAINTAIN MARGIN ");
    gotoxy(20,38);
    for(int i=0; i<63; i++)
    { printf("-"); 
    delay(10); }
    gotoxy(31,40);
    for(int i=0; i<19; i++)
    {
        printf("\\"); 
        delay(10);
        printf("/"); 
         delay(10);
    }
    gotoxy(34,42); 
    printf(">>> PRESS ESC TO GO BACK <<<\n\n");
    while(1)
    {
        int k=getch();
        if(k==ESC) 
        notepadinput(uname);
        else 
        continue;
    }
}

///                           n o t e p a d _ d e m o . H

///  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

///     It provides a beautiful interface where user can see a demo how use notepad properly

///  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


void enterhit_demo()                                        /// d e m o _ e n t e r _ h i t _ c a l l
{
    system("cls"); 
    gotoxy(14,4);
    printf("---^---x--^x^--- WELCOME %s , TO SECRET WORLD OF TEXT ---^x^--x---^---", uname);
    gotoxy(34,6); 
    printf("e x p l o r e . f r e e l y ");
    gotoxy(25,10); 
    printf(". . . . . .^. d e m o . w o r l d .^. . . . . . .");
    gotoxy(30,12);
    for(int i=0; i<19; i++)
    {
        printf("/"); 
        delay(10);
        printf("\\");
         delay(10);
    }
    gotoxy(27,46);
     printf("xx-xx press esc to exit insertion mode xx-xx");
    gotoxy(4, 14); 
    printf("ENTER TEXT: ");
    char c;
     int i;
    char str[1800];
     int f= 15;
    for(i=0; c!= ESC; i++)
    {
        c= getch(); 
        int j=c;
        if(j== BKSP ) 
        { i-=2;
         printf("<-"); 
        continue; }
        if(j==ENTER) 
        { str[i]='\n';
         gotoxy(4,f); 
         f++; 
         continue;}
        str[i]=c;
         printf("%c",c);
    } str[i-1]='\0';
    gotoxy(10,f+3);
    for(int i=0; i<85; i++)
    { printf("="); 
    delay(10);}
    f+=6; 
    gotoxy(5,f);
     i=0;
    printf("TEXT ENTERED: ");
    gotoxy(18,f);
    while(str[i]!='\0')
    {
      if(str[i]=='\n'){
         f++; 
         gotoxy(4,f);
         }
      else 
      printf("%c", str[i]); 
      i++;
    } printf("\n");
    gotoxy(10,f+3);
    for(int i=0; i<85; i++)
    { printf("=");
     delay(10);}
    gotoxy(30,f+6);
    for(int i=0; i<19; i++)
    {
        printf("/");
         delay(10);
        printf("\\");
         delay(10);
    }

    gotoxy(27,f+8); 
    printf("---||--||- press F1 to go back -||-||-||---");
    gotoxy(27,f+10); 
    printf("||-||-||- press F2 to test again -||-||-||");
    gotoxy(30,f+12);
    for(int i=0; i<19; i++)
    {
        printf("\\"); 
        delay(10);
        printf("/"); 
         delay(10);
    } 
    printf("\n\n\n");
    f=getch();
    while(1)
    {
        if(f==F1)
         notepadinput(uname);
        else if(f==F2) 
        enterhit_demo();
        f=getch();
    }
}


void notedemo()                                           ///   M A I N _ D E M O _ F U N C T I O N
{
    system("cls"); 
    gotoxy(14,4);
    printf("---^---x--^x^--- WELCOME %s , TO SECRET WORLD OF TEXT ---^x^--x---^---", uname);
    gotoxy(34,6);
     printf("e x p l o r e . f r e e l y ");
    gotoxy(24,10); 
    printf(". . . . . . .^. d e m o . w o r l d .^. . . . . . . .");
    gotoxy(26,15);
    for(int i=0; i<23; i++)
    {
        printf("/");
         delay(10);
        printf("\\");
         delay(10);
    }
    gotoxy(30,17); 
    printf("PRESS ENTER TO START INSERTING TEXT");
    gotoxy(30,19); 
    printf(">>>>>>  PRESS F1 TO GO BACK  <<<<<");
    gotoxy(30,21); 
    printf("* PRESS ESC TO EXIT INSETION MODE *");
    gotoxy(23,23);
    for(int i=0; i<26; i++)
    {
        printf("\\");
         delay(10);
        printf("/");
          delay(10);
    }
    printf("\n\n\n");
    while(1)
    {
        int k= getch();
        if(k==ENTER) { 
            enterhit_demo(); 
            break;}
        else if(k==F1){ 
            notepadinput(uname); 
            break;}
        else if(k==ESC)
         {escape(); 
        break; }
    }

}

///                            n o t e p a d _ d i s p l a y . H

///   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///       It prints all previous data user entered till now
///   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


/* DISPLAY ENTER HIT FUNCTIONALITIES */
void enterhit_display()
{
    system("cls"); 
    gotoxy(14,4);
    printf("---^---x--^x^--- WELCOME %s , TO SECRET WORLD OF TEXT ---^x^--x---^---", uname);
    gotoxy(37,6); 
    printf("e x p l o r e . f r e e l y ");
    gotoxy(23,10); 
    printf(". . . . . . .  v i s u a l . w o r l d  . . . . . . . .");
    gotoxy(30,12);
    for(int i=0; i<19; i++)
    {
        printf("/");
         delay(10);
        printf("\\"); 
        delay(10);
    }
    FILE *userfile= fopen(uname, "rb");
    char text[50]=">>>>>  FILE TEXT  <<<<<", chr; int j= 19;
    gotoxy(4, 16);
    for(int i=0; i<36; i++)
    { printf("-"); 
    delay(10);} 
    int i=0;
    while(text[i]!='\0'){
        printf("%c",text[i]);
        i++;
        delay(10);}
    for(int i=0; i<36; i++)
    { printf("-"); 
    delay(10);}

    gotoxy(4,18);
    for(int i=0; !feof(userfile); i++)
    {
        chr=fgetc(userfile);
        if(chr=='\n'){
            gotoxy(4,j);
            j++; 
            continue;}
        printf("%c",chr);
    }   j+=5;
    gotoxy(4,j);
    for(int i=0; i<95; i++)
    { printf("-"); 
    delay(5);}
    gotoxy(27,j+2); 
    printf("---||--||- press F1 to add text -||-||-||---");
    gotoxy(26,j+4);
    printf("---||--||-  press F2 to overwrite  -||-||-||---");
    gotoxy(27,j+6); 
    printf("---||--||- press F3 to go back -||-||-||---");
    gotoxy(27,j+8);
     printf("---||--||-  press ESC to EXIT  -||-||-||---\n\n");
    gotoxy(4,j+10);
    for(int i=0; i<95; i++)
    { printf("-"); 
    delay(5);}
    fclose(userfile);
    while(1)
    {
        int k= getch();
        if(k==F1) {
             noteadd(); 
             break;}
        else if(k==F2){ 
            notewrite(); 
            break;}
        else if(k==F3) {
            notepadinput(uname);
             break;}
        else if(k==ESC) {
            escape();
             break;}
    }
}

/* DISPLAY FILE TEXT */
void notedisplay()
{   system("cls"); gotoxy(14,4);
    printf("---^---x--^x^--- WELCOME %s , TO SECRET WORLD OF TEXT ---^x^--x---^---", uname);
    gotoxy(37,6); 
    printf("e x p l o r e . f r e e l y ");
    gotoxy(23,10); 
    printf(". . . . . . .  v i s u a l . w o r l d  . . . . . . . .");
    gotoxy(26,13);
    for(int i=0; i<23; i++)
    {
        printf("/");  
        delay(10);
        printf("\\");
         delay(10);
    }
    gotoxy(34,15); 
    printf("PRESS ENTER TO DISPLAY TEXT");
    gotoxy(30,17); 
    printf(">>>>>>  PRESS F1 TO GO BACK  <<<<<");
     gotoxy(23,19);
    for(int i=0; i<26; i++)
    { 
        printf("\\");
     delay(10); 
     printf("/"); 
      delay(10);
      } 
      printf("\n\n");
    while(1)
    {
        int k= getch();
        if(k==ENTER) { 
            enterhit_display(); 
            break;}
        else if(k==F1){ 
            notepadinput(uname);
             break;}
    }
}

///                            n o t e p a d _ a d d t e x t . H

///  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

///       It adds entered text after last data and gives option of adding timestamp

///  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// ADD NEW TEXT TO FILE //
void noteadd()
{
    system("cls"); gotoxy(14,4);
    printf("---^---x--^x^--- WELCOME %s , TO SECRET WORLD OF TEXT ---^x^--x---^---", uname);
    gotoxy(37,6); printf("e x p l o r e . f r e e l y ");
    gotoxy(23,10); printf(". . . . . . .  c r e a t e . w o r l d  . . . . . . . .");
    gotoxy(30,12);
    for(int i=0; i<19; i++)
    {
        printf("/");
         delay(10);
        printf("\\"); 
        delay(10);
    }
    char head[25]=">>>>>  ENTER TEXT  <<<<<", chr; int j= 19;
    gotoxy(4, 16);
    for(int i=0; i<36; i++)
    { printf("-"); 
    delay(10);} 
    int i=0;
    while(head[i]!='\0'){
        printf("%c",head[i]);
        i++;
        delay(10);}
    for(int i=0; i<36; i++)
    { printf("-"); 
    delay(10);}
    gotoxy(27,46); 
    printf("xx-xx press esc to exit insertion mode xx-xx");
    gotoxy(4,18); 
    int f= 19;
    fflush(stdin);
    char text[1800], c;
    getch();
    for(i=0; c!= ESC; i++)
    {
        c= getch(); 
        int j=c;
        if(j== BKSP ) { 
            i-=2; 
            printf("<-"); 
            continue; }
        if(j== ENTER) { 
            text[i]='\n'; 
            gotoxy(4,f); 
            f++; 
            continue;}
        text[i]=c; 
        printf("%c",c);
    } text[i-1]='\0'; 
    f+=3;
    fflush(stdin); 
    gotoxy(4,f);
    for(int i=0; i<95; i++)
    { 
        printf("-"); 
    delay(5);
    }
    gotoxy(25,f+2); 
    printf("f---||--||- press F1 to add timstamp -||-||-||---");
    gotoxy(28,f+4);  
      printf("---||--||- press F2 to add text -||-||-||---");
    gotoxy(29,f+6);   
      printf("---||--||- press F3 to go back -||-||-||---");
    gotoxy(30,f+8);   
       printf("---||--||- press ESC to exit -||-||-||---");
    fflush(stdin); 
    gotoxy(4,f+10);
    for(int i=0; i<95; i++)
    { 
        printf("-"); 
        delay(5);
        }
    while(1)
    {
        int k= getch();
        if(k==F1)      
         {
             notewrite_timestamp(1, f+12, 2, text);
              break;} ///        FUNCTION YET TO ADD
        else if(k==F2)  { 
            notewrite_timestamp(2, f+12, 2, text); 
            break;}    ///         FUNCTION YET TO ADD
        else if(k==F3)  { 
            notepadinput(uname); 
            break;}
        else if(k==ESC) { 
            escape();
             break;}
    }
}

/*  NOTEPAD INPUT FUNCTIONALITIES   */

/*  INSERTS DATA IN FILE AND GIVE TIMESTAMP WITH CHOICE */
void notewrite_timestamp(int t, int f, int a, char text[])
{
    FILE *userfile;
    if(a==1) { 
        userfile= fopen(uname, "wb"); }
    else if(a==2) {
         userfile= fopen(uname, "ab"); }
    if(t==1)
    {
        time_t t;
        time(&t);
        char *j= ctime(&t);
        char curr[200]="\n-+-+-+- TIME STAMP: ";
        strcat(curr,j); curr[45]=' ';
        strcat(curr, "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-");
        curr[93]='\n';
        curr[94]='\n';
        fwrite(&curr, sizeof(char),95,userfile);
    }
    else{char j[2]="\n\n"; fwrite(&j, sizeof(char),2,userfile); }
    int len= strlen(text);
    gotoxy(30,f);
    for(int i=0; i<19; i++)
    {
        printf("/"); 
        delay(10);
        printf("\\"); 
        delay(10);
    }
    fwrite(&text, sizeof(char),len,userfile);
    if(t==1)
    {
        time_t t; time(&t);
        char *j= ctime(&t);
        char curr[200]="\n\n-^-^-^- TIME STAMP: ";
        strcat(curr,j); curr[46]=' ';
        strcat(curr,"-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-");
        fwrite(&curr, sizeof(char),94,userfile);
    }
    gotoxy(36,f+2); 
    printf("***  TEXT - INSERTED  ***\n\n");
    fclose(userfile);
    gotoxy(32,f+4); 
    printf("***  PRESS ENTER TO GO BACK  ***\n\n");
    while(1)
    {
        int k=getch(); 
        if(k==13) notepadinput(uname);
        }
}

/* NOTEPAD OVERWRITE ENTER HIT FUNCTIONALITY */
void enterhit_write()
{
    system("cls"); 
    gotoxy(14,4);
    printf("---^---x--^x^--- WELCOME %s , TO SECRET WORLD OF TEXT ---^x^--x---^---", uname);
    gotoxy(37,6); 
    printf("e x p l o r e . f r e e l y ");
    gotoxy(23,10);
     printf(". . . . . . .  c r e a t e . w o r l d  . . . . . . . .");
    gotoxy(30,12);
    for(int i=0; i<19; i++)
    {
        printf("/"); 
        delay(10);
        printf("\\"); 
        delay(10);
    }
    char head[25]=">>>>>  ENTER TEXT  <<<<<", chr; int j= 19;
    gotoxy(4, 16);
    for(int i=0; i<36; i++)
    { printf("-"); 
    delay(10);} 
    int i=0;
    while(head[i]!='\0')
    {printf("%c",head[i]);i++;delay(10);}
    for(int i=0; i<36; i++)
    { printf("-"); 
    delay(10);}
    gotoxy(27,46);
     printf("xx-xx press esc to exit insertion mode xx-xx");
    gotoxy(4,18); 
    int f= 19; 
    fflush(stdin);
    char text[1800], c;
    for(i=0; c!= ESC; i++)
    {
        c= getch(); 
        int j=c;
        if(j== BKSP ) { 
            i-=2; printf("<-");
             continue; }
        if(j== ENTER) { 
            text[i]='\n'; 
            gotoxy(4,f);
             f++; 
             continue;}
        text[i]=c; 
        printf("%c",c);
    }
    text[i-1]='\0'; 
    f+=3;
    fflush(stdin); 
    gotoxy(4,f);
    for(int i=0; i<95; i++)
    { printf("-"); 
    delay(5);}
    gotoxy(25,f+2); 
    printf("f---||--||- press F1 to add timstamp -||-||-||---");
    gotoxy(28,f+4);  
      printf("---||--||- press F2 to add text -||-||-||---");
    gotoxy(29,f+6);   
      printf("---||--||- press F3 to go back -||-||-||---");
    gotoxy(30,f+8);   
       printf("---||--||- press ESC to exit -||-||-||---");
    fflush(stdin);
    gotoxy(4,f+10);
    for(int i=0; i<95; i++)
    { printf("-"); 
    delay(5);}
     printf("\n\n");
    while(1)
    {
        int k= getch();
        if     (k==F1)  { 
            notewrite_timestamp(1, f+12, 1, text);
             break;} ///        FUNCTION YET TO ADD
        else if(k==F2)  { 
            notewrite_timestamp(2, f+12, 1, text); 
            break;}    ///         FUNCTION YET TO ADD
        else if(k==F3)  { 
            notepadinput(uname); 
            break;}
        else if(k==ESC) { 
            escape();
             break;}
    }
}


/* NOTEPAD OVERWRITE MAIN FUNCTION */
void notewrite()
{
    system("cls"); gotoxy(14,4);
    printf("---^---x--^x^--- WELCOME %s , TO SECRET WORLD OF TEXT ---^x^--x---^---", uname);
    gotoxy(37,6); 
    printf("e x p l o r e . f r e e l y ");
    gotoxy(23,10); 
    printf(". . . . . . .  c r e a t e . w o r l d  . . . . . . . .");
    gotoxy(26,13);
    for(int i=0; i<23; i++)
    {
        printf("/");
         delay(10);
        printf("\\");
        delay(10);
    }
    gotoxy(34,15); 
    printf("PRESS ENTER TO OVERWRITE TEXT");
    gotoxy(30,17); 
    printf(">>>>>>  PRESS F1 TO GO BACK  <<<<<");
    gotoxy(28,19);
    printf(">>>>>>   PRESS F2 TO ADD TEXt   <<<<<");
    gotoxy(23,21);
    for(int i=0; i<26; i++)
    { printf("\\");
     delay(10); 
     printf("/"); 
      delay(10);}
    printf("\n\n");
    while(1)
    {
        int k= getch();
        if(k==ENTER)  {  
            enterhit_write(); 
            break;}
        else if(k==F1){ 
             notepadinput(uname);
              break;}
        else if(k==F2){ 
             noteadd(); 
             break; }
    }
}

