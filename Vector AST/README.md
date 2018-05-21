
# Grammar


The parser works by Leftmost Derivaton

E -> E + E| E - E| E * E| E/E | a | b | c

  non-terminals
	+ - * / a b c
	
Sample input = "1+2-3"

                    E
                 /     \
              E         \
            /            \
           +              \
           E               E
        /  |  \             \
       E   -   E             3
      /          \
     1            2
