#include "Zadania.hpp"

int Task::AmountOfTask=0;

void Task::AddTPripare(int Time1){

    TimeOfPripare=Time1;
}

void Task::AddTExecution(int Time1){

    TimeOfExecution=Time1;
}

void Task::AddStartMoment(int Time1){

    StartMoment=Time1;
}

void Task::AddTermiantion(int Time1){

    Termiantion=Time1;
}



int Task::ShowValueOfVariable(char FirstLetter){

    if(FirstLetter=='P'){
        return TimeOfPripare;
    }
    else if(FirstLetter=='E')
    {
        return TimeOfExecution;
    }
    else if(FirstLetter=='I')
    {
        return IdOfTask;
    }
    else if(FirstLetter=='M')
    {
        return StartMoment;
    }
    else if(FirstLetter=='T')
    {
        return Termiantion;
    }
    else
    {
    std::cout <<" Wrong choice of parametr in Task::ShowValueOfVariable";
    exit(0);
    }
    

}