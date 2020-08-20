/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 11/28/2018
**********************************************************/
#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>

namespace w7 {
	template <typename T = double>
	class DataTable {
		int width;
		int decPrec;

		std::vector<T> Xvalue;
		std::vector<T> Yvalue;

		template <typename Func>
		T calcSum(std::vector<T> data, Func func) const {

			return std::accumulate(data.begin(), data.end(), T(0), func);

		}

		T calcSum(std::vector<T> data) const {

			return std::accumulate(data.begin(), data.end(), T(0));

		}

	public:
		DataTable(std::ifstream& ifs, const int& fw, const int& prec) : width(fw), decPrec(prec) {

			std::string buffer;
			int ln_cnt = 0;

			while (!ifs.eof()) {
				std::getline(ifs, buffer);
				if (buffer.length() > 0)
					++ln_cnt;
			}

			ifs.clear();
			ifs.seekg(0, ifs.beg);

			T tempX, tempY;

			for (int i = 0; i < ln_cnt; i++) {
				ifs >> tempX >> tempY;
				if (ifs.fail()) {
					std::string err = "File has invalid formatting";
					throw err;
				}
				Xvalue.push_back(tempX);
				Yvalue.push_back(tempY);
			}
		}

		T mean() const {
			return calcSum(Yvalue) / getSize();
		}

		T sigma() const {
			T avg = mean();
			T sum = calcSum(Yvalue, [&](const T& a, const T& b) -> T {
				return a + (b - avg) * (b - avg);
			});

			sum = sum / (getSize() - 1);
			sum = sqrt(sum);

			return sum;
		}
		T median() const {
			std::vector<T> temp = Yvalue;
			std::sort(temp.begin(), temp.end());
			return temp[temp.size() / 2];
		}

		void regression(T& slope, T& y_intercept) const {
			T sumX = calcSum(Xvalue);

			T sumY = calcSum(Yvalue);

			T sumXY = std::inner_product(Xvalue.begin(), Xvalue.end(), Yvalue.begin(), T(0));

			T sumXSq = calcSum(Xvalue, [](const T& a, const T& b) -> T {
				return a + b * b;
			});

			T n = getSize();

			slope = ((n * sumXY) - (sumX * sumY)) / ((n * sumXSq) - (sumX * sumX));
			y_intercept = (sumY - slope * sumX) / n;
		}
		void display(std::ostream& os) const {
			os << std::setw(width) << "x" << std::setw(width) << "y" << std::endl;

			os << std::fixed << std::setprecision(decPrec);

			for (size_t i = 0; i < getSize(); ++i) {
				os << std::setw(width) << Xvalue[i]
					<< std::setw(width) << Yvalue[i] << std::endl;
			}
		}

		size_t getSize() const {
			return Xvalue.size();
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& src) {
		src.display(os);

		return os;
	}
}

#endif