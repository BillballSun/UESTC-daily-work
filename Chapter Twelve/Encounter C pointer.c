/*********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
**********************************************************/

int main(void)
{
	int a;
	int *b = &a;
	int **c = &b;
	int ***d = &c;

	int e[1];
	int *f= e;
	int **g = &f;
	int ***h = &g;

	int i[1][2];
	int (*j)[2] = i;
	int (**k)[2] = &j;
	//Error, k = &i, WRONG!
	int (***l)[2] = &k;

	int m[1][2];
	int (*n)[1][2] = &m;
	int (**o)[1][2] = &n;
	int (***p)[1][2] = &o;

	int *r[1][2];
	int *(*s)[1][2] = &r;
	int *(**t)[1][2] = &s;
	int *(***u)[1][2] = &t;
	int *(****v)[1][2] = &u;

	int ***w[1][2];
	int ***(*x)[1][2] = &w;
	int ***(**y)[1][2] = &x;
	int ***(***z)[1][2] = &y;
	
	//int a[] definitely equal to int *a

	return 0;
}
