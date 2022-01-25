#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  int i=0,j,k,n,scap,sdur,sfla,stex,best=0,best2=0;
  int cap[4],dur[4],fla[4],tex[4],cal[4];
  f=fopen("d15a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    s2=strchr(s,':');
    sscanf(s2,": capacity %d, durability %d, flavor %d, texture %d, calories %d",cap+i,dur+i,fla+i,tex+i,cal+i);
    i++;
    fgets(s,sizeof(s),f);
  }
  fclose(f);
  for (i=0;i<97;i++) {
    for (j=0;j<98-i;j++) {
      for (k=0; k<99-j-i; k++) {
        n=100-i-j-k;
        if ((scap=i*cap[0]+j*cap[1]+k*cap[2]+n*cap[3])<=0) continue;
        if ((sdur=i*dur[0]+j*dur[1]+k*dur[2]+n*dur[3])<=0) continue;
        if ((sfla=i*fla[0]+j*fla[1]+k*fla[2]+n*fla[3])<=0) continue;
        if ((stex=i*tex[0]+j*tex[1]+k*tex[2]+n*tex[3])<=0) continue;
        if (scap*sdur*sfla*stex>best) best=scap*sdur*sfla*stex;
        if (i*cal[0]+j*cal[1]+k*cal[2]+n*cal[3]!=500) continue;
        if (scap*sdur*sfla*stex>best2) best2=scap*sdur*sfla*stex;
      }
    }
  }
  printf("Best=%d\n",best);
  printf("Best 500 calorie=%d\n",best2);          
}
