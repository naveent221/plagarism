import java.util.*;
import java.io.*;
interface longeststring
{
  public String Char(String s);
  public int commonstring(String s1,String s2);
}
class ValidInputs implements longeststring
{                            //class to take only lowercase characters and spaces
		public String Char(String s){
			String st="";                    // empty string
			for (int i=0;i<s.length();i++ ) {
				if(95<=s.charAt(i) && s.charAt(i)<=122 || s.charAt(i)==32){            
					st=st+s.charAt(i);                               // appending lowercases to string st
				}
			}
			return st;                            //returning string
		}

		public int commonstring(String s1,String s2){        //func'n to compare two strings
			int lcs=0;
			for (int i=0;i<s1.length();i++ ) {
				for (int j=0;j<s2.length() ;j++ ) {
					String st="";
					int y=0;
					while(i+y<s1.length() && j+y<s2.length() && s1.charAt(i+y)==s2.charAt(j+y))
					{                            //incrementing by y and checking the characters or equal not
						st=st+s1.charAt(i);     // appending the characters if they are same
						y++;
					}
					if(st.length()>lcs)         //compare the lengths with lcs               
					{
						lcs=st.length();           //assign the maximum value to lcs
					}	
				}
			}
			return lcs;                   //returning maxm length
		}
}
class lcs
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
		 {    // and entering the files in it
			File file=listoffiles[i];
			if(file.getName().endsWith(".txt"))
			{ // condition to have only .txt files
				file_name[filescount]=file;
				filescount++;
			}	
		}
		if(filescount==0)
		{
			System.out.println(" empty directory");  //if there are no files, print it 
		}

		for (int i=0;i<filescount;++i )
		 {
			System.out.print("	 "+file_name[i].getName());	// For Matrix printing in columns
		}
		System.out.println("\n");

		
		for (int i=0;i<filescount;++i ) 
		{
			System.out.print(file_name[i].getName());            //For matrix printing in row
			for (int j=0;j<filescount;++j) 
			{
				if(i==j)
				{
					System.out.printf("\t"+"%.2f",100.00);
				}
				else
				{
				ValidInputs l=new ValidInputs();
				String s3=Fileread(file_name[i].getName());        //calling the function fileopen and assigning it to string
				String s4=Fileread(file_name[j].getName());
				String s1=l.Char(s3);           //calling the function char and removing special characters
				String s2=l.Char(s4);
				int denominator1=s1.length();                 
				int denominator2=s2.length();
				int denominator=denominator1+denominator2;
				int numerator=l.commonstring(s1,s2);   //function to find out the maximum length of the common string
				if(numerator*2==denominator)
			    System.out.printf("\t"+"%.2f",100.00);
				else
				System.out.printf("\t"+"%.2f",(float)(numerator*200)/denominator);
			  
			} 
			}                          //calculating the percentage
			System.out.println();
		}	
	}	
}
