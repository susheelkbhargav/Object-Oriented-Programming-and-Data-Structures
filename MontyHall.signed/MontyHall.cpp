#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

/**
 * Suggested problem decomposition.
 * You do not have to use these function declarations.
 */

void simulate(int sequence, int& win1, int& win2);

Door hideCar();
Door openDoor(Door firstChoiceDoor, Door carBehindDoor);
Door makeFirstChoice();
Door makeSecondChoice(Door firstChoiceDoor, Door openedDoor);

Door randomDoor();
Door randomDoorNot(Door aDoor, Door anotherDoor);
Door chooseRemainingDoor(Door firstChoiceDoor, Door openedDoor);
void printHeader()
{
  cout<<"#\tCar \tFirst\t Opened\tSecond \tFirst \t Second "<<endl<<"\t Here\tchoice\t door \tchoice \t wins\t wins\t"<<endl;
}
/**
 * Main
 */
int main()
{
    int win1 = 0, win2 = 0;

    srand(time(NULL));  // seed the random number generator
    printHeader();

    // Run the simulations.
   for (int i = 1; i <= SIMULATION_COUNT; i++)
   {
       cout<<i;
       simulate(i, win1, win2);
       cout<<endl;
   }
    cout << endl;
    cout << setw(4) << win1 << " wins if stay with the first choice" << endl;
    cout << setw(4) << win2 << " wins if switch to the second choice" << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << endl;
    cout << "Win ratio of switch over stay: ";
    cout << static_cast<double>(win2)/win1 << endl;
    return 0;
}

/***** Complete this program. ****/
void simulate(int sequence, int& win1, int& win2)
{
 Door carBehindDoor = rand()%3 +1;
 cout<<" \t"<<carBehindDoor;
 Door firstChoiceDoor = rand()%3 +1;
 Door openedDoor;
 cout<<" \t "<<firstChoiceDoor;
 openedDoor = openDoor(firstChoiceDoor,carBehindDoor);
 cout << "  \t" <<openedDoor ;
 Door SecondChoice;
 SecondChoice = chooseRemainingDoor(firstChoiceDoor,openedDoor);
 cout<< " \t"<<SecondChoice;

if(carBehindDoor==openedDoor || firstChoiceDoor==openedDoor)
    cout << "Test case failed" <<endl;

   if (firstChoiceDoor== carBehindDoor)
   {
           win1 ++;
           cout<<" \t yes \t";
   }

       else
        {
            win2++;
            cout<<"\t \t yes";
       }
       return;

   }




Door openDoor(Door firstChoiceDoor, Door carBehindDoor)
{
    Door openedDoor;
    do{
    openedDoor = rand()%3+1;
    }while((openedDoor == firstChoiceDoor) || (openedDoor == carBehindDoor));

    return openedDoor;
}

/*Door makeSecondChoice(Door firstChoiceDoor, Door openedDoor )
{

    Door choice;
    choice= rand%2 +1;
    if(choice ==1)
    {
        choice= firstChoiceDoor;
    }
    if(choice==2)
    {
        choice= chooseRemainingDoor(Door firstChoiceDoor, Door openedDoor);
    }
    return choice;
}*/
Door chooseRemainingDoor(Door firstChoiceDoor, Door openedDoor)
{
    Door remainingDoor;
    if((firstChoiceDoor ==1 && openedDoor==2)||(firstChoiceDoor==2 && openedDoor==1))
    {
        remainingDoor = 3;
    }
    if((firstChoiceDoor==1 && openedDoor==3)||(firstChoiceDoor==3 && openedDoor==1))
    {
        remainingDoor = 2;
    }
    if((firstChoiceDoor==2 && openedDoor==3)|| (firstChoiceDoor==3 && openedDoor==2))
    {
        remainingDoor=1;
    }
    return remainingDoor;
}
