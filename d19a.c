#include <stdio.h>
#include <string.h>
char ss[30][3];
int slast=1;
int parse(char **s) {
  int i;
  ss[slast][0]=*(*s)++;
  if (**s>='a') ss[slast][1]=*(*s)++;
   else ss[slast][1]=0;
  i=1; 
  while (strcmp(ss[slast],ss[i])) i++;
  if (i==slast) slast++;
  return i;
}
      
int main(int argc,char **argv) {
  FILE *f;
  char s[1000],*s2,*t,from[45],to[45][10],start[500],t1[10],t2[10];
  int last=0,j,n,dups[20][20],add[20],cnt=0;
  memset(ss,0,sizeof(ss));
  memset(dups,0,sizeof(dups));
  memset(add,0,sizeof(add));
  f=fopen("d19a.txt","r");
  do {
    fgets(s,sizeof(s),f);
    if((s2=strchr(s,'\n')))*s2=0;
    if (!*s) break;
    s2=s;
    from[last]=parse(&s2);
    s2+=4;
    t=to[last];
    while (*s2) *t++=parse(&s2);
    *t=0;
    last++;  
  } while (1);
  last-=3; //skip last 3 for part a
  fgets(s,sizeof(s),f);
  if((s2=strchr(s,'\n')))*s2=0;
  t=start;
  s2=s;
  while (*s2) *t++=parse(&s2);
  *t=0;  
  fclose(f);
  for (j=0;j<last;j++) {
    add[(int)from[j]]++;
    for (n=0;n<last;n++) {
      if (strlen(to[j])!=strlen(to[n])) continue;
      t1[0]=from[j]; strcpy(t1+1,to[n]);
      s2=stpcpy(t2,to[j]); *s2=from[n]; *(s2+1)=0;
      if (strcmp(t1,t2)==0) dups[(int)from[j]][(int)from[n]]=1;
    }
  }     
  s2=start;
  do {    
    cnt+=add[(int)*s2]-dups[(int)*s2][(int)*(s2+1)];
    s2++;
  } while (*s2);
  printf("%d new found\n",cnt);  
}
