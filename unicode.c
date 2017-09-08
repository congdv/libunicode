/* ============================================================
   *File : unicode.c
   *Date : 2017-09-07
   *Creator : @congdv
   *Description : Built library for support read and write
character
   Struct data like:
   [1]-[2]
    |   \
    V    >
    [0x41(a)][0x00EA(e^)]
    When read each element and write out screen
   ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct achar {
    char *bytes;
    int length;
} achar;

struct alchars {
    achar **chars;
    int length;
};

typedef struct abuf {
    char *s;
    int len;
} abuf;

#define DATABUFFER_INIT {NULL,0}

/*Encode Utf-8*/
achar *encode( unsigned codePoint) {
    achar *chars = malloc(sizeof(achar));

    if(codePoint < 0x80) {
        chars->bytes = malloc(sizeof(char));
        chars->length = 1;
        chars->bytes[0] = codePoint;
    } else if (codePoint <= 0x7FF) {
        char *buf = malloc(sizeof(char) * 2);
        buf[0] = ((codePoint >> 6) + 0xC0);
        buf[1] = ((codePoint & 0x3F) + 0x80);
        chars->bytes = buf;
        chars->length = 2;
    } else if (codePoint <= 0xFFFF) {
        char *buf = malloc(sizeof(char) * 3);
        buf[0] = ((codePoint >> 12) + 0xE0);
        buf[1] = (((codePoint >> 6) &0x3F) +0x80);
        buf[2] = ((codePoint & 0x3F) + 0x80);
        chars->bytes = buf;
        chars->length = 3;
    } else if(codePoint <= 0x10FFFF) {
        char *buf = malloc(sizeof(char) * 4);
        buf[0] = ((codePoint >> 18) + 0xF0);
        buf[1] = (((codePoint >> 12) & 0x3F) + 0x80);
        buf[2] = (((codePoint >> 6) & 0x3F) + 0x80);
        buf[3] = ((codePoint & 0x3F) + 0x80);
        chars->bytes = buf;
        chars->length = 4;
    } else {
        fprintf(stderr,"Error");
    }
    return chars;
}

void appendAChar(struct alchars *alc,unsigned c){
    achar **newAlloc = realloc(alc->chars, (alc->length + 1)*sizeof(achar *));
    if(newAlloc == NULL)
       return;

    newAlloc[alc->length] = encode(c);
    alc->length++;
    alc->chars = newAlloc;
}

void abAppend(abuf *ab, char *s, int len) {
    char *new = realloc(ab->s,ab->len + len);
    if(new == NULL)
        return;
    memcpy(&new[ab->len],s,len);
    ab->s = new;
    ab->len += len;
}

void convertToAbbuf(struct alchars *alc, abuf *ab) {
    achar ** chars = alc->chars;
    for(int i = 0; i < alc->length; i++) {
        abAppend(ab,chars[i]->bytes,chars[i]->length);
    }
}

int main() {
    struct alchars alc = DATABUFFER_INIT;
    for(int i = 0; i < 100; i++) {
        appendAChar(&alc,'a');
        appendAChar(&alc,0x00EA);
        appendAChar(&alc,0x00EA);
    }

    abuf ab = DATABUFFER_INIT;
    convertToAbbuf(&alc,&ab);
    write(STDOUT_FILENO,ab.s,ab.len);
    return 0;
}
