#include "Words.h"
#include "Words.cpp"
#include <iostream> // For input/output
#include <string> 

using namespace std;
/*
  Psuedo Code
         Start the pram and send message
         run the RunGame() function
         ask user if they want to play again
         
         functions:
                   RunGame - gets what type of game (1 or 2 player)
                           - gets the word
                           - draw the game
                           - get guess from user
                           - compare guess
                           - draw theresult of the guess
                   DrawGallows
                           - draws the game for how wever many misses they have




*/
void RunGame(); 
void DrawGallows(int state); 

// the main function of our hangman game 
int main() 
{ 
  int count = 0;
 char Continue = 'Y'; // end game if = to 'N' 
 cout << "Welcome to Hangman " << endl;

 // Continue the game as long as the player wants 
 while(Continue == 'Y') 
 { 
  RunGame(); // Run the game 
  cout<<endl<<"Do you really really want to play again (Yes or No)? "; 
  cin>>Continue; 
  Continue = toupper(Continue); 
 }

 // say good bye 
 cout<<endl<<"Thanks for playing."<<endl; 
 
 return 0;
}

// This function will run the game 
void RunGame() 
{ 
 int type = 0; // Gets the type of game
 Words word;
 int wcount = 0;  //used for guesses
 int gcount = 0;  // used for guesses
 string word2;  //Word for the game
 int size;   // This will hold the length of our word 
 int state=1;  // This holds the game state 
 int subscript=0; // This will hold subscripts 
 char guess[15]; // this will hold their current word 
 char copy[15]; // This will hold a copy of the word 
 char letter;  //This will be their letter guess 
 int correct=0;  // This is a True/False value deciding if they got a good answer 

 cout << endl << "Enter 1 for single player or 2 for two player game  ";
 cin >> type;
 if ( type == 1 )
 {
      word2 = word.RandomWord();
 }
 if ( type == 2 )
 {
      word2 = word.UserWord();
 }

 size = word.GetSize(word2); // Get the word's size
 gcount = word.GetSize(word2);
 
 // Create a null terminated string to represent the word as the 
 // player knows it. 
 for(subscript = 0; subscript < size; subscript++) 
 { 
  guess[subscript] = '-'; 
  copy[subscript] = word2[subscript];
 }
 // insert the null character 
 guess[subscript] = '\0';

 // Go till the player is hung 
 while(state!=6) 
 { 
  DrawGallows(state); //Draw the gallows 
  cout << guess << endl; // Draw Guess

  cout << "Guess a letter :"; 
  cin >> letter;

  // We will use only lower case letters 
  letter = tolower(letter); 
  
  // Loop through the word 
   //if the guess is good tell the user and update Guess 
   if(word.Compare(word2, letter) == 0) 
   { 
   for(subscript = 0; subscript < size; subscript++) 
    {
      if (copy[subscript] == letter)
      {
       guess[subscript] = letter; 
       wcount++;
      }
    }
    correct = 1; 
    gcount -= wcount;
    wcount = 0;
    cout<<endl<<"Good Guess!";

    // If guess equals the word they won so exit 
    if( gcount == 0) 
    { 
     cout << endl << "You survived and won!"; 
     return; 
    } 
       // break;
   }
   

  // If they didn't get aletter correct chide the user 
  if(correct == 0) 
  { 
   cout << endl << "Sorry, that letter in not in the word!"; 
   state++; 
  }

  correct = 0; // reset Correct

 }

 DrawGallows(state); //Draw the gallows at end of game 
 //They lost if they are here so tell them the answer. 
 cout << "The word was : " << word2 << endl << endl;

}

// This will Draw the gallows according to the state 
void DrawGallows(int state) 
{ 
 if(state==6) 
 { 
  // The \\ will translate as '\' because it is a special char 
  cout<<endl<<endl 
   <<"   +----+     "<<endl 
   <<"   |    |     "<<endl 
   <<"   |    O     "<<endl 
   <<"   |   /|\\   "<<endl 
   <<"   |   / \\   "<<endl 
   <<"   |Your Dead "<<endl 
   <<"  ============"<<endl<<endl; 
 } 
 else if(state==5) 
 { 
 
  cout<<endl<<endl 
   <<"   +----+  "<<endl 
   <<"   |    |  "<<endl 
   <<"   |    O  "<<endl 
   <<"   |   /|\\ "<<endl 
   <<"   |     \\ "<<endl 
   <<"   |       "<<endl 
   <<"  ============"<<endl<<endl; 
 } 
 else if(state==4) 
 { 
  cout<<endl<<endl 
   <<"   +----+  "<<endl 
   <<"   |    |  "<<endl 
   <<"   |    O  "<<endl 
   <<"   |   /|\\ "<<endl 
   <<"   |       "<<endl 
   <<"   |       "<<endl 
   <<"  ============="<<endl<<endl; 
 } 
 else if(state==3) 
 { 
  cout<<endl<<endl 
   <<"   +----+  "<<endl 
   <<"   |    |  "<<endl 
   <<"   |    O  "<<endl 
   <<"   |   /|  "<<endl 
   <<"   |       "<<endl 
   <<"   |       "<<endl 
   <<"  ============="<<endl<<endl; 
 } 
 else if(state==2) 
 { 
  cout<<endl<<endl 
   <<"   +----+  "<<endl 
   <<"   |    |  "<<endl 
   <<"   |    O  "<<endl 
   <<"   |    |  "<<endl 
   <<"   |       "<<endl 
   <<"   |       "<<endl 
   <<"  ============="<<endl<<endl; 
 } 
 else if(state==1) 
 { 
  cout<<endl<<endl 
   <<"   +----+  "<<endl 
   <<"   |    |  "<<endl 
   <<"   |       "<<endl 
   <<"   |       "<<endl 
   <<"   |       "<<endl 
   <<"   |       "<<endl 
   <<"  ============="<<endl<<endl; 
 }

}
