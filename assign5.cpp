#include<iostream>
using namespace std;
class node{

    public:
    int route;
    node *next;
    node *prev;
    node(){

        route=0;
        next=NULL;
        prev=NULL;
    }

    node(int d){

        route=d;
        next=NULL;
        prev=NULL;
    }
};
class navigation_system{

    public:
    node *head;

    void insert_start(int v){

        node *new_route = new node(v);
       
        if(head==NULL){

            cout<<"the list is empty."<<endl;
            head=new_route;
            head->next = head;   
            head->prev = head; 
        }
        else{
            
            node *temp= head->prev; 
            new_route->next=head;
            new_route->prev=temp;
            temp->next=new_route;
            head->prev=new_route;
           
            head=new_route;
            }
        }
        
       void insert_end(int v){
            
            node *new_route = new node(v);
            node *temp = new node();
            temp=head;
            if(head==NULL){
                
                head=new_route;
            }
            else{
                
                while(temp->next!=head){
                    
                    temp=temp->next;
                }
                new_route->prev=temp;
                temp->next=new_route;
                new_route->next=head;
                head->prev=new_route;
            }
        }

        void display(){

            node *temp=new node();
            temp=head;
            cout<<"displaying navigation system:";
            while(temp->next!=head){

                cout<<temp->route<<endl;
                temp=temp->next;
            }
            cout<<temp->route<<endl;
        }
        
        void delete_start(){
             
             node *p=head;
             node *temp=head;
             
             while(temp->next!=p){
                 temp=temp->next;
                 
             }
             temp->next=head->next;
             head->next->prev=temp;
             head=head->next;
             delete(p);
        }
        
        void delete_end(){
            node *temp = head;
        	while(temp->next!=head){
	    	temp=temp->next;
        	}
	
            temp->prev->next=head;
            head->prev=temp->prev;
            delete(temp);
        }
            
    };
    int main(){

        navigation_system n;
         int choice;
    do{
        cout<<"1.INSERT ROUTE\n2.DELETE ROUTE\n3.DISPLAY ROUTE\n";
        cout<<"enter your choice:";
        cin>>choice;
        switch(choice){
            
            case 1:
            int val1;
            do{
                cout<<"1.INSERT AT START\n2.INSERT AT END\n";
                 cout<<"enter your choice:";
                cin>>val1;
                switch(val1){
                    case 1:
                    n.insert_start(1);
                    n.insert_start(2);
                    n.insert_start(3);
                    break;
                    
                    case 2:
                    n.insert_end(4);
                    n.insert_end(5);
                    break;
                    
                }
               
            }while(val1==1);
             break;
                case 2:
                int val2;
                do{
                cout<<"1.DELETE AT START\n2.DELETE AT END\n";
                 cout<<"enter your choice:";
                cin>>val2;
                switch(val2){
                    case 1:
                    n.delete_start();
                    break;
                    
                    case 2:
                    n.delete_end();
                    break;
            
                }
            }while(val2==1);
             break;
                case 3:
                n.display();
                break;
                
        }
        
        cout<<"press 1 to continue";
        cin>>choice;
    }
    while(choice==1);
   
   return 0;

    }
