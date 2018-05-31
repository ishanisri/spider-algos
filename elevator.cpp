/*input n for number of floors, start for the start floor and then the floors to be visited*/
#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;
int n;
int start;
int main(){
	int a[100];
	int b[100];
	int c[100];
	int pos;
	int sum=0;
	cin>>n;
	cin>>start;
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-1);j++)
		if(a[j]>a[j+1])
		{
		    int tmp=a[j];
			a[j]=a[j+1];
			a[j+1]=tmp;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>start){
			pos=i;
			 break;
		}
	}
	cout<<start;
	cout<<" ";
	
	for(int i=pos;i<n;i++)
	{    
	    	c[i-pos]=a[i];
			cout<<a[i];
			cout<<" ";
		
	}
	for(int i=(pos-1);i>=0;i--)
	{   c[n-i-1]=a[i];
		cout<<a[i];
		cout<<" ";
	}
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			b[0]=abs(c[0]-start);
		}
		else
		b[i]=abs(c[i]-c[i-1]);		
	}
	for(int i=0;i<n;i++){
		cout<<" ";
		sum=sum+b[i];
	}
	cout<<"Total distance:";
	cout<<sum;
	
	 
	 
	
}
