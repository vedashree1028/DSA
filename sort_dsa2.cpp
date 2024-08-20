#include<iostream>
using namespace std;
class employee{
    
	int emp_id;
	string emp_name;
	float emp_salary;
	public:
	void input(employee e[], int f, int l);
	void quick_sort(employee e[],int f, int l);
	void show(employee e[], int f , int l);
    
};
void employee :: input(employee e[], int f, int l)
{
	for(int i=0;i<=l;i++){
    	cin>>e[i].emp_id;
    	cin>>e[i].emp_name;
    	cin>>e[i].emp_salary;
	}
}  

void employee :: quick_sort(employee e[] , int f , int l){
   if(f<l){
   	int pivot=f;
   	int i = f+1;
   	int j = l;
    
	while(i<j){
   	 
    
  	while(e[i].emp_id<e[pivot].emp_id){
   	 
    	i++;
 	}
  	while(e[j].emp_id>e[pivot].emp_id){
   	 
    	j--;
  	}
 	if(i<j){
     	 
    	employee temp;
    	temp = e[i];
    	e[i]=e[j];
    	e[j]=temp;
  	}
 	else {
      	break;
 	}
    
	}//end of while
    
	employee t;
	t=e[j];
	e[j]=e[pivot];
	e[pivot]=t;
    
	quick_sort(e,f,j-1);
	quick_sort(e,j+1,l);
   } //end of if
    
    
}
void employee :: show(employee e[],int f, int l){
    
	for(int i=0;i<=l;i++){
   	 
    	cout<<e[i].emp_id<<"  "<<e[i].emp_name<<"  "<<e[i].emp_salary<<endl;
	}
}
int main(){
    
	employee e[3],x;
	int f=0;
	int l=2;
	x.input(e,f,l);
	x.show(e,f,l);
	x.quick_sort(e,f,l);
	cout<<"after sorting::"<<endl;
	x.show(e,f,l);
}
