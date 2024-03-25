
union RecordType // Declare a simple union type
{
public: // default
    char ch;
    int i;
    long l;
    float f;
    double d;
    int *int_ptr;
};
int main()
{
    RecordType t;
    t.i = 5;    // t holds an int
    t.f = 7.25; // t now holds a float
}