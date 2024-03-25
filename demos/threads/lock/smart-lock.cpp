// RAII - resource allocation IS initialization

#include <thread>
#include <mutex>
#include <iostream>
#include <assert.h>

using namespace std;

class SmartLock
{
public:
    explicit SmartLock(mutex *m) : _pMutex(m)
    {
        cout << "Locking...";
        _pMutex->lock();
    }
    ~SmartLock()
    {
        cout << "Unlocking" << endl;
        _pMutex->unlock();
    }

private:
    mutex *_pMutex;
};

void useSmartLock()
{
    cout << "Use SmartLock" << endl;
    mutex m;
    {
        SmartLock sl(&m);

        cout << "Running code in lock...";
    }

    cout << "Done SmartLock" << endl;
}

int main()
{
    useSmartLock();

    return 0;
}
