#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  int children=3,cats=7,samoyeds=2,pomeranians=3,akitas=0,vizslas=0,goldfish=5,trees=3,cars=2,perfumes=1;
  int sue;
  f=fopen("d16a.txt","r");
  while (!feof(f)) {
    fgets(s,sizeof(s),f);
    if((s2=strchr(s,'\n')))*s2=0;
    sscanf(s,"Sue %d",&sue);
 #ifdef PARTB   
    if ((s2=strstr(s,"cats"))) if (atoi(s2+5)<=cats) continue;
    if ((s2=strstr(s,"pomeranians"))) if (atoi(s2+12)>=pomeranians) continue;
    if ((s2=strstr(s,"goldfish"))) if (atoi(s2+9)>=goldfish) continue;
    if ((s2=strstr(s,"trees"))) if (atoi(s2+6)<=trees) continue;
#else    
    if ((s2=strstr(s,"cats"))) if (atoi(s2+5)!=cats) continue;
    if ((s2=strstr(s,"pomeranians"))) if (atoi(s2+12)!=pomeranians) continue;
    if ((s2=strstr(s,"goldfish"))) if (atoi(s2+9)!=goldfish) continue;
    if ((s2=strstr(s,"trees"))) if (atoi(s2+6)!=trees) continue;
#endif
    if ((s2=strstr(s,"children"))) if (atoi(s2+9)!=children) continue;
    if ((s2=strstr(s,"samoyeds"))) if (atoi(s2+9)!=samoyeds) continue;
    if ((s2=strstr(s,"akitas"))) if (atoi(s2+7)!=akitas) continue;
    if ((s2=strstr(s,"vizslas"))) if (atoi(s2+8)!=vizslas) continue;
    if ((s2=strstr(s,"cars"))) if (atoi(s2+5)!=cars) continue;
    if ((s2=strstr(s,"perfumes"))) if (atoi(s2+5)!=perfumes) continue;
    printf("Send the thank you to Sue #%d\n",sue);
  }  
  fclose(f); 
}
