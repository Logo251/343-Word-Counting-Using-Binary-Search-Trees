////Logan Petersen
//January 18, 2020
//This is the header file for the Binary Search Tree. The purpose of this code is to be an interface for WordTree.

#pragma once

#include <iostream> //Grants cin and cout.

class WordTree {
public:
   //Description:    This function constructs the WordTree with default parameters.
   //Precondition:   The object has been requested to be instantiated.
   //Postcondition:  A BST with a root is instantiated.
   WordTree();

   //Description:    This function constructs the WordTree with an input string.
   //Parameters:     input, this string is used to set the root of the tree so a second call later is not needed.
   //Precondition:   The object has been requested to be instantiated.
   //Postcondition:  A BST with a root already containing a word is instantiated.
   WordTree(std::string input);

   //Description:    This function deletes allocated memory for WordTree.
   //Precondition:   The object has been instantiated has left variable scope.
   //Postcondition:  WordTree no longer exists, all of its memory has been freed.
   //Functions used: DeleteTree() is used to recursively delete the tree.
   ~WordTree();

   //Description:    This function adds a node if the node does not currently exist. Otherwise, it increments the node.
   //Parameters:     input, this string is used to decide whether a new node is created with input or if the node already exists.
   //Precondition:   The tree has been instantiated.
   //Postcondition:  Either a new node exists in the tree or a node has been incremented, if the node already exists.
   //Functions used: AddWord() is used to recursively add to the tree.
   void Add(std::string input);

   //Description:    This function returns the number of words added to the tree.
   //Precondition:   The tree has been instantiated.
   //Postcondition:  The number of words in the tree is returned in an int.
   //Functions used: CountWords() is used to count the number of words recursively.
   int NumWords();

   //Description:    This function allows WordTree to be printed using the standard operator "<<".
   //Parameters:     out, which is the stream of characters being sent to terminal.
   //                Tree is WordTree, allowing it to be sent out. A note about tree is it is passed by reference.
   //                This is done because otherwise it shallow copies WordTree and this function should have the
   //                permission to modify the tree as it is part of the tree.
   //Precondition:   The tree has been instantiated.
   //Postcondition:  WordTree is printed according to design, out is returned for the next item in the chain.
   //Functions used: PrintTree() is used to recursively print the tree.
   friend std::ostream& operator<<(std::ostream& out, WordTree& tree);
   
private:
   struct WordNode {
      //Description:    This function constructs the WordNode with default parameters.
      //Precondition:   The structure has been requested to be instantiated.
      //Postcondition:  A node is constructed.
      WordNode() {
         number = 0;
         left = nullptr;
         right = nullptr;
      }
      //Description:    This function constructs the WordTree with word.
      //Parameters:     inputWord, a string used to set the the word of the node so a second call later is not needed.
      //Precondition:   The structure has been requested to be instantiated.
      //Postcondition:  A BST with a root containing inputWord and number of 1 is instantiated.
      WordNode(std::string inputWord) {
         word = inputWord;
         number = 1;
         left = nullptr;
         right = nullptr;
      }
      std::string word; //This is the node's word that it stores, it is needed to relate number to work.
      int number;       //This is the number of times the word was found. Legal range is any positive number, including 0.
      WordNode* left;   //This is the pointer to another node WordNode to create a tree. Legal range is nullptr and WordNode.
      WordNode* right;  //This is the pointer to another node WordNode to create a tree. Legal range is nullptr and WordNode.
   };

   //Description:    This function deletes WordTree recursively using a postorder traversal.
   //Parameters:     inputNode, the node that the deletion starts at.
   //Precondition:   The destructor for WordTree has been called.
   //Postcondition:  WordTree no longer has allocated memory.
   //Functions used: DeleteTree() is used to recursively delete the tree.
   void DeleteTree(WordNode* inputNode);

   //Description:    This function adds a word to WordTree recursively by either creating a new one or incrementing an existing one.
   //Parameters:     input, the word being added or incremented in the tree.
   //                inputNode, the node at which the recursion to find where the node is or should go starts.
   //Precondition:   Add has been called.
   //Postcondition:  WordTree no longer has allocated memory.
   //Functions used: AddWord() is used to recursively add a node in the correct place or increment the already existing node.
   WordNode* AddWord(std::string input, WordNode* inputNode);

   //Description:    This function recursively counts the number of words in the tree using a preorder transversal.
   //Parameters:     inputNode, the node that the deletion starts at.
   //Precondition:   The destructor for WordTree has been called.
   //Postcondition:  WordTree no longer has allocated memory.
   //Functions used: CountWords() is used to recursively count the nodes.
   int CountWords(WordNode* inputNode) const;

   //Description:    This function prints the tree according to requirements recursively using a inorder traversal.
   //Parameters:     inputNode, the node that the print starts at.
   //Precondition:   The WordTree's overloaded << operator has been called.
   //Postcondition:  WordTree is printed through the << operator.
   //Functions used: PrintTree() is used to recursively print the tree. 
   std::string PrintTree(WordNode* inputNode);

   WordNode* root; //This is the base node for the tree, it is required for the tree to exist. Legal range is only WordNode.
};