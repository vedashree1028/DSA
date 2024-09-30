#include<iostream>
using namespace std;
class node{
    
    public:
    int coeff,power;
    node *next;
    
    node(){
        
        coeff =0;
        power =0;
        next=NULL;
    }
};
class linked_list{
    
    public:
    //node *head;
    
  node *head=NULL;
    void create_node(int x , int y){
        
        node *nn = new node();
        nn->coeff=x;
        nn->power=y;
        if(head==NULL){
            
            head=nn;
        }
        else{
            
            node *temp =head;
            while(temp->next!=NULL){
                
                temp=temp->next;
            }
            temp->next=nn;
        }
        
    }
    
    void print_poly(){
        

        if(head!=NULL){
                    node *temp = head;
            
            while(temp->next!=NULL){
                
                cout<<temp->coeff<<"x^"<<temp->power<<" + ";
                temp=temp->next;
            }
            
           cout<<temp->coeff<<"x^"<<temp->power;
        }
        
    }
    
    void add_poly(linked_list *l1 , linked_list *l2){
        
        node *p = l1->head;
        node *q = l2->head;
        linked_list result;
        node *curr = NULL;
       
        while(p!=NULL && q!=NULL){
            
            node *nn = new node();
            if(p->power > q->power){
                
                nn->coeff=p->coeff;
                nn->power=p->power;
                p=p->next;
            }
            else if(q->power > p->power){
                
                nn->coeff=q->coeff;
                nn->power=q->power;
                q=q->next;
            }
            else{
                
                nn->coeff = p->coeff + q->coeff;
                nn->power = p->power;
                p=p->next;
                q=q->next;
            }
            if(result.head == NULL){
                result.head=nn;
                curr=nn;
            }
            else
            {
                curr->next=nn;
                curr=curr->next;
            }
        }
        
        /*while(p!= NULL && q!= NULL){
            
            if(p->power > q->power){
                
                curr->next=p;
                curr=curr->next;
                p=p->next;
            }
            
            else if(q->power > p->power){
                
                curr->next=q;
                curr=curr->next;
                q=q->next;
            }
            
            else{
                
                curr->coeff=p->coeff + q->coeff;
                curr=curr->next;
                p=p->next;
                q=q->next;
            }
        }*/
        
        while(p!=NULL){
            node *nn = new node();
            if(result.head==NULL){
                result.head=nn;
                curr = nn;
                
            }
            else{
                curr->next = nn;
                curr = curr->next;
            }
            p=p->next;
        }
        
         while(q!=NULL){
            
           node *nn = new node();
            if(result.head==NULL){
                result.head=nn;
                curr = nn;
                
            }
            else{
                curr->next = nn;
                curr = curr->next;
            }
            q=q->next;
        }
        
        head=result.head;
    }
};
int main(){
    
    linked_list l1,l2,l3;
    l1.create_node(41,5);
    l1.create_node(22,3);
    l1.create_node(6,1);
    l2.create_node(26,6);
    l2.create_node(45,3);
    cout << "Polynomial 1: ";
    l1.print_poly();
    cout <<endl<< "Polynomial 2: ";
    l2.print_poly();
    cout<<endl << "Sum of Polynomials: ";
    l3.add_poly(&l1 , &l2);
    l3.print_poly();
    
    return 0;
    
}



