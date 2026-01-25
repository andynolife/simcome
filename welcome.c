#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main() {
  
  /* Get Current Time */
  time_t currentTime;
  struct tm *localTime;
  int current_hour;

  /* Get Greeting */
  const char *greetings[] = {"Good Morning", "Good Evening", "Good Afternoon"};

  char *greetings_output;
  greetings_output = malloc(24 * sizeof(char));
  greetings_output[0] = '\0';

  time(&currentTime);
  localTime = localtime(&currentTime);
  current_hour = localTime->tm_hour;

  /* Process for getting right grettings */
  if (current_hour >= 5 && current_hour < 12) {
    strcpy(greetings_output, greetings[0]);
  } else if (current_hour >= 12 && current_hour < 17) {
    strcpy(greetings_output, greetings[2]);
  } else {
    strcpy(greetings_output, greetings[1]);
  }

  /* Get username */
  int getlogin_r(char *buf, size_t bufsize);
  char username[256];

  /* Print out! */
  if (getlogin_r(username, sizeof(username)) == 0) {
    printf("%s, %s!. Today Time and Date: %d-%02d-%d %02d:%02d:%02d\n", greetings_output, username, localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900, localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
  } else {
    printf("Can't get the username!\n");
  }
  
  return EXIT_SUCCESS;
}
