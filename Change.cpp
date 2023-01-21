#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
void display(int arr[],int i,int P);
void decimal_binary(int num)
{
	int i=0,arr[15],rem;
	do
	{
		rem=num%2;
		num=num/2;
		arr[i++]=rem;
	}while(num>0);
	display(arr,i,2);
}

void decimal_octal(int num)
{
	int i=0,arr[15],rem;
	do
	{
		rem=num%8;
		num=num/8;
		arr[i++]=rem;
	}while(num>0);
	display(arr,i,8);
}

void decimal_hexa(int num)
{
	int i=0,arr[15],rem;
	do
	{
		rem=num%16;
		num=num/16;
		arr[i++]=rem;
	}while(num>0);
	display(arr,i,16);
}

void point(float a,int op)
{ int Op=op,arr[5],i=0;float v;
     v=a-(int)a;
     if(v==0) return;
    do
    {v=v*Op;
      arr[i++]=(int)v;
      v-=(int)v;
    }while(i<5);
    cout<<"•";
     for(int j=0;j<i;j++)
	cout<<arr[j];
}

void display(int arr[],int i,int P)
{
	int j;
   if(P==2)
	 {cout<<"\n binary of no. is : ";
     for(j=i-1;j>=0;j--)
 	cout<<arr[j];}
   else
	    if(P==8)
	    {cout<<"\n octal of no. is : ";
	     for(j=i-1;j>=0;j--)
	      cout<<arr[j];}
	    else 
	         if(P==16)
	            {cout<<"\n hexadecimal of no. is : ";
	            for(j=i-1;j>=0;j--)
	            if(arr[j]>=10)
            	cout<<(char)(arr[j]-10+65);
            	else
            	cout<<arr[j];
	            }
}

double binary_decimal()
{
	char a[20]; int p,len1,len2;
	long double num=0;
	cout<<"\n Enter a binary no. : ";
	cin>>a;
	for(p=0;a[p]!='.';p++);
    len1=strlen(a);
    if(p<25)
    len2=p;
    else
    len2=len1;
    //cout<<"\t"<<p;
    //cout<<"\t"<<len1;
	for(int i=len2-1,j=1; i>=0; i--,j*=2)
	{
	//	cout<<"\t"<<a[i]<<"\t j="<<j;
	//	cout<<"\n\t"<<(int)(a[i]*j);
		num+=a[i]*j-(48*j);
		//num=num+a[i]*j;
	}
	double S,s=.5;
	if(p<25)
	{
	for(int i=len2+1;i<len1;i++,s/=2)
	{
	     //cout<<"\n\t s= "<<s;
		S+=a[i]*s-(48*s);
		//cout<<"\t\t"<<S;
	}
	}
	//cout<<"\n decimal of no. is : "<<num;
	//cout<<"\n decimal of no. is : "<<num<<"•"<<S;
	num=num+S;	
	cout<<"\n decimal of no. is : "<<num;
	return num;
		
}

int octal_decimal()
{
	char a[20]; int p,len1,len2;
	long double num=0;
	cout<<"\n Enter a octal no. : ";
	cin>>a;
	for(p=0;a[p]!='.';p++);
    len1=strlen(a);
    if(p<25)
    len2=p;
    else
    len2=len1;
	for(int i=len2-1,j=1; i>=0; i--,j*=8)
	{
		num+=a[i]*j-(48*j);
	}
	double S,s=.125;
	if(p<25)
	{
	for(int i=len2+1;i<len1;i++,s/=8)
	{
		S+=a[i]*s-(48*s);
	}
	}
	cout<<"\n decimal of no. is : "<<num;
	
	cout<<"\n decimal of no. is : "<<num<<"•"<<S;
	num=num+S;	
	cout<<"\n decimal of no. is : "<<num;
	return num;
}

int main()
{
	int op1,po2;long double a,b;
	cout<<"\n Select conversion type from ,"
	      "\n  1 for binary to .....??"
          "\n  2 for octal to.......?? "
          "\n  3 for decimal to......?? "
          "\n  4 for hexadecimal to.......??  :: ";
     cin>>op1;
     if(op1!=1 and op1!=2)
    { cout<<"\n enter a no : ";
	cin>>a;
	b=a;}	
	switch(op1)
	{
	    case 1:b=binary_decimal();
	               decimal_octal(b);point(b,8);
	               decimal_hexa(b); point(b,16);
	                    break;
        case 2:octal_decimal();
             break;
        case 3:decimal_binary(a); point(b,2);
                   decimal_octal(a); point(b,8);
                   decimal_hexa(a); point(b,16);
                          break;
         case 4:
              break;
         default: cout<<"\n you are trying "
                        "invalid operation!!!!!!!!!";
	}
	
}
