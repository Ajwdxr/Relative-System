#include<iostream>
#include <stdlib.h>
#include<string.h>
#include <string>
#include <cstring>
#include<iomanip>
#include<windows.h>
#include <vector>

using namespace std;

struct allSet
{
	int elementA[10];
	int elementB[10];
};

//properties for set ,reflexive,symmetric,transitive
allSet set;
allSet ref;
allSet sym;
allSet trans;

int reflective(int);
int symmetric(int);
int transitive(int);
int display (int,int,int);
void inputData();
void tryagain();

string ans;
int NumofSet,reflect,symmet,transi;

//Main section : Which the system will start from here.
int main()
{
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\tLoading..."<<endl;
	cout<<"\t\t\t\t";
	for(int i = 0;i<55;i++)
    {
        cout << "|";
        if(i<5)
        {Sleep(100);}
        else if(i<30)
        {Sleep(20);}
        Sleep(10);
    }
	
	
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t|------------------------------------------------------------------|"<<endl;
	cout<<"\t\t\t|                                                                  |"<<endl;
	cout<<"\t\t\t|                   Hello ! Welcome to Relation system             |"<<endl;
	cout<<"\t\t\t|                                                                  |"<<endl;
	cout<<"\t\t\t|------------------------------------------------------------------|"<<endl<<endl<<endl;
	
	inputData();
	return 0;
	
	
	
}


