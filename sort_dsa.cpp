#include<iostream>
using namespace std;
class student {

	int roll ;
	string name;
	float marks;
    
	public:
    
	void read(student s[] , int n);
	void in_sort(student s[], int n);
	void display(student s[] , int n);
	void shell_sort(student s[],int n);
};
 
	void student :: read(student s[] , int n)
{
	for(int i=0;i<n;i++){
    	cin>>s[i].roll;
    	cin>>s[i].name;
    	cin>>s[i].marks;
	}
}  
void student :: in_sort(student s[], int n) {
   
    	for(int i=1;i<n;i++){
    	student val;
    	val=s[i];
    	int j=i-1;
    	while (j >= 0 && s[j].roll> val.roll) {
        	s[j + 1]=s[j];
        	j--;
    	}
    	s[j+1]=val;
    	}
	}
void student :: display(student s[] , int n){
    
	for(int i=0;i<n;i++){
   	 
    	cout<<s[i].roll<<"  "<<s[i].name<<"  "<<s[i].marks<<endl;
   	 
	}
    
}
void student :: shell_sort(student s[], int n) {
    	int gap=n/2;
    	while(gap>=1){
        	for(int j=gap;j<n;j++){
            	for(int i=j-gap;i>=0;i=i-gap){
            	    
            	    if(s[i+gap].name>s[i].name){
            	        
            	        break;
            	    }
            	    else{
            	        student temp;
            	        temp=s[i+gap];
            	        s[i+gap]=s[i];
            	        s[i]=temp;
            	    }
            	}
        	}
        	gap=gap/2;
    	}
}	
    	

int main(){

	student s[3],x;
	int n;
	cin>>n;
	int choice;
	do{

    	cout<<"1.ENTER RECORD\n2.DISPLAY RECORD\n3.ARRANGE ORDER USING INSERTION SORT\n4.ARRANGE USING SHELL SORT\n5.EXIT"<<endl;
    	cout<<"enter the choice:"<<endl;
    	cin>>choice;
    	switch(choice){

        	case 1:

        	cout<<"enter record:"<<endl;
        	x.read(s,n);
      	 
        	break;
        	case 2:
         	x.display(s,n);
        	break;
        	case 3:
        	cout<<"after insertion sort:"<<endl;
        	x.in_sort(s , n);
        	x.display(s,n);
        	break;
       	 
        	case 4:
            cout<<"after shell sort:"<<endl;
            x.shell_sort(s,n);
            x.display(s,n);
            break;

        	cout<<"EXIT"<<endl;
        	break;

    	}
    	if(choice==4){
        	break;
    	}
    	cout<<"press 1 to continue"<<endl;
    	cin>>choice;
	}
	while(choice==1);

	return 0;
}


