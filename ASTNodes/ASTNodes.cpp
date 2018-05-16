#include <deque>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include <typeinfo>

using namespace std;


// Enum Node Types
enum ASTNodeType 
{
   Undefined,
   NumberValue,
   StringValue,
   Package,
   Import,
   End
};
 
// Defined AST Node class
class ASTNode
{
public:
   ASTNodeType Type;
   string	   Value;
   ASTNode*    Left;
   ASTNode*    Right;
 
 	// Contructor
   ASTNode()
   {
      Type = Undefined;
      Value = "";
      Left = NULL;
      Right = NULL;
   }
 
 	//DE-constructor
   ~ASTNode()
   {
      delete Left;
      delete Right;
   }
};
//Variables Declarations
ASTNode baseNode;

static char* enumStrings[] = {
   "Undefined",
   "NumberValue",
   "StringValue",
   "Package",
   "Import",
   "End"};

//Function Declarations
ASTNode* CreateNode(ASTNodeType type, const string& value, ASTNode* left, ASTNode* right);
ASTNode* ParseWord(string nextWord);
class Parser {
 public:
  string word;
  ifstream goFile;
  
  ASTNode* nextChar() {
  	//cout << "NextChar fxn" << endl;
  goFile.open("example.go");
  char nextCharacter;
  ASTNode* returnNode;
	while (goFile.is_open())  // Check the file opend correctly
	    {
	    	
	      /*
	      while (goFile >> noskipws >> nextCharacter) {  // process nextCharacterCheck here, along with whitespaces
	        setNextWord(nextCharacter);
	      }
	
	      if (goFile.eof()) {  // eofBit set to true
	        cout << "\nEnd of the file" << endl;
	        //return CreateNode(End,NULL,NULL,NULL);
	      }*/
	      
	      returnNode = testingNextWord();
	      
	      
	    }
	    return returnNode;
	}
	
	ASTNode* testingNextWord (){
		return setNextWord(getNextChar());
	}
	char getNextChar(){
		char nextCharacter;
		
		while (goFile >> noskipws >> nextCharacter) {  // process nextCharacterCheck here, along with whitespaces
	       
			return nextCharacter;
	      }
	
	      if (goFile.eof()) {  // eofBit set to true
	        //cout << "\nEnd of the file" << endl;
	        
	        goFile.close();
	        return 0;
	      }
	      
	}
	
	
	
  ASTNode* setNextWord(char nextCharacterCheck){
  	//cout << "Next char is:" << nextCharacterCheck << endl;
  	if(isspace(nextCharacterCheck)){
  		//cout << "SetNextword sees char:" << nextCharacterCheck << endl;
		switch(nextCharacterCheck){
			case '\n':
				//cout << "\nfound new line\nWord:" << word << endl;
				return ParseWord(word);
				//return CreateNode(Undefined,word,NULL,ParseWord(word));
				break;
			case '\r':
				//cout << "\nfound carrage return\nWord:" << word << endl;
				
				//return CreateNode(Undefined,word,NULL,ParseWord(word));
				break;
			case ' ':
				//cout << "\nfound whitespace \nWord:" << word << endl;
				return ParseWord(word);
				
				//return CreateNode(StringValue,"Saving word from whitespace case"aNULLeParseWord(word)
				break;
			
			default:
				//cout << "\nshould be done\n" << endl;
				return CreateNode(End,"Setting next work failed",NULL,NULL);
			word.clear();
		}	
	
		
	}
	
	else{
		word += nextCharacterCheck;
		
	}
			
  }
  
  string getNextWord() {
  	return word;
  }
  

};
Parser parser;

int main(){
	//cout << "Starting parser" << endl;
	parser.nextChar();
	
	return 0;
}


ASTNode* CreateNode(ASTNodeType type,const string& value, ASTNode* left, ASTNode* right)
{
	
	cout << "Creating node" << endl << "\tType:" << enumStrings[type] << endl <<"\tValue: " << value << endl;
      ASTNode* node = new ASTNode;
      node->Type = type;
      node->Value = value;
      node->Left = left;
      node->Right = right;

      return node;
}


ASTNode* ParseWord(string nextWord){ // I want this to get a string value from getNextWord()
	//cout << "Parse Word sees: " << nextWord << "\nMain word before clearing:" << parser.word << endl;
	parser.word.clear();
	if(!nextWord.compare("package")){ // Error check this later
	
	//cout << "package found" << endl;
		// So we have found the token package, create a node 
		return CreateNode(Package,nextWord,NULL,parser.testingNextWord());
	} 
	else if (!nextWord.compare("import")){
		//cout << "import found" << endl;
		return CreateNode(Import,nextWord,NULL,parser.testingNextWord());
	}
	else{
		return CreateNode(StringValue,nextWord,NULL,parser.testingNextWord());
		
	}
	
	return CreateNode(Undefined,"Parsing failed",NULL,NULL);
}


