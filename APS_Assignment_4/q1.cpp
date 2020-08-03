#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high);
int ksmall(int arr[], int low, int high, int k);

int ksmall(int arr[], int low, int high, int k){
	
	if(k>0 && k<high-low+2){
    
		int index = partition(arr,low,high);
		//cout<<index<<" "<<low<<" "<<high;
			if(index == low+k-1){
				return arr[index];
			}
			else if(index > low+k-1){
				return ksmall(arr, low, index-1, k);
			}
			else{
				//return ksmall(arr, index+1, high, k);
				return ksmall(arr, index+1, high, k-index-1+low);
			}
		}
		else return INT_MAX;
}


int partition(int arr[], int low, int high){

int mod=high-low+1;
int random_index=low+rand()%mod;
int temp;
temp=arr[high];
arr[high]=arr[random_index];
arr[random_index]=temp;

int pivot=arr[high]; 
int i=low-1;
for(int j=low;j<high;j++){
	
	if(arr[j]<=pivot){

		i++;
		//swap(arr[i],arr[j])
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}
    //swap(arr[i+1],arr[high])
	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return i+1;
	//cout<<i+1<<" ";

} 


int main(){
//Initializ array size and k  
int size=1000000; int k=1345;
int arr[size];

//Initialize array
for(int i=0;i<size;i++){
	arr[i]=rand()%size;
}

clock_t start, end;
double total;

//Time for my fn 
start = clock(); 
cout<<"Answer: "<<ksmall(arr,0,size-1,k)<<endl;

end = clock(); 
total = double(end - start) / double(CLOCKS_PER_SEC); 
cout<<"Time elapsed: "<< 1000*total<<" ms " << endl<<endl;

//Time for stl fn
// start = clock();
// nth_element(arr,arr+k-1,arr+size);
// cout<<"Answer using STL nth_element function: "<<arr[k-1]<<endl;

// end = clock(); 
// total = double(end - start) / double(CLOCKS_PER_SEC); 
// cout<<"Time elapsed using STL nth_element function: "<< 1000*total<<" ms " << endl;

return 0;
}