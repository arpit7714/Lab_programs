#include<iostream>
#include<cctype>
#include<bits/stdc++.h>
#include<malloc.h>
using namespace std;
int matrix[4][4];
int checked[4][4];
int n;
vector<string> v;
int change(char str){
  switch(str){
     case 'a':
     case 'A':
          return 0;
     case 'b':
     case 'B':
          return 1;
     case 'c':
     case 'C':
          return 2;
     case 'd':
     case 'D':
          return 3;
   }
}

int * binary(int number,int count){
  
  //cout<<"\nnumber"<<number;

  //we cannot create static array here and cannot return that
  int  *arr=(int*)malloc(count*sizeof(int));
  int p=count;
  while(number!=0 && number!=1){
     int r=number%2;
     arr[--p]=r;
     number=number/2; 
   } 
   arr[--p]=number;
   if (p!=0){
      for(int i=p-1;i>=0;i--){
           arr[i]=0;        
     }
  }
  
  return arr;
} 

void initialize(int *arr){
  for(int i=0;i<n;i++)
       *(arr+i)=-1;

}

void arrangement(int *temporary,int *arr){
    for(int i=0;i<n;i++)
      temporary[i]=arr[i];

}
int changing(int binary1){
   if (binary1 == 3)
      binary1 = 2;
  else if (binary1 == 2)
  	  binary1 = 3;
  
  return binary1;
}

