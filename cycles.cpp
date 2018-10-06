#include<iostream>
#include<stack>
using namespace std;
int n;

//{{0,1,-1,-1,0},{-1,0,1,1,-1},{1,-1,0,0,1},{1,-1,0,0,1},{0,1,-1,-1,0}};
int matrix[12][12];
/*{{0,1,-1,0,0,1},
                    {-1,0,0,0,1,-1},
                    {1,0,0,-1,0,1},
                    {0,0,1,0,-1,-1},
                    {0,-1,0,1,0,-1},
                    {-1,1,-1,1,1,0}
                  };
/*={{0,1,-1,-1,0},{-1,0,1,1,0},{1,-1,0,1,-1},{1,-1,-1,0,1},{0,0,1,-1,0}};*/
/*={{0,1,-1,0,0,1},
                    {-1,0,0,0,1,-1},
                    {1,0,0,-1,0,1},
                    {0,0,1,0,-1,-1},
                    {0,-1,0,1,0,-1},
                    {-1,1,-1,1,1,0}
                  };
{{1,1,1,0,0,0,0},{-1,0,1,1,-1,0,0},{-1,-1,0,0,0,-1,1},
{0,-1,0,0,1,0,0},{0,1,0,-1,0,0,0},{0,0,1,0,0,0,-1},{0,0,-1,0,0,1,0}};*/

stack<int> stack1;
//vector<vector<int> > path(n);
int path[12][12];
stack<int> stack2;
bool arr[12];
bool final[12];
int count=0;
bool rst[10];
int loopcount;
void funct(int v){

	 int size=0;
     if (arr[v]==true){
        int i=1;                       
     	cout<<v+1<<"<-";
     	size++;
     	path[count][i++]=v+1;
       while(stack1.top()!=v){
            cout<<stack1.top()+1<<"<-";
           // path[count][i++]=stack1.top()+1;
            int a=stack1.top();
            stack2.push(a);
            stack1.pop();
        }
       cout<<stack1.top()+1;
       while(!stack2.empty()){
       	 stack1.push(stack2.top());
       	 path[count][i++]=stack2.top()+1;
       	 size++;
       	 stack2.pop();
       }
       path[count][0]=size;
       cout<<"\n";
       count++;
     }
     else{
        stack1.push(v);
        arr[v]=true;
        int i;	 

        for(i=0;i<n;i++){
     	     if (matrix[v][i]==1){//&& (final[v]==false || final[i]==true) 
     		     funct(i);
     	   }
     	 }
       final[v]=true;


        stack1.pop();
        arr[v]=false;
     }
     loopcount++;
}
int largest(){
	int largeindex=-1;
	int large=0;
	 for(int i=0;i<12;i++){
	 	 //cout<<"large"<<large<<"\n";
         if (path[i][0] > large && path[i][0]>0){
                large=path[i][0];
                largeindex=i;
          }   
   }
   return largeindex;
}
bool finding(){
  bool flag=false;
	for(int i=0;i<12;i++){
    if (path[i][0]!=0 || path[i][0]!=-1){
      flag=true;
      break;
    }
  }
  return flag;
}
void printing(bool *arr){
  cout<<"checking\n";
  for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
  cout<<"\n";       
}
int main(){
   cout<<"the number of vertices in the graph\n";
   cin>>n;
   cout<<"enter the matrix\n";	
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
      	   cin >> matrix[i][j];
      }
   }
   for(int i=0;i<12;i++){
     for(int j=0;j<12;j++){
        path[i][j]=0;
     }
   }
	for(int i=0;i<12;i++){
	    arr[i]= false;
	    final[i]=false;
      rst[i]=false;
	}
   for(int i=0;i<n;i++){
   	  for(int j=0;j<n;j++){
   	  	  cout<<matrix[i][j]<<" ";
   	  }cout<<"\n";
   }
   int count=0;
   for(int i=0;i<n;i++){
      //printing(final);
      if (final[i]==false){  
         funct(i);
     }
   }
   //funct(1);
  /* for(int i=0;i<12;i++){
   	for (int j=0;j<12;j++){
   		if (path[i][j]!=0)
   		   cout<<path[i][j]<<" ";
   	}cout<<"\n";
   }*/
   /*int *ptr=(int *)matrix[12];
   while(*ptr!=0){
     cout<<size(ptr);
     ptr++;
   }*/
   cout<<"\nall the independent path of the graph is\n";
   int checking[n];
   for(int i=0;i<n;i++)
   	    checking[i]=0;
    int index;
   while(finding()){
         index=largest();
         //cout<<"index"<<index;
         
         if (index==-1) //no need to used this if statement 
             break;

         int flag=0;
         for (int i=1;path[index][i]>0;i++){
         	if (checking[path[index][i]-1]==0){
         	    checking[path[index][i]-1]=1;
         	    flag=1;
          }
         }
         cout<<"\n";
         if (flag==1){
         	for(int i=1;path[index][i]!=0;i++)
         		  cout<<path[index][i]<<"->";
         	cout<<path[index][1];
         	path[index][0]=-1; 
          cout<<"\n";
         }
         else                 //else break will be used if path will not be repeated
           path[index][0]=-1;
     
   }

}