/*input n for no. of floors,start for starting floor,sp for number of people who enter at the starting floor, cap for capacity of lift, then the floor no with no people going inside and no of people coming outside*/
#include <iostream>
#include<cstdlib>

using namespace std;
int n;
int start;
int cap;
int main(){
	
	int a[100];
	int b[100];
	int c[100];
	int in[100];
	int out[100];
	bool check[100];

	int pos,sp;
	int sum=0;
	cin>>n;
	cin>>sp;
	cin>>start;
	cin>>cap;
	
	
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>in[i];
		cin>>out[i];
		check[i]=false;
		
	}
	    
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-1);j++)
		if(a[j]>a[j+1])
		{
		    int tmp1=a[j];
			a[j]=a[j+1];
			a[j+1]=tmp1;
			
			int tmp2=in[j];
			in[j]=in[j+1];
			in[j+1]=tmp2;
			
			int tmp3=out[j];
			out[j]=out[j+1];
			out[j+1]=tmp3;
			
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
	
	
    
	int count=0;
	bool flag=false;
	while(flag==false)
	{
	for(int i=pos;i<n;i++)
	{ if(check[i]==false){
	
	
	   if(sp+in[i]-out[i]<=cap)
	    {       check[i]=true;
	            sp=sp+in[i]-out[i];
				c[count]=a[i];
			cout<<a[i];
			cout<<" ";
			count++;
	
		}else
		check[i]=false;
			
		
	}}
	for(int i=(pos-1);i>=0;i--)
	{
	if(check[i]==false){
	if(sp+in[i]-out[i]<=cap) 
	{ sp=sp+in[i]-out[i];
	 c[count]=a[i];
		cout<<a[i];
		cout<<" ";
		check[i]=true;
		count++;
	}else
	check[i]=false;
	}
}
	
	if (count==n)
	flag=true;
	
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
