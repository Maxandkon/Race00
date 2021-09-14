void mx_printchar(const char c);

void space (int i){
	for ( ; i > 0; i--)
		mx_printchar(' ');
}

void flats (int *b1, int *b2, int *b3, int ofs){
	space(*b1);
	mx_printchar('/');
	space(*b2);
	mx_printchar('\\');
	space(*b3);
	*b1 -=1;
	*b2 += 2;
	*b3 += ofs;
	mx_printchar((ofs == 1) ? '\\' : '|');
	mx_printchar('\n');
}

void mx_pyramid(int n){
	if ((n < 2) || (n % 2 != 0)) return;
	
	int blank1, blank2, blank3;
	blank1 = n-2;
	blank2 = 1;
	blank3 = 1;
	
	
	space(n-1);
	mx_printchar('/');
	mx_printchar('\\');
	mx_printchar('\n');
	
	
	for (int i = (n-1)/2; i > 0; i--)
		flats(&blank1, &blank2, &blank3, 1);
	
	
	blank3--;
	for (int i = (n-2)/2; i > 0; i--)
		flats(&blank1, &blank2, &blank3, -1);
	
	
	mx_printchar('/');	
	for (int i = n*2 - 3; i > 0; i--)
		mx_printchar('_');	
	mx_printchar('\\');
	mx_printchar('|');
	mx_printchar('\n');
}

