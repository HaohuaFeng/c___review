#include "circular_sorted_linked_list.cpp"

int main(){
    cslist<int> list;
    int user_input;
    do{
        cout<<"\ncircular sorted linked list\n"
        <<"Enter number to perform operation:\n"
        <<"1. insert given value\n"
        <<"2. remove first occurrences\n"
        <<"3. remove all occurrences\n"
        <<"4. search given value\n"
        <<"5. check if list is empty\n"
        <<"6. get length of list\n"
        <<"7. print list\n"
        <<"8. count occurrences of a given value\n"
        <<"0. exit\n\n"
        <<"Enter a number(accept integer only): ";
        cin>>user_input;
        int value;
        switch (user_input) {
            case 1:
                cout<<"Enter a value to insert(accept integer only): ";
                cin>>value;
                list.insert(value);
                break;
            case 2:
                cout<<"Enter a value to remove(accept integer only): ";
                cin>>value;
                list.remove(value);
                break;
            case 3:
                cout<<"Enter a value to remove all occurrences(accept integer only): ";
                cin>>value;
                list.remove_all(value);
                break;
            case 4:
                cout<<"Enter a value to search(accept integer only): ";
                cin>>value;
                list.search(value);
                break;
            case 5:
                if(list.is_empty()){
                    cout<<"List is empty";
                } else{
                    cout<<"list is not empty";
                }
                break;
            case 6:
                cout<<"length of list is "<<list.get_length();
                break;
            case 7:
                list.print_list();
                break;
            case 8:
                cout<<"Enter a value to count(accept integer only): ";
                cin>>value;
                cout<<"occurrences: "<<list.duplicated(value);
                break;
            default:
                break;
        }
        std::cout<<"\n\n";
    } while (user_input != 0);
    return 0;
}