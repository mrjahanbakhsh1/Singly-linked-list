#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct node {
    int          data;
    struct node  *next;
}*start;

node *create_node(int myData)
{
    struct  node *n , *s;
    
    n = new(struct node); 
    if (n == NULL) {
        cout<<"not allocated "<<endl;
        return 0;
    }
    else {
        n->data = myData;
        n->next = NULL;  
		   
        return n;
    }
}

void insert_From_Start()
{
    struct node *n, *p;
    int value;
    cout << "value : ";
    cin >> value;

    n = create_node(value);
    
    if (start == NULL) {
    start = n;
    start->next = NULL;          
    }else {
    p = start;
    start = n;

    start->next = p;
    }
}


void insert_From_Last() {
    struct node *n, *s;
    int value;
    cout << "value : ";
    cin >> value;

    n = create_node(value);

	s = start;     
    while (s->next != NULL)
    {         
        s = s->next;        
    }

    n->next = NULL;
    s->next = n;
}
  
void insert_Special_Pos(){
    struct node *n, *s, *p;
	int value, pos, c = 0; 
    cout << "value : ";
    cin >> value;
        
        
    n = create_node(value);
        
    cout<<"position : ";
    cin>>pos;
        
    int i;
    s = start;
        
    while (s != NULL)
    {
        s = s->next;
        c++;
    }
        
    if (pos == 1)
    {
        if (start == NULL)
        {
            start = n;
            start->next = NULL;
        }else {
            p = start;
            start = n;
            start->next = p;
        }

    }else if (pos > 1  && pos <= c) {

        s = start;
        for (i = 1; i < pos; i++)
        {
            p = s;
            s = s->next;
        }
        p->next = n;
        n->next = s;

    }else {
        cout<<"OUT OF RANGE!"<<endl;
    }
}

void del_Special_Pos() {
    struct node  *s ,*p;
	int pos,i,c=0;

    if (start == NULL) return;
        
	cout << "position: ";
    cin  >> pos;
        
    s = start;
    if (pos == 1) 
		start = s->next;
    else{

        while (s != NULL) {
            s = s->next;
            c++;  
        }
            
        if (pos>=2 && pos<=c) {
            s = start;
            for (i=1; i<=pos-1; i++) 
			{
                p = s;
                s = s->next;
            }
            p->next = s->next;
        }
        else {
            cout<<"out of range"<<endl;
        }

        free(s);
    }
}

void show() {
    struct node *t;
    if (start == NULL) {
        cout<<"Empty"<<endl;
        return;
    }

    t = start;
    cout<<"Elements: "<<endl;
        
	while (t != NULL) {
        cout << "|" << t->data << "|" << t << "|" << "->";
        t = t->next;
    }

    cout<<"NULL"<<endl;
}

int main() 
{
    int x;
    start=NULL;
   
    insert_From_Start();
    insert_From_Start();
    insert_From_Start();

    insert_From_Last();
    insert_From_Last();

    cout << "\n*show list with inserted values* \n";
    show();

    cout << "\n*Delete special position* \n";
    del_Special_Pos();
    del_Special_Pos();

    cout << "\n*show list with deleted values* \n";
    show();

    cout << "\n*Insert special position* \n";
    insert_Special_Pos();
    cout << "\n*show list with insert special position values* \n";
    show();
        
    getch();
}
// Mohammad reza jhanbakhsh