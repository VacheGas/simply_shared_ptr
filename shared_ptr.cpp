#include <iostream>

template <typename T>
class shared_ptr {

public:
	shared_ptr(const shared_ptr& arg) {
		ptr = arg.ptr;
		control = arg.control;
		++(*control);
	};
	
	shared_ptr() {
		ptr = nullptr;
		control = new int;
		*control = -1;
	}
	
	shared_ptr(T *arg) {
		ptr = arg;
		control = new int;
		*control = 0;
	}
	
	shared_ptr(T arg) : ptr(new T(arg)) {
		*control = 0;
	}
	
	shared_ptr(shared_ptr&& arg) : ptr(arg.ptr) {
		arg.ptr = nullptr;
		arg.ptr = nullptr;
		
	}

	~shared_ptr() {
		if (*control == 0) {
			delete ptr;
			delete control;
			ptr = nullptr;
			control = nullptr;
		} else {
			--(*control);
		}
	}
	
	T &operator [](int idx){
		return ptr[idx];
	}
	
	T& operator *() {
		return  *ptr;
	}
	
	T* operator-> () {
		return  ptr;
	}
	
private:
	T *ptr;
	int *control;
};