#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int i,j,staddr;
	char name[10],name1[10],line[50],staddr1[50];
	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%s",line);
	printf("Enter the name of the program :\n");
	scanf("%s",name);
	for(i=1,j=0;i<6;i++,j++)
	{
		name1[j]=line[i];
	}
	name1[j]='\0';
	printf("Program name from obj. file : %s\n",name1);
	if(strcmp(name,name1)==0)
	{
		do{
			fscanf(fp,"%s",line);
			if(line[0]=='T')
			{
				for(i=2,j=0;i<8;i++,j++){
					staddr1[j]=line[i];
				}
				staddr1[j]='\0';
				staddr=atoi(staddr1);
				i=12;
				while(line[i]!='\0')
				{
					if(line[i]!='^')
					{
						printf("00%d \t %c%c\n",staddr,line[i],line[i+1]);
						staddr++;
						i=i+2;
					}
					else
						i++;
				}
			
			}
			else if(line[0]=='E')
			{
				printf("Enter Execution address:");
				for(i=2;i<8;i++)
					printf("%c",line[i]);
				break;
			}
		}while(!feof(fp));
	}
	fclose(fp);
}			
