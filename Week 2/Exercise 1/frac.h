/*****************************************************
// Author: Spencer Collins
// Date : 8/23/2025
// This program helps answer Question 3 for Assignment 1. 
// This is the header file that defines the FractionType class for Question 3.
//***************************************************/

class FractionType {
    public:
        /*
        Initializes the FractionType class and its properties.

        Parameters:
        -----------
        numerator : `int`
            Fraction numerator.
        denominator : `int`
            Fraction denominator.

        Returns:
        --------
        `void`
            Nothing.
        */
        void Initialize(int numerator, int denominator);      

        /*
        Gets the fraction numerator.

        Parameters:
        -----------
        None.

        Returns:
        --------
        `int`
            Fraction numerator.
        */
        int NumeratorIs();

        /*
        Gets the fraction denominator.

        Parameters:
        -----------
        None.

        Returns:
        --------
        `int`
            Fraction denominator.
        */
        int DenominatorIs();

        /*
        Checks if the fraction is zero.

        Parameters:
        -----------
        None.

        Returns:
        --------
        `bool`
            1 (true) if fraction is zero (num == 0), 0 (false) otherwise (num > 0 | num < 0).
        */
        bool IsZero();

        /*
        Checks if the fraction is proper or not.

        Parameters:
        -----------
        None.

        Returns:
        --------
        `bool`
            1 (true) if fraction is not proper (num >= denom), 0 (false) otherwise (num < denom).
        */
        bool IsNotProper();

        /*
        Converts improper fraction to mixed fraction (or number).

        Parameters:
        -----------
        None.

        Returns:
        --------
        `int`
            The whole number for the mixed fraction.
        */
        int ConvertToProper();

        /*
        Prints out the fraction.

        Parameters:
        -----------
        None.

        Returns:
        --------
        `void`
            Nothing.
        */
        void print();

        /*
        Addition (`+`) Operator overloader for FractionType class.

        Parameters:
        -----------
        addend : `const FractionType&`
            Direct reference to the FractionType class instance "addend".

        Returns:
        --------
        `FractionType`
            FractionType class instance with numerator and denominator calculated as follows:
                frac3.num `=` frac1.num`*`frac2.denom `+` frac2.num`*`frac1.denom
                frac3.denom `=` frac1.denom  `*` frac2.denom
        */
        FractionType operator +(const FractionType & addend);

        /*
        Subtraction (`-`) Operator overloader for FractionType class.

        Parameters:
        -----------
        addend : `const FractionType&`
            Direct reference to the FractionType class instance "addend".

        Returns:
        --------
        `FractionType`
            FractionType class instance with numerator and denominator calculated as follows:
                frac3.num `=` frac1.num`*`frac2.denom `-` frac2.num`*`frac1.denom
                frac3.denom `=` frac1.denom  `*` frac2.denom
        */
        FractionType operator -(const FractionType & addend);

        /*
        Subtract (`*`) Operator overloader for FractionType class.

        Parameters:
        -----------
        addend : `const FractionType&`
            Direct reference to the FractionType class instance "addend".

        Returns:
        --------
        `FractionType`
            FractionType class instance with numerator and denominator calculated as follows:
                frac3.num `=` frac1.num `*` frac2.num
                frac3.denom `=` frac1.denom `*` frac2.denom
        */
        FractionType operator *(const FractionType & addend);

        /*
        Division (`/`) Operator overloader for FractionType class.

        Parameters:
        -----------
        addend : `const FractionType&`
            Direct reference to the FractionType class instance "addend".

        Returns:
        --------
        `FractionType`
            FractionType class instance with numerator and denominator calculated as follows:
                frac3.num `=` frac1.num `/` frac2.num
                frac3.denom `=` frac1.denom `/` frac2.denom
        */
        FractionType operator /(const FractionType & addend);

        private:
            int num; // numerator
            int denom; // denominator
};