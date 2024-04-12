#include <stdio.h>
#include <time.h>

int main() 
{
    time_t currentTime;
    // time_t to represent time
    // currentTime is the variable name
    //uses the term calendar time when referring to a value of type time_t.
    struct tm *localTime;
    // declaring pointer localTime to a structure of type tm
    // tm is used to contain year,month, day,hour,minute

    // Get the current time
    currentTime = time(NULL);
    //time(null) returns current calendar time
    //represents number of seconds elapsed since 00:00:00 on jan 1,1970

    // Convert the current time to local time
    localTime = localtime(&currentTime);
    //localtime() converts the calendar time (currentTime) into a structure representing local time. 
    //The localtime() function takes a pointer to time_t as an argument and returns a pointer to a statically allocated structure of type tm containing the local time representation
   
    // Print the current date and time
    printf("Current Date and Time: %s", asctime(localTime));
    //asctime() converts the structure localTime into a string in the format: Day Mon dd hh:mm:ss yyyy
    
    return 0;
}
