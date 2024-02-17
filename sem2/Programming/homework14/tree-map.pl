count([], 0).
count([_ | T], R) :- count(T, TR), R is TR + 1.

nodo(Lista, K, LC, RC, nodo(Lista, K, LC, RC)).
lista(Lista, lista(Lista)).

get_by_index(Lista, N, R1, R2) :- dp(Lista, N, (R1, R2)), !.

run_list(_, [], _).
run_list(L, [H | T], Index) :- 
	assert(dp(L, Index, H)),
	Index1 is Index + 1,
	run_list(L, T, Index1), !.

map_get(Nodo, Key, Value) :- 
	nodo(K, Value, _, _, Nodo),
	K = Key, !.

map_get(Nodo, Key, Value) :- 
	nodo(K, _, LL, _, Nodo),
	Key < K,
	map_get(LL, Key, Value), !.

map_get(Nodo, Key, Value) :- 
	nodo(K, _, _, RR, Nodo),
	Key > K,
	map_get(RR, Key, Value), !.

map_replace(Nodo, Key, Value, Result) :- 
	nodo(K, _, LL, RR, Nodo),
	Key is K,
	nodo(K, Value, LL, RR, Result), !.

map_replace(Nodo, Key, Value, Result) :- 
	nodo(K, _, _, RR, Nodo),
	Key > K,
	map_replace(RR, Key, Value, Result), !.

map_replace(Nodo, Key, Value, Result) :- 
	nodo(K, _, LL, _, Nodo),
	Key < K,
	map_replace(LL, Key, Value, Result), !.

map_build(_, Beg, End, R) :- Beg > End, nodo(-1, -1, -1, -1, R), !.

map_build(Lista, Beg, End, R) :- 
	Beg =< End,
	Mid is (Beg + End) // 2,
	Mid1 is Mid - 1,
	Mid2 is Mid + 1,
	map_build(Lista, Beg, Mid1, LC),
	map_build(Lista, Mid2, End, RC),
	get_by_index(Lista, Mid, Key, Value),
	nodo(Key, Value, LC, RC, R).

map_build(ListMap, TreeMap) :-
	lista(ListMap, L),
	run_list(L, ListMap, 0),
	count(ListMap, C),
	map_build(L, 0, C - 1, TreeMap).