#include<iostream>
using namespace std;
class browsing_history{
    
    string s1[10];
    int t1=-1;
    
    public:
    
    void visited_page(string s){

        if(t1<9){
             t1++;
            s1[t1]=s;
           
        }
       
    }

    void navigate_back(){

        string d=s1[t1];
        t1--;
        cout<<s1[t1];
        cout<<endl;
    }

    void current_page(){

        cout<<s1[t1];
        t1--;
        cout<<endl;
    }
    void check(){
        
        if(t1==-1){
            cout<<"the history is empty.";
        }
    }
    void show(){
        
        for(int i=t1;i>=0;i--){
            cout<<s1[i]<<endl;
        }
    }
};
int main(){
     
  browsing_history x;
  int choice;
  string site;
  do{
      cout<<"1.ADD VISITED PAGE\n2.NAVIGATE BACK\n3.VISITED TO CURRENT PAGE\n4.CHECK IF HISTORY EMPTY OR NOT\n5.SHOW BROWSING HISTORY\n6.EXIT"<<endl;
      cout<<"enter your choice:";
      cin>>choice;
      switch(choice){
          
          case 1:
          cout<<"add the page:";
          cin>>site;
          x.visited_page(site);
          break;
          
          case 2:
          cout<<"showing the previous:"<<endl;
          x.navigate_back();
          break;

          case 3:
          cout<<"showing the current page:"<<endl;
          x.current_page();
          break;

          case 4:
          x.check();
          break;

          case 5:
          x.show();
          break;

          case 6:
          cout<<"EXIT"<<endl;
          break;
      }
      cout<<"press 1 to continue"<<endl;
      cin>>choice;
  }
  while(choice==1);
}
