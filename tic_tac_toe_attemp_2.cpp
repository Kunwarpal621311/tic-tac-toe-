#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

class game {
    char arr[3][3];
    char turn ;
    int draw;
    string user1,user2;
    public:


    game(){
    char num=49;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]=num;
            num++;
        }
    }
    turn='x';
    draw=1;
    cout<<"ENTER THE FIRST USER NAME : ";
    cin>>user1;
    cout<<"ENTER THE second  USER NAME : ";
    cin>>user2;
}

    void display(){
        system("CLS");
cout<<"-----------------------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t\t   tic tac toe"<<endl;
cout<<"-----------------------------------------------------------------------------------------------"<<endl;

    cout<<"\t\t\t\t\t     |     |     "<<endl;;
    cout<<"\t\t\t\t\t  "<<arr[0][0]<<"  | "<<arr[0][1]<<"   |  "<<arr[0][2]<<endl;
    cout<<"\t\t\t\t\t_____|_____|_____"<<endl;;
    cout<<"\t\t\t\t\t     |     |     "<<endl;
    cout<<"\t\t\t\t\t  "<<arr[1][0]<<"  | "<<arr[1][1]<<"   |  "<<arr[1][2]<<endl;;
    cout<<"\t\t\t\t\t_____|_____|_____"<<endl;;
    cout<<"\t\t\t\t\t     |     |     "<<endl;;
    cout<<"\t\t\t\t\t  "<<arr[2][0]<<"  | "<<arr[2][1]<<"   |  "<<arr[2][2]<<endl;;
    cout<<"\t\t\t\t\t     |     |     "<<endl;;
    }
    void play_turn();
    bool win();
    void  winner(){
        if(turn=='0' && draw==1){
            cout<<user1<<" win"<<endl;
        }
        else if (turn=='x' && draw==1){
              cout<<user2<<" win"<<endl;
        }
        else {
            cout<<" GAME DRAW "<<endl;
        }
       
        }
        ~game(){}
        
       
        
    };
   



int main(){
    system("CLS");
    game obj;
    while (obj.win()){
        obj.display();
        obj.play_turn();

    }
    obj.winner();
 
    

    
    
 
 
return 0;
}
void game::play_turn(){
int  index;
     string mapping[]={" ","00","01","02","10","11","12","20","21","22"};
    
   
    if(turn=='x'){
        cout<<user1<<" turn "<<endl;
    }
    else if(turn=='0'){
        cout<<user2<<" turn "<<endl;

    }
    cin>>index;
    string selected=mapping[index];
    int i=selected[0]-'0';
    int j=selected[1]-'0';
   

    if(arr[i][j]!='x'&& arr[i][j]!='0' && turn=='x'){
    arr[i][j]='x';
    turn='0';
    }
   else if(arr[i][j]!='x'&& arr[i][j]!='0' && turn=='0'){
    arr[i][j]='0';
    turn='x';
    }
    else{
        cout<<"not a valid input"<<endl;
        play_turn();
    }
    display();
}



bool game::win(){
for(int i=0;i<3;i++){
    if((arr[0][i]==arr[1][i]) && (arr[0][i]==arr[2][i])  )
    return false;
}
for(int i=0;i<3;i++){
    if((arr[i][0]==arr[i][1]) && (arr[i][0]==arr[i][2])  )
    return false;
}
if(((arr[0][0]==arr[1][1])&& (arr[0][0]==arr[2][2])) || ((arr[0][2]==arr[1][1])  && (arr[0][2]==arr[2][0]))){
    return false;
}

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(arr[i][j]!='x'  &&  arr[i][j]!='0'){
            return true;
        }
    }
}

draw=0;
return false;
}















