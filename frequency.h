struct freq
{
	char *word;											//structure declaration for storing strings and integers
	int c;
};


int frequency_count(char *s1, struct freq p1[])			//function declared in header file
{	
	char *a[100];
	char *s=strtok(s1," ");						 						
	int len=0,c=1;
	while (s!=NULL)
	{
	a[len]=s;
	len++;
	s=strtok(NULL," ");									//used to tokenize each string from the array
	}
	int z=0;
	int z1=0;
	int k=0;
	for(int i=0;i<len;i++)
	{
		c=1;
		for(int j=i+1;j<len;j++)
		{
			if(strcmp(a[i],a[j])==0 && a[i] != "|") 	//compares each string
			{
              a[j]="|";
              c=c+1;
          	  p1[i].word=a[i];							//calculates frequency of each word
    		  p1[i].c=c;
    		  k=k+1;
    		  //printf("%s : %d\n",p1[i].word,p1[i].c);
    		 
			}
		}
			if(c==1 && a[i] != "|")
			{
			  p1[i].word=a[i];							//claculates frequency of each word
    		  p1[i].c=c;
    		  k=k+1;
    		  //printf("%s : %d\n",p1[i].word,p1[i].c);
			}		
	}
	return(k);											//returns frequency of each string to main function
}