/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:00:15 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 02:00:18 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"
#include <iostream>
#include <fstream>

File::File(std::string filename) : _filename(filename), _content(""), _num_line(0)
{

}
File::~File()
{
	
}
std::string File::getContent()
{
	return _content;
}
void File::setContent(std::string content){
	_content = content;
}

int File::readFile()
{
	std::ifstream inFile(_filename.c_str());

	if (!inFile)
	{
		std::cout << "Error to open file: "<< _filename << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		_content += line + "\n";
		_num_line++;
	}
	inFile.close();
	return 0;
}

int File::writeTruncFile()
{
	std::ofstream outFile(_filename.c_str(), std::ios::trunc);

	if (!outFile){
		std::cout << "Error to open file: "<< _filename << std::endl;
		return 1;
	}
	outFile << _content;
	outFile.close();
	return 0;
}

void File::replace(std::string ocurrence, std::string replacement)
{
	std::string result;
	size_t pos = 0;
	size_t found = 0;

	while (true)
	{
		found = _content.find(ocurrence, pos);
		if (found == std::string::npos)
		{
			result += _content.substr(pos);
			break;
		}
		result += _content.substr(pos, found - pos);
		result += replacement;
		pos = found + ocurrence.length();
	}
	_content = result;
}
