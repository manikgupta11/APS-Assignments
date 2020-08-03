#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; 
	cin>>n;
	//int n=5;
	//string s="manik";
	string s; 
	cin.ignore();  //ignore cz string is read from newline
	getline(cin,s);

	s=s.append(s);  //append to handle rotation
	map<string,int>suffixarray;  //suffixarray stores (suffix,index)
	string arr[n];
	
	for(int i=0;i<n;i++)
	{   string ss=s.substr(i);  //creating suffixes
		suffixarray[ss]=i;       //insert into map
		arr[i]=ss; 
	}
	
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++)
	{
		//cout<<suffixarray[arr[i]]<<" "<<arr[i]<<endl;
		if(arr[i].size()>=n) {
			cout<<arr[i].substr(0,n)<<endl;    
			break;
				}
		//break;
	}
	
	//cout<<arr[0].substr(n+1);
	
	return 0;
}