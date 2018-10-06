import java.util.*;
class node{
   int v;
   int key; 
   public node(int a,int b){
         v=a;
         key=b;
  }
}
class minheap{
        public ArrayList<node> heap;
        
        public minheap(){
            heap=new ArrayList<node>();
        } 
        public int getkey(){
           return heap.get(0).key;
        }
        
        public minheap(ArrayList<node> nodeList) 
        {
        	heap = nodeList;
        	make();
        }
      
        public  void make(){
           int i=heap.size()/2;
           while(i>=0){
              minheapify(i);
              i--;
            }
        }
        public node extractmin(ArrayList<node> heap){
           if(heap.size()<=0) 
                   return null;
           node minvalue=heap.get(0);
         
           //swapping first node with the lastnode
           swapnode(0,heap.size()-1);
           heap.remove(heap.size()-1);
           minheapify(0);
           return minvalue; 
        }

        public void minheapify(int i){
           int smallest=i;
           int left=2*i+1;
           int right=2*i+2;
           if (left<heap.size() && heap.get(left).key <= heap.get(smallest).key)
                    smallest=left;
           if(right<heap.size() && heap.get(right).key <= heap.get(smallest).key)
                    smallest=right; 

           if (smallest!=i){
                 swapnode(smallest,i);
                 minheapify(smallest);      

             } 
         }
         public void swapnode(int a,int b){
                node temp=heap.get(a);
                heap.set(a,heap.get(b));
                heap.set(b,temp);
         }
         void decreasekey(ArrayList<node> nodelist,int v,int key){
                  int point=0;
                  for(int i=0;i<heap.size();i++)
                    if(heap.get(i).v==v){
                           point=i; 
                           break;
                    }
                int j=point;
                nodelist.get(j).key = key;
                while(j>0 && nodelist.get(j).key < nodelist.get(Integer.valueOf((j-1)/2)).key){
                      swapnode(j,Integer.valueOf((j-1)/2));
                      j=(j-1)/2;  
                } 
         }
             
   }
public class prim {
   public static void main(String [] args){
      Scanner sc=new Scanner(System.in);
      System.out.println("Enter the number of vertices in the graph");
      int n=sc.nextInt(); 
      int [][] matrix= new int[n][n];
      //int [][]matrix={{0,4,8,2,0},{4,0,6,5,0},{8,6,0,1,4},{2,5,1,0,11},{0,0,4,11,0}};
       for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               matrix[i][j]=sc.nextInt();
           }
        }
       for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               System.out.print(matrix[i][j]+" ");
           }System.out.print("\n");
        }
      prim obj=new prim();
      obj.run(n,matrix);
       
  }
   public void printing(int []arr,int number){
           for(int i=0;i<number;i++)
                  System.out.print(arr[i]+" ");
   }
   public void run(int number,int [][] matrix){
        minheap obj = new minheap();
        prim obj1= new prim();
       //---------------main function----------------------- 
         int [] parent=new int [number];
         int [] key=new int [number];
          
         for(int v=1;v<number;v++){
             parent[v]=-1;
             key[v]=9999;
             obj.heap.add(new node(v,key[v]));
           }
         key[0]=0;
         obj.heap.add(new node(0,key[0]));
         //minimum spanning tree array 
         obj.make();
         System.out.println("\n");
         int [] mst=new int [number];
         for(int i=0;i<number;i++)
                mst[i]=-1;        
         int cost=0;   
         while(!isempty(obj.heap)){
             node minvaluenode= obj.extractmin(obj.heap);
             int u=minvaluenode.v;
                          cost+=minvaluenode.key; 
             //System.out.println("next->"+u+"key"+minvaluenode.key);
             mst[u]=1; 
             //System.out.println("node num"+u+"key"+minvaluenode.key);
             for(int i=0;i<number;i++){
                 if(mst[i]==-1 && matrix[u][i]!=0 && matrix[u][i] < key[i]){
                     key[i]=matrix[u][i];  
                     parent[i]=u;
                     obj.decreasekey(obj.heap,i,key[i]);                      
                   }
                 /*System.out.println("keys");
                 obj1.printing(key,number);
                 System.out.println("actual");
                 for(int k=0;k<obj.heap.size();k++)
                      System.out.println("\n"+obj.heap.get(k).v+"  "+obj.heap.get(k).key);*/
             }
              
         }         
         System.out.println("the minimum cost of the spanning tree=" + cost); 
         for(int i=0;i<number;i++)
             System.out.print((parent[i]+1)+"-->");
   } 
   public boolean isempty(ArrayList<node> nodelist){
       if (nodelist.size()==0)
              return true;
       else
              return false;
    }
//decrease key function is not working properly
//extract minium is working fine
}
