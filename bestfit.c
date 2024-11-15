#include<stdio.h>
struct process
{
        int size;
        int allocated;
};
void main()
{
        int nb,np,best;
        printf("enter the no of memeory locations:\n");
        scanf("%d",&nb);
        int block[nb];
        printf("enter the size of memory locations:\n");
        for(int i=0;i<nb;i++)
        {
                scanf("%d",&block[i]);
        }
        printf("enter the no of process:\n");
        scanf("%d",&np);
        struct process pro[np];
        printf("enter the size of each process:\n");
        for(int i=0;i<np;i++)
        {
                scanf("%d",&pro[i].size);
                pro[i].allocated=-1;
        }
        for(int i=0;i<np;i++)
        {
                best=-1;
                for(int j=0;j<nb;j++)
                {
                        if(pro[i].size<=block[j])
                        {
                                if(best==-1)
                                {
                                        best=j;
                                }
                        else if(block[j]<block[best])
                        {
                                best=j;
                        }
                        }
                }
        if(best!=-1)
        {
                pro[i].allocated=block[best];
                block[best]=block[best]-pro[i].size;
        }
}
        printf("Sl.no\tprocess\tallocated\n");
         for(int i=0;i<np;i++)
        {
                if(pro[i].allocated!=-1)
                {
                         printf("%d\t%d\t%d\n",i+1,pro[i].size,pro[i].allocated);
                }
                else
                {
                        printf("%d\t%d\tnot allocated\n",i+1,pro[i].size);
                }
        }
         printf("\n");
}



