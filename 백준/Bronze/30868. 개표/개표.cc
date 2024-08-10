#include<iostream>


using namespace std;
int t, n;
int main(int argc, char** argv)
{
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        int a = n / 5;
        int b = n % 5;
        for(int i=0; i<a; i++)
        {
            cout << "++++ ";
        }
        for(int i=0; i<b; i++)
        {
            cout << '|';
        }
        cout << endl;
    }
   return 0;
}