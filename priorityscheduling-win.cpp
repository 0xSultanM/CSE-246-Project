#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iomanip>

// git add README.md priorityscheduling.cpp priorityscheduling-win.cpp
// git commit -m "Priority Based Meeting Scheduler"
// git push origin main

using namespace std;

int64_t i,j,n,num;

struct priorityScheduling
{
    int meetingID;
    double startTime;
    double endTime;
    double duration;
    double multiplier;
    double payment;
    double priorityLVL;
};


void largeInput();
void breakFunction();
void printMeetings(vector<priorityScheduling> inputPS, int n);

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

bool compare(priorityScheduling a, priorityScheduling b){
    return a.priorityLVL > b.priorityLVL;
}

bool comparePS(priorityScheduling a, priorityScheduling b){
    return a.startTime < b.startTime;
}

void smallInput(){
    heroArea();
    cout << "\n\n\tHow many meetings? ( Only 1 to 10 ): ";
    cin >> n;

    if(n <=10 && n >> 0){
        system("cls");
        heroArea();

        vector<priorityScheduling> inputPS(n);

        cout << "\n\tMake sure to type the meeting time as follow ( From 10:00 to 18:00 ):\n\t\t01) Type 11.00 for 11:00 AM\n\t\t02) Type 18.00 for 06:00 PM\n\n\tNote: We don't support 11:30 AM or 02:30 PM slot for meeting!\n";
        cout << "\n\tBase amount is 1000, so you can select the multiplier based on your budget!\n\t\t 01) Type 1.0 to pay 1000\n\t\t 02) Type 1.2 to pay 1200\n\t\t 03) Type 1.5 to pay 1500\n\t\t 04) Type 2.2 to pay 2000";
        breakFunction();

        for(i=0;i<n;i++){
            system("cls");
            heroArea();
            cout << "\n\tEnter the Job details:";
            inputPS[i].meetingID = i+1;
            while (1){
                cout << "\n\t\tStart Time: ";
                cin >> inputPS[i].startTime;
                if((inputPS[i].startTime - floor(inputPS[i].startTime)) != 0.0 || inputPS[i].startTime < 10.00 || inputPS[i].startTime > 17.00){
                    cout << "\t\tNot Valid Time. Type again between 10:00 to 17:00 !!\n";
                } else {
                    break;
                }
            }
            
            while(1){
                cout << "\t\tEnd Time: ";
                cin >> inputPS[i].endTime;
                if((inputPS[i].endTime - floor(inputPS[i].endTime)) != 0.0 || inputPS[i].endTime < inputPS[i].startTime || inputPS[i].endTime > 18.00 || inputPS[i].endTime < 11.00){
                    cout << "\t\tNot valid ending time, must be more than start time and less than 18:00 !!\n";
                }else{
                    break;
                }
            }

            inputPS[i].duration = inputPS[i].endTime - inputPS[i].startTime;

            while(1){
                cout << "\t\tMultiplier (1.0 / 1.1 / 1.2 / 1.5 / 2.0 ): ";
                cin >> inputPS[i].multiplier;
                if(inputPS[i].multiplier == 1.0 || inputPS[i].multiplier == 1.1 || inputPS[i].multiplier == 1.2 || inputPS[i].multiplier == 1.5 || inputPS[i].multiplier == 2.0){
                    break;
                }else{
                    cout << "\t\tNot Valid Multiplier.\n";
                }
            }

            inputPS[i].payment = 1000 * inputPS[i].multiplier;
            inputPS[i].priorityLVL = inputPS[i].payment / (inputPS[i].duration * 60);
        }

        stable_sort(inputPS.begin(), inputPS.end(), compare);
        printMeetings(inputPS,n);

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
        
        
    }else{
        system("cls");
        cout << "\n\tNot a valid input! It should be more than 10 inputs.\n";
    }
}

void printMeetings(vector<priorityScheduling> inputPS, int n){

    vector<priorityScheduling> finalPS;

    finalPS.push_back(inputPS[0]);

    int lastSelected = 0;

    for(i=1;i<n;i++){
        if(inputPS[i].startTime >= inputPS[lastSelected].endTime){
            finalPS.push_back(inputPS[i]);
            lastSelected = i;
        }
    }

    int index = 0;

    for(i=0;i<n;i++){
        if(inputPS[i].endTime <= finalPS[index].startTime){
            finalPS.push_back(inputPS[i]);
            index = finalPS.size()-1;
        }
    }

    system("cls");
    heroArea();
    cout<< "\n\n";
    cout << left << setw(12) << "\tSlot No" << setw(12) << "Meeting ID" << setw(12) << "Start Time" << setw(12) << "End Time" << setw(12) << "Payment Amount";
    cout << "\n";
    cout<< left << setw(12) << "\t-------" << setw(12) << "----------" << setw(12) << "----------" << setw(12) << "--------" << setw(12) << "--------------";
    cout << "\n";

    for(i=0;i<finalPS.size();i++){
        cout<< left << "\t" << setw(12) << i+1 << setw(12) << finalPS[i].meetingID << setw(12) << finalPS[i].startTime << setw(12) << finalPS[i].endTime << setw(12) << finalPS[i].payment << "\n";
    }

    stable_sort(finalPS.begin(),finalPS.end(),comparePS);

    cout << "\n\n\tSorted list of Scheduled Meetings:\n";
    cout << "\t----------------------------------\n\n";
    cout << left << setw(12) << "\tSlot No" << setw(12) << "Meeting ID" << setw(12) << "Start Time" << setw(12) << "End Time" << setw(12) << "Payment Amount";
    cout << "\n";
    cout<< left << setw(12) << "\t-------" << setw(12) << "----------" << setw(12) << "----------" << setw(12) << "--------" << setw(12) << "--------------";
    cout << "\n";

    for(i=0;i<finalPS.size();i++){
        cout<< left << "\t" << setw(12) << i+1 << setw(12) << finalPS[i].meetingID << setw(12) << finalPS[i].startTime << setw(12) << finalPS[i].endTime << setw(12) << finalPS[i].payment << "\n";
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
        cout << "\n\n\tInput: ";

        cin >> n;
        switch (n)
        {
        case 1 : system("cls"); smallInput(); breakFunction(); system("cls"); break;
        case 2 : system("cls"); largeInput(); breakFunction(); system("cls"); break;
        case 0 : system("cls"); endProgram(); break;
        default:
            system("cls");
            cout << "\n\n\tNot a valid choice. Kindly select again!\n\n";
            breakFunction();
            break;
        }
    }
    
}