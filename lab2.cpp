#include<iostream>
#define infinity 99999

using namespace std;
void print(int n,int *dist){
   for(int i=0;i<n;i++){
     cout<<dist[i]<<" ";
    // cout<<"node"<<pred[i]<<" "; 
 }
  cout<<"\n";
}
int count1=0;
int mod(int a){

  if (a>=0)
     return a;
  else
     return -a;
}

int path(int graph[10][10],int n,int source,int destination){
   int dist[n],visited[n];  
   int actual[n]={-1};
 
   for(int i=0;i<n;i++){
        dist[i]=graph[source-1][i];
        visited[i]=0;
       
  }
  actual[count1++]=source-1;
  dist[source-1]=0;
  int count=1;
  visited[source-1]=1;
  int next;
  cout<<"distance\n";
  print(n,dist);
  //cout<<"actual";
  //print(n,actual);
  while(visited[destination-1]==0){
      int smallest=infinity;
   
      for(int i=0;i<n;i++){
          if (dist[i]<smallest && visited[i]!=1){
                smallest=dist[i];
                next=i;
                actual[count1++]=next;      
          } 
      }
     //cout<<"next"<<next; 
     visited[next]=1;
      
     for(int i=0;i<n;i++){
         if (visited[i]==0){
            if (smallest+graph[next][i]<dist[i]){
                  dist[i]=smallest+graph[next][i];
           }
       }
    }
    cout<<next+1<<"\n";
    cout<<"distance"<<"\n";
    print(n,dist);
    count++;

    //cout<<"visited";
    //print(n,visited);
 }
  cout<<"actual";
  print(n,actual);
  int count2=0,i,j;
  int trace[n]={-1};
  i=n-2;
  j=i+1;
  //trace[count2++]=actual[j];
  while(i>=0){

    //cout<<"d"<<mod(dist[actual[j]]-dist[actual[i]]);
    if (actual[j]==-1){
        i--;
        j=i+1;
    }
    else if (mod(dist[actual[j]]-dist[actual[i]])==graph[actual[i]][actual[j]]){
    	if(count2==0)
    		trace[count2++]=actual[j];
        trace[count2++]=actual[i];
        i--;
        j=i+1;
       
    }
    else{
        i--;
    }
 
 }
 //printitng of the final path
 cout<<"final\n";
 for(int k=0;k<n;k++)
 	cout<<trace[k]+1<<"<-";
}


int main(){
  int graph[10][10],n;
  cout<<"enter the number of vertices\n";
  cin>>n;
  
  cout<<"enter the adjacency matrix of the graph\n";
  for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
        cin >> graph[i][j];
        if (graph[i][j]==0)
            graph[i][j]=infinity;
    }
  }  
  cout<<"enter the source vertex\n";
  int source,destination;
  cin>>source;
  cout<<"enter the disination vertex";
  cin>> destination;
  path(graph,n,source,destination);
}
