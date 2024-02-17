prime_table(2).
prime(2).
prime(N) :- prime_table(N), !.
prime(N) :- 
	0 < mod(N, 2),
	prime(N, 3).

prime(N, P) :- P * P > N.

prime(N, P):- 
	0 < mod(N, P),
	prime(N, P + 2),
	assert(prime_table(N)), !.

composite(N) :- \+prime(N).

prime_divisors(1, [], _) :- !.
prime_divisors(N, [N | T], P) :- P > N, !.

prime_divisors(N, D, P) :-
	(0 < mod(N, P); composite(P)),
	P1 is P + 1,
	prime_divisors(N, D, P1), !.

prime_divisors(N, [P | T], P) :-
	prime(P),
	0 is mod(N, P),
	N1 is N / P,
	prime_divisors(N1, T, P), !.

prime_divisors(N, D):-
	N > 0,
	prime_divisors(N, D, 2), !.

nth_prime(1, 2) :- !.
nth_prime(N, P) :- 
	nth_prime(N, P, 2), !.

nth_prime(0, P, S) :- composite(S), S1 is S - 1, nth_prime(0, P, S1), !.
nth_prime(0, S, S) :- !.

nth_prime(N, P, S) :- 
	composite(S),
	S1 is S + 1,
	nth_prime(N, P, S1), !.

nth_prime(N, P, S) :-
	N1 is N - 1,
	S1 is S + 1,
	nth_prime(N1, P, S1), !.