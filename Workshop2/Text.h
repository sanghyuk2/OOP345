/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 10/12/2018
**********************************************************/
#ifndef W3_TEXT_H
#define W3_TEXT_H

namespace w2 {
	class Text {
		std::string fileName;
		std::string* str;
		size_t n;
	public:
		Text();
		Text(const std::string);
		Text(const Text&);
		Text(Text&&);
		Text& operator=(const Text&);
		Text& operator=(Text&&);
		~Text();
		size_t size() const;
	};
	int getFileLine(std::ifstream&);
}
#endif 