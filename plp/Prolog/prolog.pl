factorial(0, 1).
factorial(N, F) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, F1),
    F is N * F1.

fibonacci(1, 1). %quando 1,1
fibonacci(2, 1). %quando 2, 1
fibonacci(N, F) :-
    N > 2,
    N1 is N - 1,
    N2 is N - 2,
    fibonacci(N1, F1),
    fibonacci(N2, F2),
    F is F1 + F2.

serieG_term(I, Term) :-
    fibonacci(I, Fib),
    factorial(Fib, Fact),
    Fact \= 0,
    Term is I / Fact.

is_odd(N) :-
    N mod 2 =:= 1.

serieG_helper(N, I, Sum, Result) :-
    I > N,
    Result is Sum.
serieG_helper(N, I, Sum, Result) :-
    I =< N,
    serieG_term(I, Term),
    ( is_odd(I) ->
        NewSum is Sum + Term
    ; 
        NewSum is Sum - Term
    ),
    I1 is I + 1,
    serieG_helper(N, I1, NewSum, Result).

serieG(N, Result) :-
    ( N =:= 0 ->
        Result = false
    ; 
        serieG_helper(N, 1, 0, Result)
    ).


:- serieG(0, R0), write(R0), nl.
:- serieG(1, R1), write(R1), nl.
:- serieG(2, R2), write(R2), nl.
:- serieG(3, R3), write(R3), nl.
:- serieG(4, R4), write(R4), nl.
:- serieG(5, R5), write(R5), nl.
:- serieG(6, R6), write(R6), nl.
:- serieG(7, R7), write(R7), nl.
:- serieG(8, R8), write(R8), nl.
