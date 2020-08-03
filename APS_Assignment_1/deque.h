#include<bits/stdc++.h> 
using namespace std; 

class Deque {
	int capacity; 
	int *arr;
	int Front,rear,Size; 

	public: 
    Deque(){  
		capacity=1;
		Front=-1; 
		rear=0; 
		this->Size=0; 
		arr=(int *)malloc(sizeof(int)*capacity);
    } 

    Deque( int n, int x) { 
		Front=0; 
		rear=n-1; 
		this->Size=n; 
		capacity=n;
		arr=(int *)malloc(sizeof(int)*capacity);
		for(int i=0;i<n;i++){
			arr[i]=x;
		}
    }


    bool full(){
		//   if(Front ==-1&&rear==0) return 1;
		// return (Front == (rear+1)%Size); 
		return Size==capacity;
    } 

    bool empty(){
      //return (Front == -1);
      return Size==0; 
    }

    int front() { 
    	if (empty()) { 
        	cout << " Underflow\n" << endl; 
        	return -1 ; 
      	} 
      	return arr[Front]; 
    }  

    int  back(){ 
    	if(empty()) { 
        	cout << " Underflow\n" << endl; 
        	return -1 ; 
    	} 
     	return arr[rear]; 
    } 

    int size() {
    	return Size;
    }

    void reSize(){ 
	    int *q=(int*)malloc(capacity*sizeof(int));
	    
	    for(int i=Front;i<Front+Size;i++){
	        q[i-Front]=arr[i%Size];
	    }
		free(arr);
		Front=0; rear=capacity-1;

		arr=(int*)malloc((capacity*2)*sizeof(int));
		copy(q,q+capacity,arr);
		capacity=capacity*2;
		free(q);
    }

    void reSize(int x){ 
      
		int *q=(int*)malloc(Size*sizeof(int));
		for(int i=Front;i<Front+Size;i++){
			q[i-Front]=arr[i%Size];
		}

		free(arr);
		capacity=x;

		if(x<Size){
			Size=x;
		}
		Front=0; rear=Size-1;
		arr=(int*)malloc(capacity*sizeof(int));
		copy(q,q+Size,arr);
		free(q);
    }
    void push_front(int key) { 
		if (full()) { 
			reSize();    
		} 

		if (Front == -1) { 
			Front = 0; 
			rear = 0; 
		} 
		else{
			Front=(Front+capacity-1)%capacity;
		}
		arr[Front] = key ; 
		Size++;
      
    }

    void push_back(int key) { 
		if (full()) { 
			reSize();
		} 

		if (Front == -1) { 
			Front = 0; 
			rear = 0; 
		} 
		else{  
			rear = (rear+1)%capacity; 
		}
		arr[rear] = key ; 
		Size++;
    }
    
    void pop_front() { 
		if(empty()) { 
			cout << "Queue Underflow\n" << endl; 
			return ; 
		} 

		if(Front == rear) { 
			Front = -1; 
			rear = -1; 
		} 
		else{
			Front =(Front+1)%capacity;
		}
		Size--;
    } 

    void pop_back() { 
		if (empty()) { 
			cout << " Underflow\n" << endl ; 
			return ; 
		} 
		if (Front == rear) { 
			Front = -1; 
			rear = -1; 
		} 
		else{
			rear = (rear-1+capacity)%capacity;
		}
		Size--; 
	}

    void clear(){
		free(arr);
		Size=0;
		rear=-1;
		Front=0;
    }

    int D(int n){
    	return arr[(Front+n-1)%capacity];
    }

    void printq(){
    	for(int i=Front;i<Front+Size;i++){
    		cout<<arr[i%capacity]<<" ";}
      	cout<<endl;
    }  
};
