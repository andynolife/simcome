#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main() {
  time_t currentTime;
  struct tm *localTime;
  int current_hour;
  const char greetings[3[34] = {"Good Morning", "Good Evening", "Good Afternoon"};
  char greetings_time[24];
  greetings_time[0] = '\0';
  time(&currentTime);
  localTime = localtime(&currentTime);
  current_hour = localTime->tm_hour;
  if (current_hour >= 5 && current_hour < 12) {
    strcpy(greetings_time, greetings[0]);
  } else if (current_hour >= 12 && current_hour < 17) {
    strcpy(greetings_time, greetings[2]);
  } else {
    strcpy(greetings_time, greetings[1]);
  }

  int getlogin_r(char *buf, size_t bufsize);
  char username[256];
  if (getlogin_r(username, sizeof(username)) == 0) {
    printf("%s, %s!. Today Time and Date: %d-%02d-%d %02d:%02d:%02d\n", greetings_time, username, localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900, localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
  } else {
    printf("Can't get the username!\n");
  }
  return 0;
}
