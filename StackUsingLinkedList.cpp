#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *next; 
    node(){}
    node(int data): data(data), next(nullptr){}
};

void push_(int data, node **head){
    if (*head==nullptr){
        node *ptr = new node(data);
        *head = ptr;
        return; 
    }
    node *ptr = new node(data);
    ptr->next=*head;
    *head=ptr;
}

bool isEmpty(node **head){
    return *head==nullptr;
}

void pop_(node **head){
    if(isEmpty(head)){
        return; 
    }
    *head=(*head)->next; 
}

int top_(node **head){
    if(isEmpty(head)){
        return -1;
    }
    return (*head)->data;
}


void display(node **head){
    node *temp = *head;
    while (temp!=nullptr)
    {
        cout<<temp->data<< " ";
        temp=temp->next;
    }
    cout<< endl; 
}

int main(){
    node *head;
    head = nullptr;
    // push_(5,&head); 
    // push_(7,&head);
    // push_(9,&head);
    // pop_(&head); 
    // pop_(&head); 
    // pop_(&head); 
    // pop_(&head); 
    // display(&head);
    string str;
    cin>>str;
    int flag=0; 
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i]==']' || str[i]==')' || str[i]=='}'){
            if(isEmpty(&head) || (str[i]==']' && top_(&head)!='[') || (str[i]=='}' && top_(&head)!='{') || (str[i]==')' && top_(&head)!='(') ){
                flag=1;
                break;
            }
            pop_(&head);
        }
        else    push_(str[i],&head);
    }
    if(flag || !isEmpty(&head)) cout<< "Invalid"<< endl;
    else    cout<< "Valid"<< endl;    
}