//
//  S-805-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_805_00_hpp
#define S_805_00_hpp

#include "../../Output.hpp"

class S80500 : public Output {
public:

	S80500() : Output(80500,	// Output ID
		false,	// Is tree end ?
		806,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"�galement."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_805_00_hpp */
