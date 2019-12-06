//
//  S-200-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_200_00_hpp
#define S_200_00_hpp

#include "../../Output.hpp"

class S20000: public Output {
public:

	S20000(): Output(20000,	// Output ID
					 false,	// Is tree end ?
					 201,	// Next Behaviour ID
					 false,	// Is delayed
					 0,		// Delay value (seconds)
					 0,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"As-tu détecté ça ?."
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_200_00_hpp */