
# Grammar


The parser works by Leftmost Derivaton

E -> E + E| E - E| E * E| E/E | a | b | c

  non-terminals
	+ - * / a b c
	
Sample input = "1-2+2" Line 1 of example0.go

                    E
                 /     \
              E         \
            /            \
           +              \
           E               E
        /  |  \             \
       E   -   E             2
      /          \
     1            2
