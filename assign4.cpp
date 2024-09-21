#include<iostream>
using namespace std;
class node{
    public:
    string text;
    node *next;
    node *prev;
    node(){

        text="x";
        next=NULL;
        prev=NULL;
    }

    node(string d){

        text=d;
        next=NULL;
        prev=NULL;
    }
};
class text_editor {

    node *head;
    public:
   text_editor(){
       head=NULL;
   }
    void insert_start(string d){
        node *nn = new node(d);
        if(head==NULL){

            cout<<"list is empty."<<endl;
            head = nn;
        }
        else{

           
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
    }

    void insert_end(string d){

        node *nn = new node(d);
       
       
        if(head==NULL){

            cout<<"list is empty."<<endl;
        }

        else{
             node *temp = new node();
             temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
               
        }
             nn->prev = temp;
             temp->next = nn;
         
        }
    }

    void insert_between(string d){

        node *temp = head;
        node *nn = new node(d);
        string  key;
        cout<<"enter data after which you want to insert:"<<endl;
        cin>>key;
        while(temp->next!=NULL){

            if(key==temp->text){

                nn->next=temp->next;
                temp->next->prev=nn;
                nn->prev=temp;
                temp->next=nn;
            }
             temp=temp->next;

        }
    }
   
    void delete_start(){
       
        node *temp = head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        delete(temp);
    }
   
    void delete_end(){
       
        node *temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
           
        }
        temp->prev->next=NULL;
            delete(temp);
    }
   
   
    void delete_between(){
        string  key;
        cout<<"enter which node you have to delete:";
        cin>>key;
        node *p = new node();
        node *q = new node();
        node *r = new node();
        p=head;
        q=head;
        r=p->next;
        while(p->text!=key){
            q=p;
            p=p->next;
            r=p->next;
        }
        r->prev=p->prev;
        q->next=p->next;
        delete(p);
    }
   
    void display(){
       
        cout<<"diplaying the list:"<<endl;
        node *temp = head;
        while(temp->next!=NULL){
            cout<<temp->text<<" ";
            temp=temp->next;
        }
        cout<<temp->text<<endl;
    }
    void display_reverse(){
        
        node *temp=head;
        cout<<"displaying list in reverse order:";
        while(temp->next!=NULL){
            
            temp=temp->next;
        }
        cout<<temp->text<<" ";
        while(temp->prev!=NULL){
            
            temp=temp->prev;
            cout<<temp->text<<" ";
        }
    }
};
int main(){

    text_editor l;
    int choice;
    do{
        cout<<"1.INSERT TEXT\n2.DELETE TEXT\n3.DISPLAY TEXT\n4.PRINT TEXT IN REVERSE\n";
        cout<<"enter your choice:";
        cin>>choice;
        switch(choice){
            
            case 1:
            int val1;
            do{
                cout<<"1.INSERT AT START\n2.INSERT AT END\n3.INSERT AT BETWEEN\n";
                 cout<<"enter your choice:";
                cin>>val1;
                switch(val1){
                    case 1:
                    l.insert_start("abc");
                    l.insert_start("xyz");
                    l.insert_start("lmn");
                    l.insert_start("opq");
                    break;
                    
                    case 2:
                    l.insert_end("pqr");
                    break;
                    
                    case 3:
                    l.insert_between("dfg");
                    break;
                }
               
            }while(val1==1);
             break;
                case 2:
                int val2;
                do{
                cout<<"1.DELETE AT START\n2.DELETE AT END\n3.DELETE AT BETWEEN\n";
                 cout<<"enter your choice:";
                cin>>val2;
                switch(val2){
                    case 1:
                    l.delete_start();
                    break;
                    
                    case 2:
                    l.delete_end();
                    break;
                    
                    case 3:
                    l.delete_between();
                    break;
                }
            }while(val2==1);
             break;
                case 3:
                l.display();
                break;
                
                case 4:
                 l.display_reverse();
                 break;
        }
        
        cout<<"press 1 to continue";
        cin>>choice;
    }
    while(choice==1);
   
   return 0;
}
