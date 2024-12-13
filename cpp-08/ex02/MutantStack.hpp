

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <deque>
#include <stack>

template <typename T, typename Sequence = std::deque<T> >
class MutantStack : public std::stack<T>{
	public:
		MutantStack() : std::stack<T>() {}
		~MutantStack() {}
		MutantStack(MutantStack const &other) : std::stack<T>(other) {}
		MutantStack &operator=(MutantStack const &other) {
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		typedef typename Sequence::iterator iterator;
		typedef typename Sequence::const_iterator const_iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }

};

#endif