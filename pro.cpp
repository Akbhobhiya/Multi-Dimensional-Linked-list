
#include<iostream>
#include<iomanip>

using namespace std;

struct node
{
    string data;
    struct node *px,*py,*pz;
};
struct node *start=NULL;
struct node *prevx=start;
struct node *prevy=start;
struct node *prevz=start;

struct node *x,*y,*z,*superx,*supery,*superz;
int p,q,r,xc=1,yc=1,zc=1;
int countx,county,countz;

void insertion(string data)
{
   struct node *temp=new node;
   temp->data=data;
   temp->px=NULL;
   temp->py=NULL;
   temp->pz=NULL;

   if(start==NULL)
   {
       start=temp;
       prevx=start;
       prevy=start;
       prevz=start;
       superx=temp;
       supery=temp;
       superz=temp;

    x=temp;
   y=temp;
   z=temp;

  // cout<<"\nfirst insertion";
   }
   else
   {
      /* if(xc==p && yc==q && zc==r)
       {
           cout<<".\nNO mare insertion it is full";
       }*/
      if(xc==p && yc==q)
     {
     //    cout<<"\ninsertion going above";
         xc=1;yc=1;

     //   cout<<"\ni m ok";
        z->pz= temp;
        z=temp;
        y=temp;
        x=temp;
        zc=zc+1;
        prevx=temp;
         prevy=temp;
         prevz=temp;
         superx=superz->px;
         supery=superz->py;
         superz=superz->pz;

     }
      else if(xc==p)
      {
     //     cout<<"\ninsertion going next line";
          xc=1;
          y->py=temp;
          y=temp;
          x=temp;
          yc=yc+1;
         prevx=prevy->px;
         prevy=prevy->py;
           if(zc>1)
            {
                supery->pz=temp;
                superx=supery->px;
                supery=supery->py;
            }
      }

       else if(xc<p)
       {

//cout<<"\ninsertion in a line";
       x->px=temp;

      x=temp;

      xc=xc+1;
      if(yc>1)
      {

      prevx->py=temp;

      prevx=prevx->px;
      }
      if(zc>1)
      {
         superx->pz=temp;
         superx=superx->px;

      }
      }

   }
}
int d,e;
void displayx(struct node *temp)
{  
    if(temp!=NULL)
    {
        cout<<setw(5)<<temp->data;
        displayx(temp->px);
    }
}
void disphorizantal(struct node *temp)
{
    if(temp!=NULL)
    {
       displayx(temp);
       cout<<"\n";
                while(temp->py!=NULL)
                    {
                        displayx(temp->py);
                        temp=temp->py;
                        cout<<"\n";
                    }

    }
}

void displayhorizontal(struct node *temp)
{
             while(temp!=NULL)
             {
                 cout<<"\n\n";
                 disphorizantal(temp);
                 temp=temp->pz;
             }
}
void displayy(struct node *temp)
{
    if(temp!=NULL)
    {
        cout<<setw(5)<<temp->data;
        displayy(temp->py);
    }
}

void dispvertical(struct node *temp)
{
    if(temp!=NULL)
    {
       displayy(temp);
       cout<<"\n";
                while(temp->px!=NULL)
                    {
                        displayy(temp->px);
                        temp=temp->px;
                        cout<<"\n";
                    }
    }
}

void displayvertical(struct node *temp)
{
while(temp!=NULL)
             {
                 cout<<"\n\n";
                 dispvertical(temp);
                 temp=temp->pz;
             }
}
void displayz(struct node *temp)
{
    if(temp!=NULL)
    {
        cout<<setw(5)<<temp->data;
        displayz(temp->pz);
    }
}
void dispinZdirection(struct node *temp)
{
    if(temp!=NULL)
    {
       displayz(temp);
       cout<<"\n";
                while(temp->py!=NULL)
                    {
                        displayz(temp->py);
                        temp=temp->py;
                        cout<<"\n";
                    }

    }
}

void displayinZdirection(struct node *temp)
{
    while(temp!=NULL)
             {
                 cout<<"\n\n";
                 dispinZdirection(temp);
                 temp=temp->px;
             }
}
struct node* search2(string data,struct node *temp)
{

    struct node *ptr;
    if(temp==NULL)
        countx=0;
  if(temp!=NULL)
    {
        if(temp->data==data)
            return temp;
        else{
          countx++;
     ptr=search2(data,temp->px);
     if(ptr!=NULL)
        return ptr;

    }
    }
    return NULL;
}
struct node* search1(string data,struct node *temp)
{
    struct node *ptr;
    //if(temp==NULL)
      county=0;
      countx=0;
    if(temp!=NULL)
    {

      ptr= search2(data,temp);
      if(ptr!=NULL)
        return ptr;

                while(temp->py!=NULL)
                    { 
                        county++;
                        ptr=search2(data,temp->py);
                        
                        if(ptr!=NULL)
                                return ptr;
                        temp=temp->py;
                    }

    }
    return NULL;
}
struct node* search(string data)
{   
	countx=county=countz=0;
    struct node *ptr;
    struct node *temp=start;
    if(temp==NULL)
      countz=0;
     while(temp!=NULL)
             {     
                     ptr=search1(data,temp);
                     
                     if(ptr!=NULL)
                        return ptr;
                 temp=temp->pz;
                 countz++;
             }
             return NULL;
}
void deletion(struct node *temp)
{
    temp->data=' ';


}



int main()
{
    int choice=1;
    cout<<"\nEnter the x-y dimensions to create 3-Dimensional Linked List\n";
    cin>>p>>q;
    //cin>>r;
    d=p;
    e=q;
    while(choice!=7)
    {
    cout<<"\nEnter your choice \n1.Insertion\n2.Display from X-link\n3.Display from Y-link\n4.Display from Z-link\n5.deletion\n6.Search\n7.Exit\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            string data;
           /*  if(xc==p && yc==q && zc==r)
       {
           cout<<".\nNO mare insertion it is full";
           break;
       }*/
            cout<<"\nEnter the data which u want to insert :: ";
            cin>>data;

            //string s=to_string(data);
            insertion(data);
            break;
        }
    case 2:
        {
            displayhorizontal(start);
            break;
        }
    case 3:
        {
            displayvertical(start);
            break;
        }
    case 4:
        {
            displayinZdirection(start);
            break;
        }
    case 5:
        {
            string data;
            cout<<"\nEnter the data which you want to delete:: ";
            cin>>data;
            struct node *temp=search(data);
            if(temp!=NULL)
            deletion(temp);
            else
                cout<<"\n::::the element is not there to delete:::::";
            break;
        }
    case 6:
        {
            string data;
            cout<<"\nEnter the data which you want to search ()  :: ";
            cin>>data;
            struct node *temp=search(data);
            if(temp==NULL)
                cout<<"\nData not found";
            else
               
               {
                cout<<"\nThe data is found is at [ "<<countx<<","<<county<<","<<countz<<" ]";
                countz=county=countx=0;
               }
             break;
        }

        case 7:cout<<"Programme is terminated\n";break;
        default:cout<<"\nWrong entry::\n";
    }
  }

    return 0;
}
