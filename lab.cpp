#include<iostream>
using namespace std;

 struct coordinates{
     int x;
     int y;
 };

 class stack{
  public:
    coordinates obj[100];
    int top=-1;

    void push(int xc, int yc){    //xc(xcordinate) yc(ycordinate)
         ++top;
         obj[top].x=xc;
         obj[top].y=yc;
    }
    void pop(){
        top--;
    }
    coordinates peek(){           //it will return object of the struct
        return obj[top];
    }
    int Isempty(){
         if (top==-1)
             return 1;
         else
             return 0;
     }
    coordinates value(int j){
          return obj[j]; 
    
    }
   int topvalue(){
         return top;
   }
 
 }; 
 int dx,dy,m,n;          // as desination cannot be changed
 stack st;  // object of th stack class
 

 void print(int *matrix){
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          cout<<*((matrix+i*m)+j)<<" ";
   }cout<<"\n";
  }
}
int count=0;
 int path(int findx,int findy,int *matrix){
     *((matrix+findx*m)+findy)=2;
     // cout<<"\nma "<<*((matrix+findx*m)+findy)<<findx<<" "<<findy<<" ";  
     if (count==0)  
         st.push(findx,findy);  
     count++; 
     //cout<<"\nvariables"<<dx <<dy<<" "<<findx<<findy;

     while(findx!=dx || findy!=dy){
           cout<<findx<<findy<<"\n";
           cout << st.peek().x <<" "<<st.peek().y<<"\n";

           //if (findx==2 && findy==0)
             //    return 1;

           print((int*)matrix);
           cout<<"\n\n";
     
           if(findy!=m-1 && *((matrix+findx*m)+(findy+1))==0){
                     findy+=1;
                     st.push(findx,findy); 
                     *((matrix+findx*m)+findy)=2;
             }

           else if(findx!=n-1 && *((matrix+(findx+1)*m)+findy)==0){
                     findx+=1;
                     st.push(findx,findy); 
                     *((matrix+findx*m)+findy)=2;
                     
             }
          else if(findy!=0 && *((matrix+findx*m)+(findy-1))==0){
                     findy-=1;
                     st.push(findx,findy);  
                     *((matrix+findx*m)+findy)=2;
                    
             }
         
          else if(findx!=0 && *((matrix+(findx-1)*m)+findy)==0){
                     findx-=1; 
                     st.push(findx,findy); 
                     *((matrix+findx*m)+findy)=2;
                      
             }
          else{
               *((matrix+findx*m)+findy)=1;
               return 0;    
          }
         print((int*)matrix);
         cout<<"\n\n";
     
   
    } 
      return 1; //if destination is found in a single run
 }

int main(){
   cout<<"enter the size of the matrix\n";
   cin>>n>>m;
   int matrix[n][m],hurdles,sx,sy,hx,hy;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          matrix[i][j]=0;
   }
  }
   cout<<"enter the number of hirdles do you want\n";
   cin>>hurdles;

   cout<<"enter the coordinates of the hurdles\n";
   for(int i=0;i<hurdles;i++){  
       cin >> hx >> hy;
       matrix[hx][hy]=1; 
   }
   cout<<"eneter the coordinnates of the source and the destination\n";
   cin >> sx >> sy >> dx >> dy;
   int result=0;  // default result is not found
   coordinates result1;
   int sourcex=sx;
   int sourcey=sy;
   while(result!=1){ 
    //cout<<"\n"<<sourcex<<" "<<sourcey<<"\n";
    result=path(sourcex,sourcey,(int *)matrix);
    //cout<<"result"<<result;
    if (result==0){
          st.pop();
          result1=st.peek();
          sourcex=result1.x;
          sourcey=result1.y;
    } 
   }
   coordinates result2;
   //cout<<"the path coordinates from the source to destination is \n"; 
  /* for(int j=0;j<st.topvalue();j++){
        result2=st.value(j);
        cout<<result2.x <<" "<<result2.y;
        cout<<"\n";
    }*/ 
   
 }
