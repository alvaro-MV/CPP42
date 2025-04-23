template<typename T>
T easyfind(T container, int pattern) {
	for (int i = 0; i < container.size(); i++)
	{
		if (container.front() == pattern)
			return T(container);
		container.erase(container.begin());
	}
		
	throw std::out_of_range("The pattern isn't founded inside container");
}