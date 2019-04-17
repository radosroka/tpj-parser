#include <iostream>
#include <memory>

#include "ricc-parser.hpp"
#include "ricc-parser-private.hpp"

#include "util/MakeUnique.hpp"

#include "util/Logger.hpp"

namespace RICC {

	Parser::Parser(std::istream& stream)
	: _d_pointer(RICC::make_unique<ParserPrivate>(stream)) {
		DEBUG("");
	}

	Parser::~Parser() = default;

	void Parser::Run() {
		DEBUG("");
		_d_pointer->Run();
	}

}