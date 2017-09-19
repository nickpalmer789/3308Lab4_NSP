#include <iostream>
#include <stdlib.h>

using namespace std;

//Prototypes for the methods defined below
void convertSeconds(int);
void playGame();
void solveMaze(int[4][4]);
void printMaze(int, int[4][4]);

int main() {
    //Problem 1
    convertSeconds(70000);

    //Problem 2
    playGame();

    //Problem 3
    //Create the maze that the horse is in
    //To show where the horse is, represent the horse with the number 3
    int maze[4][4] = {
        {1, 1, 0, 2},
        {0, 0, 0, 1},
        {0, 1, 0, 1},
        {3, 0, 0, 1}
    };

    //Have the horse run through the maze
    printMaze(0, maze);

    return 0;
}

//Code for problem 1
void convertSeconds(int inputSeconds) {
    int hours = (inputSeconds / 60) / 60;
    int minutes = (inputSeconds / 60) % 60;
    int seconds = (inputSeconds % 60);

    cout<<"The time is "<<hours<<" hours, "<<minutes<<" minutes, and "<<seconds<<" seconds"<<endl;
}

//Code for problem 2
void playGame() {
    bool askAgain = true;

    while(askAgain == true) {
        //Ask the user what they would like to do
        cout<<"Traveler, what would you like to do?"<<endl;
        cout<<"1. Fight the dragon"<<endl;
        cout<<"2. Go home"<<endl;
        cout<<"3. Save the princess"<<endl;
        cout<<"Please enter 1, 2, or 3 to make a selection: ";
        int choice;
        cin>>choice;

        //Check what the user entered
        if(choice == 1) {
            //Determine if the user won against the dragon if they choose to fight it
            int a= rand()%2;

            cout<<a<<endl; //For testing purposes

            if(a == 0) {
                cout<<"You win!"<<endl;
            } else if(a == 1) {
                cout<<"You lost!"<<endl;
                askAgain = false;
            }
        } else if(choice == 2) {
            //Exit the game if the user goes home
            cout<<"Wimp"<<endl;
            askAgain = false;
        } else if(choice == 3) {
            //Save the princess
            cout<<"You saved the princess"<<endl;
        }


    }

}

//Code for problem 3
void solveMaze(int maze[4][4]) {
    //Start by showing the initial maze
    printMaze(0, maze);
    bool foundApple = false;

    //Search until you found the apple
    while(!foundApple) {
        -
    }

}


void printMaze(int iteration, int maze[4][4]) {
    cout<<"Maze state at iteration "<<iteration<<":"<<endl;
    cout<<"Note that the horse is represented by the number 3."<<endl;
    cout<<"Note that when the horse has found the apple, it is represented by a star(*)"<<endl;

    //Print out the maze
    //Start by looping through the rows
    for(int i = 0; i < 4; i++) {
        //Loop through the columns
        cout<<"|";
        for(int j = 0; j < 4; j++) {
            cout<<maze[i][j]<<"|";
        }
        //End of line, go to next line
        cout<<endl;
    }
}








