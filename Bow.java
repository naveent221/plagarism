import java.util.*;
import java.io.*;
interface words
{
	public int frequencies(String[] s3);
}
class Bagofwords implements words
{
	HashMap<String,Integer> h=new HashMap<String,Integer>();
	public int frequencies(String[] s3)            //passing string array as parameter
	{
      for(String s:s3)                       //taking each string in string array
	  {
	  	if(h.containsKey(s))           //checing whether the hashmap contains string or not
	  	{
	  		h.put(s,h.get(s)+1);          //if contains,increment it by 1
	  	}
	  	else
	  	{
	  		h.put(s,1);                        // if not, assign it with 1
	  	}
	  }
	  //System.out.println(h);
	  int z=0;
	  for(Map.Entry<String,Integer> m:h.entrySet())    //entry set is used to set view of key value pairs
	  {
	  	String key=m.getKey();         //assign keys to key
	  	int value=m.getValue();          //assign values to value
	  	z=z+(int)(Math.pow(value,2));        //square all the values and sum it
	  }
	  return z;
	}
}
class Bow
{
		public static String Fileread(String s)throws FileNotFoundException
		{
		int c=0;
		File  file = new File(s);
		String s1="";
		try                                // To catch error we use try catch method
		{
			Scanner sc= new Scanner(file);
		    while(sc.hasNextLine())
		    {
		      s1+=sc.nextLine();
		      s1=s1.replace("\n"," "); // To read n lines in the given file
		      c=c+1;
		    }
		    sc.close();
		}
		catch(Exception e)
		{
		    e.printStackTrace(); // it prints the error
		}

		return s1;
        }
	public static void main(String[] args)  throws FileNotFoundException
	{
		File folder=new File(args[0]);// Craeting folder to file path 
		int filescount=0;

		File[] listoffiles=folder.listFiles();  //Creating a listoffile array and copy files
												// it from folder
		File[] file_name=new File[listoffiles.length];//Creating a String array
		for (int i=0;i<listoffiles.length ;++i )
		 {                                   // and entering the files in it
			File file=listoffiles[i];
			if(file.getName().endsWith(".txt"))
			{                                     // condition to have only .txt files
				file_name[filescount]=file;
				filescount++;
			}	
		}
		if(filescount==0)
		{
			System.out.println("empty directory");    //if there are no files print empty directory
		}

		for (int i=0;i<filescount;++i )
		 {
			System.out.print("	 "+file_name[i].getName());	// For Matrix printing in columns
		}
		System.out.println("\n");

		
		for (int i1=0;i1<filescount;++i1 ) 
		{
			System.out.print(file_name[i1].getName());         //for matrix printing in rows
			for (int j1=0;j1<filescount;++j1) 
			{
			  Bagofwords b=new Bagofwords();       // Creating object for class
			  Bagofwords b1=new Bagofwords();
			  String s1=Fileread(file_name[i1].getName());    //reading the file and assigning it to string 1
			  String s2=Fileread(file_name[j1].getName());
			  String[] s3=s1.split(" ");                 //spliting the string and assigning it to an string array
			  String[] s4=s2.split(" ");
			  int denominator1=b.frequencies(s3);       //frequencies functions returns the sum of the squares of frequencies in string1     
			  int denominator2=b1.frequencies(s4);
			  int numerator=0;
			  for(String i: b.h.keySet())
			  {
		        for(String j: b1.h.keySet())
		        {
			       if(i.equals(j))        //check if both the keys are equal
			       {
		                numerator=numerator+(b.h.get(i)*b1.h.get(j)); //if equal, multiply their values
			       }
			     }
			   }
			   double result=numerator/(Math.sqrt(denominator1)*Math.sqrt(denominator2)); //calculate the percentage
			   System.out.printf("\t"+"%.2f",result*100);    
	        }
	        System.out.println();
        }
}
}