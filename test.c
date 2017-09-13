/* ============================================================
   *File : test.c
   *Date : 2017-09-08
   *Creator : @congdv
   *Description : Do test driven
   ============================================================ */
#include "unicode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    alchars alc = newChar();

    printf("\n");

    const char *s = "Xin chào thế giới";
    appendNewString(alc,s);
    appendNewString(alc,"");
    int len = getStringLen(s);
    printf("Len bytes: %d\n",len);
    printf("Len bytes: %d\n",getLen(alc));
    printf("%s\n",getStringPointer(alc));

    printf("The seventh char is:\n ");
    achar *c = getBucketAt(alc,6);
    write(STDOUT_FILENO,c->bytes,c->length);

    freeChars(&alc);
    return 0;
}
