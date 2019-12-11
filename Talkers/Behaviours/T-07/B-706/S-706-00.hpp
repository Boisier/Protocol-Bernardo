//
//  S-706-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_706_00_hpp
#define S_706_00_hpp

#include "../../Output.hpp"

class S70600 : public Output {
public:

	S70600() : Output(70600,	// Output ID
		true,	// Is tree end ?
		-1,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Je m'inqui�te pour mes capteurs.",
		"C'�tait un test.",
		"Simple curiosit�."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_706_00_hpp */