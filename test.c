/* ============================================================
   *File : test.c
   *Date : 2017-09-08
   *Creator : @congdv
   *Description : Do test driven
   ============================================================ */

/* TODOS:- Write test case
 *       - Write delete char*/
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
    const char *str = getStringPointer(alc);
    getStringLen(str);
    printf("%s\n",str);
    insertChar(alc,1,'b');
    achar *ac = getBucketAt(alc,1);
    write(STDOUT_FILENO,ac->bytes,ac->length);
    printf("Len %d\n",getLen(alc));
    const char *str2 = getStringPointer(alc);
    printf("%s\n",str2);
    deleteBucketAt(alc,0);
    printf("After delete: %s\n",getStringPointer(alc));
    freeChars(&alc);
    return 0;
}
