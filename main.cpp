#include "LoadUc.h"

using namespace std;

int main()
{
    vector<ucTurma> data = LoadUc();
    for (auto e: data)
    {
        cout << e.mecaNumber << " | " << e.classCode << endl;
    }
    return 0;
}