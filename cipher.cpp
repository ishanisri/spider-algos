/*input n for number of test cases and k for key*/

#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;
int k;
string input[100];
string output[100];
int n;
int cap[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int small[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void encrypt(string *a)
{
  for(int j=0;j<n;j++){
		string message=a[j];
	
	string nmsg="";
	for(int i=0;i<message.length();i++){
		char c=message.at(i);
		
		
		if(islower(c))
		{int l;
			for( l=0;l<26;l++){
				if(small[l]==c){
					
					break;
				}
				
		   }
		   int newno=(l+k)%26;
			char p=small[newno];
			nmsg=nmsg+p;
			
			}else if(isupper(c))
			{int l;
				for( l=0;l<26;l++){
					if(cap[l]==c){
						
						break;
					}
				}
				int newno=(l+k)%26;
			    char p=cap[newno];
			    nmsg=nmsg+p;
			
				
				}else
				nmsg=nmsg+c;	
}
  output[j]=nmsg;
}
}

void decrypt(string *a)
{
  for(int j=n;j<(2*n);j++){
		string message=a[j];
	
	string nmsg="";
	for(int i=0;i<message.length();i++){
		char c=message.at(i);
		
		
		if(islower(c))
		{int l;
			for( l=0;l<26;l++){
				if(small[l]==c){
					
					break;
				}
				
		   }
		   int newno=(l-k)%26;
		   
		   if(newno<0)
		     newno=26+newno;
		    cout<<newno; 
		   
			char p=small[newno];
			nmsg=nmsg+p;
			
			}else if(isupper(c))
			{int l;
				for( l=0;l<26;l++){
					if(cap[l]==c){
						
						break;
					}
				}
				int newno=abs((l-k))%26;
			    char p=cap[newno];
			    nmsg=nmsg+p;
			
				
				}else
				nmsg=nmsg+c;	
}
  output[j]=nmsg;
}
}



int main(){
	
	
	cin>>n;
	cin>>k;
	for(int i=0;i<(2*n);i++)
	{
		cin>>input[i];
		
	}
	
	encrypt(input);
	
	for(int i=0;i<n;i++)
	{
		cout<<"ciphertext#";
		cout<<(i+1);
		cout<<":";
		cout<<output[i];
		cout<<"\n";
	}
	
	decrypt(input);
	for(int i=n;i<(n*2);i++){
		cout<<"plaintext#";
		cout<<(i-n+1);
		cout<<":";
		cout<<output[i];
		cout<<"\n";
	}
	return 0;
}

