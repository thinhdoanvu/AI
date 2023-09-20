create_list(List):- List=[1,2,3].
print_element_at_position(List, Position) :-
    nth1(Position, List, Element),
    write('Ph?n t? t?i v? trí '), write(Position),
    write(' là '), write(Element), nl.
