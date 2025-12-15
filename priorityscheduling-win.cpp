#include<iostream>
#include<algorithm>
#include<vector>
#include <iomanip>

using namespace std;

int64_t i,j,n,num;

void largeInput();
void breakFunction();

void heroArea(){
    cout << "\t\t-------------------------------------------------\n";
    cout << "\t\t|\tPriority Based Meeting Scheduler\t|\n";
    cout << "\t\t-------------------------------------------------\n";
}

void endProgram() {
    heroArea();
    cout << "\n\tHave a great day ahead...";
    cout << "\n\n";
    breakFunction();
    system("cls");
    exit(0);
}

void breakFunction(){
    cout << "\n\n\tPress Enter button to continue.. ";
    cin.ignore();
    cin.get();
}

void smallInput(){
    heroArea();
    cout << "\n\n\tHow many meetings? ( Only 1 to 10 ): ";
    cin >> n;

    if(n <=10){
        cout << "hello!";

    }else{
        system("cls");
        cout << "\n\tNot a valid input! It should be less than 10 inputs.\n";
    }

}

void largeInput() {
    heroArea();
    cout << "\n\n\tHow many meetings? ( Only 10+ ): ";
    cin >> n;

    if(n>=10){
        cout << "world!";
        
    }else{
        system("cls");
        cout << "\n\tNot a valid input! It should be more than 10 inputs.\n";
    }
}

int main(){
    system("cls");
    while(1){
        heroArea();
        cout << "\n\n\tSelect your Preferable Option:";
        cout << "\n\t\t1. 0-10 Meetings";
        cout << "\n\t\t2. 10+ Meetings";
        cout << "\n\t\t0. Exit";
        cout << "\n\n\t\t";

        cin >> n;
        switch (n)
        {
        case 1 : system("cls"); smallInput(); breakFunction(); system("cls"); break;
        case 2 : system("cls"); largeInput(); breakFunction(); system("cls"); break;
        case 0 : system("cls"); endProgram(); break;
        default:
            system("cls");
            cout << "\n\n\tNot a valid choice. Kindly select again!\n\n";
            break;
        }
    }
    
}

