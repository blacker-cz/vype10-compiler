/*
 * VYPe 2010 Compiler project
 *//**
 * Header file containing important constants.
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <exception>
#include <string>

/** No error return code */
#define RET_ERR_OK 0

/** Lexical error return code */
#define RET_ERR_LEXICAL 1

/** Syntactical error return code */
#define RET_ERR_SYNTACTICAL 2

/** Semantical error return code */
#define RET_ERR_SEMANTICAL 3

/** Generation error return code */
#define RET_ERR_GENERATION 4

/** Internal error return code */
#define RET_ERR_INTERNAL 5

/**
 * Processing exception class.
 */
class ProcessingException {
public:
	int code;
	std::string msg;

	ProcessingException(int code, const std::string &msg) {
		this->code = code;
		this->msg = msg;
	};
};

#endif /* CONSTANTS_H_ */
