#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char c,s[100],*s2;
  int cnt1=0,cnt2=0,n,m=0;
  f=fopen("d08a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    cnt1+=strlen(s);
    n=0;
    m+=4;
    s2=s+1;
    while ((c=*s2++)) {
      if (c=='\\') {
        if(*s2=='x') {
          s2+=3;
          m++;
        } else if (*s2=='\\' || *s2=='"') {
          s2++;
          m+=2;
        }  
      }
      n++;
    }
    cnt2+=n-1;     
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  printf("Diff=%d\n",cnt1-cnt2); 
  printf("Part b=%d\n",m);
}
