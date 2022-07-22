#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<climits>

using namespace std;

class list_node {

    public:
    string id;
    string name;
    string qua;
    string city;
    string jobtitle;
    int salary;
    string date;
    list_node* pre;
    list_node* next;

    public:

    list_node(string id, string name, string qua, string city, string jobtitle, int salary, string date){
        this->id = id;
        this->name = name;
        this->qua = qua;
        this->city = city;
        this->jobtitle = jobtitle;
        this->salary = salary;
        this->date = date;
        this->pre = NULL;
        this->next = NULL;
    }


    
};

void print_all( list_node* &head){
    if(head == NULL){
        cout<<"Record list is emppty."<<endl;
        cout<<endl;

        return ;
    }
    
    list_node* temp = head;

    while(temp != NULL){
        cout<<"Showing profile of ID : "<<temp->id<<endl;
        cout<<"Name : "<<temp->name<<endl;
        cout<<"Qualification : "<<temp->qua<<endl;
        cout<<"City : "<<temp->city<<endl;
        cout<<"Jobtitile : "<<temp->jobtitle<<endl;
        cout<<"Current salary amount : "<<temp->salary<<endl;
        cout<<"Date of joining : "<<temp->date<<endl;
        cout<<endl;
        cout<<"-----------------------------------------------------------------------------";
        cout<<endl<<endl;
        temp = temp->next;
    }
    cout<<endl;
    cout<<"ALL RECORDS ARE PRINTED."<<endl;

    return ;
}


void print_single( list_node* &head ){
    if(head == NULL){
        cout<<"List is empty. You didn't enter any data."<<endl;
        cout<<endl;
        return ;
    }
    
    cout<<"Showing profile of ID : "<<head->id<<endl;
    cout<<"Name : "<<head->name<<endl;
    cout<<"Qualification : "<<head->qua<<endl;
    cout<<"City : "<<head->city<<endl;
    cout<<"Jobtitile : "<<head->jobtitle<<endl;
    cout<<"Current salary amount : "<<head->salary<<endl;
    cout<<"Date of joining : "<<head->date<<endl;
    return ;
}


void Insert_At_Head(list_node* &head, list_node* &tail, list_node* &temp){    
    if(head == NULL){
        head = temp;
        tail = temp;
        return ;
    }

    temp->next = head;
    head->pre = temp;
    head = temp;
    return ;
}

void Insert_At_Tail(list_node* &head, list_node* &tail, list_node* &temp){    
    if(head == NULL){
        head = temp;
        tail = temp;
        return ;
    }

    tail->next = temp;
    temp->pre = tail;
    tail = temp;
    return ;
}

void Insert_after(list_node* &head, list_node* &tail, list_node* &temp, list_node* &insert){
    if( temp == tail ){
        Insert_At_Tail(head, tail, insert);
        return ;
    }

    else{
        insert->next = temp->next;
        insert->pre = temp;
        temp->next->pre = insert;
        temp->next = insert;
        return ;
    }
}
void Insert_before(list_node* &head, list_node* &tail, list_node* &temp, list_node* &insert){
    if( temp == head){
        Insert_At_Head(head, tail, insert);
        return ;
    }

    else {
        insert->next = temp;
        insert->pre = temp->pre;
        temp->pre->next = insert;
        temp->pre = insert;
        return ;
    }

}

void delete_node(list_node* &head, list_node* &tail, list_node* &temp ){
    if( temp == head && head == tail){
        delete temp;
        head == NULL;
        tail == NULL;

        return ;
    }
    
    else if( temp == head){
        head = head->next;
        head->pre = NULL;
        temp->next = NULL;
        delete temp;
        return ;
    }

    else if( temp == tail){
        tail = tail->pre;
        tail->next = NULL;
        temp->pre = NULL;
        delete temp;
        return ;
    }

    else{
        list_node* prev = temp->pre;
        list_node* nxt = temp->next;
        prev->next = nxt;
        nxt->pre = prev;
        temp->pre = NULL;
        temp->next = NULL;
        delete temp;

        return ;
    }

}

