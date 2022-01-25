#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>
int main(int argc,char **argv) {
  char s2[20];
  unsigned char s[16];
  int i=0;
  strcpy(s2,"yzbqklnj");
  do {
    i++;
    sprintf(s2+8,"%d",i);
    MD5((unsigned char *)s2,strlen(s2),s);
  } while (*s || *(s+1) || (*(s+2) & 0xf0));  
  printf("5 zeros =%d\n",i);
  do {
    i++;
    sprintf(s2+8,"%d",i);
    MD5((unsigned char *)s2,strlen(s2),s);
  } while (*s || *(s+1) || (*(s+2)));  
  printf("6 zeros =%d\n",i);
}
