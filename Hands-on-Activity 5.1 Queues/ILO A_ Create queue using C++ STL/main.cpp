#include <iostream>
#include <queue>
using namespace std;

void display(queue <string> q)
{
    queue <string> c = q;
    while (!c.empty())
        {
            cout << ", " << c.front();
            c.pop();
        }
    cout << "\n";
}

int main()
{
    queue <string> student;
    
    student.push("Helge Hroarr");
    student.push("Nara Greene");
    student.push("Ríonach Ó Conchobhairi");
    
    cout << "The queue student is :";
    display(student);
    
    cout << "student.empty() :" << student.empty() << "\n";
    cout << "student.size() : " << student.size() << "\n";
    cout << "student.front() : " << student.front() << "\n";
    
    cout << "student.back() : " << student.back() << "\n";
    cout << "student.pop() : ";
    student.pop();
    
    display(student);
    student.push("Raguel Allobrogicus");
    cout << "The queue student is :";
    display(student);
    
    return 0;
}