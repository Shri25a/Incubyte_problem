#include <iostream>
#include<vector>
using namespace std;

// Class space having position (x,y,z) and dirct (N, S, E, W, Up, Down)
class space
{

    private:
        // position co-ordinates(x,y,z), dirct of space in space
        int x;
        int y;
        int z;
        char dirct;

    public:
        // Constructor to initialize the space's position co-ordinates and dirct
        space(int startX, int startY, int startZ, char startdirct)
        {
            x = startX;
            y = startY;
            z = startZ;
            dirct = startdirct;
        }

        // NOTE: During movement in position co-ordinate
        // x co-ordinates changes => for East , West dirct
        // y co-ordinates changes => for North , South dirct
        // z co-ordinates changes => for Up , Down turn

        // Function to move the space forward (position co-ordinates changes)
        void movefront()
        {
            if (dirct == 'N')
            {
                y++;
            }
            else if (dirct == 'S')
            {
                y--;
            }
            else if (dirct == 'E')
            {
                x++;
            }
            else if (dirct == 'W')
            {
                x--;
            }
            else if (dirct == 'U')
            {
                z++;
            }
            else if (dirct == 'D')
            {
                z--;
            }
        }

        // Function to move the space backward (position co-ordinates changes)
        void moveback()
        {
            // Implement backward movement similar to forward movement but in the opposite dirct
            if (dirct == 'N')
            {
                y--;
            }
            else if (dirct == 'S')
            {
                y++;
            }
            else if (dirct == 'E')
            {
                x--;
            }
            else if (dirct == 'W')
            {
                x++;
            }
            else if (dirct == 'U')
            {
                z--;
            }
            else if (dirct == 'D')
            {
                z++;
            }
        }

        // Function to turn the space left (based on space's left hand)
        void moveleft()
        {
            if (dirct == 'N')
            {
                dirct = 'W';
            }
            else if (dirct == 'S')
            {
                dirct = 'E';
            }
            else if (dirct == 'E')
            {
                dirct = 'N';
            }
            else if (dirct == 'W')
            {
                dirct = 'S';
            }
            else if (dirct == 'U')
            {
                dirct = 'N'; // Left turn while facing up becomes North
            }
            else if (dirct == 'D')
            {
                dirct = 'S'; // Left turn while facing down becomes South
            }
        }

        // Function to turn the space right  (based on space's right hand)
        void moveright()
        {
            if (dirct == 'N')
            {
                dirct = 'E';
            }
            else if (dirct == 'S')
            {
                dirct = 'W';
            }
            else if (dirct == 'E')
            {
                dirct = 'S';
            }
            else if (dirct == 'W')
            {
                dirct = 'N';
            }
            else if (dirct == 'U')
            {
                dirct = 'S'; // Right turn while facing up becomes South
            }
            else if (dirct == 'D')
            {
                dirct = 'N'; // Right turn while facing down becomes North
            }
        }

        // Function to turn the space up (only dirct changes)
        void moveup()
        {
            // Implement upward turn logic to change the dirct
            if (dirct == 'N' || dirct == 'S' || dirct == 'E' || dirct == 'W')
            {
                dirct = 'U';
            }
            else if (dirct == 'U')
            {
                // The space is already facing up
                // You can choose to handle this differently if needed
            }
            else if (dirct == 'D')
            {
                dirct = 'N'; // Assume facing North after turning up from down
            }
        }

        // Function to turn the space down
        void movedown()
        {
            // Implement downward turn logic to change the dirct
            if (dirct == 'N' || dirct == 'S' || dirct == 'E' || dirct == 'W')
            {
                dirct = 'D';
            }
            else if (dirct == 'D')
            {
                // The space is already facing down
                // You can choose to handle this differently if needed
            }
            else if (dirct == 'U')
            {
                dirct = 'N'; // Assume facing North after turning down from up
            }
        }

        // Function to get the current position and dirct
        void currentstatus()
        {
            cout << "Position: (" << x << ", " << y << ", " << z << ") , ";
            cout << "dirct: " << dirct << "\n";
            cout<<endl;
        }

        //stores the mapping of operation char to actual operation function
        void operation(vector<char>vec)
        {
            for(int i=0;i<vec.size();i++)
            {
                if(vec[i]=='f') 
                { 
                    this->movefront();
                    this->currentstatus();
                }
                else if(vec[i]=='b') 
                { 
                    this->moveback();
                    this->currentstatus();
                }
                else if(vec[i]=='l') 
                {
                    this->moveleft();
                    this->currentstatus();
                }
                else if(vec[i]=='r') 
                {
                    this->moveright();
                    this->currentstatus();
                }
                else if(vec[i]=='u') 
                {
                    this->moveup();
                    this->currentstatus();
                }
                else if(vec[i]=='d') 
                {
                    this->movedown();
                    this->currentstatus();
                }
            }
        }

};


