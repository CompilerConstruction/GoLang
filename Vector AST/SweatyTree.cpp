#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include <vector>

using namespace std;

// Enum Node Types
enum ASTNodeType 
{
   Undefined,
   OperatorPlus,
   OperatorMinus,
   OperatorMul,
   OperatorDiv,
   ParenthesesOpen,
   ParenthesesClose,
   BracketOpen,
   BracketClose,
   CurlyOpen,
   CurlyClose,
   NumberValue,
   StringValue,
   Package,
   Import,
   End
};
static char* enumStrings[] = {
   "Undefined",
   "OperatorPlus",
   "OperatorMinus",
   "OperatorMul",
   "OperatorDiv",
   "ParenthesesOpen",
   "ParenthesesClose",
   "BracketOpen",
   "BracketClose",
   "CurlyOpen",
   "CurlyClose",
   "NumberValue",
   "StringValue",
   "Package",
   "Import",
   "End"
   };

struct Node{
	ASTNodeType Type;
	string Value;
	vector<Node> Up;
	vector<Node> Down;
};

vector<Node> CreateVectorNode(ASTNodeType type,const string& value, vector<Node> up, vector<Node> down);
vector<Node> ParseWord(string nextWord);
ifstream nameFileout;

vector<Node> getNextWord(){
	
	
	
	string line;
	while(getline(nameFileout, line))
	{
	    return ParseWord(line);
	    // TODO: assign item_name based on line (or if the entire line is 
	    // the item name, replace line with item_name in the code above)
	}
	nameFileout.close();
	
}

vector<Node> ParseWord(string nextWord){ 
    // I want this to get a string value from getNextWord()

	string passedWord;

	//else {
	
		if (!nextWord.compare("package")) {  // Error check this later
	
	    // cout << "package found" << endl;
	    // So we have found the token package, create a node
	    //return CreateVectorNode(Package, nextWord, parser.testingNextWord(), parser.testingNextWord());
	  } else if (!nextWord.compare("import")) {
	    // cout << "import found" << endl;
	    //return CreateVectorNode(Import, nextWord, vector<Node>(), parser.testingNextWord());
	  }
	  // 1-2
	  else {
	    switch(nextWord[0]){
			// For open and closing parathesis, we need a a flag to make sure there's a closing pair ?
			case '+':
				passedWord = nextWord;
				passedWord.erase(passedWord.begin());
				return CreateVectorNode(OperatorPlus,string(1,nextWord[0]),{},ParseWord(passedWord));
			case '-':
				passedWord = nextWord;
				passedWord.erase(passedWord.begin());
				return CreateVectorNode(OperatorMinus,string(1,nextWord[0]),{},ParseWord(passedWord)); 
			case '*':
				passedWord = nextWord;
				passedWord.erase(passedWord.begin());
				return CreateVectorNode(OperatorMul,string(1,nextWord[0]),{},ParseWord(passedWord)); 
			case '/':
				passedWord = nextWord;
				passedWord.erase(passedWord.begin());
				return CreateVectorNode(OperatorDiv,string(1,nextWord[0]),{},ParseWord(passedWord)); 
	 		case '{':
	 			//return CreateNode(CurlyOpen,nextWord,NULL,parser.testingNextWord());
			case '(':
				//return CreateNode(ParenthesesOpen,nextWord,NULL,parser.testingNextWord());
			case '}':
				//return CreateNode(CurlyClose,nextWord,NULL,parser.testingNextWord());
			case ')':
				//return CreateNode(ParenthesesClose,nextWord,NULL,parser.testingNextWord());
//			case '\"':
//				return CreateNode(OperatorDiv,nextWord,NULL,parser.testingNextWord());
//			case '\'':
//				return CreateNode(OperatorDiv,nextWord,NULL,parser.testingNextWord());
			default:
				int i = 0;
				if(isdigit(nextWord[0])){
					
					// found one number '2' look in the string 'nextword' to find an operator '-', as up node
					
						// This get the next char from the string 
						//ParseWord(string(1,nextWord[i]));
						
						for (int i = 0; !nextWord[i] == '\0'; i++){

							passedWord = nextWord;
							passedWord.erase(passedWord.begin());
							return CreateVectorNode(NumberValue,string(1,nextWord[i]),ParseWord(passedWord),{});
							
						}
//						while(!(nextWord[i] == NULL)){
//							cout << "\t"; 
//							return CreateNode(NumberValue,string(1,nextWord[0]),ParseWord(string(1,nextWord[i])),NULL);
//							i++;
//						}
					
				}
				cout << "defaulting on my debt " << endl;
				return CreateVectorNode(Undefined,nextWord,{},{});
		}
	  }
		
		
	  
	//}

	return CreateVectorNode(Undefined,"Parsing failed",{},{});
}


vector<Node> CreateVectorNode(ASTNodeType type,const string& value, vector<Node> up, vector<Node> down){
	//cout << "Creating vector node" <<  "\tType:" << enumStrings[type] << endl <<"\tValue: " << value << endl;

	vector<Node> node;
	
//	vector<Node>* tempNode;
//	
//	ASTNodeType tempUp;
//	ASTNodeType tempDown;
//	
////	tempUp = up[0].Type;
////	cout << "Printing in create node" << enumStrings[tempDown];
////	tempDown = down[0].Type;
////	cout << "Printing in create node" << tempDown;
//	if (!down[0].Up.empty())
//	{
//		cout <<down[0].Type;
//	}
	
	node.push_back(Node());
	
	node[0].Type = type;
	node[0].Value = value;
	copy (up.begin(), up.end(), std::back_inserter(node[0].Up));
	copy (down.begin(), down.end(), std::back_inserter(node[0].Down));
	//node[0].Up = &up;
	//node[0].Down = &down;
	//node.emplace_back(type,value,up,down);

	return node;
}
vector<Node>* temp;
void display(vector<Node> vectorNodeToBeDisplayed){
	
	
//	temp = vectorNodeToBeDisplayed[0].Up; 
//	cout << vectorNodeToBeDisplayed[0].Up[0].Value << endl;
//	cout << vectorNodeToBeDisplayed[0].Value << endl;
//	cout << temp[0].Down[0].Value;
//	
	
	if(!vectorNodeToBeDisplayed[0].Up.empty() && !vectorNodeToBeDisplayed[0].Up.empty()){
		cout << "\n\t" << vectorNodeToBeDisplayed[0].Value;
		cout << "\nWe're going up!" << endl;
		temp = &vectorNodeToBeDisplayed[0].Up;
		display(*temp);
	}
	else if (vectorNodeToBeDisplayed[0].Up.empty() && !vectorNodeToBeDisplayed[0].Down.empty()){
		cout << "\n\t" << vectorNodeToBeDisplayed[0].Value << " \nWe're going down" << endl;
		temp = &vectorNodeToBeDisplayed[0].Down;
		display(*temp);
	}
	
	if (!vectorNodeToBeDisplayed[0].Down.empty() && !vectorNodeToBeDisplayed[0].Up.empty()){
		cout << vectorNodeToBeDisplayed[0].Value;
		cout << "Think that's the end" << endl; 
	}
	

}

int main (){
    vector<Node> baseNode;
    nameFileout.open("example0.go");
	while(nameFileout.is_open()){
		baseNode = getNextWord();
		display(baseNode);
	}
	
	return 0;
}
