//
//  Output.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-27.
//

#include <cstdlib>
#include <ctime>

#include <boost/regex.hpp>

#include "Output.hpp"
#include "Message.hpp"

#include "../Utils/Random.hpp"

double Output::getDelay() const {
	if(!_isDelayed)
		return 0;

	// Init rand
	srand (static_cast <unsigned> (time(0)));

	// Get variance
	double variance = ((rand() / RAND_MAX) * _delayVariance * 2) - _delayVariance;

	return _delayValue + variance;
}

Message * Output::getMessage() const {
	Message * message = new Message();
	message->behaviour = _nextBehaviour;

	for(const std::string &valueName: _outputValues) {
		message->values[valueName] = _state.at(valueName);
	}

	message->caption = getCaption();

	return message;
}

std::string Output::getCaption() const {
	// Select a caption by random
	std::string rawCaption = *select_randomly(_captions.begin(), _captions.end());

	// Replace flags in the regex
	std::string builtCaption = boost::regex_replace(rawCaption, boost::regex("(\\{[\\w]+\\})+"), [&] (auto& match) -> std::string {

		// For each match
		std::string fullMatch = match.str();
		std::string key = fullMatch.substr(1, fullMatch.size() - 2);

		return _state.at(key);
	});

	return builtCaption;
}