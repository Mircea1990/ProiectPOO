#pragma once

#include "LocuriLibereSala.h"

template <typename T>
class ISala {
public:
	virtual our_iterator<T> begin() const = 0;
	virtual our_iterator<T> end() const = 0;
protected:
	LocuriLibereSala locuriLibere;
};

