#include <stdio.h>

int main(){
    int x1, x2, y1, y2, m, n, contin, contout, t, i;

    scanf("%d",&t);
    contin = contout = 0;
    for (i=0; i<t; i++){
        scanf("%d%d",&n,&m);
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        //printf("%d,%d,%d,%d,%d",n,m, x1, y1, x2, y2);



        if(y2-1>=1)contout++;

        if(y2+1<=m)contout++;

        if(x2-1>=1)contout++;

        if(x2+1<=n)contout++;

        if(y1-1>=1)contin++;

        if(y1+1<=m)contin++;

        if(x1-1>=1)contin++;

        if(x1+1<=n)contin++;

        //printf("%d,%d\n",contin,contout);

        if(contin<contout){
            printf("%d\n",contin);
        }
        else{
            printf("%d\n",contout);

        }
        contin=0;
        contout=0;
    }






}