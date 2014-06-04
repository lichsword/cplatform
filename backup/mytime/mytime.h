#ifndef _TIME_
#define _TIME_

// field index
const int ERA = 0;
const int YEAR = 1;
const int MONTH = 2;
const int WEEK_OF_YEAR = 3;
const int WEEK_OF_MONTH = 4;
const int DATE = 5;
const int DAY_OF_MONTH = 6;
const int DAY_OF_YEAR = 7;
const int DAY_OF_WEEK = 8;
const int DAY_OF_WEEK_IN_MONTH = 9;
const int AM_PM = 9;
const int HOUR = 10;
const int HOUR_OF_DAY = 11;
const int MINUTE = 12;
const int SECOND = 13;
const int MILLISECOND = 14;
const int ZONE_OFFSET = 15;
const int DST_OFFSET = 16;

// field count
const int FIELD_COUNT = 1;

struct Calendar{
    int fields[FIELD_COUNT];
};

void set(Calendar calendar, int field, int value);
void set(Calendar calendar, int year, int month, int day);
void set(Calendar calendar, int year, int month, int day, int hourOfDay, int minute, int second);
void computeFields(Calendar calendar);

#endif
