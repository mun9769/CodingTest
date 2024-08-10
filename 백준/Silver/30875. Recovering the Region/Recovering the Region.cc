#include<iostream>


using namespace std;
int n, a;
int main(int argc, char** argv)
{
    cin >> n;
    for(int i=0; i<n*n; i++) cin >> a;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << i+1 << ' ';
        }
        cout << endl;
    }

   return 0;
}