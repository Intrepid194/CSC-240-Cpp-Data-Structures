/*****************************************************
// Author: Spencer Collins
// Date : 8/23/2025
// This program helps answers Questions 3 and 4 for Assignment 1. 
// This is the header file that defines the FractionType class for Questions 3 and 4.
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
        Checks if the fraction is negative.

        Parameters:
        -----------
        None.

        Returns:
        --------
        `bool`
            1 (true) if fraction is negative (num < 0), 0 (false) otherwise (num >= 0).
        */
        bool IsNegative();

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

        private:
            int num; // numerator
            int denom; // denominator
};