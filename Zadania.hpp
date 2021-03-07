#ifndef Zadania_hpp
#define Zadania_hpp

#include <iostream>
class Task{
    static int AmountOfTask;
    int IdOfTask;
    int TimeOfPripare;
    int TimeOfExecution;
    int StartMoment;
    int Termiantion;
    int PositionInQueue;
    
public:
    Task(){
        IdOfTask=++AmountOfTask;
        TimeOfPripare=0;
        TimeOfExecution=0;
        StartMoment=0;
        Termiantion=0;
        PositionInQueue=0;
    }

    void AddTPripare(int Time1);
    void AddTExecution(int Time1);
    void AddPosition(int position);
    void AddStartMoment(int TimeTerminationPreviousTask);
    void AddTermiantion();
    int ShowValueOfVariable(char FirstLetter);
    

};
#endif