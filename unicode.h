/* ============================================================
   *File : unicode.h
   *Date : 2017-09-08
   *Creator : @congdv
   *Description : Header file
   ============================================================ */
#ifndef UNICODE_H
#define UNICODE_H

typedef struct achar achar;
typedef struct alchars *alchars; // Definition to itselft

alchars newChar();
/* Create new char*/
alchars createNewChar(unsigned c);
/* Add new char*/
void appendNewChar(alchars alc,unsigned c);
/* Add new string */
void appendNewString(alchars alc,const char *s);

/* Free chars*/
void freeChars(alchars *alc);

/* Get string */
const char *getStringPointer(alchars alc);

/* Get string length*/
int getStringLen(const char *s);

/* Get length buckets*/
int getLen(alchars alc);

#endif // End UNICODE_H
