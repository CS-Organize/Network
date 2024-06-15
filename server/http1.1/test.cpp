#include <iostream>
#include <sstream>
using namespace std;

int main(void)
{
    istringstream iss("GET /index.html HTTP/1.1  aa");
    string method, requestURL, httpVersion;
    if (iss >> method >> requestURL >> httpVersion && iss.eof())
    {
        cout << "method: " << method << endl;
        cout << "requestURL: " << requestURL << endl;
        cout << "httpVersion: " << httpVersion << endl;
    }
    else
    {
        cout << "fail" << endl;
    }
    cout << "method: " << method << endl;
    cout << "requestURL: " << requestURL << endl;
    cout << "httpVersion: " << httpVersion << endl;
    return 0;
}
