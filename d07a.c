#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ndx(char *s) {
  if (strlen(s)==1) return *s-'a';
  return (*s-'a'+1)*26+*(s+1)-'a';
}  
int main(int argc,char **argv) {
  FILE *f;
  unsigned short v[350];
  char s[100],*s1,*s2,*s3,*s4,*s5,ops[350];
  int k,n,parta,dst,src1[350],src2[350];
  memset(ops,0,sizeof(ops));
  f=fopen("d07a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    s1=strtok(s," ");
    s2=strtok(NULL," ");
    s3=strtok(NULL," ");
    if ((s4=strtok(NULL," "))==NULL) dst=ndx(s3);
    else {
      if ((s5=strtok(NULL," "))) dst=ndx(s5); else dst=ndx(s4);
    }
    if (strcmp(s1,"NOT")==0) ops[dst]='~';
     else if (*s1>='0' && *s1<='9') src1[dst]=-atoi(s1);
     else src1[dst]=ndx(s1);
    if (strcmp(s2,"AND")==0) ops[dst]='&';
     else if (strcmp(s2,"OR")==0) ops[dst]='|';
     else if (strcmp(s2,"LSHIFT")==0) ops[dst]='<';
     else if (strcmp(s2,"RSHIFT")==0) ops[dst]='>';
     else if (strcmp(s2,"->")==0) ops[dst]='=';
     else src1[dst]=ndx(s2);
    if (strcmp(s3,"->")) {
      if ((k=atoi(s3))) src2[dst]=-k;
       else src2[dst]=ndx(s3);
    }     
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  for (n=0; n<2; n++) {
    k=1;
    while (ops[k]) {
      switch (ops[k]) {
        case '=': v[k]=-src1[k];
                  break;
        case '~': v[k]=~v[src1[k]];
                  break;
        case '&': if (src1[k]>=0) v[k]=v[src1[k]] & v[src2[k]];
                  else v[k]=-src1[k] & v[src2[k]];
                  break;                    
        case '|': v[k]=v[src1[k]] | v[src2[k]];
                  break;                    
        case '<': v[k]=v[src1[k]] << -src2[k];
                break;            
        case '>': v[k]=v[src1[k]] >> -src2[k];
      }
      k++;
    }
    v[0]=v[src1[0]];
    if (n==0) { 
      parta=v[0];
      src1[1]=-v[0];
    }  
  }
  printf("part a - a=%d\n",parta);   
  printf("part b - a=%d\n",v[0]);   
}
