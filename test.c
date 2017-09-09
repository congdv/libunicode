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

int main() {
    alchars alc = newChar();

    printf("\n");

    const char *s = "Xin chào thế giới";
    appendNewString(alc,s);
    int len = getStringLen(s);
    printf("Len bytes: %d\n",len);
    printf("Len bytes: %d\n",getLen(alc));
    printf("%s\n",getStringPointer(alc));

    freeChars(&alc);
    return 0;
}