//Input Section : Input for set which based on input number of set.
void inputData()
{
	cout<<"-------------------------------------"<<endl;
	cout<<"Please enter the number of sets : ";
	cin>>NumofSet;
	cout<<"-------------------------------------"<<endl;
	cout<<endl<<endl;
	
	
	
	for(int i=0;i<NumofSet;i++)
	{
		
		cout<<"The number of subset "<<i+1<<endl;
		cout<<"-------------------------------------"<<endl;
		//input element A
		cout<<"Please insert value A : ";
		cin>>set.elementA[i];
		//input element B
		cout<<"Please insert value B : ";
		cin>>set.elementB[i];
		cout<<"-------------------------------------"<<endl;
		cout<<endl<<endl;
}
		
		cout<<"-------------------------------------------------------------------"<<endl;
		//Display the set
		cout<<"Set = {";
		for(int x=0;x<NumofSet;x++)
		{
			cout<<"{"<<set.elementA[x]<<","<<set.elementB[x]<<"}";
			if(x<NumofSet-1)
			{
				cout<<",";
			}
			
		}
		
		cout<<"}"<<endl;
		cout<<"-------------------------------------------------------------------"<<endl;
		
		
		//Number of set will pass to every function
		reflect = reflective(NumofSet);
		symmet = symmetric(NumofSet);
		transi = transitive(NumofSet);
		display(reflect,symmet,transi); 
		cout<<"-------------------------------------------------------------------"<<endl;
		tryagain();
		
		
	}
	
	//Reflexive funtion 
	int reflective(int NumofSet1)
	{
		int count=0;
		int c1=2,c2=2;
		int position=0;
		
		   //to check (a,a)(b,b) in the set and every different element must have 1 set which pair with their own number
		   for(int i=0;i<NumofSet1;i++)
		   {
		   	
		   	count=0;
		   	
		   	   for(int miaw=0;miaw<NumofSet1;miaw++)
		   	   {
		   	   	//comparing for each element
		   	   	  if(set.elementA[i]==set.elementA[miaw] && set.elementA[i] == set.elementB[miaw])
		   	   	     {
		   	   	     	count++;
					 }
		   	   	 	
			   }
			   
			   if(count<1)
			   {
			   	    c1=0;
			   	    
			   	    for(int w=0;w<10;w++)
			   	    {
			   	    	if(set.elementA[i]==ref.elementA[w])
			   	    	{
			   	    		c2++;
						}
				    }
				    if(c2!=0)
				    {
				    	ref.elementA[position]=set.elementA[i];
				    	ref.elementB[position]=set.elementA[i];
				    	position++;
					}
			   }
			   c2=2;
			   count=0;
			      for(int wow=0;wow<NumofSet1;wow++)
			      {
			      	
			      	if(set.elementB[i]==set.elementA[wow] && set.elementB[i]==set.elementB[wow])
			      	{
			      	    count++;	
					}
			      	
				  }
				if(count<1)
				{
					c1=0;
				    for(int y=0;y<10;y++)
				    {
				    	if(set.elementA[i]==ref.elementB[y] && set.elementB[i]==ref.elementB[y])
				    	  {
				    	  	c2=0;
						  }
					}
					if(c2!=0)
					{
						ref.elementA[position]=set.elementB[i];
						ref.elementB[position]=set.elementB[i];
						position++;
					}
				}
				c2=2;
		   	
		   	
		   }
		return c1;
		
	}
	
	
	//symmetric function
	int symmetric(int NumofSet2)
	{   //to check (a,b) (b,a) in set
		int count2,c1=2,c2=2,position1=0;
		
		for(int x=0;x<NumofSet2;x++)
		{
			count2=0;
			
			for(int y=0;y<NumofSet2;y++)
			{
				//to check either set A0 = b1 && b0 = A1
				if(set.elementB[x]==set.elementA[y] && set.elementA[x]==set.elementB[y])
				{
					count2++;
				}
			}
			if(count2<1)
			{
				c1=0;
				sym.elementA[position1]=set.elementB[x];
				sym.elementB[position1]=set.elementA[x];
				position1++;
			}
			
		}
		
		return c1;
		
	}
	
	
	//transitive function
	int transitive(int NumofSet3)
	{
		int c3=0,c4,cube=2,position2=0;
		//to check wether (a,b),(b,c),(a,c)
		for(int x=0;x<NumofSet3;x++)
		{
			c4=0;
			for(int y=0;y<NumofSet3;y++)
			{
				if(set.elementB[x]==set.elementA[y])
				{
					for(int v=0;v<NumofSet3;v++)
					{
						if(set.elementA[x]==set.elementA[v] && set.elementB[y]==set.elementB[v])
						{
							c4++;
						}
						else
						{
							c3++;
						}
					}
					if(c3!=NumofSet3-1)
					{
						c3=2;
						cube=0;
						for(int a=0;a<10;a++)
						{
							if(trans.elementA[a]==set.elementA[x] && trans.elementB[a]==set.elementB[y])
							{
								c3=0;
							}
						}
						if(c3!=0)
						{
							trans.elementA[position2]= set.elementA[x];
							trans.elementB[position2]= set.elementB[y];
							position2++;
						}
					}
					c3=0;
				}
			}
		}
		
		return cube;
	}
	
	//Display function : display all the properties are available and closure.
	int display(int r1,int r2,int r3)
	{
		
		if(r1==2 && r2==2 && r3==2)
		{
			cout<<"The set properties is REFLEXIVE, SYMMETRIC AND TRANSITIVE"<<endl<<endl;
		}
		else if(r1==2 && r2==2 && r3==0)
		{
			cout<<"The set properties is REFLEXIVE AND SYMMETRIC "<<endl<<endl;
			
			cout<< "Transitive Closure  =  {";
			for(int x=0;x<10;x++)
			 {
			 	if(trans.elementA[x]!=0 && trans.elementB[x]!=0)
			 	{
			 		cout<<"("<<trans.elementA[x]<<","<<trans.elementB[x]<<"}";
			 		if(trans.elementA[x+1]!=0 && trans.elementB[x+1]!=0)
			 		{
			 			cout<< ",";
					 }
				 }
			 }
			 cout<<"}"<<endl;
		}
		
		
		else if(r1==2 && r2==0 && r3 ==2)
		{
			cout<<"Set properties is REFLEXIVE AND TRANSITIVE"<<endl<<endl;
			
			cout<<"Symmetric Closure = { ";
			for(int x=0;x<10;x++)
			{
				if(sym.elementA[x]!=0 && sym.elementB[x]!=0)
				{
					cout<<"{"<<sym.elementA[x]<<","<<sym.elementB[x]<<"}";
					
					if(sym.elementA[x+1]!=0  && sym.elementB[x+1]!=0)
					{
						cout<<",";
					}
				}
			}
			
		  cout<<"}"<<endl;	
			
		}
		
		else if(r1==0 && r2==2 && r3==2)
		{
			cout<<"Set properties is SYMMETRIC AND TRANSITIVE"<<endl<<endl;
			cout<<"Reflective closure = {";
			for(int x=0;x<10;x++)
			{
				if(ref.elementA[x]!=0 && ref.elementB[x]!=0)
				{
					cout<< "{" << ref.elementA[x]<<","<<ref.elementB[x]<<"}";
					  if(ref.elementA[x+1]!=0 && ref.elementB[x+1]!=0)
					  {
					  	cout<<",";
					  }
				}
				
				
				
			}
			cout<<"}"<<endl;
		}
		
		else if(r1==2 && r2==0 && r3==0)
		{
			cout<<"Set properties is REFLETIVE"<<endl<<endl;
			cout<<"Symmetric Closuree = {";
			
			for(int x=0;x<10;x++)
			{
				if(sym.elementA[x]!=0 && sym.elementB[x]!=0)
				{
					cout<<"{"<<sym.elementA[x]<<","<<sym.elementB[x]<<"}";
					if(sym.elementA[x+1]!=0 && sym.elementB[x+1]!=0)
					{
						cout<<",";
					}
				}
			}
			cout<<"}"<<endl;
			
			cout<<"Transitive Closure = {";
			for(int x=0;x<10;x++)
			{
				if(trans.elementA[x]!=0 && trans.elementB[x]!=0)
				{
					cout<<"{"<<trans.elementA[x]<<","<<trans.elementB[x]<<"}";
					  if(trans.elementA[x+1]!=0 && trans.elementB[x+1]!=0)
					  {
					  	cout<<",";
					  }
				}
			}
			cout<<"}"<<endl;
		}
		
		else if(r1==0 && r2 ==2 && r3==0)
		{
			cout<<"Set properties is SYMMETRIC"<<endl<<endl;
			cout<<"Reflexive Closure =  {";
			for(int x=0;x<10;x++)
			{
				if(ref.elementA[x]!=0 && ref.elementB[x]!=0)
				{
					cout<<"{"<<ref.elementA[x]<<","<<ref.elementB[x]<<"}";
					if(ref.elementA[x+1]!=0 && ref.elementB[x+1]!=0)
					{
						cout<<",";
					}
				}
			}
			
			cout<<"}"<<endl;
			
				cout<<"Transitive Closure = {";
			for(int x=0;x<10;x++)
			{
				if(trans.elementA[x]!=0 && trans.elementB[x]!=0)
				{
					cout<<"{"<<trans.elementA[x]<<","<<trans.elementB[x]<<"}";
					  if(trans.elementA[x+1]!=0 && trans.elementB[x+1]!=0)
					  {
					  	cout<<",";
					  }
				}
			}
			cout<<"}"<<endl;
			
			
			
		}
		
		else if(r1==0 && r2==0 && r3 ==2)
		{
			cout<<"Set properties is Transitive"<<endl<<endl;
			
			cout<<"Reflexive Closure =  {";
			for(int x=0;x<10;x++)
			{
				if(ref.elementA[x]!=0 && ref.elementB[x]!=0)
				{
					cout<<"{"<<ref.elementA[x]<<","<<ref.elementB[x]<<"}";
					if(ref.elementA[x+1]!=0 && ref.elementB[x+1]!=0)
					{
						cout<<",";
					}
				}
			}
			
			cout<<"}"<<endl;
			
				cout<<"Symmetric Closure = {";
			
			for(int x=0;x<10;x++)
			{
				if(sym.elementA[x]!=0 && sym.elementB[x]!=0)
				{
					cout<<"{"<<sym.elementA[x]<<","<<sym.elementB[x]<<"}";
					if(sym.elementA[x+1]!=0 && sym.elementB[x+1]!=0)
					{
						cout<<",";
					}
				}
			}
			cout<<"}"<<endl;
			
			
			
		}
		
		else if(r1==0 && r2==0 && r3 ==0)
		{
			cout<<"Set doesn't have any properties "<<endl<<endl;
			
			cout<<"Reflexive Closure =  {";
			for(int x=0;x<10;x++)
			{
				if(ref.elementA[x]!=0 && ref.elementB[x]!=0)
				{
					cout<<"{"<<ref.elementA[x]<<","<<ref.elementB[x]<<"}";
					if(ref.elementA[x+1]!=0 && ref.elementB[x+1]!=0)
					{
						cout<<",";
					}
				}
			}
			
			cout<<"}"<<endl;
			
				cout<<"Symmetric Closuree = {";
			
			for(int x=0;x<10;x++)
			{
				if(sym.elementA[x]!=0 && sym.elementB[x]!=0)
				{
					cout<<"{"<<sym.elementA[x]<<","<<sym.elementB[x]<<"}";
					if(sym.elementA[x+1]!=0 && sym.elementB[x+1]!=0)
					{
						cout<<",";
					}
				}
			}
			cout<<"}"<<endl;
			
				cout<<"Transitive Closure = {";
			for(int x=0;x<10;x++)
			{
				if(trans.elementA[x]!=0 && trans.elementB[x]!=0)
				{
					cout<<"{"<<trans.elementA[x]<<","<<trans.elementB[x]<<"}";
					  if(trans.elementA[x+1]!=0 && trans.elementB[x+1]!=0)
					  {
					  	cout<<",";
					  }
				}
			}
			cout<<"}"<<endl;
			
		}
		
		
	}
	
	
	
	//Repeat function : either the customer want to input another set or not
	void tryagain()
	{   cout<<endl<<endl;
		cout<<"Do you want to continue (yes/no)"<<endl;
		cin>>ans;
		
		if(ans =="yes")
		{
			cout<<"-------------------------------------------------------"<<endl;
			inputData();
		}
		else
		{
			cout<<endl;
			cout<<"Thankyou please come again !"<<endl;
			cout<<endl;
			cout<<"---------------------------------------------------------"<<endl;
		}
	}
	
	
	
	
	
	
	
	
	

