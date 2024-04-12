#include <stdio.h>
#define RESET  "\x1b[0m"
#define RED    "\x1b[31m"
#define GREEN  "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE  "\e[4;32m"
#define BOLDgreen "\e[1;32m"
#define  backpurple "\e[45m"
#define highintencyan "\e[0;96m"
int main()
 {
    printf(RED "This is red text\n" RESET);
    printf(GREEN "This is green text\n" RESET);
    printf(YELLOW "This is yellow text\n" RESET);
    printf(BLUE "This is blue text\n" RESET);
    printf(backpurple "HI \n" RESET );
    printf(BOLDgreen "hello \n" RESET);
    printf(highintencyan "pds coding \n" RESET);
    return 0;
}
