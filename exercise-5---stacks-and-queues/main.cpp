#include <iostream>
#include <stack>
using namespace std;
stack<string>pl;

void displayS(stack<string>pl);
void displayQ(stack<string>pl);


int main()
{
    
    cout << "Push Elements into stack: " << "\n";
    //add items to stack
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    cout << "Initial stack: " << endl;
    displayS(pl);
    
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    cout << "\n" << "Final queue: ";
    //create stacks into queue
    displayQ(pl);
    
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    //limited input
    cout << "\n" << "Limiter stack: ";
    return 0;
}


void displayS(stack<string>pl)
{
    while(!pl.empty())
    {
        cout << pl.top() << ", ";
        pl.pop();
    }
}

void displayQ(stack<string>pl)
{
    string queue[3] = {"0","0","0"};
    queue[2] = pl.top();
    
    pl.pop();
    queue[1] = pl.top();
    
    pl.pop();
    queue[0] = pl.top();
    
    cout << queue[0] << ", " << queue[1] << ", " << queue[2];
    
    
}

void inputLimiter(stack<string>pl)
{
    cin >>
    
    
    
}
