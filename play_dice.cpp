/* Add your name here */
    
#include <iostream>
#include <cstdlib>  // contains the rand() and srand() function 
#include <ctime>    // time() function
using namespace std;


int main()
{
    srand(time(NULL)); // initialize random seed generator to current time: 
					// needed to generate a different sequence of random numbers
					// each time you run your program

    // Add your code to play the dice game here
    cout << "Welcome to the game." << endl;
    const int WIN1 = 7;                                 //inits all of the win and lose cases.
    const int WIN2 = 11;
    const int LOSE1 = 2;
    const int LOSE2 = 3;
    const int LOSE3 = 12;
    const int POINTSLOSE = 7;
    int userPoints = 0;                                 //inits the points
    bool points = false;                                //and the loop exit conditions
    bool pointLoss = false;
    char playGame;  
    cout << "Do you want to play a game? Y/N" << endl;  //allows the user to play the game via their input
    cin >> playGame;

    while (playGame=='y' || playGame=='Y')              //will play the game when they type y or Y
    {
        int die1= rand()%6+1;                           //inits the two initial die values
        int die2= rand()%6+1;
        int sum= die1+die2; 
        cout << "Die 1: " << die1;                     //shows user the two die rolls
        cout << " Die 2: " << die2;                     //and the sum of them
        cout << " Total: " << sum << endl;
        userPoints +=sum;                               //stores the sum in points for later use

        if (sum ==WIN1 || sum ==WIN2)                   //checks if you won the game.
        {                                               
            cout << "Congratulations! You win! Play again? Y/N" << endl;
            cin >> playGame;
        }            
        
        else if(sum ==LOSE1 || sum ==LOSE2 || sum ==LOSE3)  //checks if you lost the game.
        {
            cout << "Oh no! You lost! Try again? Y/N" << endl;
            cin >> playGame;
        }    
        
        else
        {
            do
            {
              die1= rand()%6+1;                           //otherwise, rerolls both dice
              die2= rand()%6+1;
              sum= die1+die2;                             //sums them up
              cout << "Die 1: " << die1;                  //displays new rolls and sum
              cout << " Die 2: " << die2;
              cout << " Total: " << sum << endl;                  
              pointLoss= sum ==POINTSLOSE;                //check if 7 rolled. if yes, exits
              points= sum ==userPoints;                   //checks if the new sum matches the original sum. 
                                                          //if yes, exits loop. Otherwise continues loop

            }while(points || pointLoss);

            if (!pointLoss)                                  //if you exited loop because same sum twice,
            {                                             //displays win message
              cout << "Oh no! You lost! Try again? Y/N" << endl;
              cin >> playGame;
            }
            if (!points)                                          //if exited loop because of 7, displays loss message
            {
              cout << "Congratulations! You win! Play again? Y/N" << endl;
              cin >> playGame;
            }
        }
        
    }
    cout << "Thank you for playing" << endl;
}


