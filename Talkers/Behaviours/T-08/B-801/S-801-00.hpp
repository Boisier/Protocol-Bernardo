//
//  S-801-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_801_00_hpp
#define S_801_00_hpp

#include "../../Output.hpp"

class S80100 : public Output {
public:

	S80100() : Output(80100,	// Output ID
		false,	// Is tree end ?
		802,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Probablement. Pourquoi y seraient-elles sinon ?"
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_801_00_hpp */