void kmap(int *arr){
    //cout<<"hello"<<"\n";
  int count=0;
  int temporary[n];
  for(int i=0;i<n;i++){
    if (arr[i]==-1)
          count++;
  }
  
  int total=(int)pow(2,count);
  int p;
  int *brr;
  for (int i=0;i<total;i++){
      brr=binary(i,count);

      p=0;
      arrangement(temporary,arr);
      for(int i=0;i<n;i++){
         if (temporary[i]==-1){
           temporary[i]=brr[p++];
       }
      }
    //for only 4 variable
  int binary2,binary1;   
  if (n==4){    
          binary1=temporary[3]+2*temporary[2];
       binary2=temporary[1]+2*temporary[0];
  }
  if (n==3){
  	binary1=temporary[2]+2*temporary[1];
  	binary2=temporary[0];
  }
  if(n==2){
    binary1=temporary[1];
    binary2=temporary[0];

  }
  binary1=changing(binary1);
  binary2=changing(binary2);
       
    matrix[binary2][binary1]= 1;
    }
  }
  //for pow(2,n-1)
  //valid only for n==4 and n==3 (only for colums)
  char * merging(int x,int y,int cols){
  	char ar[]={'a','b','c','d'};
  	int p;
  	int point=0;
  	if (cols==1)
  		p=2;
  	else
  		p=0;
   char *final = (char*)malloc(n*sizeof(char));
   int *temp1=binary(x,2);
   int *temp2=binary(y,2);

   	  if (temp1[0]==temp2[0]){
          if(temp1[0]==0){
              if (n==4){
              	  final[point++]=toupper(ar[p]);
              }
              if (n==3){
                  final[point++]=toupper(ar[p-1]);
              }   
          }
          else{
              if (n==4){
              	  final[point++]=ar[p];
              }
              if (n==3){
                  final[point++]=ar[p-1];
              }   
    
          }
   	  }
   	 else if (temp1[1]==temp2[1]){
            if(temp1[1]==0){
              if (n==4){
              	  final[point++]=toupper(ar[p+1]);
              }
              if (n==3){
                  final[point++]=toupper(ar[p]);
              }   
          }
          else{
              if (n==4){
              	  final[point++]=ar[p+1];
              }
              if (n==3){
                  final[point++]=ar[p];
              }   
    
          }
   	 } 
   	
    return final;
}
//for 4 variables
char* inserting(int x,int y,int cols){  
            y=changing(y);
            x=changing(x);

            //cout<<"\nposition"<<x<<y;
            char *exp=(char*)malloc(sizeof(char));
            exp=merging(x,y,cols);
            return exp;
}
//for 8 blocks
void setchecked(int x,int y,int cols){
   if(cols==1){
      for(int i=0;i<n;i++){
           checked[i][x]=1;
           checked[i][y]=1;
      }
   }
   else{
      for(int i=0;i<n;i++){
          checked[x][i]=1;
          checked[y][i]=1;

      }
   }
}
void setchecked1(int var1,int var2,int x,int i){
	
      for(int j=i;j<i+var1;j++){
             for(int k=x;k<x+var2;k++){
             	checked[k%4][j%4]=1;
             
        }
     }
}   
void setchecked2(int x,int cols){
  if (cols==1){
  	for (int i=0;i<4;i++)
       checked[i][x]=1;
  }
  else{
    for (int i=0;i<4;i++)
       checked[x][i]=1;
  }
}
void number8(char *exp){
           if (v.empty()){
                v.push_back(exp);
            }
            else{
                v.push_back("+");
            	v.push_back(exp);
           }
}
void number4(char *exp,int end){
	  if (v.empty()){
         v.push_back(exp);
	  }
	  else if(end==0){
	  	 v.push_back("+");
	  	 v.push_back(exp);
	  }
	  else{
	  	v.push_back(exp);
	  }

}
//only for 4 variable
char * inserting1(int x,int cols){
	x=changing(x);
	char arr[]={'a','b','c','d'};
    int  *temp=binary(x,2);
   char *final=(char*)malloc(sizeof(char)*2); 
   int p;
   int point=0;
    if (cols==1)
       p=2;
   	else
   	   p=0;	
   	if (n==4){
       if (temp[0]==0){
            final[point++]=toupper(arr[p]);
       }
       else{
         	final[point++]=arr[p];
       }
       if (temp[1]==0){
            final[point++]=toupper(arr[p+1]);
      }
       else{
         	final[point++]=arr[p+1];
       }
   }
   else if(n==3 || n==2 && cols==0){
      if(temp[1]==0)
      	 final[point++]=toupper(arr[p]);
      else
         final[point]=arr[p];	

   }
   else if(n==3 && cols==1){
   	  p--;
      if (temp[0]==0){
            final[point++]=toupper(arr[p]);
       }
       else{
         	final[point++]=arr[p];
       }
       if (temp[1]==0){
            final[point++]=toupper(arr[p+1]);
      }
       else{
         	final[point++]=arr[p+1];
       }
   }
   //vertical
   else if(n==2 && cols==1){
   	  p--;
      if (temp[1]==0){
      	 final[point++]=toupper(arr[p]);
      }
      else
         final[point++]=arr[p];
   }
   //horizontal
    return final;
}
void manageblocks(int var1,int var2,int cols){
    int on,var;
    if (n==4)
    	var=4;
    else if (n==3)
    	var=2;
    for(int x=0;x<var;x++){
        for(int i=0;i<4;i++){
        	 int flag2=1;
             on=0;
             for(int j=i;j<i+var1;j++){
                 for(int k=x;k<x+var2;k++){
                 	   if (matrix[k%4][j%4]==0){
                 	   	   flag2=0;
                 	   	   break;
                 	   }
                       if (checked[k%4][j%4]==0){ 
                       	   on=1;
                       	}
                             
                 }
                 if (flag2==0)
                 	 break;
             }
             if (flag2==1 && on==1){
             	char *exp1,*exp2;
             	if(cols==1){
             	  exp1= inserting(i,(i+var1-1)%4,cols);
             	  exp2= inserting1(x,1-cols);
             	 }
             	else{
             	  exp2= inserting1(i,1-cols);
             	  exp1= inserting(x,(x+var2-1)%4,cols);
             	}  

             	  number8(exp1);
             	  number4(exp2,1);
             	  if (n==4){
             	  setchecked1(var1,var2,x,i);
                  }
                  else if (n==3){
                  	setchecked1(var1,var2,x,i);
                  }
                          	  
            }
        }
    }      

}
void singleblock(int var1,int var2){
	   for(int i=0;i<var1;i++){
      for (int j=0;j<var2;j++){
         if (matrix[i][j]==1 && checked[i][j]==0){
               char *exp1=inserting1(j,1);
               char *exp2=inserting1(i,0);
               number8(exp1);
               number4(exp2,1);
               checked[i][j]=1;
          }
        }
      }

}

