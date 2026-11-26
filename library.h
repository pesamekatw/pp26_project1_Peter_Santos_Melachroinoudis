#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ctype.h>

#define SIZE_FOR_STRINGS 100

typedef struct Student {
    unsigned int id;
    char name[SIZE_FOR_STRINGS];
    char surname[SIZE_FOR_STRINGS];
    unsigned int year;
} student_t;

typedef struct Course {
    unsigned int id;
    char title[SIZE_FOR_STRINGS];
    char description[SIZE_FOR_STRINGS];
    bool semester; // winterSemester = true, summerSemester = false
} course_t;

typedef struct Score {
    unsigned int *student_id;
    unsigned int *course_id;
    unsigned int grade;
} score_t;