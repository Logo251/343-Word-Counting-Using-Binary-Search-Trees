//Logan Petersen
//January 18, 2020
//This file contains the code that drives this program. This code's purpose is to handle getting input from the user,
//executing the needed methods from the Binary Search Tree to achieve the program's goal, and later
//displaying in console what the tree stored.

//Input: cin from the user.
//Output: alphabetically sorted key-value pairs containing a word and the count of the word.
//To use this program execute it, enter in the console a string, then read the output described above.
//No assumptions are made beyond the user entering a string of characters.
//A few major algorithms are used. Main will read data from user, parse data to be acceptable, call
//the BST to use the parsed data, and then display the BST's data in accordance to the output
//described above. the Binary Search Tree class will be created with a root, have nodes added to it
//side of parent determined by alphabet, offer the ability to print number of words and the tree itself,
//and eventually delete the tree.
//Major variables are bst, the Binary Search Tree object, the char input for user input, and the BST
//class's root node.

#include <iostream>     //Grants cin and cout.
#include <cctype>       //Grants the function tolower.
#include "WordTree.h"   //Grants the WordTree BST.

int main() {

   //Local Variable
   WordTree bst;     //This is the binary search tree, its fits in to the program because it is where the words are added to.
   char input;       //This is the variable that handles each character of input from cin. Legal range is any character of the input given.
   std::string word; //This build the characters from input into a word that gets fed to the BST. Legal range is any amount of chars.


   //Ask for and recieve input from user.
   std::cout << "Enter characters to be parsed and counted.\nIf you are typing text in here, you will need to put";
   std::cout << " a EOF character on a newline (control - d on linux, control - z on Windows).\n";

   while(std::cin.get(input)) {    
   //The character stream has not ended.
      //Set input to be lowercase.
      input = std::tolower(input);
         
      //Add input to word if character is a letter or apostrophe
      if(std::isalpha(input) || input == 39) { //39 is the ascii value of a '
      word.push_back(input);
      }
      //If input is not a letter or apostrophe, then it is the end of a word, and word should be added to the BST.
      else {
         if (word.size() != 0) { //check to ensure we are not putting blank spaces into the BST.
            bst.Add(word);
            word.clear();
         }
      }
   }

   //Display number of words in the tree.
   std::cout << "\n" << "Number of words in the tree is: " << bst.NumWords();

   //Display the tree sorted alphabetically
   std::cout << "\n" << bst;

   //Let user read file.
   std::cout << "\nPress any key to exit.";
   std::cin >> input;
   return 0;
}
