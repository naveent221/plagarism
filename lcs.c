#include <stdio.h>
#include <string.h>
#include <dirent.h>                     //including header files to the program
#include "commonstring.h"               //creating header file #include "commonstring.h"
int main(int argc, char const *argv[])  //main function
{
	char filestr[100][30];
	DIR *d;                           // directory traverse
	struct dirent *dir;
	//char path[100]=argv[1];
	printf("%s\n",argv[1]);
	d=opendir(argv[1]);                  //opening directory at current path
	int filescount=0;
	if (d)
	{
		while((dir=readdir(d))!=NULL)
		{
			int m=strlen(dir->d_name);            //calculating length of directory
			if (((int)dir->d_name[m-1])==116&&((int)dir->d_name[m-2])==120&&((int)dir->d_name[m-3])==116)
			{
				strcpy(filestr[filescount],dir->d_name);      //copying directory name to filestr 
				filescount++;                                    // incrementing filescount
			}
		}
	}
	printf("matrix");
	int i;
	for (i=0;i<filescount;i++)
	{
		printf("%15s",filestr[i]);
	}
	FILE *fp;                               // file pointer
	FILE *fp1;
	char a1;                             //declaring character a1
	char b1;
	for(int i1=0;i1<filescount;i1++)
	{
	    printf("\n%s ",filestr[i1]);
		char s1[1000];                  //declaring array s1
		char s2[1000];
	
		for(int j=0;j<filescount;j++)
		{
			fp=fopen(filestr[i1],"r");	        //opening and reading file
	        int i2=0;
	        a1=fgetc(fp);
            while (a1!=EOF)               //loop terminates when it reaches end of file
            {
	         	if(a1!='\n')
	         	{
	         	s1[i2]=a1;
	         	i2++;
	         	a1=fgetc(fp);               // getting the characters from file
	            }
	            else
	            {
	            	a1=' ';
	            }
          
            }
	         //printf("%s",s1);
	        s1[i2]='\0';
	        fclose(fp);                    // closed the file
		    fp1=fopen(filestr[j],"r");  //opened the second file  
			int j1=0;
			b1=fgetc(fp1);            // getting the characters from file
	        while (b1!=EOF)
	        {
	         	if(b1!='\n')
	         	{
	         	s2[j1]=b1;
	         	j1++;
	         	b1=fgetc(fp1);
	         	}
	         	else
	         	{
	         		b1=' ';
	         	}        
	        }
	         //printf("%s",s2);
	         s2[j1]='\0';
	         fclose(fp1);
		
			int s3=strlen(s1);                      // calculating the length of string s3
			int s4=strlen(s2);
			int denominator=s3+s4;                           // adding both the lengths
			int numerator=commonstring(s3,s4,s1,s2);         // function calling				
			// for(int i=0;i<max;i++)
			// {
			// 	printf("%c",max1[i]);
			// }
			int n=2;
			printf("%15.2f",(float)(numerator*200)/denominator);            // dividing both numerator and denominator
       }
    }
    printf("\n");
}
				
			     
     

				
	