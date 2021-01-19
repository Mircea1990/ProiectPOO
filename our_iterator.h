#pragma once

template <typename T>
class our_iterator {
public:
	our_iterator(T* pointer) : pointer(pointer) {
	}
	our_iterator operator++() { ++pointer; return *this; }
	bool operator!=(const our_iterator& i) const { return pointer != i.pointer; }
	const T& operator*() const { return *pointer; }
private:
	T* pointer;
};