// Function to run tests for the space class
void runTests()
{
    // Initialize the space with a starting position and dirct
    space chandryan(0, 0, 0, 'N'); 
    cout<<"Start Position: ";
    chandryan.currentstatus(); // Input: Start Position: (0,0,0), dirct: N

    // Tests for movefront operation ----------------------------------------------------------
    
    // Test 1: Move forward when facing North
    chandryan.movefront();
    cout<<"movefront: ";
    chandryan.currentstatus(); // Expected: Position: (0, 1, 0), dirct: N

    // Test 2: Move forward again when facing North 
    chandryan.movefront();
    cout<<"movefront: ";
    chandryan.currentstatus(); // Expected: Position: (0, 2, 0), dirct: N
    
    // Tests for MoveBackword operation ----------------------------------------------------------

    // Test 1: Move backward when facing North
    chandryan.moveback();
    cout<<"moveback: ";
    chandryan.currentstatus(); // Expected: Position: (0, 1, 0), dirct: N

    // Test 2: Move backward again when facing North 
    chandryan.moveback();
    cout<<"moveback: ";
    chandryan.currentstatus(); // Expected: Position: (0, 0, 0), dirct: N
    
    // // Tests for moveleft operation ----------------------------------------------------------

    // // Test 1: Turn Left when facing North
    chandryan.moveleft();
    cout<<"moveleft: ";
    chandryan.currentstatus(); // Expected: Position: (0, 0, 0), dirct: W

    // // Test 2: Turn Left again when facing West 
    chandryan.moveleft();
    cout<<"moveleft: ";
    chandryan.currentstatus(); // Expected: Position: (0, 0, 0), dirct: S
    
    // Tests for moveright operation ----------------------------------------------------------

    // // Test 1: Turn Right when facing North
    chandryan.moveright();
    cout<<"moveright: ";
    chandryan.currentstatus(); // Expected: Position: (0, 0, 0), dirct: E

    // // Test 2: Turn Right again when facing East 
    chandryan.moveright();
    cout<<"moveright: ";
    chandryan.currentstatus(); // Expected: Position: (0, 0, 0), dirct: S
    
    // Tests for moveup operation ----------------------------------------------------------

    // Test 1: Turn Up when facing North
    chandryan.moveup();
    cout<<"moveup: ";
    chandryan.currentstatus(); // Expected: Position: (0, 0, 0), dirct: U
    
    // Tests for movedown operation ----------------------------------------------------------

    // Test 1: Turn Down when facing North
    chandryan.movedown();
    cout<<"movedown: ";
    chandryan.currentstatus(); // Expected: Position: (0, 0, 0), dirct: D
}

void runGivenTest()
{
    // Initialize the space with a starting position and dirct
    space chandryan(0, 0, 0, 'N'); 
    cout<<"Start Position: ";
    chandryan.currentstatus(); // Input: Start Position: (0,0,0), dirct: N

    //Commands = {'f', 'r', 'u', 'b', 'l'};

    // Test 1: Move forward when facing Position: (0,0,0), dirct: N
    chandryan.movefront();
    cout<<"movefront: ";
    chandryan.currentstatus(); // Expected: Position: (0, 1, 0), dirct: N

    // Test 2: Turn Right when facing with Position: (0, 1, 0), dirct: N
    chandryan.moveright();
    cout<<"moveright: ";
    chandryan.currentstatus(); // Expected: Position: (0, 1, 0), dirct: E

    // Test 3: Turn Up when facing Position: (0, 1, 0), dirct: E
    chandryan.moveup();
    cout<<"moveup: ";
    chandryan.currentstatus(); // Expected: Position: (0, 1, 0), dirct: U
    
    // Test 4: Move backward when facing North
    chandryan.moveback();
    cout<<"moveback: ";
    chandryan.currentstatus(); // Expected: Position: (0, 1, -1), dirct: U

    // Test 5: Turn Left when facing North
    chandryan.moveleft();
    cout<<"moveleft: ";
    chandryan.currentstatus(); // Expected: Position: (0, 1, -1), dirct: N

    // Required Final Position: (0, 1, -1) , dirct: N
}

int main()
{
    // cout<<"runTests for each individual function testing: "<<endl;
    // runTests();
    // cout<<"//---------------------//"<<endl;
    // cout<<"runGivenTest for entire commands for space movements testing: "<<endl;
    // runGivenTest();
    //---------------------------------------------------------------------------//

    //----------------Complete Running Program with input/output from User------------//
    // Initialize the space with a starting position and dirct
    int x,y,z;
    char dir;
    cout<<"Enter the current position co-ordinates and dirct: ";
    cin>>x>>y>>z>>dir;
    space chandryan(x, y, z, dir); //0 0 0 N
    // space chandryan(0, 0, 0, 'N');

    // print current position and dirct
    cout << "Current Position and dirct: " << endl;
    chandryan.currentstatus();
    //---------------------------------------------------------------------------//


    //---------------------------------------------------------------------------//
    // Execute commands : Commands: ['f', 'r', 'u', 'b', 'l']
    int num_of_operations;
    cout<<"Enter number of operations want to perform: ";
    cin>>num_of_operations;
    cout<<"Enter the sequence of commands you want to execute on space: "; //f,b,l,r,u,d
    vector<char> operation_vec;
    char op;
    for(int i=0;i<num_of_operations;i++)
    {
        cin>>op;
        operation_vec.push_back(op);
    }
    chandryan.operation(operation_vec);
    //---------------------------------------------------------------------------//
    
    // Get the final position and dirct
    cout << "Final Position and dirct: " << endl;
    chandryan.currentstatus();
    //---------------------------------------------------------------------------//
    return 0;
}