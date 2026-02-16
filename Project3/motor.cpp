#include <iostream>

template <class T>
class  LimitValue {

private:
	T current_value ;
	T min_value ;
	T max_value ;

public:	LimitValue(T value, T min, T max) :current_value(value), min_value(min), max_value(max){}

	T val() {
		return current_value;
}

	LimitValue& operator=(T num){
		if (num > max_value)
			current_value = max_value;
		else if (num < min_value)
			current_value = min_value;
		else
			current_value = num;
		return *this;
}
	LimitValue& operator+=(T sum) {
		current_value += sum;
		while (current_value > max_value) {
			current_value -= (max_value - min_value);
		}
		while (current_value < min_value) {
			current_value += (max_value - min_value);
		}
		return *this;
	}
};