list_node* give_node( list_node* &head, string ID ){
    if( head == NULL){
        cout<<"There are no entries available."<<endl;
        return head;
    }

    list_node* temp = head;
    while( temp != NULL){
        if(temp->id == ID){
            return temp;
        }

        temp = temp->next;
    }

    return temp;
}

vector<list_node*> search_name( list_node* &head, string give_name){
    list_node* temp = head;

    vector<list_node*> ans;
    ans.clear();

    if(head == NULL)
        return ans;

    while(temp != NULL){
        if(give_name == temp->name){
            ans.push_back(temp);
        }

        temp = temp->next;
    }

    return ans;
}
vector<list_node*> search_qua(list_node* &head, string give_qua){
    list_node* temp = head;

    vector<list_node*> ans;
    ans.clear();

    if(head == NULL)
        return ans;

    while(temp != NULL){
        if(give_qua == temp->qua){
            ans.push_back(temp);
        }

        temp = temp->next;
    }

    return ans;
}


vector<list_node*> search_city(list_node* &head, string give_city){
    list_node* temp = head;

    vector<list_node*> ans;
    ans.clear();

    if(head == NULL)
        return ans;

    while(temp != NULL){
        if(give_city == temp->city){
            ans.push_back(temp);
        }

        temp = temp->next;
    }

    return ans;
}


vector<list_node*> search_date(list_node* &head, string give_date){
    list_node* temp = head;

    vector<list_node*> ans;
    ans.clear();

    if(head == NULL)
        return ans;

    while(temp != NULL){
        if(give_date == temp->date){
            ans.push_back(temp);
        }

        temp = temp->next;
    }

    return ans;
}


vector<list_node*> search_jobtitle(list_node* &head, string give_jobtitle){
    list_node* temp = head;

    vector<list_node*> ans;
    ans.clear();

    if(head == NULL)
        return ans;

    while(temp != NULL){
        if(give_jobtitle == temp->jobtitle){
            ans.push_back(temp);
        }

        temp = temp->next;
    }

    return ans;
}

void update_record( list_node* &temp){
    char inp;
    cout<<"Do you want to update name of the employee [Y/N] : ";
    cin>>inp;
    if(inp == 'Y' || inp == 'y'){
        string n;
        cout<<"Enter new name : ";
        cin>>n;

        temp->name = n;
    }
    
    cout<<"Do you want to update qualification of the employee [Y/N] : ";
    cin>>inp;
    if(inp == 'Y' || inp == 'y'){
        string n;
        cout<<"Enter new qualification : ";
        cin>>n;

        temp->qua = n;
    }

    
    cout<<"Do you want to update city of the employee [Y/N] : ";
    cin>>inp;
    if(inp == 'Y' || inp == 'y'){
        string n;
        cout<<"Enter new city name : ";
        cin>>n;

        temp->city = n;
    }
    
    cout<<"Do you want to update jobtitle of the employee [Y/N] : ";
    cin>>inp;
    if(inp == 'Y' || inp == 'y'){
        string n;
        cout<<"Enter new jobtitle : ";
        cin>>n;

        temp->jobtitle = n;
    }
    
    cout<<"Do you want to update salary of the employee [Y/N] : ";
    cin>>inp;
    if(inp == 'Y' || inp == 'y'){
        int n;
        cout<<"Enter new salary : ";
        cin>>n;

        temp->salary = n;
    }

    cout<<"Do you want to update date of joining of the employee [Y/N] : ";
    cin>>inp;
    if(inp == 'Y' || inp == 'y'){
        string n;
        cout<<"Enter new date of joining : ";
        cin>>n;

        temp->date = n;
    }
}




