#ifndef SHARED_POINTER_H
# define SHARED_POINTER_H

#include <algorithm>
#include <atomic>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <utility>

template <typename T, class Deleter = std::default_delete<T>>
class SharedPointer
{
	private:
		template <class Y>
		struct Block
		{
			Y	*ptr;
			std::atomic<long> strong_count;
			std::atomic<long> weak_count;
			Deleter d;
		};
		Block<T>	*b;

	public:

		SharedPointer() {
			b = new Block<T>;
			b->ptr = nullptr;
			b->strong_count = 0;
			b->weak_count = 0;
		}
		SharedPointer(T *ptr) {
			b = new Block<T>;
			b->ptr = ptr;
			b->strong_count = 1;
			b->weak_count = 0;
		};
		SharedPointer(const SharedPointer &sp) {
			this->b = sp.b;
			this->b->strong_count++;
		}
		
		SharedPointer(T* ptr, Deleter d) {
			b = new Block<T>;
			b->ptr = ptr;
			b->strong_count = 1;
			b->weak_count = 0;
			b->d = d;
		}
		
		SharedPointer& operator=(SharedPointer &sp) {
			this->b = sp.b;
			this->b->strong_count++;
			return (*this);
		}

		~SharedPointer() {
			if (b->strong_count > 0)
				b->strong_count--;
			if (!b->strong_count && !b->weak_count) {
				b->d(b->ptr); // b->deleter()
				delete b;
				std::cout << "No ref. left. Deleting the owned pointer" << std::endl;
			}
			std::cout << "SharedPointer destroyed" << std::endl;
		}

		T	operator*(SharedPointer &sp) {
			return (sp.b->ptr);
		}

		T* operator->() {
     	   return b->ptr;
   		}


		const T* operator->() const {
			return b->ptr;
		}

		void	reset(void) { //shared_ptr().swap(*this);.
			this->b->strong_count--;
			if (!this->b->strong_count && !this->b->weak_count) {
				b->d(b->ptr);
				delete b;
				this->b = new Block<T>;
			}
			b->ptr = nullptr;
			b->strong_count = 0;
			b->strong_count = 0;
		} //Se carga el puntero en caso de ser el último y pone un nullptr
		
		T	*get(void) {
			return (b->ptr);
		}

		void	reset(T* ptr) {
			this->b->strong_count--;
			if (!this->b->strong_count && !this->b->weak_count) {
				b->d(b->ptr);
				delete b;
				this->b = new Block<T>;
			}
			b->ptr = ptr;
			b->strong_count = 1;
			b->strong_count = 0;
		}
		
		void	reset(T* ptr, Deleter d) {
			if (!this->b->strong_count && !this->b->weak_count)
				d(b->ptr);
			b->ptr = ptr;
			b->strong_count = 1;
			b->strong_count = 0;
		}

		long	use_count(void) const{
			return this->b->strong_count;
		}

		void	swap(SharedPointer& r) noexcept {
			Block<T>	*tmp = r.b;

			tmp = this->b;
			this->b = r.b;
			r.b = tmp;
		}
	
};

template< class T, class... Args >
	SharedPointer<T> MakeShared(Args&&... args);

template< class T >
	SharedPointer<T> MakeShared();

template< class T >
	SharedPointer<T> MakeShared(T *ptr);


#endif