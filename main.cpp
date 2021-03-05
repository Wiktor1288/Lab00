#include <iostream>
#include "RandomNumberGenerator.h"
#include "Zadania.hpp"

int main(){
    auto SeedValue=0, Number=0, i=0, A=0;

    std::cout << "Podaj ilosc zadan:";
    std::cin >> Number;
    std::cout << "Podaj Ziarno";
    std::cin >> SeedValue;
    std::cout << std::endl;
    Task TabOfTasks[Number];
    RandomNumberGenerator Generator(SeedValue);

    for(i=0; i<Number; i++){
        TabOfTasks[i].AddTExecution(Generator.nextInt(1,29));
        A+=TabOfTasks[i].ShowValueOfVariable('E');
    }

    for(i=0; i<Number; i++)
      TabOfTasks[i].AddTPripare(Generator.nextInt(1,A));
    
    std::cout << "ID:  ";
    for(i=0; i<Number; i++)
        std::cout<<TabOfTasks[i].ShowValueOfVariable('I') << " ";
        
    std::cout << std::endl << "r:  ";
    for(i=0; i<Number; i++)
        std::cout<<TabOfTasks[i].ShowValueOfVariable('P') << " ";

    std::cout << std::endl <<"p:  " ;

    for(i=0; i<Number; i++)
        std::cout<<TabOfTasks[i].ShowValueOfVariable('E') << " ";

    


    return 0;
}