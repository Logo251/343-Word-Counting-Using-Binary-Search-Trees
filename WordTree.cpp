////Logan Petersen
//January 18, 2020
//This file contains the code for the WordTree. The purpose of this code is to create, modify
//demonstrate, and eventually remove a WordTree.

#include <string> //Grants to_string.
#include "WordTree.h"

//Description:    This function constructs the WordTree with default parameters.
//Precondition:   The object has been requested to be instantiated.
//Postcondition:  A BST with a root is instantiated.
WordTree::WordTree() {
   root = new WordTree::WordNode;
}

//Description:    This function constructs the WordTree with an input string.
//Parameters:     input, this string is used to set the root of the tree so a second call later is not needed.
//Precondition:   The object has been requested to be instantiated.
//Postcondition:  A BST with a root already containing a word is instantiated.
WordTree::WordTree(std::string inputWord) {
   root = new WordTree::WordNode;
   root->number = 0;
}

//Description:    This function deletes allocated memory for WordTree.
//Precondition:   The object has been instantiated has left variable scope.
//Postcondition:  WordTree no longer exists, all of its memory has been freed.
//Functions used: DeleteTree() is used to recursively delete the tree.
WordTree::~WordTree() {
   DeleteTree(root);
}

//Description:    This function adds a node if the node does not currently exist. Otherwise, it increments the node.
//Parameters:     input, this string is used to decide whether a new node is created with input or if the node already exists.
//Precondition:   The tree has been instantiated.
//Postcondition:  Either a new node exists in the tree or a node has been incremented, if the node already exists.
//Functions used: AddWord() is used to recursively add to the tree.
void WordTree::Add(std::string input) {
   AddWord(input, root);
}

//Description:    This function returns the number of words added to the tree.
//Precondition:   The tree has been instantiated.
//Postcondition:  The number of words in the tree is returned in an int.
//Functions used: CountWords() is used to count the number of words recursively.
int WordTree::NumWords() {
   return CountWords(root);
}

//Description:    This function allows WordTree to be printed using the standard operator "<<".
//Parameters:     out, which is the stream of characters being sent to terminal.
//                Tree is WordTree, allowing it to be sent out. A note about tree is it is passed by reference.
//                This is done because otherwise it shallow copies WordTree and this function should have the
//                permission to modify the tree as it is part of the tree.
//Precondition:   The tree has been instantiated.
//Postcondition:  WordTree is printed according to design, out is returned for the next item in the chain.
//Functions used: PrintTree() is used to recursively print the tree.
std::ostream& operator<<(std::ostream& out, WordTree& tree) {
   
   out << tree.PrintTree(tree.root);
   return out;
}

//Description:    This function deletes WordTree recursively using a postorder traversal.
//Parameters:     inputNode, the node that the deletion starts at.
//Precondition:   The destructor for WordTree has been called.
//Postcondition:  WordTree no longer has allocated memory.
//Functions used: DeleteTree() is used to recursively delete the tree.
void WordTree::DeleteTree(WordTree::WordNode* inputNode) {
   
   //When we have gone too far.
   if (inputNode == nullptr) {
      return;
   }

   //First step of postorder, go left.
   DeleteTree(inputNode->left);

   //Second step, go right.
   DeleteTree(inputNode->right);

   //Third step, take root (in this case just delete).
   delete inputNode;
   return;
}

//Description:    This function adds a word to WordTree recursively by either creating a new one or incrementing an existing one.
//Parameters:     input, the word being added or incremented in the tree.
//                inputNode, the node at which the recursion to find where the node is or should go starts.
//Precondition:   Add has been called.
//Postcondition:  WordTree no longer has allocated memory.
//Functions used: AddWord() is used to recursively add a node in the correct place or increment the already existing node.
WordTree::WordNode* WordTree::AddWord(std::string input, WordTree::WordNode* inputNode) {

   //Handle the condition that no items are in the tree.
   if(root->word.empty()) {
      root->word = input;
      root->number++;
      return nullptr; //Need to return something, if this code is ran, no recursion will happen.
                        //Return can be any node or nullptr.
   }

   //This checks if the inputNode is not a valid WordNode. If true, we know the inputNode is where the new node goes
   //and we can skip figuring out which way to progress.
   if(inputNode != nullptr) {

      //Compares strings, go right if string is alphabetically greater, otherwise go left.
      if(input.compare(inputNode->word) > 0) {
         inputNode->right = AddWord(input, inputNode->right);
         return inputNode; //To ensure we don't create a second WordNode, causing memory leak.
      }
      else if(input.compare(inputNode->word) < 0) {
         inputNode->left = AddWord(input, inputNode->left);
         return inputNode; //To ensure we don't create a second WordNode, causing memory leak.
      }

      //If they are equal, then string already exists, increment it.
      else {
         inputNode->number++;
         return inputNode; 
      }
   }

   //At this point, if the while has been escaped, we can assume that item does not exist in tree,
   //and that currentNode is where the new item should go.
   WordNode* node = new WordNode(input); //This is used to be the new node for the tree to grow. Legal range is a WordNode
                                          //containing word being input and count being 1.
   return node; //end of recursion.
}


//Description:    This function recursively counts the number of words in the tree using a preorder transversal.
//Parameters:     inputNode, the node that the deletion starts at.
//Precondition:   The destructor for WordTree has been called.
//Postcondition:  WordTree no longer has allocated memory.
//Functions used: CountWords() is used to recursively count the nodes.
int WordTree::CountWords(WordTree::WordNode* inputNode) const {
   
   //Local Variable
   int count = 0; //This is the variable that will added to to count all the words in the tree. Legal range is non-negative.

   //When we have gone too far.
   if (inputNode == nullptr) {
      return 0;
   }

   //First step of preorder, take root (in this case just add to count).
   count += inputNode->number;

   //Second step, go left.
   count += CountWords(inputNode->left);

   //Third step, go right.
   count += CountWords(inputNode->right);

   return count;
}

//Description:    This function prints the tree according to requirements recursively using a inorder traversal.
//Parameters:     inputNode, the node that the print starts at.
//Precondition:   The WordTree's overloaded << operator has been called.
//Postcondition:  WordTree is printed through the << operator.
//Functions used: PrintTree() is used to recursively print the tree.
std::string WordTree::PrintTree(WordTree::WordNode* inputNode) {
         
   std::string returnString;

   //When we have gone too far.
   if (inputNode == nullptr) {
      return std::string(); //should be nothing, this satisfies
   }

   //First step of inorder, go left.
   returnString += PrintTree(inputNode->left);

   //Second step, take root (in this case just add to count).
   returnString += (inputNode->word + '\t' + '\t' + ':' + '\t' + std::to_string(inputNode->number)); //to_string converts int to string.
   returnString += '\n'; //This does new line, so the output actually is decent.

   //Third step, go right.
   returnString += PrintTree(inputNode->right);

   return returnString;
}
   