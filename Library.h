#pragma once

#include <iostream>
#include <vector>
#include "Book.h"

using Catalog = std::vector<BookLibrary>;
class Library {
    std::string name;
    unsigned short built_date;
    Catalog catalog;
    std::vector<Member> members;
    std::vector<Librarian> librarians;
};
