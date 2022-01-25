#include <stdio.h>
#include <string.h>
  char c,s[5000000],s2[5000000],*ss,*ss2;
int main(int argc,char **argv) {
  int k,n;
  
  strcpy(s,"3113322113");
  ss=s;
  while (*ss) *ss++-='0'; 
  for (k=0;k<50;k++) {
    ss=s;
    ss2=s2;
    while ((c=*ss++)) {
      n=1;
      while (c==*ss) {n++; ss++;}
      *ss2=n;
      *(ss2+1)=c;
      ss2+=2;
    }
    *ss2=0;
    strcpy(s,s2);
    if (k==40) printf("Length after 40 = %ld\n",strlen(s)); 
  }
  printf("Length after 50 = %ld\n",strlen(s));
}
