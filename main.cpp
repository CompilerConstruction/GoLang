#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;

class Node
{
public:
    string value;
    string parent;
    string child[5];

private:

};

Node packageNode;
Node importNode;
Node funcNode;
Node bodyNode;
Node varNode;

string x;
string result;
int counter;
string leaf;

int parsePackage();
int parseImport();
int parseFunc();
int parseBody();
int parseConst();
int parseVar();

/*
int parseVar()
{
    int varCounter = 1+parseBody();
    while(iswspace(x[varCounter]) || x[varCounter] == '{' || x[varCounter] == '}')
    {
        varCounter++;
    }

    if(isalnum(x[varCounter]))
    {
        int q = varCounter;
        string varName;
        cout << "I am printing from inside 'parseVar()'"<< endl;
        for(int i = q; !iswspace(x[i]) && x[i] != '}'; i++)
        {
            varName = varName + x[i];
            counter = i;
        }
        cout << "var--> " << varName << endl;
        leaf = "var";
        return counter;
    }
    else
    {
        cout << "Error: invalid syntax"<< endl;
    }
    return 0;

}


int parseConst()
{
    int constCounter = 1+parseBody();
    while(iswspace(x[constCounter]) || x[constCounter] == '{' || x[constCounter] == '}')
    {
        constCounter++;
    }

    if(isalnum(x[constCounter]) && x.substr(constCounter, 5) == "const")
    {
        int n = constCounter;
        string constName;
        cout << "I am printing from inside 'parseConst()'"<< endl;
        for(int i = n; !iswspace(x[i]) && x[i] != '}'; i++)
        {
            constName = constName + x[i];
            counter = i;
        }
        cout << "const--> " << constName << endl;
        leaf = "const";
        return counter;
    }
    else
    {
        parseVar();
        cout << "Error: invalid syntax"<< endl;
    }
    return 0;
}
*/

int parseVar()
{
    int varCounter = 1 + parseFunc();
    while(iswspace(x[varCounter]) || x[varCounter] == '{' || x[varCounter] == '}')
    {
        varCounter++;
    }

    if(x.substr(varCounter, 3) == "var")
    {
        varCounter = varCounter + 4;
        while(iswspace(x[varCounter]))
        {
            varCounter++;
        }
        int k = varCounter;
        string varName;
        cout << "I am printing from inside 'parseVar()'"<< endl;
        for(int i = k; !iswspace(x[i]) && x[i] != '('; i++)
        {
            varName = varName + x[i];
            counter = i;
        }
        cout << "var--> " << varName << endl;
        varNode.value = varName;
        funcNode.child[0] = "varNode";
        varNode.parent = "funcNode";
        return counter;
    }



}

/*
int parseBody()
{
    int bodyCounter = 1 + parseFunc();
    while(iswspace(x[bodyCounter]) || x[bodyCounter] == '{' || x[bodyCounter] == '}')
    {
        bodyCounter++;
    }
    cout << bodyCounter << endl;

    if(x.substr(bodyCounter, 5) == "const" && leaf != "const")
    {
        return bodyCounter+4;
    }
    else if(x.substr(bodyCounter, 3) == "var" && leaf != "var")
    {
        return bodyCounter+2;
    }

    else
    {
        cout << "Error: invalid syntax" << endl;

    }
    return 99;

}
*/

int parseFunc()
{
    int funcCounter = 1 + parseImport();
    while(iswspace(x[funcCounter]))
    {
        funcCounter++;
    }
    cout << funcCounter << endl;

    if(x.substr(funcCounter, 4) == "func")
    {
        funcCounter = funcCounter + 4;
        while(iswspace(x[funcCounter]))
        {
            funcCounter++;
        }
        int j = funcCounter;
        string funcName;
        cout << "I am printing from inside 'parseFunc()'"<< endl;
        for(int i = j; !iswspace(x[i]); i++)
        {
            funcName = funcName + x[i];
            counter = i;
        }
        cout << "func--> " << funcName << endl;
        funcNode.value = funcName;
        funcNode.child[0] = "bodyNode";
        bodyNode.parent = "funcNode";
        return counter;
    }
    else
    {
        cout << "Error: invalid syntax"<< endl;
    }
    return 0;
}

int parseImport()
{
    int importCounter = 1 + parsePackage();
    while(iswspace(x[importCounter]))
    {
        importCounter++;
    }
    cout << importCounter << endl;

    if(x.substr(importCounter, 6) == "import")
    {
        importCounter = importCounter + 6;
        while(iswspace(x[importCounter]))
        {
            importCounter++;
        }
        int k = importCounter;
        string importName;
        cout << "I am printing from inside 'parseImport()'"<< endl;
        for(int i = k; !iswspace(x[i]) && x[i] != '('; i++)
        {
            importName = importName + x[i];
            counter = i;
        }
        cout << "import--> " << importName << endl;
        importNode.value = importName;
        importNode.child[0] = "funcNode";
        funcNode.parent = "importNode";
        return counter;
    }
    else
    {
        cout << "Error: invalid syntax"<< endl;
    }
    return 0;
}

int parsePackage()
{
    if(x.substr(0,7) == "package") //find subset of string, compare to target string (i.e. 'package')
    {
        int packageCounter = 7;
        cout << "I am printing from inside 'parsePackage()'"<< endl;
        while(iswspace(x[packageCounter]))
        {
            packageCounter++;
        }

        for(int i = packageCounter; !iswspace(x[i]); i++)
        {
            result = result + x[i];
            counter = i;
        }
        cout << "package--> " << result << endl;
        packageNode.value = result;
        packageNode.child[0] = "importNode";
        importNode.parent = "packageNode";
        return counter;
    }
    else
    {
        cout << "Error: invalid syntax"<< endl;
    }
    return 0;
}

int main()
{
    //x = "package main\n";
    x = "package main\nimport \"fmt\"\nfunc main()\n{\nvar Pi = 50\n}";
    //x = "package main\nimport \"fmt\"\nfunc main()\n{\n\tprintln(\"helloworld\")\n}";
    //x = "package main\nfunc main()\n{\n\tprintln(\"helloworld\")\n}";
    int result = parseVar();
    cout << "\n\n\npackageNode's value-->" << packageNode.value << endl;
    cout << "\n\n\npackageNode's child-->" << packageNode.child[0] << endl;
    cout << "importNode's child-->" << importNode.child[0] << endl;
    cout << "funcNode's child-->" << funcNode.child[0] << endl;
    return 0;

    /*
    char nextCharacterCheck;
      ifstream goFile ("example.go");
      if (goFile.is_open()) // Check the file opend correctly
      {
        while(goFile >> noskipws >> nextCharacterCheck) { // process nextCharacterCheck here, along with whitespaces


        nextCharacter(nextCharacterCheck);

        }

        if(goFile.eof()){ // eofBit set to true
            cout <<"\nEnd of the file" << endl;
        }
        goFile.close();
      }

      else cout << "Unable to open file";

      string returningWord;
string nextWord(string nextCharacterCheck){

	if(!isspace(nextCharacterCheck)){
		returningWord += nextCharacterCheck;
	}
	returningWord.clear();
	return returningWord;
}*/
}

//testing my branch

