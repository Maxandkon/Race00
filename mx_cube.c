void mx_printchar(const char c);

void space (int i){
	for (int j = i; j > 0; j--)
		mx_printchar(' ');
}
	
void horiz (int n){
	mx_printchar('+');
	for ( ; n > 0; n--)
		mx_printchar('-');
	mx_printchar('+');
}

void flats (int *n2, int *j, int ofs, char ch){
	
	mx_printchar((ofs == 1) ? '/' : '|');
	space(*n2);
	mx_printchar((ofs == 1) ? '/' : '|');
	space(*j);
	*j += ofs;
	mx_printchar(ch);
	mx_printchar('\n');
}

void mx_cube(int n){
	if (n < 1) return;
		
	int j = 0;
	int n2 = n * 2;
	int nhalf = n / 2;
	
	
	space(nhalf+1);
	horiz(n2);
	mx_printchar('\n');
	
	
	for (int i = nhalf; i > 0; i--){
		space(i);
		flats(&n2, &j, 1, '|');
	}
	
	
	horiz(n2);
	space(j);
	mx_printchar('|');
	mx_printchar('\n');
	
	
	for (int i = nhalf - !(n % 2); i > 0; i--)
		flats(&n2, &j, 0, '|');	
	flats(&n2, &j, -1, '+');
	
	
	for (int i = nhalf; i > 0; i--)
		flats(&n2, &j, -1, '/');
	horiz(n2);
	mx_printchar('\n');
}

