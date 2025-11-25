#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <ctime>
#include <climits>
#include <stdexcept>
#include <algorithm>

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& to_copy);

		// gestion
		void	parseInput(int argc, char* argv[]);
		void	execute(); // Lance tout et mesure le temps

		// utils
		void	displaySequence(const std::string& title, const std::vector<int>& data) const;
		void	displaySequence(const std::string& title, const std::deque<int>& data) const;
		double	getTimeDif(clock_t start, clock_t end) const;

		// getters
		const std::vector<int>& getVectorData() const;
		const std::deque<int>&  getDequeData() const;

	private:
		std::vector<int>	_vectorData;
		std::deque<int>		_dequeData;

		// pour vector
		// Algo recursif principal
		void						_sortVector(std::vector<int>& arr);
		std::vector<int>::iterator	_binarySearch(std::vector<int>& sortedSeq, int val);

		//pour deque
		void						_sortDeque(std::deque<int>& arr);
		std::deque<int>::iterator	_binarySearch(std::deque<int>& sortedSeq, int val);

		// utils
		std::vector<size_t> 		_generateJacobsthal(size_t maxSize);
};

#endif