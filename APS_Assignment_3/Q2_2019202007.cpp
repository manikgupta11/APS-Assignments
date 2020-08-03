#include<bits/stdc++.h> 
#define ll long long
using namespace std; 
  
class trNode 
{   public:
    trNode* left; 
    trNode* right;
    bool isLeaf;

    trNode(){ 
    this->isLeaf = false; 
    this->left = NULL; 
    this->right = NULL;
    } 
}; 
  
void insert(trNode* root, ll x) 
{ 
    trNode* current=root; 
  
    for (ll i=31; i>=0; i--)  //taking 31 cz integer is 32 bits 
    { 
        ll rightshiftx = x>>i;
        ll bit = 1&rightshiftx;   //bit is 0 if ith bit of x is 0 and vice versa
       
       if(bit==0)
       {  
          //If bit is 0, insert new node in left. Ignore if already present
          if(current->left==NULL)
          {
            current->left=new trNode();
            current=current->left;
          }
          else
          {
            current=current->left;
          }
       }

       else
       {
          //If bit is 1, insert new node in right. Ignore if already present
          if(current->right==NULL)
          {
            current->right=new trNode();
            current=current->right;
          }
          else
          {
            current=current->right;
          }
       }

    } 
    current->isLeaf=true; 
} 
  
 
ll max_xor(trNode *root, ll x) 
{ 
    ll max=0; 
    trNode* current=root; 
  
  
    for(ll i=31; i>= 0; i--) 
    { 
       ll rightshiftx = x>>i;
       ll bit = 1&rightshiftx;   //bit is 0 if ith bit of x is 0 and vice versa
          
      if(bit==0)
      {
        //If bit is 0, move right to maximize xor. If null, move left
        if(current->right!=NULL)
        {
          ll leftshift1 = 1<<i;  //shifting 1 by level no.
          max+=leftshift1; 
          current=current->right;
        }
        else
        {
          current=current->left;
        }
      }
      else
      {
        if(current->left!=NULL)
        {
          ll leftshift1 = 1<<i;  //shifting 1 by level no.
          max+=leftshift1; 

          current=current->left;
        }
        else
        {
          current=current->right;
        }
      }
      
    } 
  
    return max; 
} 
  

  
// Driver code 
int main() 
{ 
    trNode* root = new trNode(); 
   // cout<<"No. of elements to insert? \n";
    ll n; cin>>n;
    ll arr[n];
     //   cout<<"No. of queries?\n";
      ll q; cin>>q;
      ll query[q];
   //   cout<<"Insert "<<n<<" elements\n";
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    for(ll i=0;i<q;i++){
        cin>>query[i];
    }
     for(ll i=0;i<n;i++){
        insert(root,arr[i]);
    }
      for(ll i=0;i<q;i++){
        cout<<max_xor(root,query[i])<<endl;
    }
  
 
      // while(q--){
      //   ll x; cin>>x;
      //    cout << "Max xor is "<<max_xor(root, x) << endl; 

      // }
    //cout << "Max xor is"<<max_xor(root, 22) << endl; 
 
   // cout << max_xor(root, 6) << endl; 
    return 0; 
} 