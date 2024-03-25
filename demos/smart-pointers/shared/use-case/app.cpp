// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring &artist_, const std::wstring &title_) : artist{artist_}, title{title_} {}
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring &date_,
        const std::wstring &location_,
        const std::wstring &subject_) : date{date_}, location{location_}, subject{subject_} {}
};

using namespace std;

/*
 The following example shows various ways to declare and initialize a shared_ptr together with a new object.
 */
void example1()
{
    // Use make_shared function when possible.
    shared_ptr<Song>  sp1 = make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");

    // Using new expression as constructor argument
    // creates no named variable for other code to access.
    shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));

    // When initialization must be separate from declaration, e.g. class members,
    // initialize with nullptr to make your programming intent explicit.
    shared_ptr<Song> sp5(nullptr);
    // Equivalent to: shared_ptr<Song> sp5;
    //...
    sp5 = make_shared<Song>(L"Elton John", L"I'm Still Standing");
}

/*
You can wrap elements in a shared_ptr, and then copy it into other containers with the
understanding that the underlying memory is valid as long as you need it, and no longer.
The following example shows how to use the remove_copy_if algorithm on shared_ptr instances in a vector.
*/
void example()
{
    vector<shared_ptr<Song>> v{
        make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
        make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
        make_shared<Song>(L"Thalía", L"Entre El Mar y Una Estrella")};

    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](shared_ptr<Song> s)
                   { return s->artist.compare(L"Bob Dylan") == 0; });

    for (const auto &s : v)
    {
        wcout << s->artist << L":" << s->title << endl;
    }
}

int main()
{
    example();
}