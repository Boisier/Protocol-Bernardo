//
//  S-311-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_311_00_hpp
#define S_311_00_hpp

#include "../../Output.hpp"

class S31100: public Output {
public:

	S31100(): Output(31100,	// Output ID
					 false,	// Is tree end ?
					 312,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"De quoi donc ?"
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_311_00_hpp */