int main(){
  cout<<"enter the number of variables\n";
  cin>>n;
  cout<<"Enter the expression\n";

  for(int i=0;i<4;i++){
      for (int j=0;j<4;j++){
          matrix[i][j]=0;
          checked[i][j]=0;
    }
  } 
  //getline method will take the new line character from the above cin
 for(int i=0;i<4;i++){
      for (int j=0;j<4;j++){
         cout<< matrix[i][j];
    }
    cout<<"\n";
  }
  cin.ignore();

  string input;
  getline(cin,input);
  
  int index;
  int arr[n];
  cout<<"\ninput"<<input;
  cout<<"\n";

  int k;
  initialize(arr);
 
  for (int i=0;i<=input.size();i++){
  	 
     if (input[i]=='+' || input[i]=='\0'){
     	          
         kmap(arr);
         initialize(arr);
         cout<<"\n";
     }
    else{
      
       index=change(input[i]);

       if (isupper(input[i]))
           arr[index]=0; 
       else
           arr[index]=1;  

      }
   }
  cout<<"\n-------- K-MAP ---------\n";
 //printting
  for(int i=0;i<4;i++){
      for (int j=0;j<4;j++){
         cout<< matrix[i][j];
    }
    cout<<"\n";
  } 

//-------------procedure for rectangles---------------
   //int x,y;
 if(n==4 || n==3){
   int p,q;
   int flag=1;
   //checking for n bits
   int var;
   if (n==4)
   	  var=4;
   	else if(n==3)
   	   var=2;	
   for(int i=0;i<var;i++){
      for(int j=0;j<n;j++){
      	  if (matrix[i][j]==0){
      	  	  flag=0;
      	  	  break;
      	  }
      }
      if (flag==0)
      	  break;
   }
   if (flag==1)
   	   cout<<"Minimised funtion = "<<"1\n";
if (flag!=1){
    //for 8 bits
   //columns
//only for n==4	
if(n==4){
    for(int i=0;i<n-1;i++){
    	int flag1=1;
        for(int j=0;j<n;j++){
            if (matrix[j][i]!=1 || matrix[j][i+1]!=1){
                    flag1=0;
                    break;
            }
    }
        if (flag1==1){
            number8(inserting(i,i+1,1));	
            setchecked(i,i+1,1);
        }
    }
    //for side colums
    int flag1=1;
    for(int j=0;j<n;j++){
        if (matrix[j][0]!=1 || matrix[j][n-1]!=1){
                  flag1=0;              
                  break;
        }

    } 
    if (flag1==1){
    	number8(inserting(0,n-1,1));
    	setchecked(0,n-1,1);
    }
   //rows
      for(int i=0;i<n-1;i++){
    	int flag1=1;
        for(int j=0;j<n;j++){
            if (matrix[i][j]!=1 || matrix[i+1][j]!=1){
                    flag1=0;
                    break;
            }

        }
        if (flag1==1){
           number8(inserting(i,i+1,0));	
           setchecked(i,i+1,0);
        }

      }
     flag1=1;
    for(int j=0;j<n;j++){
        if (matrix[0][j]!=1 || matrix[n-1][j]!=1){
                  flag1=0;              
                  break;
            }
    } 
    if (flag1==1){
    	number8(inserting(0,n-1,0));
    	setchecked(0,n-1,0);
    }
}
    //for n-2 blocks or for 4 rectangles
        //for noraml rectangles
    int on;
    for(int x=0;x<var;x++){
        for(int i=0;i<4;i++){
        	 int flag2=1;
             on=0;
             for(int j=i;j<i+2;j++){
                 for(int k=x;k<x+2;k++){
                 	   if (matrix[k%4][j%4]==0){
                 	   	   flag2=0;
                 	   	   break;
                 	   }
                       if (checked[k%4][j%4]==0){ 
                       	   on=1;
                       	}     
                 }
                 if (flag2==0)
                 	 break;
             }
             if (flag2==1 && on==1){
             	  if (n==4){
             	  number4(inserting(x,(x+1)%4,0),0); //(i and i+1)%4  and (x and x+1)%4
             	  number4(inserting(i,(i+1)%4,1),1);
             	  setchecked1(2,2,x,i);  //2=var1 and 2=var2
             	  }
             	  else if(n==3){
                      number4(inserting(i,(i+1)%4,1),1);
                      setchecked1(2,2,0,i);
             	  }
            }
        }
    }  
    if (n==4){  
    //VERTICAL 4 blocks
      for(int i=0;i<n;i++){
     	int flag2=1;
     	int on=0;
        for(int j=0;j<n;j++){
                   if (matrix[j][i]==0){
                 	   	   flag2=0;
                 	   	   break;
                 	   }
                       if (checked[j][i]==0){ 
                       	   on=1;
                       	}
                             
                 } 
              if (flag2==1 && on==1){
              	if (n==4){
             	  number8(inserting1(i,1));
             	  setchecked2(i,1);
                 }

                 }  	
             }
      }       

     //for 4 horizontal rows
      for(int i=0;i<var;i++){
     	int flag2=1;
     	int on=0;
        for(int j=0;j<n;j++){
                   if (matrix[i][j]==0){
                 	   	   flag2=0;
                 	   	   break;
                 	   }
                       if (checked[i][j]==0){ 
                       	   on=1;
                       	}       
                 } 
              if (flag2==1 && on==1){
             	  number8(inserting1(i,0));
             	  setchecked2(i,0);
                    	
             }
          }   

     //corners

     if ((n==4 )&& matrix[0][0]==1 && matrix[0][n-1]==1 && matrix[n-1][0]==1 && matrix[n-1][n-1]==1 && (checked[0][0]==0 || checked[0][n-1]==0 || 
     	checked[n-1][0]==0 || checked[n-1][n-1]==0)){
     	//hardcode
     	char *exp="BD";
        number8(exp);
        checked[0][0]==1;
        checked[0][n-1]==1; 
     	checked[n-1][0]==1;
     	checked[n-1][n-1]==1;

     }  
   
    //for 2 horizontal blocks
     //2=var1 1=var2,1=cols 

     manageblocks(2,1,1);  
     
    //for vertical 2 blocks
   
     manageblocks(1,2,0);

     //for single block
     singleblock(var,4);

   }
}
//for variables n==2
  if(n==2){	
  int flag=1;
   for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
      	  if (matrix[i][j]==0){
      	  	  flag=0;
      	  	  break;
      	  }
      }
      if (flag==0)
            break;
   }
   if (flag==1)
   	   cout<<"Minimised funtion = "<<"1\n";

  else if (flag!=1){          //if flag!=1
  	 //horizontal blocks
         if(matrix[0][0]==1 && matrix[0][1]==1 && (checked[0][0]==0 || checked[0][1]==0)){
                 number8(inserting1(0,0));
                 checked[0][0]=1;
                 checked[0][1]=1;
         }       
         if(matrix[1][0]==1 && matrix[1][1]==1 && (checked[1][0]==0 || checked[1][1]==0)){
                 number8(inserting1(1,0));
                 checked[1][0]=1;
                 checked[1][1]=1;
         } 
     //vertical blocks
          if(matrix[0][0]==1 && matrix[1][0]==1 && (checked[0][0]==0 || checked[1][0]==0)){
                 number8(inserting1(0,1));
                 checked[0][0]=1;
                 checked[1][0]=1;
         }       
         if(matrix[0][1]==1 && matrix[1][1]==1 && (checked[0][1]==0 || checked[1][1]==0)){
                 number8(inserting1(1,1));
                 checked[0][1]=1;
                 checked[1][1]=1;
         }   

         singleblock(2,2);
  }
}
      cout<<"\nchecked\n";
      for(int i=0;i<4;i++){
           for (int j=0;j<4;j++){
              cout<< checked[i][j];
        }
         cout<<"\n";
     } 
       
      for(string n : v){
          cout<<n<<" ";
         }  
     
}
  

















