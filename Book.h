#pragma once
#include <iostream>
#include "Member.h"

enum class eBookState{
    BRAND_NEW,
    WELL_PRESERVED,
    AGED,
    MUTILATED,
};

class BookBase {
    std::string name, editor, author, genre;
    unsigned short year;
};

class Bookshelf{
    unsigned short bookshelfID;
};

class BookLibrary : public BookBase{
    eBookState state;
    Bookshelf location;
    bool borrowed;
    Member * holder;

public:
    BookLibrary();
    BookLibrary(eBookState state, const Bookshelf &location, bool borrowed);
};