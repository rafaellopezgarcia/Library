#include "Book.h"

BookLibrary::BookLibrary(eBookState state, const Bookshelf &location, bool borrowed) :
        state(state),
        location(location),
        borrowed(borrowed),
        holder(nullptr){}

BookLibrary::BookLibrary() :
        state(eBookState::WELL_PRESERVED),
        borrowed(false),
        holder(nullptr) {}
