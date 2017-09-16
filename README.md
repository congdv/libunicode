# Libunicode 
A library for support read and write utf-8 charset

# What 's inside?
I create a list memory like a list bucket, with a bucket will contain raw bytes for present a character. In bucket contains data and length of bytes of data.

```
+-------+--------+-----+ 
|0x64|1 |0xc3aa|2|.....|
+-------+--------+-----+
```

# Usage

```
alchar alc = newChar(); /*Initalize for store buckets*/

alchar alcnl = createNewChar('x'); /*Initalize for store buckets with first bucket*/

appendNewChar(alc,'x'); /* Add new character*/

appendNewString(alc,"in chào"); /*Add new string*/

printf("%s",getStringPointer(alc));/*Get string from all buckets to print*/

int getLen(alc); /* Get length of buckets */

int len = getStringLen("Xin Chào");/*Count number of character from string*/

insertChar(alc,0,'b'); /*Insert at 0 with char 'b'*/
achar *ac = getBucketAt(alc,0);  /* Get string value of bucket at index*/

deleteBucketAt(alc,0); /* Delete a bucket at index*/

freeChars(&alc); /*Free buckets*/
```

# Test

```
make

./test
```

Feel free to feed back on my project

