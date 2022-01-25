#include <stdio.h>
#include <string.h>
void inc(char *s,int i) {
  char c;
  c=++(*(s+i));
  if (c>'z') {
    *(s+i)='a';
    if (i!=0) inc(s,i-1);
  }
  if (c=='i' || c=='l' || c=='o') (*(s+i))++;
}    
int main(int argc,char **argv) {
  char s[100],ok;
  int i,n;
  strcpy(s,"vzbxkghb");
  for (n=0;n<2;n++) {
    ok=0; 
    while (!ok) {
      inc(s,7);
      ok=(s[0]==s[1]-1)&&(s[1]==s[2]-1);
      ok=ok||((s[1]==s[2]-1)&&(s[2]==s[3]-1));
      ok=ok||((s[2]==s[3]-1)&&(s[3]==s[4]-1));
      ok=ok||((s[3]==s[4]-1)&&(s[4]==s[5]-1));
      ok=ok||((s[4]==s[5]-1)&&(s[5]==s[6]-1));
      ok=ok||((s[5]==s[6]-1)&&(s[6]==s[7]-1));
      if (ok) {
        for (i=0; i<7; i++) {
          if (s[i]==s[i+1]) {
            ok++;
            i++;
          }
        }
      }
      ok=(ok>=3);      
    }
    printf("New password %d=%s\n",n+1,s);
  }  
}
