#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>										//including header files to the program
#include <math.h>
#include <dirent.h>
#include "frequency.h"									//creating header file #include "frequency.h"

int frequency_count(char *s1, struct freq p1[]);		//prototype declaration for function frequency
int power(int d,struct freq p1[])
{
	int z4=0;
	for(int x=0;x<d;x++)
	{
		
		z4=z4+pow((p1[x].c),2);
	}
	//printf("%d",z);
	return z4;
}
int main()												//main function
{	
    char filestr[100][30];
	DIR *d;
	struct dirent *dir;
	d=opendir(".");										//opens the directory
	int filescount=0;								
	if (d)
	{
		while((dir=readdir(d))!=NULL)
		{
			int m=strlen(dir->d_name);
			if (((int)dir->d_name[m-1])==116&&((int)dir->d_name[m-2])==120&&((int)dir->d_name[m-3])==116)
			{
				strcpy(filestr[filescount],dir->d_name);	//copies the file name
				filescount++;								//to calculates the number of files
			}
		}
	}
	printf("matrix   ");
	int i;
	for (i=0;i<filescount;i++)
	{
		printf("%15s",filestr[i]);            			//prints file names in a row
	}	

	FILE *fp;											//creating file pointer
	FILE *fp1;
	
	
	char w1[1000];
	char w2[1000];
	for(int i=0;i<filescount;i++)
	{
		char a;
	    printf("\n%s",filestr[i]);						//prints file names in a column
		int j;
	
		for(j=0;j<filescount;j++)
		{
	
		fp=fopen(filestr[i],"r");						//opens the file to read
		int k1=0;
		a=fgetc(fp);									//takes each character from the file pointer
        while (a!=EOF)									//checks the file until the end of file
         {
         	if(a!='\n')
         	{
         	w1[k1]=a;									//stores each character in an array
         	k1++;
         	a=fgetc(fp);
            }
            else
            {
            	a=' ';
            }
          
         }
        //printf("%s",w2);
         w1[k1]='\0';
        //printf("%s",w1);
         fclose(fp);
    fp1=fopen(filestr[j],"r");							//opens the file to read
	int k=0;
	char b;
	b=fgetc(fp1);
      while (b!=EOF)									//checks the file until the end of file
         {
         	if(b!='\n')
         	{
         	w2[k]=b;									//stores each string in an array
         	k++;
         	b=fgetc(fp1);								//reads each character from file
         	}
         	else
         	{
         		b=' ';
         	}        
         }
         //printf("%s",w2);
         w2[k]='\0';
         fclose(fp1);									//closes the file
     struct freq p1[100];								//creating an empty array for storing frequency
     struct freq p2[100];
	
	int d = frequency_count(w1,p1);						//Calls the function frequency_count which is in header file #include "frequency.h"
	int e = frequency_count(w2,p2);
	int m1=power(d,p1);
    int m2=power(e,p2);
	

	float denominator = sqrt(m1)*sqrt(m2);					//calculates the denominator
	//printf("%.2f",denominator);
	int numerator=0;
	for(int x=0;x<d;x++)
	{
		for(int y=0;y<e;y++)
		{
			if(strcmp(p1[x].word,p2[y].word)==0)
			{
				numerator = numerator+((p1[x].c)*(p2[y].c));//calculates the dot product for numerator
			}

		}
	}
	//printf("%d",numerator);
	printf("\t\t %.2f",(numerator/denominator)*100);		//prints the output in matrix form 
}
}
}