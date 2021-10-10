
#include<string>
#include<iostream>
using namespace std;

int main()
{
    enum JDirection { JD_INVALID,
                      JD_X_POS, JD_X_NEG,
                      JD_Y_POS, JD_Y_NEG,
                      JD_Z_POS, JD_Z_NEG };
    JDirection J_direction;

    J_direction = JD_INVALID;
    cout << J_direction << endl;
    // String J_direction_str = GetStringInitValue("J_direction","-z");
    return 0;
}