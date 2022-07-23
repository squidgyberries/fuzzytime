#include <stdio.h>
#include <string.h>
#include <time.h>

// clang-format off
const char *hourwords[] = {
  "Twelve", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven"
};
const char *minutewords[] = {
  "O'Clock", "Oh One", "Oh Two", "Oh Three", "Oh Four", "Oh Five", "Oh Six", "Oh Seven", "Oh Eight", "Oh Nine",
  "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
  "Twenty", "Twenty One", "Twenty Two", "Twenty Three", "Twenty Four", "Twenty Five", "Twenty Six", "Twenty Seven", "Twenty Eight", "Twenty Nine",
  "Thirty", "Thirty One", "Thirty Two", "Thirty Three", "Thirty Four", "Thirty Five", "Thirty Six", "Thirty Seven", "Thirty Eight", "Thirty Nine",
  "Forty", "Forty One", "Forty Two", "Forty Three", "Forty Four", "Forty Five", "Forty Six", "Forty Seven", "Forty Eight", "Forty Nine",
  "Fifty", "Fifty One", "Fifty Two", "Fifty Three", "Fifty Four", "Fifty Five", "Fifty Six", "Fifty Seven", "Fifty Eight", "Fifty Nine"
};
// clang-format on

int main(int argc, char **argv) {
  time_t timeraw = time(NULL);
  struct tm *timestruct = localtime(&timeraw);
  int hours = timestruct->tm_hour % 12;
  char *format = "%s %s\n";
  if (argc > 1) {
    format = argv[1];
  }
  printf(format, hourwords[hours], minutewords[timestruct->tm_min]);
  return 0;
}