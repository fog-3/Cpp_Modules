/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:22:24 by fosuna-g          #+#    #+#             */
/*   Updated: 2026/11/23 17:22:25 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("DefaultShrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        _target = other._target;
        setIsSigned(other.getIsSigned());
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}


void ShrubberyCreationForm::performAction() const {
    std::ofstream outfile((_target + "_shrubbery").c_str());

    if (!outfile.is_open()) {
        throw OpenFileExeption();
    }

    outfile
        << "                     *\n"
        << "                    /|\\\n"
        << "                   /*|*\\\n"
        << "                  /**|**\\\n"
        << "                 /o**|**o\\\n"
        << "                /***O|O***\\\n"
        << "               /****/|\\****\\\n"
        << "              /o***/ | \\***o\\\n"
        << "             /____/__|__\\____\\\n"
        << "                 /***|***\\\n"
        << "                /**o*|*o**\\\n"
        << "               /*****|*****\\\n"
        << "              /O****o|o****O\\\n"
        << "             /*******|*******\\\n"
        << "            /o***O***|***O***o\\\n"
        << "           /_________|_________\\\n"
        << "               /*****|*****\\\n"
        << "              /o*****|*****o\\\n"
        << "             /*******|*******\\\n"
        << "            /**O*****|*****O**\\\n"
        << "           /********o|o********\\\n"
        << "          /o****O****|****O****o\\\n"
        << "         /***********|***********\\\n"
        << "        /____________|____________\\\n"
        << "                    |||\n"
        << "                    |||\n"
        << "                 ___|||___\n"
        << "                |_________|\n";

    outfile.close();
}

const char *ShrubberyCreationForm::OpenFileExeption::what() const throw()
{
	return ("Could not open and write the file!");
}
