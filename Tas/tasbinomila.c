
# inclut  < stdio.h >
# inclut  < stdlib.h >
# inclut  < limits.h >

# inclure  " heap.h "

jeton struct {
	int prio;
	const  char * str;
};

# définir  LONGUEUR ( a ) ( sizeof (a) / sizeof (a [ 0 ]))

jeton struct tokens1 [] = {
	{ 24 , " all " }, { 16 , " star " }, { 9 , " true. \n Singing " }, { 7 , " clear " },
	{ 25 , " louanges " }, { 13 , " à " }, { 5 , " Talon " }, { 6 , " voix \n Sonnerie " },
	{ 26 , " ta. " }, { 21 , " brillance \n Carolina " }, { 117 , " rah, " }, { 102 , " goudron " },
	{ 108 , " élevé \n Et " }, { 125 , " Rah! " }, { 107 , " Heel " }, { 118 , " Rah, " },
	{ 111 , " die \n I'm " }, { 115 , " dead. \n So " }, { 120 , " Rah, " },
	{ 121 , " Car'lina-lina \n Rah, " }, { 109 , " quand " }, { 105 , " a " },
	{ 123 , " Car'lina-lina \n Rah! " }, { 110 , " I " }, { 114 , " Heel " }, { 101 , " a " },
	{ 106 , " Tar " }, { 18 , " all \n Clear " }, { 14 , " the " }
};

jeton struct tokens2 [] = {
	{ 113 , " Tar " }, { 124 , " Rah! " }, { 112 , " a " }, { 103 , " Heel " },
	{ 104 , " born \n I'm " }, { 122 , " Rah, " }, { 119 , " Car'lina-lina \n Rah, " },
	{ 2 , " sound " }, { 20 , " radiance " }, { 12 , " NCU. N Hail " },
	{ 10 , " Carolina's " }, { 3 , " of " }, { 17 , " of " }, { 23 , " gem. \n Receive " },
	{ 19 , " its " }, { 0 , " \n Hark " }, { 22 , " inestimable " }, { 4 , " Tar " },
	{ 1 , " the " }, { 8 , " and " }, { 15 , " brightest " },
	{ 11 , " louanges. \n N Crier " }, { 100 , " \n je suis " }, { 116 , " c'est " }
};

# définir la  ligne  " \\n  =================================== "

disposition du jeton struct [] = {
	{ 90 , ligne}, {- 2 , ligne}, { 200 , ligne}, { 201 , " \n \n " }
};


titre du jeton struct [] = {
	{ 1000 , " \n UNC Alma Mater: " }, { 120 , " \n UNC Fight Song: " }
};

jeton struct mauvais [] = {
	{ 666 , " Dook " }, { 666666 , " Blue Devils " }
};

static  int  token_cmp ( struct heap_node * _a, struct heap_node * _b)
{
	jeton struct * a, * b;
	a = ( jeton struct *) heap_node_value (_a);
	b = ( jeton struct *) heap_node_value (_b);
	return a-> prio <b-> prio ;
}

static  void  add_token ( struct heap * heap, struct token * tok)
{
	struct heap_node * hn = malloc ( sizeof ( struct heap_node));
	heap_node_init (hn, tok);
	heap_insert (token_cmp, heap, hn);
}

static  void  add_token_ref ( struct heap * heap, struct token * tok,
			  struct heap_node ** hn)
{
	* hn = malloc ( sizeof ( struct heap_node));
	heap_node_init_ref (hn, tok);
	heap_insert (token_cmp, heap, * hn);
}

static  void  add_tokens ( struct heap * heap, struct token * tok, int len)
{
	int i;
	pour (i = 0 ; i <len; i ++)
		add_token (tas, jeton + i);
}

int  main ( int argc __attribute__ ((inutilisé)), char ** argv __attribute __ ((inutilisé)))
{
	tas de structure h1, h2, h3;
	struct heap_node * hn;
	struct heap_node * t1, * t2, * b1, * b2;
	struct token * tok;

	heap_init (& h1);
	heap_init (& h2);
	heap_init (& h3);

	add_tokens (& h1, tokens1, LENGTH (tokens1));
	add_tokens (& h2, tokens2, LENGTH (tokens2));
	add_tokens (& h3, layout, LENGTH (layout));

	add_token_ref (& h3, title, & t1);
	add_token_ref (& h2, title + 1 , & t2);

	heap_union (token_cmp, & h2, & h3);
	heap_union (token_cmp, & h1, & h2);

	add_token_ref (& h3, bad, & b1);
	add_token_ref (& h3, mauvais + 1 , & b2);

	heap_union (token_cmp, & h1, & h3);

	heap_delete (token_cmp, & h1, b1);
	libre (b1);
	heap_delete (token_cmp, & h1, b2);
	gratuit (b2);

	titre [ 0 ]. prio = - 1 ;
	titre [ 1 ]. prio = 99 ;

	heap_decrease (token_cmp, & h1, t1);
	heap_decrease (token_cmp, & h1, t2);

	printf ( " htest: \n " );
	while (! heap_empty (& h1)) {
		hn = heap_take (token_cmp, & h1);
		tok = heap_node_value (hn);
		printf ( " % s  " , tok-> str );
		gratuit (hn);
	}
	retourner  0 ;
}