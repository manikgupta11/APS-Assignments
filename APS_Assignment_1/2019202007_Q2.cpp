#include<bits/stdc++.h>
#include "deque.h"
using namespace std;


int main()
{
	Deque dq(1,1);


	dq.push_front(1);

	dq.push_back(4);
	dq.push_front(2);
	dq.pop_back();
	dq.push_front(3);
	dq.push_back(5);
	dq.push_front(3);
	dq.pop_front();
	// cout<<dq.D(2);

	dq.printq();
	return 0;
}