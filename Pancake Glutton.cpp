/*
    Write a program that asks the userto enter the number of pancakes eaten for
    breakfast by 10 different people (Person 1, Person 2, ..., Person 10). Once
    the data has been entered, the program must analyze the data and output which
    person ate the most pancakes for breakfast

    Modify the program so that it also outputs which person ate the least number of
    pancakes for breakfast

    Modify the program so that it outputs a list in order of number of pancakes eaten
    of all 10 people
    i.e.
    Person 4: ate 10 pancakes
    Person 3: ate 7 pancakes
    Person 8: ate 4 pancakes
    ...
    Person 5: ate 0 pancakes
*/

#include <iostream>
#include <string>

using namespace std;

// this is where the user's input will be stored
// this keeps track of the number of pancakes eaten by which person
// person 1 is pancakesEaten[0], person 2 is pancakesEaten[1], etc etc
int pancakesEaten[10];


// stores the index number for ate the most pancakes
int morePancakesEaten;

// stores the largestIndex of who ate the most pancakes, smallestIndex holds the index
// of the person who ate the least pancakes, and temp temporarily stores the most
// pancakes eaten
int largestIndex, smallestIndex, temp;

int main()
{
    
    cout << "Please enter in the number of pancakes eaten for 10 people: " << endl;

    // for loop that will ask the user for a value which is equivalent to the number
    // of pancakes eaten by a person, person 1 is arr[0], person 2 is [1], etc etc
    for (int i = 0; i < size(pancakesEaten); i++)
    {
        cout << "Pancakes eaten by Person " << i + 1 << ": ";
        cin >> pancakesEaten[i];
    }

    // sets largestIndex equal to pancakesEaten[0], compares it to the current value in
    // pancakesEaten[i], then stores the higher values index in morePancakesEaten
    // temp then gets set to the next index value
    temp = pancakesEaten[0];
    for (int i = 0; i < size(pancakesEaten); i++)
    {
        
        if (temp < pancakesEaten[i])
        {
            temp = pancakesEaten[i];
            largestIndex = i;
        }
    }

    // sets temp back to the first index in pancakesEaten and starts up a new for loop
    // that will find the person who ate the least amount of pancakes
    temp = pancakesEaten[0];
    for (int i = 0; i < size(pancakesEaten); i++)
    {

        if (temp > pancakesEaten[i])
        {
            temp = pancakesEaten[i];
            smallestIndex = i;
        }
    }

    cout << endl;

    // creates an array that will be used to store the Person number which will correspond
    // to the sorted array
    int personNumber[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // sorts through pancakesEaten from greatest to least, and stores the number in the
    // array sortedPersonPancakes. The top array stores the person it is, and the second
    // array will store how many pancakes were eaten
    temp = pancakesEaten[0];
    int tempPerson = personNumber[0];
    for (int i = 0; i < size(pancakesEaten); i++)
    {
        if (pancakesEaten[i] < pancakesEaten[i + 1])
        {
            temp = pancakesEaten[i];
            pancakesEaten[i] = pancakesEaten[i + 1];
            pancakesEaten[i + 1] = temp;

            tempPerson = personNumber[i];
            personNumber[i] = personNumber[i + 1];
            personNumber[i + 1] = tempPerson;
            // updates the value of i = -1 so that the loop will start over
            i = -1;
            
        }
        
    }

    cout << "Person " << largestIndex + 1 << " ate the most pancakes." << endl;
    cout << "Person " << smallestIndex + 1 << " ate the least pancakes." << endl;
    // used just as a spacer
    cout << endl;

    for (int i = 0; i < size(pancakesEaten); i++)
    {
        cout << "Person " << personNumber[i] << " ate " << pancakesEaten[i] << " pancakes." << endl;
    }
}

