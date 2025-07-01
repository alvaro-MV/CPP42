using namespace std;
#include "shared_pointer.hpp"

template< class T, class... Args >
SharedPointer<T> MakeShared(Args&&... args) {
	T	*obj = new T(std::forward<Args>(args)...);
	return (SharedPointer<T>(obj));
}

template< class T >
SharedPointer<T> MakeShared() {
	return (SharedPointer<T>());
}

template< class T >
SharedPointer<T> MakeShared(T *ptr) {
	return (SharedPointer<T>(ptr));
}

struct Song
{
    std::string artist;
    std::string title;
    Song(const std::string& artist_, const std::string& title_) :
        artist{ artist_ }, title{ title_ } {}
};


void	print_cosas(SharedPointer<Song> sp) {
	std::cout << "sp use count: " << sp.use_count() << std::endl;
}

// int main()
// {
// 		// Use make_shared function when possible.
// 	Song *song_ptr = new Song("Rata", "Timorata");
	
// 	SharedPointer<Song> sp;
// 	std::cout << "sp use count: " << sp.use_count() << std::endl;

// 	SharedPointer<Song>	sp2 = MakeShared<Song>(song_ptr);
// 	std::cout << "sp2 artist: " << sp2->artist << std::endl;

// 	sp.swap(sp2);
// 	std::cout << "sp use count " << sp.use_count() << " sp2 use count: " << sp2.use_count() << std::endl;
// 	std::cout << "sp artist: " << sp->artist << std::endl;

// 	sp.reset();
// 	std::cout << "sp use count " << sp.use_count() << " sp2 use count: " << sp2.use_count() << std::endl;

// }

int	main(void) {
	// Song *song_ptr = new Song("Rata", "Timorata");
	
	SharedPointer<Song>	sp = MakeShared<Song>("Rata", "Timorata");
	std::cout << "sp artist: " << sp->artist << std::endl;

	std::cout << "sp use count " << sp.use_count() << " sp raw: " << sp.get() << std::endl;

	SharedPointer<Song> sp2 = sp;
	std::cout << "sp use count " << sp.use_count() << " sp2 use_count: " << sp2.use_count() << std::endl;
	print_cosas(sp);


	SharedPointer<Song> sp3(sp2);
	std::cout << "sp2 use count " << sp2.use_count() << " sp3 use_count: " << sp3.use_count() << std::endl;
	print_cosas(sp);
}


int	main(void) {
	vector<shared_ptr<Song>> v {
	make_shared<Song>("Bob Dylan", "The Times They Are A Changing"),
	make_shared<Song>("Aretha Franklin", "Bridge Over Troubled Water"),
	make_shared<Song>("Thalía", "Entre El Mar y Una Estrella")
	};

	vector<shared_ptr<Song>> v2;
	remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (shared_ptr<Song> s) 
	{
		return s->artist.compare("Bob Dylan") == 0;
	});

	for (const auto& s : v2)
	{
		cout << s->artist << ":" << s->title << endl;
	}
}

// int	main(void) {
// 	vector<SharedPointer<Song>> v {
// 	MakeShared<Song>("Bob Dylan", "The Times They Are A Changing"),
// 	MakeShared<Song>("Aretha Franklin", "Bridge Over Troubled Water"),
// 	MakeShared<Song>("Thalía", "Entre El Mar y Una Estrella")
// 	};

// 	vector<SharedPointer<Song>> v2;
// 	remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (SharedPointer<Song> s) 
// 	{
// 		return s->artist.compare("Bob Dylan") == 0;
// 	});

// 	for (const auto& s : v2)
// 	{
// 		cout << s->artist << ":" << s->title << endl;
// 	}
// }


