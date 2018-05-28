//Implementation of hungarian method.
#include<iostream>
#include<vector>
using namespace std;
int min(int a, int b, int c);
int min2(int a, int b);
int main()
{
  int k,b1=0;
  int jh=0;
  int fg=0;
  int jt=0;
  int u;
  int sum=0;
  int zero=0;
  int zero1=0;
  int cv=0;
  int t=0;
  vector <int> narr;
  int i,j;
  int length=0;
  int y=0;
  int s[3]={-1,-1,-1};
  int x[3]={-1,-1,-1};
  int z=0;
  int index[3][3]={{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
  int q=10;
  int arr[3][3]={{2500,4000,3500},{4000,6000,3500},{2000,4000,2500}};

  int arr1[3][3]={{2500,4000,3500},{4000,6000,3500},{2000,4000,2500}};
  for(int i=0;i<3;i++)
  {
  	k=min(arr[i][0], arr[i][1], arr[i][2]);

  	for(int j=0;j<3;j++)
  	{
  		arr[i][j]-=k;
  	}

  }
  for(j=0;j<3;j++)
  {
  	k=min(arr[0][j], arr[1][j], arr[2][j]);
  	for(i=0;i<3;i++)
  	{
  		arr[i][j]-=k;

  	}
  }

  for(i=0;i<3;i++)
  {

  	for(j=0;j<3;j++)
  	{
  		if(arr[i][j]==0)
  		{
  			zero1++;
  		}
  	}

  	for(j=0;j<3;j++)
	  {
  		if(arr[i][j]==0)
  		{
  		  if(zero1>1)
			{
				break;
			}
		  else
		    {
	         s[y]=j;
	         index[i][j]=arr[i][j];
	         y++;

		    }
  		  q=i;
  		}
  	  }
		zero1=0;
  }

  for(j=0;j<3;j++)
  {

  }
  for(j=0;j<3;j++)
  {
  	 	for(i=0;i<3;i++)
  	{
  		if(arr[i][j]==0)
  		{
  			zero++;
  		}
  	}
  	for(i=0;i<3;i++)
	  { int flag=0;
  		if(arr[i][j]==0)
  		{
  		  if(zero>1)
			{
				break;
			}
		  for(int m=0;m<3;m++)
		  {
		  	if(s[m]==j)
		  	{
		  	 flag=1;
		  	 cv=0;
		  	 break;
		  	}
		  	else{cv=1;}
		  	}

		  if(flag==1){
		  	break;
		  }

		  if(cv==1)
		    {
	         x[z]=i;
	         index[i][j]=arr[i][j];
	         z++;

		    }
  		  q=j;}
  		}
  		zero=0;
  	  }

  for(i=0;i<3;i++)
  {
  	if(s[i]!=-1)
  	{
  		length++;
  	}
  	if(x[i]!=-1)
  	{
  		length++;
  	}
  }
  if(length==3)
  {
  	cout<<"Output is";
  	for(i=0;i<3;i++)
  	{
  		for(int j=0;j<3;j++)
  		{
  			if(index[i][j]==0){
  				sum+=arr1[i][j];
  				cout<<arr1[i][j]<<"\t";

  			}
  		}
  	}cout<<"\nSum is "<<sum;
  }
  /*second it*/while(length!=3){
  	for(i=0;i<3;i++)
  	{
      for(j=0;j<3;j++)
      {
        for(int p;p<3;p++){
    			if(x[p]==i or s[p]==j){
    				b1=1;
            break;
    			}
          else{
            b1=0;
          }
      }
      if(b1==1){
        narr.push_back(arr[i][j]);
 			  t++;
      }
  		/*for(int p;p<3;p++){
  			if(x[p]==i){
  				b1=1;
          break;
  			}
        else{
          b1=0;
        }
  		}
  		for(j=0;j<3;j++)
  		{
  		for(int p;p<3;p++){
  			if(s[p]==j){
  				b2=1;
          break;
  			}
        else{
          b2=0;
        }
      }*/


  	}
  }
  int jh;
  if(narr.size()==1){
  int fg=narr[0];
}
  if(narr.size()==2){
  int fg=min2(narr[0],narr[1]);
}
if(narr.size()==3){
int fg=min(narr[0],narr[1], narr[2]);
}
if(narr.size()==4){
int fg1=min(narr[0],narr[1], narr[2]);
int fg=min2(fg1,narr[3]);
}
if(narr.size()==5){
int fg1=min(narr[0],narr[1], narr[2]);
int fg2=min2(narr[3], narr[4]);
int fg=min2(fg1,fg2);
}
if(narr.size()==6){
int fg1=min(narr[0],narr[1], narr[2]);
int fg2=min(narr[3], narr[4],narr[5]);
int fg=min2(fg1,fg2);
}
//same as earlier.Repeating the above steps.
  for(i=0;i<3;i++){
  	for(j=0;j<3;j++){
  	  if(j==x[i])
  	  {
  	  	jh=1;
  	  	break;
  	  }
  	  else{
  	  	jh=0;
  	  }
  }
  if(jh==1){
  	break;
  }
  for(int u=0;u<3;u++){
  	  		arr[i][u]-=fg;
  	  	}




}
 for(i=0;i<3;i++){
  	for(j=0;j<3;j++){
  	  if(j==s[i])
  	  {
  	  	jt=1;
  	  	break;
  	  }
  	  else{
  	  	jt=0;
  	  }
  }
  if(jt==0){
  	break;
  }
  for(int u=0;u<3;u++){
  	  		arr[u][i]+=fg;
  	  	}




}
}
for(int i=0;i<3;i++)
  {
  	k=min(arr[i][0], arr[i][1], arr[i][2]);

  	for(int j=0;j<3;j++)
  	{
  		arr[i][j]-=k;
  	}

  }
  for(j=0;j<3;j++)
  {
  	k=min(arr[0][j], arr[1][j], arr[2][j]);
  	for(i=0;i<3;i++)
  	{
  		arr[i][j]-=k;

  	}
  }

  for(i=0;i<3;i++)
  {

  	for(j=0;j<3;j++)
  	{
  		if(arr[i][j]==0)
  		{
  			zero1++;
  		}
  	}

  	for(j=0;j<3;j++)
	  {
  		if(arr[i][j]==0)
  		{
  		  if(zero1>1)
			{
				break;
			}
		  else
		    {
	         s[y]=j;
	         index[i][j]=arr[i][j];
	         y++;

		    }
  		  q=i;
  		}
  	  }
		zero1=0;
  }

  for(j=0;j<3;j++)
  {

  }
  for(j=0;j<3;j++)
  {
  	 	for(i=0;i<3;i++)
  	{
  		if(arr[i][j]==0)
  		{
  			zero++;
  		}
  	}
  	for(i=0;i<3;i++)
	  { int flag=0;
  		if(arr[i][j]==0)
  		{
  		  if(zero>1)
			{
				break;
			}
		  for(int m=0;m<3;m++)
		  {
		  	if(s[m]==j)
		  	{
		  	 flag=1;
		  	 cv=0;
		  	 break;
		  	}
		  	else{cv=1;}
		  	}

		  if(flag==1){
		  	break;
		  }

		  if(cv==1)
		    {
	         x[z]=i;
	         index[i][j]=arr[i][j];
	         z++;

		    }
  		  q=j;}
  		}
  		zero=0;
  	  }

  for(i=0;i<3;i++)
  {
  	if(s[i]!=-1)
  	{
  		length++;
  	}
  	if(x[i]!=-1)
  	{
  		length++;
  	}
  }
  if(length==3)
  {
  	cout<<"Output is";
  	for(i=0;i<3;i++)
  	{
  		for(int j=0;j<3;j++)
  		{
  			if(index[i][j]==0){

  				cout<<arr1[i][j]<<"\t";

  			}
  		}
  	}cout<<"\n Sum is "<<sum;
  }
}



int min(int a, int b, int c)
{
	int l;
	if(a>b)
	{
		if(b>c)
		{
			l=c;
		}
		else{
			l=b;
		}
	}
	else{
	  	if(a>c)
		{
			l=c;
		}
		else{
			l=a;
		}
	}
	return l;
}



int min2(int a, int b)
{
  int l;
  if(a>b)
  {
    l=b;
  }
  else{
    l=a;
  }
  return l;
}
