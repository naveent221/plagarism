int commonstring(int s3,int s4,char s1[],char s2[])      //prototype declaration for function commonstring
{
	int max=0;
	char max1[1000];	
	for(int i=0;i<s3;i++)
	{
		int a[1000];             //initialized integer array
		int k=0;
		for(int j=0;j<s4;j++)
		{
			if(s1[i]==s2[j])            //comparing strings
			{
				a[k]=j;          //inserting indexes into array 
				k=k+1;
			}
		}
		for(int p=0;p<k;p++)             
		{
			int m1=a[p];
	 	    int y=0;
	 	    int z=0;
	 	    char a1[1000];            //declared character array
	 	    while(i+y<=s3-1 && m1+y<=s4-1 && s1[i+y]==s2[m1+y])    
	 	    {
               a1[z]=s2[m1+y];           //assigning common strings to a1 array
               z++;
               y++;
	 	    }
	 	    a1[z]='\0';               
	 	    if(strlen(a1)>max)                   //comparing max with a1 length
	 	    {
	 	    	max=(strlen(a1));          // assign maximum value to max
	 	    	for(int i=0;i<max;i++)
	 	    	{
	 	    		max1[i]=a1[i];               //assign longest string to max1
	 	    	}
	 	    }

		}
	
	}
	return (max);                //returning maximum value

}