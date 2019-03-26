#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class nod
{
    char info;
    nod *next;

public:
    char getNumber()
    {
        return info;
    }
    nod* getNext()
    {
        return next;
    }
    void setNext(nod *next)
    {
        this->next=next;
    }
    friend class stack;
};


class stack
{
private:
    nod *top;
public:
    stack()
    {
        top=NULL;
    }
    nod* getTop() const
    {
        return top;
    }
    void push(char a );
    void pop();
    void topS();
    void Reverse(istream &in);
    friend ostream  &operator << (ostream &os, const stack &s1);
    friend istream  &operator >> (istream &,stack &);
    stack operator - (stack&);
    ~stack();

};

ostream &operator << (ostream &output,const stack& s1)
{
    nod *temp;
    temp=new nod;
    temp=s1.top;
    while(temp!=NULL)
    {
        output<<temp->getNumber()<<endl;
        delete temp;
        temp=temp->getNext();
    }
    delete temp;
    output<<endl;
    return output;
}

istream &operator >> (istream &input,stack &st)
{
    int n;
    input>>n;

    for (int i=0; i<n; i++)
    {
        char a;
        input>>a;
        st.push(a);
    }
    return input;
}

void stack :: Reverse(istream &in)
{
    nod *temp;
    temp=new nod;
    int n;
    //dam nr de caractere si apoi caracterele
    in>>n;
    for(int i=0; i<n; i++)
    {
        nod *temp;
        temp=new nod;
        in>>temp->info;
        temp->next=top;
        top=temp;
    }
}

stack stack::operator - (stack& st)
{
    while(st.getTop()->getNumber() == this->getTop()->getNumber())
    {
        st.pop();
        this->pop();
    }

    return *this;
}


void stack :: push(char a )
{
    nod *temp;
    temp=new nod;
    temp->info=a;
    temp->next=top;
    top=temp;
    cout<<temp->info<<" was pushed into the stack";
    cout<<endl;
}

void stack :: topS()
{
    if(top!=NULL)
    {
        cout<<top->info<<" top of the stack";
        cout<<endl;
    }
}
void stack :: pop()
{
    if(top!=NULL)
    {
        nod *temp;
        temp=new nod;
        temp=top;
        top=top->next;
        cout<<temp->info<<" deleted";
        delete temp;
        cout<<endl;
    }
}

void DisplayMenu()
{
    cout << "1. INPUT from CONSOLE " << endl;
    cout << "2. INPUT from FILE" << endl;
}

void DisplayMenu1()
{
    cout <<  "1) Push function " << endl;
    cout << "2) Pop function " << endl;
    cout << "3) Top function " << endl;
    cout << "4) - operator " << endl;
    cout << "5) Reverse stack "<<endl;
    cout << "0) EXIT " << endl << endl;
}

stack :: ~stack()
{
    while(top!=NULL)
    {
        nod *temp=top;
        top=top->next;
        delete temp;
    }
}


int main()
{
    stack Stack,Stack1;
    ifstream f("file.in");
    int opt1;
    cout<<  "Choose your option for input:  " <<endl<<endl;
    DisplayMenu();
    cin>>opt1;

    switch(opt1)
    {
    case 1 :

        int opt2;
        cout<<endl;
        cout<<  "Choose your option to operate on stack :  " <<endl;
        DisplayMenu1();
        cin>>opt2;
        while(opt2)
        {
            switch(opt2)
            {
            case 0:
                break;
            case 1:
                cout<<"Number of characters: ";
                cin>>Stack;
                break;
            case 2 :
                Stack.pop();
                break;
            case 3 :
                Stack.topS();
                break;
            case 4:
            {
                stack Stack1; //dam nr de caractere si apoi caracterele
                cin>>Stack1;
                Stack-Stack1;
                cout<<Stack;
                break;
            }
            case 5:
                Stack.Reverse(cin); //citire consola
                cout<<Stack;
                break;
            }
            cout << "Choose your option to operate on stack :  " << endl << endl;
            DisplayMenu1();
            cin>>opt2;

        }
        break;

    case 2 :

        cout<<  "Choose your option to operate on stack :  " << endl << endl;
        DisplayMenu1();
        cin>>opt2;
        while(opt2)
        {

            switch(opt2)
            {

            case 0:
                break;
            case 1:
                f >> Stack;
                break;
            case 2 :
                Stack.pop();
                //cout << Stack;
                break;
            case 3 :
                Stack.topS();
                break;
            case 4:
            {
                stack stack1;
                f >> stack1;
                Stack - stack1;
                cout << Stack;
                break;
            }
            case 5:
                Stack.Reverse(f);  //citire fisier
                cout << Stack;
                break;
            }
            cout << "Choose your option to operate on stack :  " << endl << endl;
            DisplayMenu1();
            cin>>opt2;

        }
        f.close();
        break;

    }
    return 0;
}


