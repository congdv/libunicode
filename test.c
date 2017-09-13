/* ============================================================
   *File : test.c
   *Date : 2017-09-08
   *Creator : @congdv
   *Description : Do test driven
   ============================================================ */

/* TODOS:- Write test case
 *       - Check dupplicate string*/
#include "unicode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    alchars alc = newChar();
    const char *s = "Xin chào thế giới";
    appendNewString(alc,s);
    printf("Len %d\n",getLen(alc));
    printf("%s\n",getStringPointer(alc));
    insertChar(alc,1,'b');
    achar *ac = getBucketAt(alc,1);
    write(STDOUT_FILENO,ac->bytes,ac->length);
    printf("Len %d\n",getLen(alc));
    printf("%s\n",getStringPointer(alc));
    freeChars(&alc);
    return 0;
}
