
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
int main()
{
// implementing Seive of Eratosthenes
  int primes[101]; //Declaring an array of 100 elements
  primes[0]=0;     // The primes contain 1 in their array element and the rest 0
  primes[1]=0;
  for(int i=2;i<101;i++)
  primes[i]=1;     //initializing all numbers as primes
  for (int i=2;i<101;i++)
  {
          for (int j=2; i*j<=100;j++)
          
              primes[i*j]=0; //cancelling out the multiples of primes
          

  }
  
  //Printing them in a 10*10 array
  
  
  cout<<"Primes:"<<endl;
 int a[10][10];
 for(int i=0;i<10;i++)
 {
     cout<<endl;
     for(int j=0;j<10;j++)
     {
         if(primes[i*10+j+1]==1)
         {
             a[i][j]= i*10+j+1;
             cout<<a[i][j]<<" ";
         }
         else
         {
         cout<<".  ";
         }
     }
}
cout<<endl<<endl;

//Goldbach's conjecture

cout<<"Test of Goldbach's Conjecture:"<<endl<<endl;
int temp1;

for( int k=4;k<=100;k=k+2) //checking for all even numbers from 4-100
{
    cout<<k<<":";
    for(int prime=2;prime<=k/2;prime++)
    {
        if(primes[prime]==1)  //if a prime is found,  
        {
            temp1=prime; 
        
        if(primes[k-prime]==1) //subtract from the even number check the other prime which makes the sum
            {
                cout<<" \t"<<prime<<" \t"<<k-prime<<endl; //Print the sum
            }
    
        
        }
    }
    cout<<endl;
}
}

