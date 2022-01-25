#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  int x,y,z,wrap=0,ribbon=0;
  f=fopen("d02a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n'))) *s2=0;
    sscanf(s,"%dx%dx%d",&x,&y,&z);
    wrap+=(x*y+x*z+y*z)*2;
    ribbon+=x*y*z;
    if (x>=y) {
      if (x>=z) {
        wrap+=y*z;
        ribbon+=2*(y+z);
      } else {
        wrap+=x*y;
        ribbon+=2*(x+y);
      }  
    } else {
      if (y>=z) {
        wrap+=x*z;
        ribbon+=2*(x+z);
      } else {
        wrap+=x*y;
        ribbon+=2*(x+y);
      }
    }    
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  printf("%d square feet needed\n",wrap);
  printf("%d feet ribbon needed\n",ribbon); 
}
