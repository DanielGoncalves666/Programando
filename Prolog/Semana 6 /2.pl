total(Q1,Q2,Q3,Q4,Q5,Q6,Q7,Q8,Total) :- Total is Q1 * 1.5 + Q2 * 3.0 + Q3 * 1.5 +  Q4 * 0.5 + Q5 * 0.5 + Q6 * 1.5 + Q7 * 0.5 + Q8 * 1.0.

tempoTotal(Q1,Q2,Q3,Q4,Q5,Q6,Q7,Q8,TT) :- TT is Q1 * 22 + Q2 * 17 + Q3 * 13 + Q4 * 12 + Q5 * 11 + Q6 * 16 + Q7 * 10 + Q8 * 21.

responde(0).
responde(1).

prova(Q1,Q2,Q3,Q4,Q5,Q6,Q7,Q8,Valor,Tempo) :-
	responde(Q1), responde(Q2), responde(Q3), responde(Q4), responde(Q5), responde(Q6), responde(Q6), responde(Q7), responde(Q8), total(Q1,Q2,Q3,Q4,Q5,Q6,Q7,Q8,Total), Total >= Valor, tempoTotal(Q1,Q2,Q3,Q4,Q5,Q6,Q7,Q8,TT), TT =< Tempo,

