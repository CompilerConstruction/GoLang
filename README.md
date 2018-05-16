# GoLang  
GoLang Compiler  

## Context Free Grammar Draft  
LINE -> TYPE NAME | ASSIGNMENT  
TYPE -> string  
NAME -> string  
ASSIGNMENT -> NAME VALUE  
VALUE = string  

Simplified  
L -> TN | A  
T -> string  
N -> string  
A -> NV  
V = string  

explanation:  
Line is a line of code  
Type is a type of data, e.g. import or func  
Name is a naame of a type e.g. "main" or "fmt"  
Assignment is a variable assignment, e.g. pi = 3.14  
Value is a value assigned to variable, e.g. 5 or "test"  

## Reading from a .go file  
char buffer[200];  
ifstream myFile("example.go", ios::in | ios::binary);  
myFile.read(buffer, 200);   
x=buffer;  
