#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  int boxes[30],wgt=0,last=0;
  int i1,i2,i3,i4,i5,i6,w;
  unsigned long qe,minqe=999999999999;
  f=fopen("d24a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    sscanf(s,"%d",boxes+last);
    wgt+=boxes[last];
    last++;
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  wgt/=3;
  w=0;
  for (i1=0;i1<last-5;i1++) {
    w=boxes[i1];
    for (i2=i1+1;i2<last-4;i2++) {
      w+=boxes[i2];
      for (i3=i2+1;i3<last-3;i3++) {
        w+=boxes[i3];
        for (i4=i3+1;i4<last-2;i4++) {
          w+=boxes[i4];
          for (i5=i4+1;i5<last-1;i5++) {
            w+=boxes[i5];
            for (i6=i5+1;i6<last;i6++) {
              if (boxes[i6]+w==wgt) {
                qe=(long)boxes[i1]*boxes[i2]*boxes[i3]*boxes[i4]*boxes[i5]*boxes[i6];
                if (qe<minqe) minqe=qe;
              }
            }
            w-=boxes[i5];
          }
          w-=boxes[i4];
        }
        w-=boxes[i3];
      }
      w-=boxes[i2];
    }
  }
  printf("Minimum QE=%lu\n",minqe);              
}
