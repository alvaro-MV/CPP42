#include "ScavTrap.hpp"

int	main(void) {

	ScavTrap st("robototo");

	st.attack("Perico");

	st.beRepaired(7);
	st.guardGate();
}