int main(){

    list_node* record = NULL;
    list_node* head = record;
    list_node* tail = record;

    while(1){
        int a;
        cout<<"WELCOME TO EMPLOYEE RECORD SYSTEM "<<endl;
        cout<<"    1-> Add a record "<<endl;
        cout<<"    2-> Search a record "<<endl;
        cout<<"    3-> Update a record "<<endl;
        cout<<"    4-> Delete a record "<<endl;
        cout<<"    5-> Display a record "<<endl;
        cout<<"    6-> Display all records "<<endl;
        cout<<"    7-> Exit "<<endl<<endl;
        cout<<"Enter your choice : ";
        cin>>a;

        while( a<1 || a>7) {
            cout<<"Invalid command. Please give choice among above commands."<<endl<<endl;
            cout<<"Enter yout choice : ";
            cin>>a;
            if( a > 0 && a < 8)
                break;
        }

        while( a == 1 && 1){
            int b;

            cout<<"    1-> Add record to very first"<<endl;
            cout<<"    2-> Add record to very last"<<endl;
            cout<<"    3-> Add record after ID number"<<endl;
            cout<<"    4-> Add record before ID number"<<endl;
            cout<<"    5-> Return to main menu"<<endl;
            cout<<"Enter your choice : ";

            cin>>b;
            while( b<1 || b>5) {
                cout<<"Invalid command. Please give choice among above commands."<<endl<<endl;
                cout<<"Enter yout choice : ";
                cin>>b;
                if( b > 0 && b < 6)
                    break;
            }

            if( b == 5 ){
                cout<<endl;
                break;
            }

            string id;
            string name;
            string qua;
            string city;
            string jobtitle;
            int salary;
            string date;
            cout<<endl;
            cout<<"Welcome ! you are wishing to save a new profile "<<endl;
            cout<<"Give a ID number for new candidate : ";
            cin>>id;
            cout<<"Enter the name of candidate : ";
            cin>>name;
            cout<<"Enter the qualification of candidate : ";
            cin>>qua;
            cout<<"Enter the city of candidate : ";
            cin>>city;
            cout<<"Enter the jobtitle of candidate : ";
            cin>>jobtitle;
            cout<<"Enter the date of joining : ";
            cin>>date;
            cout<<"What is the salary amount : ";
            cin>>salary;
            cout<<endl;

            list_node* temp = new list_node(id, name, qua, city, jobtitle, salary, date);

            if( b == 1 ){
                Insert_At_Head(head, tail, temp);
                continue;
            } 

            if(b == 2){
                Insert_At_Tail(head, tail, temp);
                continue;
            }
            if(b == 3){
                string i;
                cout<<"Give ID number which next you want to add new record : ";
                cin>>i;

                list_node* temp2 = give_node(head, i);

                if(temp2 == NULL){
                    cout<<"No record exist with this ID."<<endl;
                    cout<<endl;
                }

                else{
                    Insert_after(head, tail, temp2, temp);
                }
                continue;
            }
            if(b == 4){
                string i;
                cout<<"Give ID number which before you want to add new record : ";
                cin>>i;

                list_node* temp2 = give_node(head, i);

                if(temp2 == NULL){
                    cout<<"No record exist with this ID."<<endl;
                    cout<<endl;
                }

                else{
                    Insert_before(head, tail, temp2, temp);
                }
                continue;
            }


            
    
        }

        while( a == 2 && 1 ){
            vector<list_node*> ans;
            ans.clear();

            cout<<endl;
            cout<<"    1-> Search for name"<<endl;
            cout<<"    2-> Search for jobtitle"<<endl;
            cout<<"    3-> Search for qualification"<<endl;
            cout<<"    4-> Search for city"<<endl;
            cout<<"    5-> Search for date of joining"<<endl;
            cout<<"    6-> Return to main menu"<<endl;
            cout<<endl;

            int y;
            cout<<"Enter your choice : ";
            cin>>y;

            while( y<1 || y>6){
                cout<<"Invalid command"<<endl;
                cout<<"Enter your choice : ";
                cin>>y;

                if( y>0 && y<7)
                    break;
                
            }

            if( y == 6 ){
                break ;
            }

            if(y == 1){
                cout<<endl;
                string give_name;
                cout<<"Enter the name : ";
                cin>>give_name;
                ans = search_name(head, give_name);

                if(ans.empty()){
                    cout<<endl;
                    cout<<"There are no records for this name.";
                    cout<<endl;
                }

                else {
                    cout<<"Here are the IDs for the given name"<<endl;
                    for(int i = 0; i<ans.size(); i++){
                        cout<<ans[i]->id<<"  ";
                    }
                    cout<<endl;
                }
                continue;
            }
            if( y == 2){
                cout<<endl;
                string give_jobtitle;
                cout<<"Enter the jobtitle : ";
                cin>>give_jobtitle;
                ans = search_jobtitle(head, give_jobtitle);

                if(ans.empty()){
                    cout<<endl;
                    cout<<"There are no records for this jobtitle.";
                    cout<<endl;
                }

                else {
                    cout<<"Here are the IDs for the given jobtitle"<<endl;
                    for(int i = 0; i<ans.size(); i++){
                        cout<<ans[i]->id<<"  ";
                    }
                    cout<<endl;
                }
                continue;
            }
            if(y == 3){
                cout<<endl;
                string give_qua;
                cout<<"Enter the qualification : ";
                cin>>give_qua;
                ans = search_qua(head, give_qua);

                if(ans.empty()){
                    cout<<endl;
                    cout<<"There are no records for this qualification.";
                    cout<<endl;
                }

                else {
                    cout<<"Here are the IDs for the given qualification"<<endl;
                    for(int i = 0; i<ans.size(); i++){
                        cout<<ans[i]->id<<"  ";
                    }
                    cout<<endl;
                }
                continue;
            }
            if(y == 4){
                cout<<endl;
                string give_city;
                cout<<"Enter the city name : ";
                cin>>give_city;
                ans = search_city(head, give_city);

                if(ans.empty()){
                    cout<<endl;
                    cout<<"There are no records for this city name.";
                    cout<<endl;
                }

                else {
                    cout<<"Here are the IDs for the given city name"<<endl;
                    for(int i = 0; i<ans.size(); i++){
                        cout<<ans[i]->id<<"  ";
                    }
                    cout<<endl;
                }
                continue;
            }
            if(y == 5){
                cout<<endl;
                string give_date;
                cout<<"Enter the date of joining : ";
                cin>>give_date;
                ans = search_date(head, give_date);

                if(ans.empty()){
                    cout<<endl;
                    cout<<"There are no records for this date of joining.";
                    cout<<endl;
                }

                else {
                    cout<<"Here are the IDs for the given date of joining"<<endl;
                    for(int i = 0; i<ans.size(); i++){
                        cout<<ans[i]->id<<"  ";
                    }
                    cout<<endl;
                }
                continue;
            }
        }

        while( a == 3 && 1 ){
            string i;
            cout<<"Enter the ID number of the employee whose record you want to update : ";
            cin>>i;
            list_node* temp = give_node(head, i);
            if( temp == NULL){
                cout<<"There are no record present with this id."<<endl;
                continue;
            }

            else{
                update_record(temp);
                cout<<"record updated successfully."<<endl;
                cout<<endl;
                break;
            }
        }

        if(a == 4){
            cout<<endl;
            string id;
            cout<<"Give ID number of the record which you want to delete : ";
            cin>>id;

            list_node* temp = give_node(head, id);

            if(temp == NULL){
                cout<<"There are no record present with this id."<<endl<<endl;
            }

            else{
                delete_node(head, tail, temp);
                cout<<"Record with ID "<<id<<" has been deleted. "<<endl<<endl;
            }
        }

        if( a == 5 ){
            cout<<endl;
            string id;
            cout<<"Give ID number of the record which you want to print : ";
            cin>>id;

            list_node* temp = give_node(head, id);

            if(temp == NULL){
                cout<<"There are no record present with this id."<<endl;
            }

            else {
                cout<<endl;
                cout<<"##################################################################################"<<endl;
                print_single(temp);
                cout<<"##################################################################################"<<endl;
                cout<<endl;
            }
        }

        if( a == 6 ){
            cout<<endl;
            cout<<"##################################################################################";
            cout<<endl;
            cout<<"PRINTING ALL RECORDS : "<<endl<<endl;
            print_all(head);
            cout<<endl<<"##################################################################################"<<endl;
            cout<<endl;
        }


        if(a == 7)
            break;
    }

    cout<<"EXIT BUTTON PRESSED. CODE ENDED"<<endl;

    return 0;
}