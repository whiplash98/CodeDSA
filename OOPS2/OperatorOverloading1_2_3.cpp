//Operator Overloading 1


// Operator Overloading means extending functionalities of preexisting operators.
// such that it'll work for out user defined class also

// e.g int c = a + b;
// similarly, extend it for fractions, F1 = F2 + F3


//modified add fuction to return fraction in a new seperate fNew 
Fraction add(Fraction const &f2)
{
    int lcm = denominator* f2.denominator;

    int x = lcm/denominator;
    int y = lcm/f2.denominator;

    int num = x*numerator + (y*f2.numerator);

    Fraction fNew(num, lcm);
    fNew.simplify();
    return fNew;
}

// just as above, operator overloading on +
// SYNTAX: operator+
// param me const reference to prevent any illegal changes
Fraction operator+(Fraction const &f2) const //doesnt change anything in this
{
    int lcm = denominator* f2.denominator;

    int x = lcm/denominator;
    int y = lcm/f2.denominator;

    int num = x*numerator + (y*f2.numerator);

    Fraction fNew(num, lcm);
    fNew.simplify();
    return fNew;
}

//overloading on multiply operator
Fraction operator*(Fraction const &f2) const
{
    int n = numerator*f2.numerator;
    int d = denominator*f2.denominator;
    Fraction fNew(n, d);
    fNew.simplify();
    return fNew;
}

// overloading  == for fractions
bool operator==(Fraction const &f2) const
{
    // numerator mtlb this->nuerator, which means f1 numerator
    return (numerator == f2.numerator && denominator == f2.denominator);
}


int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    Fraction f3 = f1.add(f2);
    f1.print();
    f2.print();
    f3.print();
    //using operator overloading
    Fraction f4 = f1+f2;
    f4.print();

    Fraction f5 = f1*f2;
    f5.print();

    if(f1 == f1)
        cout<<"Equal:"<<endl;
    else
        cout<<"Not equal"<<endl;

}



// Operator Overloading 2


// Pre-increment
//we cant make this function const, as were changing values of this->
        Fraction& operator++() {// & means returned by reference, directly from location where ++f was calculated and thus prevents wastage of buffer
            numerator = numerator + denominator;
            simplify();

            return *this;   //returning complete block of num and denom
        }

int main() {
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    f1.print();
    Fraction f3 = ++(++f1);
    f1.print();
    f3.print();





    //++f1;
    //f1.print();

    /*
    Fraction f3 = ++f1;
    f1.print();
    f3.print();
    */
    /*
    Fraction f3 = f1.add(f2);
    Fraction f4 = f1 + f2;
    f1.print();
    f2.print();
    f3.print();
    f4.print();

    Fraction f5 = f1 * f2;
    f5.print();

    if(f1 == f2) {
        cout << "Equal" << endl;
    }
    else {
        cout << "Not equal " << endl;
        
    }
    */
}   

//PART 3:

// Post-increment
		Fraction operator++(int) {
			Fraction fNew(numerator, denominator);
			numerator = numerator + denominator;
			simplify();
			fNew.simplify();
			return fNew;
		}


		Fraction& operator+=(Fraction const &f2) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			numerator = num;
		  denominator = lcm;
			simplify();

			return *this;
		}

int main() {

	int i = 5, j = 3;
	(i += j) += j;

	cout << i << " " << j << endl;

	Fraction f1(10, 3);
	Fraction f2(5, 2);

	
	(f1 += f2) += f2;

	f1.print();
	f2.print();



	/*
	Fraction f3 = f1++;
	f1.print();
	f3.print();
	*/

	/*
	f1.print();
	Fraction f3 = ++(++f1);
	f1.print();
	f3.print();
	*/




	//++f1;
	//f1.print();

	/*
	Fraction f3 = ++f1;
	f1.print();
	f3.print();
	*/
	/*
	Fraction f3 = f1.add(f2);
	Fraction f4 = f1 + f2;
	f1.print();
	f2.print();
	f3.print();
	f4.print();

	Fraction f5 = f1 * f2;
	f5.print();

	if(f1 == f2) {
		cout << "Equal" << endl;
	}
	else {
		cout << "Not equal " << endl;
		
	}
	*/
}

