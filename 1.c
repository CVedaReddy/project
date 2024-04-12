#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<termios.h>
#include<unistd.h>

#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define ESC 27
#define ENTER 13
#define BKSP 8

#define FUNCTION       int passwordsecure(char pswd[])
#define DECLARATION    int a=0, A=0, num=0, spe=0;
#define LOOP           for(int i=0; i<strlen(pswd); i++)
#define LENGTH         if(strlen(pswd)<7)  return 2;
#define SMALL          if(pswd[i]>='a' && pswd[i]<='z') a=1;
#define LARGE          else if(pswd[i]>='A' && pswd[i]<='Z') A=1;
#define NUMBER         else if(pswd[i]>='0' && pswd[i]<='9')  num=1;
#define SEP_CHAR       else if( (pswd[i]>='!' && pswd[i]<='/') || pswd[i]=='@' || pswd[i] == '_') spe=1;
#define INVALIDCHAR    else if( (pswd[i]>=':' && pswd[i]<='?') || (pswd[i]>='[' && pswd[i]<='`') || (pswd[i]>='{' && pswd[i]<='~') ) return 3;
#define STRENGTH       if(a==1 && A==1 && num==1 && spe==1) return 1;
#define INLOOP         { SMALL LARGE NUMBER SEP_CHAR INVALIDCHAR }
#define RETURN         return 2;
#define SPE_CHAR       (( (uname[i]>='!' && uname[i]<='/') || uname[i]=='@' || uname[i]==' ')
#define INVALID_CHAR   ( (uname[i]>=':' && uname[i]<='?') || (uname[i]>='[' && uname[i]<='`') || (uname[i]>='{' && uname[i]<='~') ) )

int i;
char pswd[100]; // Specify the size of the array
struct { char name[20]; char pswd[20]; } user;
struct { char name[20]; char pswd[20]; } use;
FILE *fptr;
char uname[30];

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void delay(int ms) {
    usleep(ms * 1000);
}

int logprompt() {
    int n;
    printf("---- xx ------- xx ------- S e C u R e . N o T e P a D ------- xx -------- xx ----\n");
    delay(3000);
    gotoxy(18, 10);
    printf("=============================================================================\n");
    delay(2000);
    gotoxy(38, 13);
    printf("** PRESS F1 TO LOGIN **\n");
    delay(2000);
    gotoxy(36, 15);
    printf("** PRESS F2 TO REGISTER **\n");
    delay(2000);
    gotoxy(35, 17);
    printf("** PRESS F3 TO SEE ABOUT **\n");
    delay(2000);
    gotoxy(37, 19);
    printf("** PRESS ESC TO EXIT **\n");
    delay(2000);
    gotoxy(25, 21);
    printf("---------------*-*-**-**-**-**-*-*-------------\n\n\n");
    delay(2000);
    gotoxy(18, 24);
    printf("=============================================================================\n\n\n");
    delay(2000);
    n = getchar();
    return n;
}

void escape() {
    system("clear");
    printf("=======================================================\n");
    printf("!!!!!!!! -x-x-x-x- NoTePaD CloSeD -x-x-x-x-  !!!!!!!!\n\n\n");
    printf("=======================================================\n\n\n");
    exit(1);
}

void about() {
    system("clear");
    printf("\n\n\n\n");
    printf(" ================  *   ===  *  === * S E C U R E . N O T E P A D * ===  *  ===  * ==================== \n\n\n");
    printf("     ============================================================================================\n\n");
    printf("    ABOUT PROJECT :\n\n");
    printf("    A BRIEF OVERVIEW OF 'Secure Notepad'  \n");
    printf("    PROJECT by Veda,Varshitha and Mohitha, 1st year UG   \n\n");
    printf("    This Project is  coded in C Language using concepts like: FILE HANDLING , FUNCTION, POINTERS, HEADER FILE, TIME ");
    delay(3000);
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
    delay(3000);
    printf("    It also provides many other functionalities like \n");
    printf("    i)   securepassword() : IT CHECKS WEATHER PASSWORD ENTERED IS STRONG OR NOT \n");
    printf("    ii)  timestamp()      : IT STORES THE TIMING WHEN DATA IS ENTERED \n");
    printf("    iii) username_valid() : ALLOWS ONLY VALID USERNAME WITHOUT ANY SPECIAL CHAR OTHER THAN  ' _ ' \n");
    printf("    iv)  userchk()        : IT MAKES SURE THAT ONLY UNIQUE USERNAME EXISTS. IF USERNAME EXITS ALREADY \n");
    printf("                            IT DISALLOWS TO MAKE CHANGES AND ASK TO LOGIN \n");
    printf("    v)   inputuser()      : Stores userdata credentials to a file \n\n");
    delay(3000);
    printf("    ================================================================================================= \n\n\n\n");
    printf("** PRESS ESC TO GO BACK ** \n\n\n");
    printf("    ================================================================================================= \n\n\n\n");
    while(1) {
        int k = getchar();
        if (k == 27)
            main();
    }
}

int main() {
    system("clear");
    int n;
    while(1) {
        n = logprompt();
        switch(n) {
            case F1:
                // Implement login functionality
                break;
            case F2:
                // Implement user registration functionality
                break;
            case F3:
                about();
                break;
            case ESC:
                escape();
        }
        system("clear");
    }
    return 0;
}
