#include <iostream>
#include<algorithm>
#include "RandomNumberGenerator.h"
#include "Zadania.hpp"
void DataGeneration(Task *pointer1,int size1, int SeedVa); 
void CalculateData(Task *pointer1,int size1,int *orderTask);
void SortOfTasks(Task *pointer1, int size1,int *OrderTask);

int main(){
    auto SeedValue=0, Number=0, i=0;

    std::cout << "Podaj ilosc zadan: ";
    std::cin >> Number;
    std::cout << "Podaj Zrodlo: ";
    std::cin >> SeedValue;
    std::cout << std::endl;
    Task *TabOfTasks= new Task[Number];
    int *OrderTab=new int[Number];
    for (i=0; i<Number; i++){
      OrderTab[i]=i;
    }
    
    DataGeneration(TabOfTasks,Number,SeedValue);
    CalculateData(TabOfTasks,Number,OrderTab);


    std::cout << "ID:  ";
    for(i=0; i<Number; i++)
        std::cout << TabOfTasks[i].ShowValueOfVariable('I') << " | ";
     
    std::cout << std::endl << "r:  ";
    for(i=0; i<Number; i++)
        std::cout << TabOfTasks[i].ShowValueOfVariable('P') << " | ";

    std::cout<< std::endl << "p:  ";
    for(i=0; i<Number; i++)
        std::cout << TabOfTasks[i].ShowValueOfVariable('E') << " | ";

    std::cout << std::endl << std::endl << "ID:  ";
    for(i=0; i<Number; i++)
        std::cout << TabOfTasks[i].ShowValueOfVariable('I') << " | ";
     
    std::cout << std::endl << "S:  ";
    for(i=0; i<Number; i++)
        std::cout << TabOfTasks[i].ShowValueOfVariable('M') << " | ";

    std::cout<< std::endl << "C:  ";
    for(i=0; i<Number; i++)
        std::cout << TabOfTasks[i].ShowValueOfVariable('T') << " | ";

    
    SortOfTasks(TabOfTasks,Number,OrderTab);
    
    std::cout<< std::endl << "ID:  ";
    /*for(i=1; i<=Number; i++)
        for(auto j=0; j<Number; j++){
            if(TabOfTasks[j].ShowValueOfVariable('Q')==i){
                std::cout <<TabOfTasks[j].ShowValueOfVariable('I') << " | ";
            }

        }*/
        for(i=0; i<Number; i++)
        {
            std::cout << TabOfTasks[OrderTab[i]].ShowValueOfVariable('I') << " | ";
        }
    std::cout<< std::endl << "S:  ";
    for(i=0; i<Number; i++){
        std::cout << TabOfTasks[OrderTab[i]].ShowValueOfVariable('M') << " | ";
    }

    std::cout<< std::endl << "C:  ";
    for(i=0; i<Number; i++){
        std::cout << TabOfTasks[OrderTab[i]].ShowValueOfVariable('T') << " | ";
    }
    
    delete[] TabOfTasks;
    delete[] OrderTab;

    return 0;
}



void DataGeneration(Task *pointer1,int size1,int SeedVa){
    RandomNumberGenerator Generator(SeedVa);
    auto i=0,A=0;
    for(i=0; i<size1; i++){
        pointer1[i].AddTExecution(Generator.nextInt(1,29));
        A+=pointer1[i].ShowValueOfVariable('E');
    }

    for(i=0; i<size1; i++)
      pointer1[i].AddTPripare(Generator.nextInt(1,A));

}

void CalculateData(Task *pointer1,int size1, int *orderTask){
for(auto i=0; i<size1; i++){
        if(i!=0)
            pointer1[orderTask[i]].AddStartMoment(pointer1[orderTask[i-1]].ShowValueOfVariable('T'));
            
        else
            pointer1[orderTask[i]].AddStartMoment(0);

        pointer1[orderTask[i]].AddTermiantion();
    }

}


void SortOfTasks(Task *pointer1, int size1, int *OrderTask){
    int Tab1[size1];
    bool appear=false;

    for(int i=0; i<size1; i++){
        Tab1[i]=pointer1[i].ShowValueOfVariable('P');
        OrderTask[i]=-1;
    }
    std::sort(Tab1, Tab1+size1);

    for(auto i=0; i<size1; i++)
        for(auto j=0; j<size1; j++){
            appear=false;
            for(auto w=0; w<size1; w++){
                if(OrderTask[w]==j)
                    appear=true;
            }
            if(Tab1[i]==pointer1[j].ShowValueOfVariable('P') && !appear){
                pointer1[j].AddPosition(i+1);
                OrderTask[i]=j;
                break;
            }
        }
    CalculateData(pointer1,size1,OrderTask);
}

