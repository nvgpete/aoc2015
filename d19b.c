#include <stdio.h>
#include <string.h>
char ss[30][3];
int slast=1;
int parse(char **s) {
  int i;
  char *s2;
  s2=*s;
  ss[slast][0]=*(*s)++;
//  printf("%c%c %ld\n",ss[slast][0],*(s2+1),*s-s2);
//  printf("%c %ld\n",ss[slast][0],*s-s2);
  if (**s>='a') ss[slast][1]=*(*s)++;
   else ss[slast][1]=0;
  i=1; 
//  printf("%c %c\n",ss[slast][0],ss[i][0]);
  while (strcmp(ss[slast],ss[i])) i++;
  if (i==slast) slast++;
  return i;
}

char xchr(char c) {
  c+='0';
  if (c>'9') c+='a'-10-'0';
  return c;
}  

void pstr(char *s) {
  char c;
  while (c=*s++) printf("%c",xchr(c));
  printf("\n");
}
      
int main(int argc,char **argv) {
  FILE *f;
  char s[1000],*s2,*t,from[45],to[45][10],from2[20],to2[20][10],start[500],t1[10],t2[10];
  int last=0,last2,i,j,n,dups[20][20],add[20],cnt=0;
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
  fgets(s,sizeof(s),f);
  if((s2=strchr(s,'\n')))*s2=0;
  t=start;
  s2=s;
  while (*s2) *t++=parse(&s2);
  *t=0;  
  fclose(f);
  pstr(start);
  printf("strlen start=%lu\n",strlen(start)); // to see how long it is
  for (j=0;j<last;j++) add[from[j]]++;
  last2=0; j=0;
  for (n=0;n<last;n++) { // split rules into two sets
    if (strlen(to[n])==2) {
      if (n!=j) {
        from[j]=from[n];
        strcpy(to[j],to[n]);
      }
      j++;
    } else {
      for (i=1;i<slast-1;i++) { // bad rules tha create things not in result
        if (add[i]==0 && strchr(to[n],i)!=NULL && strchr(start,i)==NULL) break;
      }
      if (i==slast-1) { 
        from2[last2]=from[n];
        strcpy(to2[last2],to[n]);
        last2++;
      }
    }
  }
  last=j;            
  for (n=0;n<last;n++) {
    printf("%c => ",xchr(from[n]));
    pstr(to[n]);
  }
  for (n=0;n<last2;n++) {
    printf("%c => ",xchr(from2[n]));
    pstr(to2[n]);
  }
  s2=start;
  for (j=0;j<18;j++) printf("%d ",add[j]);printf("\n");
  for (j=0;j<17;j++) for (n=0;n<17;n++) if(dups[j][n]) printf("%c-%c ",xchr(j),xchr(n)); printf("\n");
}
