/*
Description: Using class and pointers and dowcasting to look
through a box of chocholates and select them and print out
the selction using a virtual function
Input: input is an command line argument that acts as the
seed for the rand vlaues.
Output: the putput is the type of chocolate there is and
the print that follows that function. it coninues untill a
rand empty value is reached
*/
#include <iostream>
#include <cstdlib> //srand library
#include <string>  //string library
using namespace std;

class chocolate
{
public:
    virtual string whatamI() = 0; // pure virtual function
    // chocolate();
    virtual ~chocolate(){};
};

class dark : public chocolate
{
public: // functions for subclass
    string whatamI() { return "dark"; }
    void feelBitter()
    { // done
        cout << "Dark Chocolate: oof that was bitter!" << endl;
    }
};

class milk : public chocolate
{
public: // functions for subclass
    string whatamI() { return "milk"; }
    void feelSoft()
    { // done
        cout << "Milk Chocolate: Too soft, no chocolate taste!" << endl;
    }
};

class hazelnut : public chocolate
{
public: // functions for subclass
    string whatamI() { return "hazelnut"; }
    void getAllergy()
    { // done
        cout << "Hazelnut Chocolate: I don't feel so good." << endl;
    }
};

class raspberry : public chocolate
{
public: // functions for subclass
    string whatamI() { return "raspberry"; }
    void telljoke()
    { // done
        cout << "Raspberry Chocolate: I don't always Raspberry,"
             << " but when I do, I Raspberry Pi" << endl;
    }
};

class white : public chocolate
{
public: // functions for subclass
    string whatamI() { return "white"; }
    void feelScammed()
    { // done
        cout << "White Chocolate: Is this even real chocolate?" << endl;
    }
};

class mint : public chocolate
{
public: // functions for subclass
    string whatamI() { return "mint"; }
    void feelInquisitive()
    { // done
        cout << "Mint Chocolate: Am I still eating chocolate"
             << " or am I brushing my teeth?" << endl;
    }
};

class boxOfChocolates
{
private:
    int length;
    int width;
    chocolate ***box;

public:
    boxOfChocolates(int length = 6, int width = 5) //done 
    : length(length), width(width)
    {

        box = new chocolate **[length]; // dynamically assigned length
        for (int i = 0; i < length; i++)
        {
            box[i] = new chocolate *[width]; //dynamically assigned width
        }
        fillBox();
    }
    ~boxOfChocolates() //done 
    {
        //checking if null 
        if (box != NULL)
        {
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (box[i][j] != NULL)
                    {
                        delete box[i][j]; // deletes stored ptr
                    }
                }
                delete[] box[i]; // deletes sub array
            }
        }
        delete[] box; // deletes outer array
        box = NULL;   // sets to null
    }
    void fillBox();
    bool takeChocolate();
};
void boxOfChocolates::fillBox()
{
    // irrerate though the array to randomly fill chocolate

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int y = rand() % 6;
            switch (y)
            {
                // conditions to check results on rand
            case 0:
                box[i][j] = new dark;//done 
                break;
            case 1:
                box[i][j] = new milk;//done 
                break;
            case 2:
                box[i][j] = new hazelnut;//done 
                break;
            case 3:
                box[i][j] = new raspberry;//done 
                break;
            case 4:
                box[i][j] = new white;//done
                break;
            case 5:
                box[i][j] = new mint; //done 
                break;
                // default:cout << "Error\n"; break;
            }
        }
    }
};
bool boxOfChocolates::takeChocolate()
{
    int i = rand() % length;
    int j = rand() % width;
    chocolate *name = box[i][j];

    // condition if box is false
    if (box[i][j] == NULL)
    {
        return false;
    }
    // declaring new pointer to check
    // down casting dark
    if (name->whatamI() == "dark")//done 
    {
        dark *dobj = dynamic_cast<dark *>(name);
        dobj->feelBitter();
    }
    // downcasting milk
    else if (name->whatamI() == "milk")//done 
    {
        milk *dobj = dynamic_cast<milk *>(name);
        dobj->feelSoft();
    }
    // downcasting hazelnut
    else if (name->whatamI() == "hazelnut")//done 
    {
        hazelnut *dobj = dynamic_cast<hazelnut *>(name);
        dobj->getAllergy();
    }
    // down casting raspberry
    else if (name->whatamI() == "raspberry")//done 
    {
        raspberry *dobj = dynamic_cast<raspberry *>(name);
        dobj->telljoke();
    }
    // downcasting white
    else if (name->whatamI() == "white")//done 
    {
        white *dobj = dynamic_cast<white *>(name);
        dobj->feelScammed();
    }
    else if (name->whatamI() == "mint") //done 
    {
        // down casting mint
        mint *dobj = dynamic_cast<mint *>(name);
        dobj->feelInquisitive();
    }
    delete name;
    box[i][j] = NULL;

    return true;
};
int main(int argc, char *argv[])
{

    // chocolate dobj1;
    // boxOfChocolates dobj2;
    if (argc != 2)
    {
        cout << "Error argument\n";
        return 0;
    }
    srand(atoi(argv[1]));
    boxOfChocolates ChocolateBox;
    //bool choice;
    // print statment
    cout << "\"My mom always said life was like a"
         << " box of chocolates."
         << " You never know what you're gonna get."
         << "\" - Forrest Gump" << endl;
    // loop to check if null is reached
    while (true)
    {
        // bool to check if its true or false
        bool choice = ChocolateBox.takeChocolate();
        // if its flase to break
        if (choice == false)
        {
            break;
        }
    }

    return 0; // ending
}
// no need to call distructor
// use a loop to check if true in main
// done with code
// done
