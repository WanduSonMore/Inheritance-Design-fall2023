#pragma once
template <class T>
class queue
{
private:
	deque <T> data;
public:
	queue assign(queue rhs);
	queue copy(queue rhs);
	int size() const {return data.}
	bool empty() const { return data.empty(); }
	void push(const T& t) { date.push_back(t); }
	void pop() { data.pop_front(); }
	T& front() { return data.front(); }
	T& back() { return data.back(); }
};

//template <class T>
//class deque
//{
//
//};