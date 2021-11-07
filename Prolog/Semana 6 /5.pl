ackerman(M, N, R) :- M = 0, R is N + 1, !;
					 M > 0, N = 0, Aux is M - 1, ackerman(Aux, 1, R), !;
					 Aux is N - 1, Aux_2 is M - 1, ackerman(M, Aux, R1), ackerman(Aux_2, R1, R). 
