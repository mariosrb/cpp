#include "./include/Pmerge.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& to_copy) {
	if (this != &to_copy)
		{
			_vectorData = to_copy._vectorData;
			_dequeData = to_copy._dequeData;
		}
		return (*this);
}

const std::vector<int>& PmergeMe::getVectorData() const {
	return (_vectorData);
}

const std::deque<int>& PmergeMe::getDequeData() const {
	return (_dequeData);
}

// Parse les arguments, verifie leur validite et les push dans les conteneurs
void	PmergeMe::parseInput(int argc, char* argv[]) {

	if (argc < 2) {
		throw std::invalid_argument("Error : must be 2 arg min.");
	}

	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];

		if (arg.empty() || arg[0] == '-') {
			throw std::invalid_argument("Error : Empty or negative value.");
		}

		for (size_t j = 0; j < arg.length(); j++) {
			if (!isdigit(arg[j])) {
				throw std::invalid_argument("Error");
			}
		}

		// 4. Conversion et vérification des limites (Overflow)
		char* end;
		long num = strtol(arg.c_str(), &end, 10);

		// Si strtol n'a pas tout converti, ou si c'est < 0 (redondant mais sûr) ou > INT_MAX
		if (*end != '\0' || num < 0 || num > INT_MAX) {
			throw std::overflow_error("Error");
		}

		// Ajout aux conteneurs
		_vectorData.push_back(static_cast<int>(num));
		_dequeData.push_back(static_cast<int>(num));
	}
}

// On affiche soit after soit before en verifiant le nb de int
void PmergeMe::displaySequence(const std::string& title, const std::vector<int>& data) const {
	std::cout << title;

	if (data.empty()) {
		std::cout << std::endl;
		return;
	}

	size_t	displayCount = data.size() > 5 ? 5 : data.size();
	for (size_t i = 0; i < displayCount; i++) {
		std::cout << data[i];
		if (i < displayCount - 1)
			std::cout << " ";
	}

	if (data.size() > 5)
		std::cout << " [...]";

	std::cout << std::endl;
}

// retourne la diff entre fin et debut / valeur dun tick en seconde puis converti en microseconde
double	PmergeMe::getTimeDif(clock_t start, clock_t end) const {
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000.0;
}

std::vector<size_t> PmergeMe::_generateJacobsthal(size_t maxSize) {
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	// J(n) = J(n-1) + 2 * J(n-2)
	while (jacobsthal.back() < maxSize) {
		size_t last = jacobsthal.back();
		size_t prev = jacobsthal[jacobsthal.size() - 2];
		size_t next = last + 2 * prev;

		jacobsthal.push_back(next);
    }

    return jacobsthal;
}

void	PmergeMe::execute() {
	displaySequence("Before: ", _vectorData);

	clock_t	startVec = clock();
	_sortVector(_vectorData);
	clock_t	endVec = clock();
	double	timeVec = getTimeDif(startVec, endVec);

	displaySequence("After: ", _vectorData);
	std::cout << "Time to process a range of " << _vectorData.size()
				<< " elements with std::vector : " << timeVec << " us" << std::endl;

}

std::vector<int>::iterator PmergeMe::_binarySearch(std::vector<int>& sortedList, int val) {
	int	low = 0;
	int high = sortedList.size();

	while (low < high) {
		// calcul du milieu
		int mid = low + (high - low) / 2;
		if (sortedList[mid] < val) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	return (sortedList.begin() + low);
}

void PmergeMe::_sortVector(std::vector<int>& arr) {
	if (arr.size() <= 1)
		return;

	// Etape 1) creation des pairs et gestion de straggler
	// On verifie, recupere et enleve le straggler
	bool hasStraggler = (arr.size() % 2 != 0);
	int straggler = 0;
	if (hasStraggler) {
		straggler = arr.back();
		arr.pop_back();
	}

	// Creation des pairs
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		int a = arr[i];
		int b = arr[i + 1];

		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	// Dans une chaine on met que les max
	std::vector<int>	mainChain;
	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
	}
	// appel recursif on trie les gagnants
	_sortVector(mainChain);

	// Etape 3 : Recontruction
	std::vector<int>	waiting;
	// Main chain est trie faut reorganiser les pairs on pousse la nvl derriere et on supp
	for (size_t i = 0; i < mainChain.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (pairs[j].first == mainChain[i]) {
				waiting.push_back(pairs[j].second);
				std::swap(pairs[j], pairs.back());
				pairs.pop_back();
				break;
			}
		}
	}

	mainChain.insert(mainChain.begin(), waiting[0]);
	//on genere la suite
	std::vector<size_t>	jacobsthal = _generateJacobsthal(waiting.size());

	size_t last_pos = 1;
	for (size_t k = 3; k < jacobsthal.size(); k++) {
		size_t boundary = jacobsthal[k];
		if (boundary > waiting.size())
			boundary = waiting.size();
		// insertion en reculant de boundary a derniere traite
		for (size_t i = boundary; i > last_pos; i--) {
			int	valToInsert = waiting[i - 1]; // waiting est 0 indexed donc decale de 1
			// binary search on cherche ou inserer la vaToInsert dans mainChain
			std::vector<int>::iterator pos = _binarySearch(mainChain, valToInsert);
			mainChain.insert(pos, valToInsert);
		}
		last_pos = boundary;
		if (last_pos == waiting.size())
			break;
	}
	if (hasStraggler) {
		std::vector<int>::iterator pos = _binarySearch(mainChain, straggler);
		mainChain.insert(pos, straggler);
	}
	arr = mainChain;
}


