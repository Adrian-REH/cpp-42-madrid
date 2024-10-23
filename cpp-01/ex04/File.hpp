/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:00:20 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 02:00:20 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include <string>

class File {
	private:
		std::string _filename;
		std::string _content;
		int _num_line;
	public:
	File(std::string filename);
	~File();
	void setContent(std::string content);
	std::string getContent();
	void replace(std::string ocurrence, std::string replacement);
	int readFile();
	int writeTruncFile();
};

#endif